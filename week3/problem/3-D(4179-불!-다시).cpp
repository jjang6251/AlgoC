#include<bits/stdc++.h>
using namespace std;

int r, c , ret, mn = 987654321;
char a[1004][1004];
char temp[1004][1004];
int visited[1004][1004];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool Fire() {
    vector<pair<int, int>> v;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] == 'F') {
                for(int q = 0; q < 4; q++) {
                    int ny = j + dy[q];
                    int nx = i + dx[q];
                    if(ny < 0 || nx < 0 || ny >= c || nx >= r) continue;
                    if(a[ny][nx] != '#') {
                        if(a[ny][nx] == 'J') return false;
                        v.push_back({ny, nx});
                    }
                }
            }
        }
    }

    for(pair<int, int> i : v) {
        a[i.first][i.second] = 'F';
    }
    return true;
}

void DFS(int y, int x) {
    if(y == c || x == r) {
        ret++;
        mn = min(ret, mn);
        return;
    }
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= c || nx >= r) continue;
        if(a[ny][nx] == '.' && visited[ny][nx] == 0 && a[ny][nx] != '#' && a[ny][nx] != 'F') {
            memcpy(temp, a, sizeof(a));
            if(Fire()) {
                ret++;
                DFS(ny, nx);
            } else {
                if(ret) ret--;
                memcpy(a, temp, sizeof(temp));
                return;
            }
            memcpy(a, temp, sizeof(temp));
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'J') x = i; y = j;
        }
    }

    DFS(y, x);
    
    if(mn == 987654321) {
        cout << "IMPOSSIBLE";
    } else {
        cout << mn;
    }

    return 0;
}