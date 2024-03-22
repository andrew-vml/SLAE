#include "../src/SIM.hpp"
#include <fstream>

int main(){
    std::vector<double> x0 = {1., 2., 4.};
    std::vector<double> v = {7., 1., 5., 1.};
    std::vector<std::size_t> c = {0, 2, 1, 2};
    std::vector<std::size_t> r = {0, 2, 3, 4};
    CSR_Matrix A{v, c, r};
    std::vector<double> b = {6., 1., 1.};

    std::ofstream out;
    out.open("simple_iteration.txt");
    if (out.is_open())
    {
        for (size_t n = 1; n < 32; n++){
            std::cout << n << std::endl;
            std::vector<double> res = SIM(A, x0, b, 0.25, n, 0.00000001);
            out << std::to_string(n) << " "  << std::to_string(std::sqrt(res*res)) << std::endl; 
        }   
    }
}