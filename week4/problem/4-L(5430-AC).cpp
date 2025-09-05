#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        string p, arr;
        int n;
        cin >> p >> n >> arr;

        deque<int> dq;
        // 배열 파싱: 숫자만 뽑아 stoi
        string num;
        for (char c : arr) {
            if (isdigit(c) || c == '-') num += c;
            else {
                if (!num.empty()) {
                    dq.push_back(stoi(num));
                    num.clear();
                }
            }
        }

        bool rev = false, err = false;
        for (char c : p) {
            if (c == 'R') {
                rev = !rev;
            } else { // 'D'
                if (dq.empty()) { err = true; break; }
                if (!rev) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (err) {
            cout << "error\n";
            continue;
        }

        cout << "[";
        if (!rev) {
            for (size_t i = 0; i < dq.size(); i++) {
                cout << dq[i];
                if (i + 1 != dq.size()) cout << ",";
            }
        } else {
            for (size_t i = 0; i < dq.size(); i++) {
                cout << dq[dq.size() - 1 - i];
                if (i + 1 != dq.size()) cout << ",";
            }
        }
        cout << "]\n";
    }
    return 0;
}