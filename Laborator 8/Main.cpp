#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

struct ComparareCuvinte {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first; 
    }
};

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Nu am putut deschide fisierul!";
        return 1;
    }

    std::string text, linie;
    while (std::getline(file, linie)) {
        text += linie + " ";
    }

    std::map<std::string, int> frecventa;
    std::string separatori = " ,?!.";
    size_t start = 0, end;

    while ((end = text.find_first_of(separatori, start)) != std::string::npos) {
        if (end > start) {
            std::string cuvant = text.substr(start, end - start);
            
            for (auto &c : cuvant) c = tolower(c);
            
            frecventa[cuvant]++;
        }
        start = end + 1;
    }
    if (start < text.length()) {
        std::string cuvant = text.substr(start);
        if(!cuvant.empty()) {
             for (auto &c : cuvant) c = tolower(c);
             frecventa[cuvant]++;
        }
    }

    std::priority_queue<std::pair<std::string, int>, 
                        std::vector<std::pair<std::string, int>>, 
                        ComparareCuvinte> pq;

    for (auto const& [cuvant, count] : frecventa) {
        pq.push({cuvant, count});
    }

    while (!pq.empty()) {
        std::pair<std::string, int> top = pq.top();
        std::cout << top.first << " => " << top.second << std::endl;
        pq.pop();
    }

    return 0;
}
