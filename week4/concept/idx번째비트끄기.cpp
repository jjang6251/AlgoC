#include<bits/stdc++.h>
using namespace std;
int main() {
    int S = 18;
    int idx = 1;
    S &= ~(1 << idx);
    cout << S << '\n';
    return 0; 
}