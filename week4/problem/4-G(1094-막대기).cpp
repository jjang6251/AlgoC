#include<bits/stdc++.h>
using namespace std;

int ret;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;

    while(x != 1) {
        if(x & 1) ret++; //홀수면 개수 추가
        x /= 2;
    }

    cout << ret;
    return 0;
}