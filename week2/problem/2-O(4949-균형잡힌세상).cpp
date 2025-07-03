#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[') {
            stk.push(c);
        } else if (c == ')') {
            if (stk.empty() || stk.top() != '(') return false;
            stk.pop();
        } else if (c == ']') {
            if (stk.empty() || stk.top() != '[') return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s == ".") break;

        if (check(s)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}