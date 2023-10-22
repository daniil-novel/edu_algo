#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const string ifname{"data"};
const string ofname{"out-cpp"};
const string fext{".txt"};
const int fnum{6};

template<typename T, typename U>
ostream& operator<<(ostream& os, vector<pair<T, U>>& v) {
    for(auto& x : v) {
        os << x.first << " " << x.second << endl; 
    }

    return os;
}

int main() { 
    int n_skulpt = 0;
    int x_ideal_ice = 0;
    long t_min = 0;

    vector<pair<int, int>> v;

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
        t_min -= v[k].first;
        if(t_min < 0) break;
    }
    fout << k << endl;

    for(int i = 0; i < k; i++) {
        fout << v[i].second << " ";
    }
    
    fout << "\n";

    fin.close();
    fout.close();
    
    return 0;
}
