#include<bits/stdc++.h>
using namespace std;

const int num = 52;
vector<int> a[num];

int n, del, ret;
int visited[num];

void DFS(int x) {
    visited[x] = 1;
    if(a[x].size() == 0) {
        ret++;
        return;
    }
    for(int i : a[x]) {
        if(visited[i]) continue;
        DFS(i);
    }
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    int root;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if(j == -1) {
            root = i;
        } else {
            a[j].push_back(i);
        }
    }

    cin >> del;

    if(del == root) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < num; i++) {
        a[i].erase(remove(a[i].begin(), a[i].end(), del), a[i].end());
    }

    visited[del] = 1;

    DFS(root);

    cout << ret;
    return 0;
}