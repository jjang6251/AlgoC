//돌다리 두들겨 보기 권법
#include<bits/stdc++.h>
using namespace std;
const int n = 6;
vector<int> adj[n];
int visited[n];

void DFS(int u) {
    cout << u << "\n";
    for(int v : adj[u]) {
        if(visited[v]) continue;
        visited[v] == 1;
        DFS(v);
    }
    cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
    return;
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    DFS(1);
}