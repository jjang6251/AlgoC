//3*3 맵을 입력받아야 함. 이 맵은 1과 0으로 이루어져있고 {0, 0}은 무조건 1임을 보장한다. {0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며 방문한 정점은 다시 방문하지 않으며 방문하는 좌표를 출력하는 코드. 0은 갈 수 없는 지역. 1은 갈 수 있는 지역을 구현하시오.
#include<bits/stdc++.h>
using namespace std;
const int n = 3;
const int dy[] = {-1, 0 ,1, 0};
const int dx[] = {0, 1, 0, -1};
int a[n][n], visited[n][n];

void go(int y, int x) {
    visited[y][x] = 1;
    cout << y << " : " << x << '\n';
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n ) continue;
        if(a[ny][nx] == 0) continue;
        if(visited[ny][nx] == 1) continue;
        go(ny, nx);
    }
    return;
}

int main() {
    int y = 0, x = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    go(0, 0);
}