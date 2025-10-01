#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    bool chk = true;

    while (!s.empty()) {
        if (s[0] == 'p') {
            if (s.size() < 2 || s.substr(0, 2) != "pi") { chk = false; break; }
            s.erase(0, 2);
        } else if (s[0] == 'k') {
            if (s.size() < 2 || s.substr(0, 2) != "ka") { chk = false; break; }
            s.erase(0, 2);
        } else if (s[0] == 'c') {
            if (s.size() < 3 || s.substr(0, 3) != "chu") { chk = false; break; }
            s.erase(0, 3);
        } else {
            // 이 부분이 없어서 무한 루프가 날 수 있었음
            chk = false;
            break;
        }
    }

    cout << (chk ? "YES" : "NO");
    return 0;
}