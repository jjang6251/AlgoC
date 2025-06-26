#include<bits/stdc++.h>
using namespace std;

int a[102][102]; //처음 높이값 저장 배열
int b[102][102]; //안전영역 배열
bool visited[102][102];
int n, ret, cnt;
int dy[] = {-1, 0 , 1, 0};
int dx[] = {0, 1, 0, -1};

void DFS(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny <0 || nx < 0 || ny>=n || nx >=n) continue;
        if(b[ny][nx] == 1 && visited[ny][nx] == 0) {
            DFS(ny, nx);
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i <= 100; i++) {
        fill(&b[0][0], &b[0][0] + 102 * 102, 0);
        fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
        ret = 0;
        for(int j = 0; j <n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[j][k] > i) {
                    b[j][k] = 1;
                } 
            }
        }

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(b[j][k] == 1 && visited[j][k] == 0) {
                    ret++;
                    DFS(j, k);
                }
            }
        }
        if(ret > cnt) {
            cnt = ret;
        }
    }

    cout << cnt << '\n';
}
