#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <numeric>
#include <functional>
using std::vector;

double U(double x, double y1, double y2) {
    return 99 * y1 + 250 * y2;
}

double V(double x, double y1, double y2) {
    return 40 * y1 + 99 * y2;
}

class RKSolver {
public:
    RKSolver(double a, double b, unsigned int N, double A, double B) : 
            a(a), b(b), N(N), A(A), B(B) {}
    vector<vector<double>> y;
    vector<double> eps;
    double a = 0, b = 0.01; // границы
    double A = 0, B = -0.004;
    unsigned int N = 1e4; // степень приближения
    void Solve() {
        y.push_back(vector<double>());
        y.push_back(vector<double>());
        RK();
    }
private:
    void RK() {
        double h = (b - a) / N;
        for (auto& it: y) it.clear();
        y[0].push_back(A);
        y[1].push_back(B);
        for(size_t i = 1; i <= N; ++i) {
            double xn = a + i * h;
            double yn = y[0][i - 1];
            double zn = y[1][i - 1];
            
            double k1 = U(xn, yn, zn);
            double q1 = V(xn, yn, zn);
            double k2 = U(xn + h / 2, yn + h * k1 / 2, zn + h * q1 / 2);
            double q2 = V(xn + h / 2, yn + h * k1 / 2, zn + h * q1 / 2);
            double k3 = U(xn + h / 2, yn + h * k2 / 2, zn + h * q2 / 2);
            double q3 = V(xn + h / 2, yn + h * k2 / 2, zn + h * q2 / 2);
            double k4 = U(xn + h, yn + h * k3, zn + h * q3);
            double q4 = V(xn + h, yn + h * k3, zn + h * q3);

            y[0].push_back(yn + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6);
            y[1].push_back(zn + h * (q1 + 2 * q2 + 2 * q3 + q4) / 6);
        }
    }
};

int main(int argc, char** argv) {
    RKSolver s(std::stod(argv[1]), std::stod(argv[2]), std::stoi(argv[3]),
            std::stod(argv[4]), std::stod(argv[5]));
    s.Solve();
    std::ofstream output("kaf_rk", std::ofstream::out | std::ofstream::trunc);
    output << std::fixed << std::showpoint;
    output << std::setprecision(10);
    for(size_t i = 0; i <= s.N; ++i) {
        output << s.y[0][i] << ' ' << s.y[1][i] << '\n';
    }
    output.close();
}