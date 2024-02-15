#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <numeric>

using std::vector;

// solving y'=y+x with y(0) = 1
// y = -x+2e^x-1

const double YA = 1;

double f(double x, double y) {
    return y + x;
}

vector<double> RungeKutt() {
    vector<double> y;
    y.push_back(YA);
    double h = (b - a) / N;

    for(size_t i = 1; i <= N; ++i) {
        double xn = a + i * h;
        double yn = y[i - 1];
        
        double k1 = f(xn, yn);
        double k2 = f(xn + h / 2, yn + h * k1 / 2);
        double k3 = f(xn + h / 2, yn + h * k2 / 2);
        double k4 = f(xn + h, yn + h * k3);
        y.push_back(yn + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6);
        // eps.push_back(fabs(-xn + 2 * exp(xn) - 1 - yn));
    }
    
    return y;
}

class RKSolver {
public:
    RKSolver() = default;
    vector<double> y;
    vector<double> eps;
    double a = 0, b = 1; // границы
    unsigned int N = 10000; // степень приближения
    // наконец узнаю как добавлять лямбда функции в параметры ыыыыы
    void Solve() {
        
    }
private:

};

int main(int argc, char** argv) {
    RKSolver s;
    s.Solve();
    std::ofstream output("rk");
    output << std::fixed << std::showpoint;
    output << std::setprecision(10);
    for(size_t i = 0; i < s.N + 1; ++i) {
        output << s.y[i] << ' ' << s.eps[i] << '\n';
    }
    std::cout << std::accumulate(s.eps.begin(), s.eps.end(), 0) / s.N << '\n';
    output.close();
}