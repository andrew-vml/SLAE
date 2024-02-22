#include "dense_matrix.hpp"

double Dense_Matrix::operator()(std::size_t i, std::size_t j) const
{
    return V[cols * i + j];
}

Dense_Matrix Dense_Matrix::operator+(const Dense_Matrix & another) const
{
    std::vector<double>result;
    for (std::size_t i = 0; i < rows; ++i)
    {
        for(std::size_t j = 0; j < cols; ++j)
        {
            result.push_back(V[cols * i + j] + another(i, j));
        }
    }
    Dense_Matrix result_Matrix(result, cols, rows);
    return result_Matrix;
}

Dense_Matrix Dense_Matrix::operator*(const Dense_Matrix & another) const //tricikl
{
     std::vector<double>result;
    for (std::size_t i = 0; i < rows; ++i)
    {
        for(std::size_t j = 0; j < another.cols; ++j)
        {
            for(size_t k = 0; k < cols; ++k)
            {
                result.push_back(V[cols * i + k] * another(k,j));
            }
        }
    }
    Dense_Matrix result_Matrix(result, cols, rows);
    return result_Matrix; 
}

Dense_Matrix Dense_Matrix::operator*(double num) const
{
    std::vector<double>result;
    result = V * num;
    Dense_Matrix result_Matrix(result, cols, rows);
    return result_Matrix;
}

std::vector <double> Dense_Matrix::operator*(const std::vector<double>& vec) const
{
    std::vector <double> result;
    for(std::size_t i = 0; i < rows; ++i)
    {
        for(std::size_t j = 0; j < cols; ++j)
        {
            result.push_back(V[cols * i + j] * vec[j]);
        }
    }
    return result;
}

void Dense_Matrix::show() const
{
    for(std::size_t i = 0; i < rows; ++i)
    {
        for(std::size_t j = 0; j < cols; ++j)
        {
            std::cout<<V[cols * i + j] << " ";
        }
    }
}

size_t Dense_Matrix::GetRows() const
{
    return rows;
}

size_t Dense_Matrix::GetCols() const
{
    return cols;
}