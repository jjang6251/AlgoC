#include <bits/stdc++.h>
using namespace std;

string str, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, str);

    for(char a : str) {
        if(a>= 65 && a <= 90) {
            if(a+13 > 90) ret += a+13-26;
            else ret += a+13;
        } else if(a>=97 && a<=122) {
            if(a+13 > 122) ret += a+13-26;
            else ret += a+13;
        } else ret += a;
    }

    cout << ret << "\n";
    return 0;
}