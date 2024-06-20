#include "Exchange_rate.h"

int main() {


    std::vector<Exchange_rate_struct> rates1;
    loadData(rates1);

    std::vector<Exchange_rate_class*> rates2;
    loadData(rates2);
    
    std::string word = "racecar";
    if (is_palindrome(word)) {
        std::cout << "Palindrome!" << std::endl;
    }
    else {
        std::cout << "Nope" << std::endl;
    }

    std::string input = "Ala ma kota";
    std::vector<size_t> pos = find_all(input, 'a'); // wynik: {2, 5, 10}
    for (auto& p : pos) {
        std::cout << p << '\n';
    }

    std::string input1 = "Ala ma kota kot jezdzi na Roombie";
    std::string longest = find_longest_word(input1); // "Roombie"
    std::cout << longest << '\n';

    std::string sentence = "Ala ma kota";
    std::vector<std::string> words = split(sentence); // wynik: {"Ala", "ma", "kota"}
    for (auto& w : words) {
        std::cout << w << '\n';
    }
    std::string csv = "Mount Everest,8848,1953";
    std::vector<std::string> data = split(csv, ','); // wynik: {"Mount Everest", "8848", "1953"}
    for (auto& w : data) {
        std::cout << w << '\n';
    }
    std::string input3 = "Ala ma kota, kot zjadl Ale!";
    std::string output = find_and_replace(input3, "kot", "hefalump");
    // wynik: "Ala ma hefalumpa, hefalump zjadl Ale!"
    std::cout << output << '\n';

    return 0;
}
