#include<bits/stdc++.h>
using namespace std;

int a[102][102], visited[102][102];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k, ret, cnt;
vector<int> result;

int DFS(int x, int y) {
    visited[x][y] = 1;
    int ret = 1;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(a[nx][ny] == 0 && visited[nx][ny] == 0) {
            ret += DFS(nx, ny);
        }
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;
    fill(&a[0][0], &a[0][0]+ 102 * 102, 0);

    for(int i = 0; i < k; i++) {
        int l_x = 0, l_y = 0, r_x = 0, r_y = 0;

        cin >> l_x >> l_y >> r_x >> r_y;

        for(int j = l_x; j < r_x; j++) {
            for(int o = l_y; o < r_y; o++) {
                a[j][o] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0 && visited[i][j] == 0) {
                result.push_back(DFS(i, j));
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';

    for(int a : result) {
        cout << a << ' ';
    }

    return 0;

}
