#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int n, m, mx, d[10001];
int visited[10001];

int DFS(int x) {
    visited[x] = 1;
    int ret = 1;
    for(int i : v[x]) {
        if(visited[i]) continue;
        ret += DFS(i);
    }
    return ret;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        d[i] = DFS(i);
        mx = max(d[i], mx);
    }


    for(int i = 1; i <= n; i++) {
        if(mx == d[i]) cout << i << " ";
    }

    return 0;

}