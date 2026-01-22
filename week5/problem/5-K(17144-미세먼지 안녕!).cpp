#include<bits/stdc++.h>
using namespace std;

int a[54][54], cop[54][54], r, c, t, air_x = -1, air_y = -1;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void diffusion(int x, int y) {
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= c || nx < 0 || nx >= r) continue;
        if(a[nx][ny] == -1) continue;
        cop[nx][ny] += a[x][y] / 5;
        ret++;
    }
    cop[x][y] += a[x][y] - ((a[x][y] / 5) * ret);
}

void circul() {
    int top = air_x;
    int bot = air_x + 1;

    // -------- 위쪽 (반시계) --------
    // 왼쪽 세로: 위로
    for(int i = top - 1; i > 0; i--) cop[i][0] = cop[i - 1][0];
    // 위쪽 가로: 왼쪽으로
    for(int j = 0; j < c - 1; j++) cop[0][j] = cop[0][j + 1];
    // 오른쪽 세로: 아래로
    for(int i = 0; i < top; i++) cop[i][c - 1] = cop[i + 1][c - 1];
    // 아래쪽 가로(청정기 윗줄): 오른쪽으로
    for(int j = c - 1; j > 1; j--) cop[top][j] = cop[top][j - 1];

    cop[top][1] = 0;
    cop[top][0] = -1;

    // -------- 아래쪽 (시계) --------
    // 왼쪽 세로: 아래로
    for(int i = bot + 1; i < r - 1; i++) cop[i][0] = cop[i + 1][0];
    // 아래쪽 가로: 왼쪽으로
    for(int j = 0; j < c - 1; j++) cop[r - 1][j] = cop[r - 1][j + 1];
    // 오른쪽 세로: 위로
    for(int i = r - 1; i > bot; i--) cop[i][c - 1] = cop[i - 1][c - 1];
    // 위쪽 가로(청정기 아랫줄): 오른쪽으로
    for(int j = c - 1; j > 1; j--) cop[bot][j] = cop[bot][j - 1];

    cop[bot][1] = 0;
    cop[bot][0] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) {
                if(air_x == -1) { // 첫 -1이 위쪽
                    air_x = i;
                    air_y = j; // 보통 0열
                }
            }
        }
    }

    while(t--) {
        memset(cop, 0, sizeof(cop));

        // 1) 확산 (a -> cop)
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(a[i][j] > 0) diffusion(i, j);
            }
        }

        // 공기청정기 위치 복원
        cop[air_x][0] = -1;
        cop[air_x + 1][0] = -1;

        // 2) 순환 (cop in-place)
        circul();

        // 3) cop -> a 갱신
        memcpy(a, cop, sizeof(a));
    }

    long long ans = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] > 0) ans += a[i][j];
        }
    }
    cout << ans << "\n";

    return 0;
}