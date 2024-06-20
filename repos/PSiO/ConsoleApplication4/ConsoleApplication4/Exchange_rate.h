#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

struct Exchange_rate_struct {
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

void loadData(std::vector<Exchange_rate_struct> val);

class Exchange_rate_class {
    std::string date;
    double usd;
    double eur;
    std::string table_id;
public:
    void setDate(const std::string& _date);
    void setUSD(const double& _usd);
    void setTableId(const std::string& _ID);
    void setEUR(const double& _EUR);
    std::string getDate() const;
    std::string getTableID() const;
    friend void loadData(std::vector<Exchange_rate_class*>& val);
};

bool is_palindrome(const std::string& word);

std::vector<size_t> find_all(const std::string& input, 
    const char& letter);

std::string find_longest_word(const std::string& input);

std::vector<std::string> split(const std::string& input, 
    const char& sep = ' '); // default argument in .h file, when not given it will be default which is used

std::string find_and_replace(const std::string& input,
    const std::string& old_, const std::string& new_);