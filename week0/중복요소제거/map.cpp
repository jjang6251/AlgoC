#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {
    vector<int> v{1, 1, 2, 2, 3, 3};
    for(int i : v) {    
        if(mp[i]) {
            continue;
        } else {
            mp[i] = 1;
        }
    }
    vector<int> ret;
    for(auto it : mp) {
        ret.push_back(it.first); //first는 key, second는 value이다(map에서)
    }
    for(int i : ret) cout << i << '\n';
}