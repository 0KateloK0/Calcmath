#include <vector>
#include <fstream>

using std::vector;

double p(double x) {
    return 0;
    // return x * x * x;
}

double q(double x) {
    return -1;
    // return 1 / x;
}

double f(double x) {
    return 2 * x;
    // return 1 / x / x;
}

vector<vector<double>> get_coefficients(double a, double b, unsigned int N) {
    double h = (b - a) / N;
    vector<vector<double>> res;
    res.push_back(vector<double>(N, 0));
    res[0][0] = -2 / h / h + q(a + h);
    res[0][1] = 1 / h / h + p(a + h) / 2 / h;
    for(size_t i = 1; i < N - 1; ++i) {
        double x = a + h * (i + 1);
        res.push_back(vector<double>(N, 0));
        res[i][i - 1] = 1 / h / h - p(x) / 2 / h;
        res[i][i] = -2 / h / h + q(x);
        res[i][i + 1] = 1 / h / h + p(x) / 2 / h;
    }
    res.push_back(vector<double>(N, 0));
    res[N - 1][N - 2] = 1 / h / h - p(b - h) / 2 / h;
    res[N - 1][N - 1] = -2 / h / h + q(b - h);
    return res;
}

vector<double> get_b(double a, double b, double ya, double yb, unsigned int N) {
    double h = (b - a) / N;
    vector<double> res;
    res.push_back(f(a + h) - ya / h / h + p(a + h) / 2 / h * ya);
    for(size_t i = 1; i < N - 1; ++i) {
        res.push_back(f(a + h * (i + 1)));
    }
    res.push_back(f(b - h) - yb / h / h - p(a + h) / 2 / h * yb);
    return res;
}

class IterationSolver {
public:
    // IterationSolver(unsigned int N) : N(N) {}
    // vector<double> y;
    // double a, b; // границы
    // unsigned int N; // степень приближения
    // наконец узнаю как добавлять лямбда функции в параметры ыыыыы
    vector<double> Solve(vector<vector<double>> A, vector<double> b, unsigned int N) {
        vector<double> nu(N, 0);
        vector<double> u(N, 0);
        nu[0] = -A[0][1] / A[0][0];
        u[0] = -b[0] / A[0][0];
        for(size_t i = 1; i < N - 1; ++i) {
            nu[i] = A[i][i + 1] / (-A[i][i] - A[i][i - 1] * nu[i - 1]);
            u[i] = (A[i][i - 1] * u[i - 1] - b[i]) / (-A[i][i] - A[i][i - 1] * nu[i - 1]);
        }
        nu[N - 1] = 0;
        u[N - 1] = (A[N - 1][N - 2] * u[N - 2] - b[N - 1]) / 
                (-A[N - 1][N - 1] - A[N - 1][N - 2] * nu[N - 2]);
        vector<double> y(N, 0);
        y[N - 1] = u[N - 1];
        for(ssize_t i = N - 2; i >= 0; --i) {
            y[i] = y[i + 1] * nu[i] + u[i];
        }
        return y;
    }
private:

};

int main() {
    IterationSolver s{};
    double a = 0;
    double b = 2.452;
    double ya = 0;
    double yb = 0;
    unsigned int N = 10000;
    auto res = s.Solve(get_coefficients(a, b, N), get_b(a, b, ya, yb, N), N);
    std::ofstream out("iter");
    for(auto it : res) {
        out << it << '\n';
    }
    out.close();
}