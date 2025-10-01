// 라인스위핑은 구간과 관련된 문제에서 최대의 구간, 횟수 등을 찾는데 많이 쓰이는 알고리즘이다.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
P L[1000004];
int n, from, to, l, r, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> from >> to;
        L[i] = P(from, to);
    }
    sort(L, L+n);
    l = L[0].first; r = L[0].second;
    for(int  i = 1; i < n; i++) {
        if(r < L[i].first) {
            ret += (r-1);
            l = L[i].first;
            r = L[i].second;
        } else if(L[i].first <= r && L[i].second >= r) {
            r = L[i].second;
        }
    }
    ret += r-1;
    cout << ret << '\n';
    return 0;
}