//커스텀 오퍼레이터

#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> order, cnt;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int>b) {
    if(a.second == b.second) {
        return order[a.first] < b.first; //오름차순
    }
    return a.second > b.second; //내림차순
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    for(int i = 0; i < n; i++) {
        int num;
        cin  >> num;

        cnt[num]++;
        if(order[num] == 0) order[num] = i;
    }

    for(auto p : cnt) {
        v.push_back({p.first, p.second});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto p : v) {
        for(int j = 0; j < p.second; j++) {
            cout << p.first << ' ';
        }
    }

    return 0;
}