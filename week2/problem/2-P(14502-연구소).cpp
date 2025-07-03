#include <bits/stdc++.h>
using namespace std;

int n, m, result = -1;
int ret0, k = 3;
int arr[10][10], visited[10][10];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> a;
vector<int> b;
int temp[10][10];
int tempVisited[10][10];

void DFS(int y, int x) {
    if(temp[y][x] == 0) temp[y][x] = 2;
    tempVisited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if((temp[ny][nx] == 0 || temp[ny][nx] == 2) && tempVisited[ny][nx] == 0) {
            DFS(ny, nx);
        }
    }

    return;
}

void makeAndCal(vector<int> b) {
    int y, x;
    int cnt = 0;
    
    // 배열 복사본 만들기
    memcpy(temp, arr, sizeof(arr));
    memset(tempVisited, 0, sizeof(tempVisited));

    // 벽 세우기
    for (int i : b) {
        tie(y, x) = a[i];
        temp[y][x] = 1;
    }

    // 바이러스 퍼뜨리기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(temp[i][j] == 2 && tempVisited[i][j] == 0) {
                DFS(i, j);
            }
        }
    }

    // 안전 영역 세기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) cnt++;
        }
    }

    result = max(result, cnt);
}

void combi(int start, vector<int> b)
{
    if (b.size() == k)
    {
        makeAndCal(b);
        return;
    }
    for (int i = start + 1; i < ret0; i++)
    {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                a.push_back({i, j});
                ret0++;
            }
        }
    }

    combi(-1, b);

    cout << result;

    
}