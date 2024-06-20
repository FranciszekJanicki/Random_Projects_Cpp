#include "Matrix.h"

template <typename U>
std::ostream& operator<<(std::ostream& str, const Matrix<U>& matrix) {
	for (unsigned int j = 0; j < matrix.matrix_.size(); ++j) {
		for (unsigned int i = 0; i < matrix.matrix_[j].size(); ++i) {
			str << matrix.matrix_[j][i] << " ";
		}
		str << '\n';
	}
	return str;
}

template <typename U>
std::istream& operator>>(std::istream& str, Matrix<U>& matrix) {
	unsigned int rows = 0, columns = 0;

	std::string input;
	while ((rows && columns) > 0) {
		std::cout << "How many rows: ";
		str >> rows;
		std::cout << "How many columns: ";
		str >> columns;
	}
	matrix.clear();
	matrix.matrix_.resize(rows, std::vector<U>(columns));

	for (auto& rows : matrix.matrix_.size()) {
		for (auto& columns : matrix.matrix_[0].size()) {
			str >> input;
			columns = static_cast<U>(stoi(input));
		}
	}
	return str;
}

