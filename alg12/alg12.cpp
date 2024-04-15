#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n_move = 0;

struct Cell {
    int x_cord {};
    int y_cord {};
    int mark {}; // единица крестик, 0 ноль 

    friend ostream& operator<<(ostream& os, const Cell& cell) {
        os << "x_cord:" << cell.x_cord
           << ",\n y_cord:" << cell.y_cord
           << ",\n mark: " << cell.mark
           << "\n";
        return os;
    }
};

vector<Cell> field {};

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto& t : v) { 
        os << t;
    }
    return os << endl;
}

int checkWinner(const vector<Cell>& field, int n_move) {
    int size = field.size();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= size - 5; ++j) {
            int countX = 0, countO = 0;
            for (int k = j; k < j + 5; ++k) {
                if (field[k].mark == 1) {
                    countX++;
                } else if (field[k].mark == 0) {
                    countO++;
                }
            }
            if (countX == 5) return 1;
            if (countO == 5) return 0;
        }
    }

    for (int j = 0; j < size; ++j) {
        for (int i = 0; i <= size - 5; ++i) {
            int countX = 0, countO = 0;
            for (int k = i; k < i + 5; ++k) {
                if (field[k * size + j].mark == 1) {
                    countX++;
                } else if (field[k * size + j].mark == 0) {
                    countO++;
                }
            }
            if (countX == 5) return 1;
            if (countO == 5) return 0;
        }
    }

    for (int i = 0; i <= size - 5; ++i) {
        for (int j = 0; j <= size - 5; ++j) {
            int countX = 0, countO = 0;
            for (int k = 0; k < 5; ++k) {
                if (field[(i + k) * size + (j + k)].mark == 1) {
                    countX++;
                } else if (field[(i + k) * size + (j + k)].mark == 0) {
                    countO++;
                }
            }
            if (countX == 5) return 1;
            if (countO == 5) return 0;
        }
    }

    for (int i = 0; i <= size - 5; ++i) {
        for (int j = size - 1; j >= 4; --j) {
            int countX = 0, countO = 0;
            for (int k = 0; k < 5; ++k) {
                if (field[(i + k) * size + (j - k)].mark == 1) {
                    countX++;
                } else if (field[(i + k) * size + (j - k)].mark == 0) {
                    countO++;
                }
            }
            if (countX == 5) return 1;
            if (countO == 5) return 0;
        }
    }

    return -1; // Нет победителя
}

void init() {
    ifstream fin{"input.txt"};
    fin >> n_move;

    for(int i = 0; i < n_move; i++) {
        Cell cell;
        fin >> cell.x_cord >> cell.y_cord;
        if(i % 2 == 1) {
            cell.mark = 0;
        } else {
            cell.mark = 1;
        }

        field.push_back(cell);
    }
}

int main() {
    init();
    cout << field << endl;
    return 0;
}
