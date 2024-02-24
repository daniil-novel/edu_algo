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

using person = int;

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto x : v) {
        os << x << " ";
    }

    return os << endl;
}   

int getBarrier(vector<int>& person_stack, int depth) {
    if(!depth) return 0;

    int person = person_stack[depth];

    for(int barrier = 0; barrier < n_person - 1; barrier++) {
        int up_person = person_stack[depth - barrier - 1];
        if(!language[up_person] || language[up_person] == language[person]) {
            return barrier;
        }
    }

    return -1;
}

int getBarrierRecursion(vector<int> &person_stack, int depth) {
    int current_person = person_stack[depth];
    char current_language = language[current_person];

    int barrier_count = 0;

    if (depth > 0) {
        for (int i = depth - 1; i >= 0; i--) {
            int up_person = person_stack[i];
            char up_language = language[up_person]; 

            if (up_language != current_language) {
                barrier_count++; 
            } else {
                break; 
            }
        }
    }

    return barrier_count; 
}

//typedef int person;

bool sameLanguage(person p1, person p2) {
    return language[p1] == language[p2] || !language[p1] || !language[p2];
}

void DFS(person current = 0, person parent = 0, int prev_chain = -1, int depth = 0) {
    static int person_index = 0;
    
    int chain = sameLanguage(current, parent) ? prev_chain + 1 : 1;
    barrier[current] = chain > 1 ? 0 : prev_chain;

//    cout << "chain = " << chain << endl;
//    cout << "barrier = " << barrier[current] << endl;
    cout << string(depth, '*') << current << endl;

    while(1) {
        person next = hierarchy[++person_index];
        if(current == next) {
            return;
        } else {
            DFS(next, current, chain, depth + 1);
        }
    }
}

void DFSStackSearch(vector<int> &person_stack, int depth = 0, int person = 0) {
    static int index = 0;

    barrier[person] = getBarrierRecursion(person_stack, depth);

    cout << string(depth, '*') << person << endl;

    while(1) {
        int next_person = hierarchy[++index];
        if(person == next_person) {
            return;
        } else {
            person_stack.push_back(next_person);
            DFSStackSearch(person_stack, depth + 1, next_person);
            person_stack.pop_back();
        }
    }
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

void DFSNoRecursionStackSearch() {
    vector<int> person_stack(n_person);

    int depth = 0;
    cout << depth << endl;

    for(int next_person : hierarchy) {
        if(person_stack[depth] == next_person) {
            // 0 == 0, 
            // 0 == 1
            if(depth) depth--; 
            
//            cout << "(person_stack[" << depth
//                 << "]) " << person_stack[depth]
//                 << " == " << next_person << " (next_person)" 
//                 << " | depth = " << depth
//                 << endl; 
        } else {
            person_stack[++depth] = next_person; 
            barrier[next_person] = getBarrier(person_stack, depth);
            
//            cout << "(person_stack[" << depth
//                << "]) " << person_stack[depth]
//                << " == " << next_person << " (next_person)"  
//                << " | depth = " << depth
//                << " | barrier √"
//                << endl; 


            cout << string(depth, '*') << next_person << endl;
        }
    }
}

void DFSPseudoRecursionStackSearch() {
    vector<int> person_stack(n_person);

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
//    DFS();
//    DFSNoRecursionStackSearch();
    DFSNoRecursion();
//    DFSPseudoRecursionStackSearch();

//    cout << barrier;

    printBarrier();
    return 0;
}
