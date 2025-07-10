#include<bits/stdc++.h>
using namespace std;

int n, m;
int lt = 10000000;
vector<pair<int, int>> one, two;

int cal(vector<pair<int, int>> b) {
    int ret = 0;
    for(int i = 0; i < one.size(); i++) {
        int mn = 102;
        int distance;
        for(int j = 0; j < m; j++) {
            distance = abs(one[i].first - b[j].first) + abs(one[i].second - b[j].second);
            mn = min(distance, mn);
        }
        ret += mn;
    }
    return ret;
}


void combi(int start, vector<pair<int, int>> b) {
    if(b.size() == m) {
        int result;
        result = cal(b);
        lt = min(result, lt);
        return;
    }
    for(int i = start+1; i < two.size(); i++) {
        b.push_back(two[i]);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> b;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            if(num == 1) {
                one.push_back({i, j});
            }
            if(num == 2) {
                two.push_back({i, j});
            }
        }
    }

    combi(-1, b);

    cout << lt;
    return 0;
    
}