#include "frequencia.hpp"

using namespace std;

int main() {
    // Defina o nome dos arquivos de stopwords.
    string stopwordsFile = "src/dataset/stopword.txt";

    // Leia as stopwords do arquivo.
    unordered_set<string> stopwords = readStopwords(stopwordsFile);

    // Defina os nomes dos arquivos de entrada.
    string inputFile1 = "src/dataset/input/input0.txt";
    string inputFile2 = "src/dataset/input/input1.txt";

    // Abra os arquivos de entrada.
    ifstream input0(inputFile1);
    ifstream input1(inputFile2);

    if (!input0 || !input1) {
        cerr << "Erro ao abrir um ou ambos os arquivos de entrada." << endl;
        return 1;
    }

    // Processar o texto dos dois arquivos e calcular a frequência das palavras.
    unordered_map<string, int> frequencyMap1 = processText(input0, stopwords);
    unordered_map<string, int> frequencyMap2 = processText(input1, stopwords);

    // Combine as frequências dos dois arquivos.
    for (const auto& pair : frequencyMap2) {
        frequencyMap1[pair.first] += pair.second;
    }

    // Defina o valor de k para os principais k elementos.
    int k = 20;

    // Encontre os k elementos de maior frequência.
    vector<WordFrequency> topK = findTopK(frequencyMap1, k);

    // Exiba os resultados.
    cout << "============================" << endl;
    cout << "palavras\tfrequencia" << endl;
    cout << "============================" << endl;

    for (const WordFrequency& wf : topK) {
        cout << wf.word << "\t\t" << wf.frequency << endl;
    }

    cout << "============================" << endl;


    return 0;
}
