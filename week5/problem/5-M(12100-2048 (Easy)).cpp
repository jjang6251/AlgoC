#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;

// 한 줄(벡터)을 왼쪽으로 "2048 규칙"대로 이동/합치기
static vector<int> compressMergeLeft(const vector<int>& line) {
    vector<int> v;
    v.reserve(line.size());

    // 1) 0 제거
    for (int x : line) if (x != 0) v.push_back(x);

    // 2) 왼쪽부터 합치기 (한 번 합친 타일은 그 턴에서 다시 합치지 않음)
    vector<int> res;
    res.reserve(line.size());

    for (int i = 0; i < (int)v.size(); ) {
        if (i + 1 < (int)v.size() && v[i] == v[i + 1]) {
            res.push_back(v[i] * 2);
            i += 2;
        } else {
            res.push_back(v[i]);
            i += 1;
        }
    }

    // 3) 0 채우기
    while ((int)res.size() < (int)line.size()) res.push_back(0);

    return res;
}

// dir: 0=Left, 1=Right, 2=Up, 3=Down
static vector<vector<int>> moveBoard(const vector<vector<int>>& b, int dir) {
    vector<vector<int>> nb = b;

    if (dir == 0) { // Left
        for (int r = 0; r < n; r++) {
            nb[r] = compressMergeLeft(b[r]);
        }
    } 
    else if (dir == 1) { // Right
        for (int r = 0; r < n; r++) {
            vector<int> line = b[r];
            reverse(line.begin(), line.end());
            line = compressMergeLeft(line);
            reverse(line.begin(), line.end());
            nb[r] = line;
        }
    }
    else if (dir == 2) { // Up
        for (int c = 0; c < n; c++) {
            vector<int> col(n);
            for (int r = 0; r < n; r++) col[r] = b[r][c];
            col = compressMergeLeft(col);
            for (int r = 0; r < n; r++) nb[r][c] = col[r];
        }
    }
    else { // Down (dir == 3)
        for (int c = 0; c < n; c++) {
            vector<int> col(n);
            for (int r = 0; r < n; r++) col[r] = b[r][c];
            reverse(col.begin(), col.end());
            col = compressMergeLeft(col);
            reverse(col.begin(), col.end());
            for (int r = 0; r < n; r++) nb[r][c] = col[r];
        }
    }

    return nb;
}

static int getMaxTile(const vector<vector<int>>& b) {
    int mx = 0;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            mx = max(mx, b[r][c]);
    return mx;
}

static void dfs(int depth, const vector<vector<int>>& b) {
    ans = max(ans, getMaxTile(b));
    if (depth == 5) return;

    for (int dir = 0; dir < 4; dir++) {
        auto nb = moveBoard(b, dir);

        // 가지치기(선택): 변화 없으면 굳이 더 깊게 안 가도 됨
        if (nb == b) continue;

        dfs(depth + 1, nb);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dfs(0, board);
    cout << ans << "\n";
    return 0;
}