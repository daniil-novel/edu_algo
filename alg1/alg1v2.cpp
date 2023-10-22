#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const string ifname{"data"};
const string ofname{"out-cpp"};
const string fext{".txt"};
const int fnum{6};

struct Pair {
    int value;
    int index;
    bool operator<(const Pair& p) {
        return value < p.value;
    }
};

ostream& operator<<(ostream& os, vector<Pair>& v) {
    for(auto& x : v) {
        os << x.value << " " << x.index << endl; 
    }

    return os;
}

int main() { 
    int n_skulpt = 0;
    int x_ideal_ice = 0;
    long t_min = 0;

    vector<Pair> v;

    string ifilename = ifname + to_string(fnum) + fext;
    ifstream fin{ifilename};
    fin >> n_skulpt >> x_ideal_ice >> t_min;
    cout << n_skulpt << endl;

    int a = 0;

    // while(fin >> a) {}
    
    for(int i = 1; i <= n_skulpt; i++) {
        fin >> a;
        v.push_back({abs(a - x_ideal_ice), i});
    }

    //cout << v;

    sort(v.begin(), v.end());

    //cout << v;

    string ofilename = ofname + to_string(fnum) + fext;
    ofstream fout{ofilename};
    int k;
    for(k = 0; k < n_skulpt; k++) {
        t_min -= v[k].value;
        if(t_min < 0) break;
    }
    fout << k << endl;

    for(int i = 0; i < k; i++) {
        fout << v[i].index << " ";
    }
    
    fout << "\n";

    fin.close();
    fout.close();
    
    return 0;
}
