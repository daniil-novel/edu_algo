#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

const string ifname{"data"};
const string ofname{"out-cpp"};
const string fext{".txt"};
const int fnum{6};

template<typename T, typename U>
ostream& operator<<(ostream& os, multimap<T, U>& m) {
    for(auto& x : m) {
        os << x.first << " " << x.second << endl;
    }
    return os;
}

int main() {
    int n_skulpt = 0;
    int x_ideal_ice = 0;
    long t_min = 0;

    multimap<int, int> m{};

    string ifilename = ifname + to_string(fnum) + fext;
    ifstream fin{ifilename};
    fin >> n_skulpt >> x_ideal_ice >> t_min;
    cout << n_skulpt << endl;

    int a = 0;
    for(int i = 1; i <= n_skulpt; i++) {
        fin >> a;
        m.insert({abs(a - x_ideal_ice), i});
    }
    
    string ofilename = ofname + to_string(fnum) + fext;
    ofstream fout{ofilename};

    int k = 0;
    for(const auto& p : m) {
        t_min -= p.first;
        if(t_min < 0) break;
        k++;
    }
    fout << k << endl;

    int i = 0;
    for(const auto& p : m) {
        fout << p.second << " ";
        i++;
        if(i == k) break;
    }

    fout << "\n";

    fin.close();
    fout.close();
}
