#include "../src/Chebyshev.hpp"
#include <fstream>
#include <time.h>
#include <chrono>

int main(){
    std::vector<double> x0 = {1., 2., 4.};
    std::vector<double> v = {7., 1., 5., 1.};
    std::vector<std::size_t> c = {0, 2, 1, 2};
    std::vector<std::size_t> r = {0, 2, 3, 4};
    CSR_Matrix A{v, c, r};
    std::vector<double> b = {6., 1., 1.};
    std::vector<double> res = Chebyshev(A, x0, b, 1., 7., 7, 0.000001);
    std::ofstream out;

    out.open("simple_chebyshev_time.txt");
    if (out.is_open())
    {
        for (double tolerance = 0.01; tolerance >= 0.0000001; tolerance *= 0.5){
            std::cout << tolerance << std::endl;
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<double> res = Chebyshev(A, x0, b, 1., 7., 7, 0.000001);
            auto end = std::chrono::high_resolution_clock::now();
            out << std::to_string(tolerance) << " "  << std::to_string((end-start).count()) << std::endl; 
        }   
    }
    out.close();
}