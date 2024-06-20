#include "Histogram.h"

Histogram::Histogram(const std::vector<int>& data) {
    emplace(data);
}

void Histogram::emplace(const int& val) {
    bins_[val]++;
}

void Histogram::emplace(const std::vector<int>& data) {
    for (const auto& val : data) {
        bins_[val]++;
    }
}

void Histogram::clear() {
    bins_.clear();
}

bool Histogram::from_csv(const std::string& filename, char sep, int column_idx) {
    std::ifstream file(filename);
    std::string input;
    
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::stringstream str(line);
            for (int i = 0; i < column_idx; ++i)
                std::getline(str, input, sep);
            this->emplace(std::stoi(input));
        }
        return true;
    }
    return false;
}

std::pair<int, int> Histogram::max() const {
    auto it = std::max_element(bins_.begin(), bins_.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
    return { it->first, it->second };
}

std::pair<int, int> Histogram::range() const {
    auto it = std::minmax_element(bins_.begin(), bins_.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
    return { it.first->first, it.second->first };
}

std::vector<int> Histogram::unique_bins() const {
    std::vector<int> uniqueBins;
    for (const auto& b : bins_) {
        uniqueBins.emplace_back(b.first);
    }
    std::sort(uniqueBins.begin(), uniqueBins.end());
    return uniqueBins;
}

Histogram::BinsVector Histogram::unique_items() const {
    BinsVector uniqueItems;
    for (const auto& b : bins_) {
        uniqueItems.emplace_back(b);
    }
    return uniqueItems;
}

Histogram& Histogram::operator<<(const int& val) {
    emplace(val);
    return *this;
}

Histogram Histogram::generate(int min, int max, int count) {
    Histogram hist;
    for (int i = 0; i < count; ++i) {
        int randomValue = rand() % (max - min + 1) + min;
        hist.emplace(randomValue);
    }
    return hist;
}

Histogram Histogram::generate(int count, int (*func_ptr)) {
    Histogram hist;
    for (int i = 0; i < count; ++i) {
        hist.emplace(*func_ptr);
    }
    return hist;
}

int Histogram::operator[](const int& v) const {
    auto it = bins_.find(v);
    if (it != bins_.end())
        return it->second;
    else
        return 0; // Return 0 if the value is not found in any bin
}

Histogram::operator BinsVector() const {
    BinsVector binsVector;
    for (const auto& b : bins_) {
        binsVector.emplace_back(b);
    }
    return binsVector;
}

std::istream& operator>>(std::istream& str, Histogram& hist) {
    int n = 0;
    std::string myString;
    while (n < 0) {
        std::cout << "How many grades would you like to enter: \n";
        str >> n;
    }
    for (unsigned int i = 0; i < n; ++i) {
        str >> myString;
        hist.emplace(stoi(myString));
    }
    return str;
}

std::ostream& operator<<(std::ostream& str, const Histogram& hist) {
    for (const auto& bin : hist.bins_)
        str << "[" << bin.first << "]: " << bin.second << "\n";
    return str;
}

void print(const std::vector<std::pair<int, int>> values) {
    for (const auto& v : values) {
        std::cout << "[" << v.first << "] = " << v.second << '\n';
    }
}

float sum(float a, float b) {
    return a + b;
}

float mul(float a, float b) {
    return a * b;
}

