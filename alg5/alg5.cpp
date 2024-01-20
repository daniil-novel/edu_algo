#include <iostream>
#include <fstream>

using namespace std;

struct PriorityList {
    int r_pos;
    int s_want_prog;
    int *prog_num;
};

int main() {
    int n_stud, k_prog;
    int *place_i = new int[k_prog]{};
    
    string filename = "data.txt";
    ifstream fin{filename};

    fin >> n_stud >> k_prog;
//    cout << n_stud << " " << k_prog << endl;
    for(int i = 1; i <= k_prog; i++) {
        fin >> place_i[i];
//        cout << place_i[i] << " ";
    }
    PriorityList* pl = new PriorityList[n_stud]{};
    for(int n = 1; n <= n_stud; n++) {
        fin >> pl[n].r_pos;
        fin >> pl[n].s_want_prog;
        cout << pl[n].r_pos << " ";
        cout << pl[n].s_want_prog << " ";
        pl[n].prog_num = new int[pl[n].s_want_prog];
        for(int s = 1; s <= pl[n].s_want_prog; s++) { 
            fin >> pl[n].prog_num[s];
            cout << pl[n].prog_num[s] << " ";
        }
        cout << endl;
    }


    /*освобождение памяти*/
    for (int n = 0; n <= n_stud; n++) {
        delete[] pl[n].prog_num;
    }

    delete[] pl;
    delete[] place_i;

    return 0;
}
