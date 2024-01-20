#include <iostream>
#include <fstream>

using namespace std;

int main() {
    long n, m;
    int c2, c5;

    string filename = "data3.txt";
    ifstream fin{filename};

    if(!fin) return 1;

    fin >> n >> m >> c2 >> c5;

    cout << n << endl;
    cout << m << endl;
    cout << c2 << endl;
    cout << c5 << endl;
    
    double p2 = c2;
    double p5 = c5 / 4;

    if(n >= m) {
        cout << 0 << endl;
    } else {
        long d = m - n; 
        if(p2 <= p5) {
            cout << d * c2 << endl;
        } else {
            int r = d % 4;
            cout << d / 4 * c5 + (r * c2 > c5 ? c5 : r * c2) << endl;
        }
    }
    
}
