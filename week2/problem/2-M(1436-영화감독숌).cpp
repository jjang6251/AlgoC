#include<bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    int i = 666;
    while(true) {
        if(to_string(i).find("666") != string::npos) {
            n--;
        }

        if(n==0) break;
        i++;
    }

    cout << i;
    return 0;
}