#include <bits/stdc++.h>
using namespace std;

long long s, e, cnt[100001], a[1000001], n, ret;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while(e < n) {
        if(!cnt[a[e]]) {
            cnt[a[e]]++;
            e++;
        } else {
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }

    ret += (long long)(e - s) * (e - s + 1) / 2;
    cout << ret << "\n";
}