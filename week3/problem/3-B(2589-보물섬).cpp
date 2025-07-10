#include<bits/stdc++.h>
using namespace std;

int n, m, mx;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int visited[54][54];
char a[54][54];

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x];
    q.push({y, x});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if(a[ny][nx] == 'L' && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                mx = max(mx, visited[ny][nx]);
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'l') {
                memset(visited, 0, sizeof(visited));
                BFS(i, j);
            }
        }
    }

    cout << mx-1;
    return 0;
}