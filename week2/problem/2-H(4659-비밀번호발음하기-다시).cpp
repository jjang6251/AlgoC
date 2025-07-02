#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
string s;
int lcnt, rcnt; //모음, 자음
char before;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


    // 모음 포함.
    //  모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
    //  같은 글자가 연속적으로 두번 오면 안되나, ee와 oo는 허용.

int main()
{

    while (true)
    {
        s = "";
        cin >> s;
        if(s == "end") break;
        bool flag = 0;
        lcnt = rcnt = 0;
        bool is_include_vowel = 0;
        int prev = -1;
        for(int i= 0 ; i < s.size(); i++) {
            int idx = s[i];
            if(isVowel(idx)) {
                lcnt++, rcnt = 0, is_include_vowel = 1;
            }
            else rcnt++, lcnt = 0;
            if(lcnt == 3 || rcnt == 3) flag = 1;
            if(i >= 1 && (prev == idx) && (idx != 'e' && idx !='o')) flag = 1;
            prev = idx;
        }
        if(is_include_vowel == 0) flag = 1;
        if(flag == 0) {
            cout << '<' << s << "> " << "is acceptable." << '\n';
        } else {
            cout << '<' << s << "> "  << "is not acceptable." << '\n';
        }
    }
    return 0;
}