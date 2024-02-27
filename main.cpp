#include <fstream>
#include <vector>
#include <array>
#include "DTO.hpp"
#include "RungeKuttSolver.hpp"

int main(int argc, char** argv) {
    // auto s = Solver.get_instance(argc, argv); // абстрактный солвер принимающий на вход параметры задачи
    // Солвер не должен иметь в конструкторе параметры как argv потому что это извращение

    // s.solve();
    // Солвер также не должен знать ничего про вывод его результатов
    // std::ofstream f;
    // s.outputs.print(f); // наверное, результаты могут знать как им самих себя вывести в произвольный поток
    // f.close();
    print();
    return 0;
}