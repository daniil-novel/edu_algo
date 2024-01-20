#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

struct Dig {
    int day;
    int walk_id;

    friend ostream& operator<<(ostream& os, const Dig& dig) {
        os << dig.day << " " << dig.walk_id;
        return os;
    }
};

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const T& t : v) {
        os << t << endl;
    }

    return os << endl;
}


bool cmp(const Dig a, const Dig b) {
    return a.walk_id < b.walk_id;
}

void init(vector<Dig>& dig_list, int& m_count) {
    int k_walk;
    int n_dig;
    int m_repair;

    string filename = "datav3.txt";
    ifstream fin{filename};

    fin >> k_walk >> n_dig >> m_repair;
    cout << k_walk << " " << n_dig << " " << m_repair << endl;

    m_count = m_repair;

    for(int i = 0; i < n_dig; i++) {
        Dig dig;
        fin >> dig.day;
        fin >> dig.walk_id;
        dig_list.push_back(dig);
    }

    sort(dig_list.begin(), dig_list.end(), cmp);

    cout << "dig_list:" << endl;
    cout << dig_list;
}

int main() {
    vector<Dig> dig_list;
    vector<int> sad_list;
    int m_count;

    init(dig_list, m_count);

    Dig pdig {};
    for(const auto& dig : dig_list) {
        if(dig.walk_id == pdig.walk_id) {
            sad_list.push_back(dig.day - pdig.day);
        } else {
            sad_list.push_back(INF);
        }
        
        pdig = dig;
    }

    sort(sad_list.begin(), sad_list.end(), greater<int>{});
    
    int sum_sad = 0;
    for(auto sad : sad_list) {
        if(m_count) {
            m_count--;
        } 
        else if(sad == INF) {
            sum_sad = -1;
            break;
        } 
        else {
            sum_sad += sad;
        }
    }
    
    cout << sum_sad;
}
