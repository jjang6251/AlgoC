#include <bits/stdc++.h>
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

    l = L[0].first; r = l+L[0].second;

    for(int i = 0; i < n; i++) {
        if(r < L[i].first) {
            l = L[i].first;
            r = l + L[i].second;
        } else if(r > L[i].first) {
            r += L[i].second;
        }
    }
    
    cout << r;
}

