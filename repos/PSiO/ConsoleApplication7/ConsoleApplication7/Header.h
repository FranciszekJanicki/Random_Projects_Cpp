#pragma once
#include "Histogram.h"

template <typename T>
std::vector <std::vector <T>> createMatrix(int m, int n) {
    std::vector <std::vector <T>> matrix(m);
    for (unsigned int i = 0; i < m; ++i) {
        m = std::vector<T>(n);
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

template <typename T>
Histogram<T>::Histogram(const std::vector<T>& data) {
    emplace(data);
}
template <typename T>
void Histogram<T>::emplace(const T& val) {
    bins_[val]++;
}
template <typename T>
void Histogram<T>::emplace(const std::vector<T>& data) {
    for (const auto& val : data) {
        bins_[val]++;
    }
}
template <typename T>
std::pair<T, int> Histogram<T>::max() const {
    auto it = std::max_element(bins_.begin(), bins_.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
    return { it->first, it->second };
}
template <typename T>
std::pair<T, T> Histogram<T>::range() const {
    auto it = std::minmax_element(bins_.begin(), bins_.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
    return { it.first->first, it.second->first };
}
template <typename T>
std::vector<T> Histogram<T>::unique_bins() const {
    std::vector<T> uniqueBins;
    for (const auto& b : bins_) {
        uniqueBins.emplace_back(b.first);
    }
    std::sort(uniqueBins.begin(), uniqueBins.end());
    return uniqueBins;
}
template <typename T>
Histogram<T>::BinsVector Histogram<T>::unique_items() const {
    BinsVector uniqueItems;
    for (const auto& b : bins_) {
        uniqueItems.emplace_back(b);
    }
    return uniqueItems;
}