#include <bits/stdc++.h>
using namespace std;

string str;
int num, al[26], result[26], check;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;

    for(int i=0; i< num; i++) {
        cin >> str;
        al[str[0] - 'a']++;
    }

    for(int i = 0; i< 26; i++) {
        if(al[i] >= 5) {
            result[i]++;
            check++;
        }
    }
    if(check == 0) {
        cout << "PREDAJA" << "\n";
    } else {
        for(int i = 0; i< 26; i++) {
            if(result[i] > 0) {
                char a = i + 'a';
                cout << a;
            }
        }
    }

    return 0;

}