#include "frequencia.cpp"

unordered_set<string> readStopwords(const string& filename) {
    unordered_set<string> stopwords;
    ifstream file(filename);

    if (!file) {
        cerr << "Erro ao abrir o arquivo de stopwords." << endl;
        exit(1);
    }

    string word;
    while (file >> word) {
        stopwords.insert(word);
    }

    return stopwords;
}

unordered_map<string, int> processText(istream& inputStream, const unordered_set<string>& stopwords) {
    unordered_map<string, int> frequencyMap;
    string line;

    while (getline(inputStream, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            while (!word.empty() && ispunct(word.front())) {
                word.erase(0, 1);
            }
            while (!word.empty() && ispunct(word.back())) {
                word.pop_back();
            }

            if (stopwords.find(word) == stopwords.end() && !word.empty() && any_of(word.begin(), word.end(), ::isalpha)) {
                frequencyMap[word]++;
            }
        }
    }

    return frequencyMap;
}

// Função para encontrar os k elementos de maior frequência.
vector<WordFrequency> findTopK(const unordered_map<string, int>& frequencyMap, int k) {
    priority_queue<WordFrequency, vector<WordFrequency>, CompareWordFrequency> minHeap;

    for (const auto& pair : frequencyMap) {
        minHeap.push({pair.first, pair.second});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<WordFrequency> topK;
    while (!minHeap.empty()) {
        topK.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(topK.begin(), topK.end());
    return topK;
}
