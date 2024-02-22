#include "csr_matrix.hpp"

CSR_Matrix::CSR_Matrix(const Dense_Matrix & Dmatrix)
{
    row_index.push_back(0); //because of the rules for making csr
    std::size_t k = 0; //the number of non-zero elements in the start
    for(std::size_t i = 0; i < Dmatrix.GetRows(); ++i)
    {
        for (size_t j = 0; j < Dmatrix.GetCols(); ++j)
        {
            if(Dmatrix(i, j) != 0)
            {
                V.push_back(Dmatrix(i, j));
                col_index.push_back(j);
                k++;
            }
        }
        row_index.push_back(k);
        
    }

}
double CSR_Matrix::operator()(std:: size_t i, std::size_t j) const
{
    for(std::size_t n = row_index[i]; n < row_index[i + 1]; ++n)
    {
        if(col_index[n] == j)
        {
            return V[n];
        }
    }
}

CSR_Matrix CSR_Matrix::operator*(double num) const {
    std::vector<double> result;
    for (std::size_t i = 0; i < V.size(); ++i) {
        result.push_back(V[i] * num);
    }
    CSR_Matrix result_Matrix(result, col_index, row_index);
    return result_Matrix;
}

void CSR_Matrix::show() const {
        std::cout << "non-zero values: ";
        for(std::size_t i = 0; i <V.size(); i++) std::cout << V[i] << " ";
        std::cout << std::endl;
        std::cout << "the column in which the corresponding entry V is located: ";
        for(std::size_t i = 0; i < col_index.size(); i++) std::cout << col_index[i] << " ";
        std::cout << std::endl;
        std::cout << "the number of non-zero elements in each string and row_index sums in every string: ";
        for(std::size_t i = 0; i < row_index.size(); i++) std::cout << row_index[i] << " ";
        std::cout << std::endl;    
}