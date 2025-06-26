#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int visited[100];
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};

void BFS(int here) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while(q.size()) {
        int here = q.front();
        q.pop();
        for(int there: adj[here]) {
            if(visited[there]) continue;
            visited[there]  = visited[here] + 1;
            q.push(there);
        }
    }
}

int main() {
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);
    BFS(10);

    for(int i : nodeList) {
        cout << i << " : " << visited[i] << '\n';
    }

    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] - 1 << '\n';
    return 0;
}