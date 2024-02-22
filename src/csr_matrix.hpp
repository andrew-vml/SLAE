#pragma once

#include <iostream>
#include "dense_matrix.hpp"
#include <vector>
#include "vector_operations.hpp"

class CSR_Matrix
{
    private:
    std::vector <double> V; //contain the non-zero values
    std::vector <size_t> col_index; //contains the column in which the corresponding entry V is located
    std::vector <size_t> row_index; //the number of non-zero elements in each string and row_index sums in every string
    
    public:
    CSR_Matrix(const std::vector <double>& V, const std::vector <size_t>& col_index, const std::vector <size_t>& row_index): V(V), col_index(col_index), row_index(row_index){};

    CSR_Matrix(const Dense_Matrix & Dmatrix);

    double operator()(std:: size_t i, std::size_t j) const; //access to i and j elements

    CSR_Matrix operator*(double num) const; // matrix * number

    void show() const; // just shows elements of csr matrix

};
