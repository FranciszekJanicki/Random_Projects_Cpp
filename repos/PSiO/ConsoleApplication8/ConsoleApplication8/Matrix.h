#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <fstream>
#include <functional>

template <typename T>
class Matrix {
	using matrix = std::vector<std::vector<T>>;
	matrix matrix_;
	unsigned int m_ = 0, n_ = 0;
public:
	Matrix();
	Matrix(unsigned int, unsigned int);
	Matrix(matrix matrix);
	static Matrix getEye(unsigned int m, unsigned int n);
	static Matrix fill(unsigned int m, unsigned int n, std::function<int()> func_ptr);
	Matrix operator+(const Matrix<T>& rhs);
	Matrix operator-(const Matrix<T>& rhs);
	Matrix operator*(const T& rhs);
	std::vector<T> operator*(const Matrix<T>& rhs);
	bool operator[](const Matrix<T>& rhs);
	void print() const;
	void clear();

	template <typename U>
	friend std::ostream& operator<<(std::ostream& str, const Matrix<U>& matrix);
	template <typename U>
	friend std::istream& operator>>(std::istream& str, Matrix<U>& matrix);
};

template<typename T>
Matrix<T> operator*(const T& lhs, Matrix<T>& rhs) {
	for (unsigned int j = 0; j < rhs.matrix_.size(); ++j) {
		for (unsigned int i = 0; i < rhs.matrix_[j].size(); ++i) {
			rhs.matrix_[j][i] *= lhs;
		}
	}
	return *rhs;
}

template<typename T>
inline Matrix<T>::Matrix() : Matrix<T>(0, 0) {
}

template<typename T>
inline Matrix<T>::Matrix(unsigned int m , unsigned int n) : m_(m), n_(n) {
	matrix_.resize(m, std::vector<T>(n));
}

template<typename T>
inline Matrix<T>::Matrix(matrix matrix) : matrix_(matrix){
}

template<typename T>
inline Matrix<T> Matrix<T>::getEye(unsigned int m, unsigned int n) {
	Matrix<T> eyeMatrix(m, n);
	for (unsigned int j = 0; j < n; ++j) {
		for (unsigned int i = 0; i < m; ++i) {
			eyeMatrix.matrix_[j][i] = 1;
		}
	}
	return eyeMatrix;
}

template <typename T>
inline Matrix<T> Matrix<T>::fill(unsigned int n, unsigned int m, std::function<int()> func_ptr) {
	Matrix myMatrix(m, n);
	for (unsigned int j = 0; j < myMatrix.matrix_.size(); ++j) {
		for (unsigned int i = 0; i < myMatrix.matrix_[j].size(); ++i) {
			myMatrix.matrix_[j][i] = func_ptr();
		}
	}
	return myMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
	for (unsigned int j = 0; j < this->matrix_.size(); ++j) {
		for (unsigned int i = 0; i < this->matrix_[j].size(); ++i) {
			this->matrix_[j][i] += rhs.matrix_[j][i];
		}
	}
	return *this;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) {
	for (unsigned int j = 0; j < this->matrix_.size(); ++j) {
		for (unsigned int i = 0; i < this->matrix_[j].size(); ++i) {
			this->matrix_[j][i] -= rhs.matrix_[j][i];
		}
	}
	return *this;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator*(const T& rhs) {
	for (unsigned int j = 0; j < this->matrix_.size(); ++j) {
		for (unsigned int i = 0; i < this->matrix_[j].size(); ++i) {
			this->matrix_[j][i] *= rhs;
		}
	}
	return *this;
}

template<typename T>
inline std::vector<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
	std::vector<T> result(this->matrix_.size(), T());

	for (size_t i = 0; i < this->matrix_.size(); ++i) {
		for (size_t j = 0; j < rhs.matrix_[0].size(); ++j) {
			for (size_t k = 0; k < this->matrix_[0].size(); ++k) {
				result[i] += this->matrix_[i][k] * rhs.matrix_[k][j];
			}
		}
	}
	return result;
}

template <typename T>
inline bool Matrix<T>::operator[](const Matrix<T>& rhs) {
	if (this->matrix_.size() != rhs.matrix_.size()) {
		throw std::out_of_range("element does not exist");
		return false;
	}
	else
		return true;
}

template<typename T>
inline void Matrix<T>::print() const {
	for (unsigned int j = 0; j < this->matrix_.size(); ++j) {
		for (unsigned int i = 0; i < this->matrix_[j].size(); ++i) {
			std::cout << i;
		}
		std::cout << '\n';
	}
}

template<typename T>
inline void Matrix<T>::clear() {
	this->matrix_.clear();
}
