#include<bits/stdc++.h>
using namespace std;
int n, temp;
vector<int> v;

int main() {
    cin >> n;
    double b = 0; //소수점이 나오기 때문에 선언언
    for(int i = 0; i < n; i++) {
        cin >> temp;
        b += temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    cout << '\n';
    cout << fixed << setprecision(2) << (b/n) << '\n';
    return 0;
}