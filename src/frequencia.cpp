#ifndef FREQUENCIA_HPP
#define FREQUENCIA_HPP

#include <unordered_set>
#include <unordered_map>

#include <istream>
#include <fstream>
#include <sstream>
#include <iostream>

#include <string>
#include <vector>

#include <cctype>
#include <algorithm>

#include <queue>

using namespace std;

// Estrutura para representar palavras e frequências.
struct WordFrequency {
    string word;
    int frequency;
};

// Função para comparar a frequência de duas estruturas WordFrequency.
struct CompareWordFrequency {
    bool operator()(const WordFrequency& wf1, const WordFrequency& wf2) const {
        return wf1.frequency > wf2.frequency;
    }
};

#endif
