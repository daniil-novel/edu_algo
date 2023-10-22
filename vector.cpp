#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto& x : v) {
        os << x << endl; 
    }

    return os;
}

int main() {
    vector<int> v(10);
    cout << v;
}
