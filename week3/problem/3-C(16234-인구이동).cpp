#include<bits/stdc++.h>
using namespace std;

int n, l, r, ret, cnt, day;
int a[54][54], visited[54][54];
int dy[] = {1, 0, -1, 0};
int dx[] = {0 ,1, 0, -1};
vector<pair<int, int>> v;

void DFS(int y, int x) {
    visited[y][x] = 1;
    v.push_back({y, x});
    ret += a[y][x];
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r && visited[ny][nx] == 0) {
            DFS(ny, nx);
        } 
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    

    while(true) {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0) {
                    ret = 0;
                    v.clear();
                    DFS(i, j);
                    if(v.size() >= 2) {
                        for(auto i : v) {
                            a[i.first][i.second] = ret/v.size();
                        }
                        cnt++;
                    }
                }
            }
        }
        if(cnt == 0 ) break;
        day++;
    }

    cout << day;
    return 0;

}