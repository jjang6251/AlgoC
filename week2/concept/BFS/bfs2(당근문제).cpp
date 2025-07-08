#include <bits/stdc++.h>
using namespace std;
int adj[102][102];
int visited[102][102];
int n, m, sw_y, sw_x, dk_y, dk_x;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (adj[ny][nx] == 1 && visited[ny][nx] == 0)
            {
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    cout << "최단 거리: " <<visited[dk_y][dk_x] << '\n';
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> sw_y >> sw_x;
    cin >> dk_y >> dk_x;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    BFS(0 , 0);
    return 0;
}