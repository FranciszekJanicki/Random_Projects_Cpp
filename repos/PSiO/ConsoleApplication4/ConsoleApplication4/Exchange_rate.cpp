#include "Exchange_rate.h"

void loadData(std::vector<Exchange_rate_struct> val) {
    std::fstream file("kursy_usd_eur.csv", std::fstream::in);

    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        
        while (std::getline(file, line)) {
            std::stringstream str(line);
            Exchange_rate_struct er;

            std::getline(str, er.date, ',');
            std::string double_str;
            std::getline(str, double_str, ',');
            er.usd = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.eur = std::stod(double_str);
            std::getline(str, er.table_id, ',');

            val.emplace_back(er);
        }
    }
}

void loadData(std::vector<Exchange_rate_class*>& val) {
    std::fstream file("kursy_usd_eur.csv", std::fstream::in);

    if (file.is_open()) {
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream str(line);
            Exchange_rate_class* er = new Exchange_rate_class;

            std::getline(str, er->date, ',');
            str >> er->usd;
            str.ignore();  // Ignore the comma
            str >> er->eur;
            str.ignore();  // Ignore the comma
            std::getline(str, er->table_id, ',');

            val.emplace_back(er);
        }
    }
}

void Exchange_rate_class::setDate(const std::string& _date) {
    this->date = _date;
}

void Exchange_rate_class::setUSD(const double& _usd) {
    this->usd = _usd;
}

void Exchange_rate_class::setTableId(const std::string& _ID) {
    this->table_id = _ID;
}

void Exchange_rate_class::setEUR(const double& _EUR) {
    this->eur = _EUR;
}

std::string Exchange_rate_class::getDate() const {
    return date;
}

std::string Exchange_rate_class::getTableID() const {
    return table_id;
}

bool is_palindrome(const std::string& word) {
    for (unsigned int i = 0; i < word.length() / 2; ++i) {
        if (word[i] != word[word.length() - 1 - i]) {
            return false;
        }
    }
    // returns true by default, but if there's an exception, returns false (in the loop), 
    // the loop breaks after return statement
    return true; 
}

bool is_palindrome2(const std::string& word) {
    bool isPalindrome = true;
    while (isPalindrome) {
        if (word[i] != word[word.length() - 1 - i]) {
            isPalindrome = false;
        }
    }
    return isPalindrome;
}

std::vector<size_t> find_all(const std::string& input, 
    const char& letter) {
    std::vector<size_t> vector;
    size_t position = 0;
    bool atEnd = false;

    while (!atEnd) {
        position = input.find(letter, position);
        if (position != std::string::npos) {
            vector.emplace_back(position);
            position++;
            atEnd = false;
        }
        else atEnd = true;
    }
    return vector;
}

std::string find_longest_word(const std::string& input) {
    size_t pos = 0, next_pos = 0;
    std::string longest, current, last;

    while (true) {
        next_pos = input.find(' ', pos);
        current = input.substr(pos, (next_pos != std::string::npos) 
            ? (next_pos - pos) : std::string::npos);
        if (current.length() > longest.length()) {
            longest = current;
        }
        if (next_pos != std::string::npos) {
            pos = next_pos + 1;
        } else  break;
    }
    return longest;
}

std::vector<std::string> split(const std::string& input, 
    const char& sep) {
    size_t pos = 0, next_pos = 0;
    std::string word;
    std::vector <std::string> words;

    while (true) {
        next_pos = input.find(sep, pos);
        word = input.substr(pos, (next_pos != std::string::npos)
            ? (next_pos - pos) : std::string::npos);

        if (next_pos != std::string::npos) {
            words.emplace_back(word);
            pos = next_pos + 1;
        }
        else  break;
    }
    return words;
}

std::string find_and_replace(const std::string& input,
    const std::string& old_, const std::string& new_) {
    size_t pos = 0, next_pos = 0;
    std::string sentence = input;

    while (true) {
        next_pos = sentence.find(old_, pos);
        if (next_pos != std::string::npos) {
            sentence.replace(next_pos, old_.length(), new_);
            pos = next_pos + new_.length();
        }
        else  break;
    }
    return sentence;
}