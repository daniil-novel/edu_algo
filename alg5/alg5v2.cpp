#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct PriorityList {
    int r_pos;
    int s_want_prog;
    vector<int> prog_num;

    PriorityList() : r_pos(0), s_want_prog(0) {}
};

int main() {
    unsigned int n_stud;
    int k_prog;
    vector<int> place_i {k_prog};
    
    string filename = "data.txt";
    ifstream fin{filename};

    fin >> n_stud >> k_prog;

    cout << n_stud << " " << k_prog << endl;
    for(int i = 0; i < k_prog; i++) {
        fin >> place_i[i];
        cout << place_i[i] << " ";
    }
    cout << endl;

    vector<PriorityList> pl{n_stud};

    for(int n = 0; n < n_stud; n++) {
        fin >> pl[n].r_pos;
        fin >> pl[n].s_want_prog;

        cout << pl[n].r_pos << " ";
        cout << pl[n].s_want_prog << " ";
        
        pl[n].prog_num.resize(pl[n].s_want_prog);

        for(int s = 0; s < pl[n].s_want_prog; s++) { 
            fin >> pl[n].prog_num[s];
            cout << pl[n].prog_num[s] << " ";
        }

        cout << endl;
    }

    return 0;
}
