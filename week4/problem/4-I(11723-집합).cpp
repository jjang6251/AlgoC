#include<bits/stdc++.h>
using namespace std;

int m, bit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;

    for(int i = 0; i < m; i++) {
        string s; int x;
        cin >> s;

        if(s == "add") {
            cin >> x;
            bit |= (1 << x);
        }
        else if(s == "remove") {
            cin >> x;
            bit &= ~(1 << x);
        }
        else if(s == "check") {
            cin >> x;
            if(bit & (1 << x)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
        else if(s == "toggle") {
            cin >> x;
            bit ^= (1 << x);
        }

        else if(s == "all") {
            bit = (1 << 21) -1;
        }
        else if(s == "empty") {
            bit = 0;
        }
    }

    return 0;

}