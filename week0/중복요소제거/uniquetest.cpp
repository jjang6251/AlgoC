#include <bits/stdc++.h>
using namespace std;

vector<int> v = {2, 2, 3, 3, 1, 1, 5, 5};

int main() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i: v) cout<<i;
    cout<< "\n";
    return 0;
}