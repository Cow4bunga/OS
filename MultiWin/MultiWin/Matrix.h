#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <thread>
#include <mutex>
#include <ctime>
#include <windows.h>

class Matrix {
public:
	Matrix() {}

	Matrix(int _size) :a(_size, std::vector<double>(_size, 0)), n(_size) {}

	Matrix(std::vector<std::vector<double>> v, int s) : a(v), n(s) {}

	int getSize() const {
		return n;
	}

	double operator()(int i, int j) const {
		return a[i][j];
	}

	double& operator()(int i, int j) {
		return a[i][j];
	}

private:
	std::vector<std::vector<double>> a;
	int n;
};

std::ostream& operator<<(std::ostream& out, const Matrix& a) {
	for (int i = 0; i < a.getSize(); i++) {
		for (int j = 0; j < a.getSize(); j++) {
			out << std::setw(5) << a(i, j);
		}
		out << std::endl;
	}
	out << std::endl << std::endl;
	return out;
}