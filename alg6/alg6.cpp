#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Curb {
    int take_day = 0;
    int put_day = 0;
    int id = 0;
    int sad = 0;

    friend ostream& operator<<(ostream& os, const Curb& crb) {
        os << crb.take_day << " " << crb.put_day << " " << crb.sad << " | " << crb.id;
        return os << endl;
    }
};

//struct PutCurb {
//    int m_put_delta;
//    vector<Curb*> curb_list;
//};

ostream& operator<<(ostream& os, const vector<Curb>& v) {
    for(const Curb& crb : v) {
        os << crb;
    }

    return os;
}

bool cmp(const Curb a, const Curb b) {
    return a.id < b.id;
}

void init(vector<Curb>& curb_list, vector<Curb>& sorted_curb_list, int& m_delta, int& n_take) {
    unsigned int k_curb;
    int m_put;

    string filename = "datav2.txt";
    ifstream fin{filename};

    fin >> k_curb >> n_take >> m_put;
    cout << k_curb << " " << n_take << " " << m_put << endl;

    m_delta = m_put;

    for(int i = 0; i < n_take; i++) {
        Curb curb;
        fin >> curb.take_day;
        fin >> curb.id;
        curb_list.push_back(curb);
        sorted_curb_list.push_back(curb);

//        cout << curb.take_day << " " << curb.id << endl;
    }

//    cout << endl;

    sort(sorted_curb_list.begin(), sorted_curb_list.end(), cmp);

//    cout << "sorted_curb_list  = " << endl;
//    cout << sorted_curb_list;
}

int main() {
    vector<Curb> curb_list;
    vector<Curb> sorted_curb_list;
    int m_delta;
    int n_take;

    init(curb_list, sorted_curb_list, m_delta, n_take);

    int summ_sad = 0;
    int id = 0;
    for(int i = 0; i < n_take; i++) {
        auto scl = sorted_curb_list[i];
        if(scl.id != id) {
            id = scl.id;
            scl.put_day = scl.take_day;
        } else {
            scl.put_day = sorted_curb_list[i - 1].take_day;
        }
        scl.sad = scl.take_day - scl.put_day;
        summ_sad += scl.sad;
        if(m_delta > 0) m_delta--;
        cout << scl;
    }

    cout << "ответ " << summ_sad;

}
