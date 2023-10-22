#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

template<typename T, typename U>
ostream& operator<<(ostream& os, unordered_map<T, U>& m) {
    for(auto& x : m) {
    os << x.first << " " << x.second << endl;
    }
    return os;
}

template<typename T, int w = 12>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto& t : v) { 
        os << t << " ";
    }
    return os << endl;
}


int main () {
    int n_button = 0;

    unordered_map<int, int> um{};

    string filename = "alg2-data.txt";
    ifstream fin{filename};

    
    fin >> n_button;
    cout << "n_button = " << n_button << endl;

    int char_id[n_button];
    int row_number;

    for(int i = 0; i < n_button; i++) {
        fin >> char_id[i];
    } 

    for(int i = 0; i < n_button; i++) {
        fin >> row_number;
        um.insert({char_id[i], row_number});
    }
    
    /*
     * Варианты заполнения unordered_multimap с файла
    // Неудачное решение, ибо значения считываются по очереди
    while(fin >> char_id >> row_number) {
    um.insert({char_id, row_number});
    cout << "char_id =  " << char_id << endl;
    cout << "row_number = " << row_number << endl;
    }
    */

    /*

    // Вариант для отслеживания вывода (максимально подробно) 

    for(int i = 0; i < n_button; i++) {
    fin >> char_id[i];
    cout << "char_id[" << i << "]=  " << char_id[i] << endl;
    } 
    for(int i = 0; i < n_button; i++) {
    fin >> row_number[i];
    cout << "row_number[" << i << "]=  "<< row_number[i] << endl;
    }
    for(int i = 0; i < n_button; i++) {
    cout << "char_id[" << i << "]=  " << char_id[i];
    cout << " row_number[" << i << "]=  " << row_number[i];
    cout << endl;
    um.insert({char_id[i], row_number[i]});
    cout << um;
    }
    */

    /*
       for(int i = 0; i < n_button; i++) {
       fin >> char_id[i];
       cout << "char_id[" << i << "]=  " << char_id[i];

    //        fin >> ws; // Думал, что она переведет курсор на новую строку

    fin >> row_number[i];
    cout << " row_number[" << i << "]=  " << row_number[i];

    cout << endl;
    um.insert({char_id[i], row_number[i]});
    //        cout << um;
    }
    */


//    cout << um << endl;

    int k_char = 0;
    fin >> k_char;
//    cout << k_char << endl;

    vector<int> row_number_array{};
    int current_char = 0;
    int count_transitions = 0;
    for(int k = 0; k < k_char; k++) {
        fin >> current_char;
//        auto itr = um.find(current_char);
//        cout << current_char << " -> " << itr->second << endl;
        row_number_array.push_back(um[current_char]);
//        cout << row_number_array;
        if(k > 0 && row_number_array.at(k - 1) != row_number_array[k]) {
            count_transitions++;
        }
    }
    cout << count_transitions;
}
