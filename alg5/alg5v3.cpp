#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Program {
    int id;
    int place_num;
};

struct Student {
    int id;
    int rank;
    vector<Program*> desired_prog_list;
    Program *admitted_prog; 

    friend ostream& operator<<(ostream& os, const Student& stud) {
        os << stud.id << " | " << stud.rank << " " << stud.desired_prog_list.size() << " ";
        for(Program *prog : stud.desired_prog_list) {
            os << prog->id << " ";
        }

        return os << endl;
    }
};

ostream& operator<<(ostream& os, const vector<Student>& v) {
    for(const Student& stud : v) {
        os << stud;
    }

    return os;
}

ostream& operator<<(ostream& os, const vector<Student*>& v) {
    for(auto stud : v) {
        os << *stud;
    }

    return os;
}


bool cmp(const Student *a, const Student *b) {
    return a->rank < b->rank;
}

void init(vector<Program>& prog_list, vector<Student>& student_list, vector<Student*>& sorted_student_list) {
    string filename = "data.txt";
    ifstream fin{filename};

    unsigned int n, k;

    fin >> n >> k;
    cout << n << " " << k << endl;
    
    Program prog_empty;
    prog_empty.id = -1;

    prog_list.push_back(prog_empty);
    for(int i = 1; i <= k; i++) {
        Program prog;
        prog.id = i;
        fin >> prog.place_num;
        prog_list.push_back(prog);
    }

    for(int i = 0; i < n; i++) {
        student_list.push_back({});
        Student& stud = student_list.back();

        stud.id = i;

        fin >> stud.rank;

        int s, prog_id;
        fin >> s;
        for(int i = 0; i < s; i++) { 
            fin >> prog_id;
            stud.desired_prog_list.push_back(&prog_list[prog_id]);
        }

        stud.admitted_prog = &prog_list.front();
    }

    for(auto& stud : student_list) {
        auto& lst = sorted_student_list;
        lst.push_back(nullptr);
        lst.back() = &stud; 
    }

    sort(sorted_student_list.begin(), sorted_student_list.end(), cmp);
}

int main() {
    vector<Program> prog_list;
    vector<Student> student_list;
    vector<Student*> sorted_student_list;

    init(prog_list, student_list, sorted_student_list);
    cout << student_list << endl;
    cout << sorted_student_list << endl;

    for(auto *stud : sorted_student_list) {
        cout << "Stud id "<< stud->id << " go to program ";
        for(auto *prog : stud->desired_prog_list) {
            if(prog->place_num > 0) {
                cout << prog->id << " ";
                stud->admitted_prog = prog;
                prog->place_num--;
                break;
            }
        }
        cout << endl;
    }
    cout << endl;

    for(auto stud : student_list) {
        cout << stud.admitted_prog->id << " ";
    }

    return 0;
}
