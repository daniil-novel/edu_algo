#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n_person {};

vector<char> language;
vector<int> hierarchy;
vector<int> barrier;

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto x : v) {
        os << x << " ";
    }

    return os << endl;
}   

void DFS(int depth = 0, int person = 0) {
    static int index = 0;

    //TODO
    cout << string(depth, '*') << person << endl;

    while(1) {
        int next_person = hierar
        if(person == next_person) {
            return;
        } else {
            DFS(depth + 1, next_person);
        }
    }
}

void printBarrier() {
    for(int i = 1; i < barrier.size(); i++) {
        cout << barrier[i] << " ";
    }
    cout << endl;
}

int getBarrier(vector<int>& person_stack, int depth) {
    if(!depth) return 0;

    int person = person_stack[depth];

    for(int barrier = 0; barrier < n_person; barrier++) {
        int up_person = person_stack[depth - barrier - 1];
        if(!language[up_person] || language[up_person] == language[person]) {
            return barrier;
        }
    }

    return -1;
}

void DFSNoRecursionStackSearch() {
    vector<int> person_stack(n_person + 1);

    int depth = 0;
    cout << depth << endl;

    for(int next_person : hierarchy) {
        if(person_stack[depth] == next_person) {
            if(depth) depth--;
        } else {
            person_stack[++depth] = next_person; 
            barrier[next_person] = getBarrier(person_stack, depth);

            cout << string(depth, '*') << next_person << endl;
        }
    }
}

void DFSPseudoRecursionStackSearch() {
    vector<int> person_stack(n_person + 1);

    int index = 0;

    int depth = 0;
    bool new_level = 1;
    while(depth >= 0) { 
        if(new_level) {
            int person = person_stack[depth];
            cout << string(depth, '*') << person << endl;
            barrier[person] = getBarrier(person_stack, depth);

            new_level = 0;
        }

        int next_person = hierarchy[++index];
        if(person_stack[depth] == next_person) {
            depth--;
        } else {
            person_stack[++depth] = next_person; 
            new_level = 1;
        }
    }
}

void init() {
    string filename = "data.txt";
    ifstream fin{filename};

    fin >> n_person;

    language.resize(n_person + 1);
    language[0] = 0;
    for (int i = 1; i <= n_person; i++) {
        fin >> language[i];
    }

    hierarchy.resize(2 * (n_person + 1));
    for (int i = 0; i < 2 * (n_person + 1); i++) {
        fin >> hierarchy[i];
    }

    barrier.resize(n_person + 1);

    fin.close();
}


int main() {
    init();
//    DFS();
//    DFSNoRecursionStackSearch();
    DFSPseudoRecursionStackSearch();

//    cout << barrier;

    printBarrier();
    return 0;
}
