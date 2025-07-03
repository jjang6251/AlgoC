#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int l, r;

bool VPS(string s)
{
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] == '(')
            l++;
        else if (s[j] == ')')
        {
            if (l == 0)
            {
                return false;
            }
            l--;
        }
    }
    if(!(l == 0 && r == 0)) {
        return false;
    }
    return true;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        l = r = 0;
        if(VPS(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int n;  
// string s; 
// bool check(string s){
// 	stack<char> stk;
// 	for(char c : s){
// 		if(c == '(')stk.push(c); 
// 		else{
// 			if(!stk.empty()) stk.pop(); 
// 			else return false; 
// 		}
// 	}
// 	return stk.empty();
// }
// int main() {
// 	cin >> n; 
// 	for(int i = 0; i < n; i++){
// 		cin >> s; 
// 		if(check(s)) cout << "YES\n"; 
// 		else cout << "NO\n";
// 	}  
// 	return 0;
// } 