#include<bits/stdc++.h>
using namespace std;
int main() {
    int S = 18;
    int idx = 0;
    if(S & (1 << idx)) {
        cout << "해당 idx : " << idx << "가 켜져있습니다.\n";
    } else {
        cout << "해당 idx : " << idx << "가 꺼져있습니다.\n";
    }
    return 0;
}