#pragma once

#include<iostream>
#include<vector>

std::vector<double>operator*(const std::vector<double> & x, const double & num); //vector * number

std::vector<double>operator*(const double & num, const std::vector<double> & x); //number * vector

double operator*(const std::vector<double> & x, const std::vector<double> & y); //vector * vector

std::vector<double>operator+(const std::vector<double> & x, const std::vector<double> & y); // vector + vector

std::vector<double>operator-(const std::vector<double> & x, const std::vector<double> & y); // vector - vector

void show(const std::vector<double> & result); // just shows elements of vector