#include <bits/stdc++.h>
using namespace std;

int n, from, to, ret = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> from >> to;
        a[i].first = to; a[i].second = from;
    }

    sort(a.begin(), a.end());

    from = a[0].second; to = a[0].first;

    for(int i = 1; i < n; i++) {
        if(a[i].second < to) continue;
        from = a[i].second; to = a[i].first; ret++;
    }

    cout << ret << "\n";
    return 0;

}