#include <bits/stdc++.h>
using namespace std;
const int V = 10;
bool a[V][V], visited[V];

void go(int from) {
    visited[from] = 1;
    cout << from << '\n';
    for(int i = 0; i < V; i++) {
        if(visited[i]) continue;
        if(a[from][i]) {
            go(i);
        }
    }
    return;
}

int main() {
    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(a[i][j] && visited[i] == 0) {
                go(i);
            }
        }
    }
}