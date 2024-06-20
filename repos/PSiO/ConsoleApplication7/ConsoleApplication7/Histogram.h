#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>


class Histogram {
    std::map<int, int> bins_;
    using BinsVector = std::vector<std::pair<int, int>>;
public:
    Histogram(const std::vector<int>& data = std::vector<int>());
    void emplace(const int& val);
    void emplace(const std::vector<int>& data);
    void clear();
    bool from_csv(const std::string& filename, char sep = ',', int column_idx = 4);
    std::pair<int, int> max() const;
    std::pair<int, int> range() const;
    std::vector<int> unique_bins() const;
    BinsVector unique_items() const;
    Histogram& operator<<(const int& v);
    static Histogram generate(int min, int max, int count);
    static Histogram generate(int count, int (*func_ptr));
    int operator[](const int& v) const;
    operator BinsVector() const;

    friend std::istream& operator>>(std::istream& str, Histogram& hist);
    friend std::ostream& operator<<(std::ostream& str, const Histogram& hist);
};

void print(const std::vector<std::pair<int, int>> values);

float sum(float a, float b);

float mul(float a, float b);

template <typename T>
std::vector <std::vector <T>> createMatrix(int m, int n) {
    std::vector <std::vector <T>> matrix(m);
    for (auto& m : matrix) {
        m = std::vector<T> (n);
    }
    return matrix;
}

template <typename T>
std::vector<std::vector<T>> copy(const std::vector<std::vector<T>>& matrix) {
    unsigned int m = matrix.size();
    unsigned int n = matrix[0].size();
    auto matrixCopy = createMatrix<T>(m, n);

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            matrixCopy[i][j] = matrix[i][j];
        }
    }
    return matrixCopy;
}