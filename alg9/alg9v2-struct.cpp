#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n_person {};

vector<char> language;
vector<int> hierarchy;
vector<int> barrier;

using person = int;

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto x : v) {
        os << x << " ";
    }

    return os << endl;
}   

void DFSNoRecursion() {
    vector<person> person_stack(n_person);
    vector<int> chain_stack(n_person);

    int depth = 0;
    cout << depth << endl;

    for(person next : hierarchy) {
        if(person_stack[depth] == next) {
            if(depth) depth--; 
        } else {
            person current = person_stack[depth];
            int current_chain = chain_stack[depth];

            depth++;
            person_stack[depth] = next; 

            int next_chain = sameLanguage(current, next) ? current_chain + 1 : 1;
            chain_stack[depth] = next_chain;
            barrier[next] = next_chain > 1 ? 0 : current_chain;
            
            cout << string(depth, '*') << next << endl;
        }
    }
}

void printBarrier() {
    for(int i = 1; i < barrier.size(); i++) {
        cout << barrier[i] << " ";
    }
    cout << endl;
}

void init() {
    string filename = "data.txt";
    ifstream fin{filename};

    int n_employee;
    fin >> n_employee;

    n_person = n_employee + 1;

    language.resize(n_person);
    language[0] = 0;
    for (int i = 1; i < n_person; i++) {
        fin >> language[i];
    }

    hierarchy.resize(2 * n_person);
    for (int i = 0; i < 2 * n_person; i++) {
        fin >> hierarchy[i];
    }

    barrier.resize(n_person);

    fin.close();
}


int main() {
    init();
    DFSNoRecursion();

    printBarrier();
    return 0;
}
