#include<bits/stdc++.h>
using namespace std;
const int V = 4;
vector<int> adj[V];

int main() {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    for(int i = 0; i < 4; i++) {
        cout << i << " :: ";
        for(int there : adj[i]) {
            cout << there << " ";
        }
        cout << "\n";
    }

    //다른 버전
    for(int i = 0; i < 4; i++) {
        cout << i << " :: ";
        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}