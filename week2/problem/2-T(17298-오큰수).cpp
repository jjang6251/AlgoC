#include<bits/stdc++.h>
using namespace std;

int n;
stack<int> s;
int check[1000004], a[1000004];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    memset(check, -1, sizeof(check));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(!s.empty() && a[s.top()] < a[i]) {
            check[s.top()] = a[i]; s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++) {
        cout << check[i] << " ";
    }

    return 0;
}