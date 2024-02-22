#include"vector_operations.hpp"

std::vector<double>operator*(const std::vector<double> & x, const double & num)
{
    std::vector<double>result;
    for(std::size_t i = 0; i < x.size(); ++i)
    {
        result.push_back(x[i] * num);
    }
    return result;
}

std::vector<double>operator*(const double & num, const std::vector<double> & x)
{
    std::vector<double>result;
    for(std::size_t i = 0; i < x.size(); ++i)
    {
        result.push_back(num * x[i]);
    }
    return result;
}

double operator*(const std::vector<double> & x, const std::vector<double> & y)
{
    double result = 0;
    for(std::size_t i = 0; i < x.size(); ++i)
    {
        result += x[i] * y[i];
    }
    return result;
}

std::vector<double>operator+(const std::vector<double> & x, const std::vector<double> & y)
{
    std::vector<double>result;
    for(std::size_t i = 0; i < x.size(); ++i)
    {
        result.push_back(x[i] + y[i]);
    }
    return result;
}

std::vector<double>operator-(const std::vector<double> & x, const std::vector<double> & y)
{
    std::vector<double>result;
    for(std::size_t i = 0; i < x.size(); ++i)
    {
        result.push_back(x[i] - y[i]);
    }
    return result;
}

void show(const std::vector<double> & result)
{
    for(std::size_t i = 0; i < result.size(); ++i)
    {
        std::cout<<result[i]<< " ";
    }
}


