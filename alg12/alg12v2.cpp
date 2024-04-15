#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <array>
#include <vector>

using namespace std;

constexpr int LINE_LENGTH_MAX = 5;

template<typename T>
using Point = pair<T, T>;

using CellPoint = Point<int>;
using CellType = bool;

template<typename T>
using Ilist = initializer_list<T>;

template<typename T>
struct std::hash<Point<T>> {
    size_t operator()(const Point<T>& p) const {
        return hash<T>()(p.first) ^ hash<T>()(p.second);
    }
};

int n_move = 0;

unordered_map<CellPoint, CellType> cell_map; 
array<array<int, 2>, 4> dir_list {1, 0, 0, 1, 1, 1, -1, 1};

template<typename T>
ostream& operator<<(ostream& os, const Point<T>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename K, typename V>
ostream& operator<<(ostream& os, const unordered_map<K, V>& umap) {
    for (const auto& pair : umap) {
        os << pair.first << " : " << pair.second << endl;
    }
    return os;
}

int getLineLength(int x, int y, int dx, int dy) {
    int r = 1;
    int l = 1;
    int pr = 0;
    int pl = 0;
    int length = 1;

    while(r > pr || l > pl) {
        if(r > pr) {
            pr = r;
            if(cell_map.count(CellPoint{x + dx * r, y + dy * r})) {
                length++;
                r++;
            }
        }
        if(l > pl) {
            pl = l;
            if(cell_map.count(CellPoint{x - dx * l, y - dy * l})) {
                length++;
                l++;
            }
        }
    }

    return length;
}

bool checkGameFinished() {
    for(const auto& [point, type] : cell_map) {
        auto [x, y] = point;
        for(auto [dx, dy] : dir_list) {
            int length = getLineLength(x, y, dx, dy);
            if(length >= LINE_LENGTH_MAX) {
                return 1;
            }
        }

    }

    return 0;
}

void analyze() {
    ifstream fin{"data6.txt"};
    fin >> n_move;

    int step, player;
    for(step = 1; step <= n_move; step++) {
        int x_coord;
        int y_coord;
        player = step % 2;

        fin >> x_coord >> y_coord;
        //        cout << x_coord << " " << y_coord << endl;
        cell_map.insert({CellPoint{x_coord, y_coord}, player}); 
        bool gameFinished = checkGameFinished();
        if(gameFinished) break;
    }

    if(step < n_move) {
        cout << "Inattention" << endl;
    } else if(step > n_move) {
        cout << "Draw" << endl;
    } else {
        if(player == 1) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }

}

void generate() {
    // TODO
}

int main() {
    analyze();
//    generate();
    return 0;
}
