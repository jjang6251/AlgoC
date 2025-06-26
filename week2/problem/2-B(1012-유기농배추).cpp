#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[51][51], visited[51][51];


void DFS(int y, int x)
{
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] == 1 && visited[ny][nx] == 0) {
            DFS(ny, nx);
        }
    }
    return;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;


    for (int i = 0; i < t; i++)
    {
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;
        cin >> n >> m >> k;
        for(int j = 0; j < k; j++) {
            int num1, num2;
            cin >> num1 >> num2;
            a[num1][num2] = 1;
        }

        for(int count_i = 0; count_i < n; count_i++) {
            for(int count_j = 0; count_j < m; count_j++) {
                if(a[count_i][count_j] == 1 && visited[count_i][count_j] == 0) {
                    ret++;
                    DFS(count_i, count_j);
                }
            }
        }
        cout << ret << '\n';
    }

    return 0;
}