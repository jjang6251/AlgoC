#include <bits/stdc++.h>
using namespace std;

string str, ret;
int num, al[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;

    for(int i=0; i< num; i++) {
        cin >> str;
        al[str[0] - 'a']++;
    }

    for(int i=0; i < 26; i++) if(al[i] >= 5) ret += (i+'a');

    if(ret.size()) cout << ret << "\n";
    else cout << "PREDAJA" << "\n";

    return 0;

}