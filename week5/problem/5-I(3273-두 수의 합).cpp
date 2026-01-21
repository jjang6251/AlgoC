#include <bits/stdc++.h>
using namespace std;

long long n, x, sum, ret;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    sort(a.begin(), a.end());

    int l = 0, r = n - 1;

    while(l < r) {
        int sum = a[l] + a[r];

        if(sum == x) {
            ret++;
            r--;
            l++;
        } else if(sum < x) {
            l++;
        } else {
            r--;
        }
    }

    cout << ret << "\n";
    return 0;
}