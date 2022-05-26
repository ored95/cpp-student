#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
// g++ test.cpp -std=c++20

/**
 * @brief Get all words from file
 * 
 * @param fileName - input
 * @return vector<string> - list of extracted words
 */
vector<string> get_words(const char *fileName) {
    ifstream fin(fileName);
    vector<string> wordList;
    if (fin.is_open()) {
        char c = 0;
        while (fin.get(c)) {
            string word;
            while (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
                if ('A' <= c && c <= 'Z')
                    c = c - 'A' + 'a';
                word.push_back(c); 
                fin.get(c);
            }
            if (word.size() > 0) {
                wordList.push_back(word);
            }
        }
    }
    fin.close();
    return wordList;
}

/**
 * @brief Find word frequency from a list
 * 
 * @param wordList - list of words
 * @return map<string, int> - words with it frequency
 */
map<string, int> words_count(vector<string> wordList) {
    map<string, int> dict;
    for (string word: wordList) {
        if (dict.size() == 0) {
            dict.insert({word, 1});
        }
        else {               
            if (dict.contains(word)) {
                dict[word]++;
            } else {
                dict.insert({word, 1});
            }
        }
    }
    return dict;
}

/**
 * @brief output word frequency to file
 * 
 * @param dict - words with it frequency
 * @param fileName 
 */
void word_count_to_file(map<string, int> dict, const char *fileName) {
    ofstream fout(fileName);
    for (const auto& [word, n]: dict) {
        if (n > 1) {
            fout << word << " [" <<  n << "]" << endl;
        }
    }
    fout.close();
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        cout << "Command instruction: <program> <input-fileName> <output-fileName>" << endl;
        return -1;
    }

    vector<string> wordList = get_words(argv[1]);
    map<string, int> dict = words_count(wordList);
    word_count_to_file(dict, argv[2]);
    return 0;
}