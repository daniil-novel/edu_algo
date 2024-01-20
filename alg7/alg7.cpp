#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const T& t : v) {
        os << t << endl;
    }

    return os << endl;
}


int main() {
    int t_string;

    string filename = "data.txt";
    ifstream fin{filename};
    
    fin >> t_string;
    
    vector<string> words;
    cout << t_string << endl;
    for(int i = 0; i < t_string; i++) {
        string word = "0";
        fin >> word;
        words.push_back(word);
    }
    cout << words;

    
}
