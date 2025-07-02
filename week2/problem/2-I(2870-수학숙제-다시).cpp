#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;
string s;
string result_num = "";

void go()
{
    if(result_num.empty()) return;
    while (!result_num.empty() && result_num.front() == '0')
    {
        result_num.erase(result_num.begin());
    }
    if (result_num.empty())
        result_num = "0";
    a.push_back(result_num);
    result_num.clear();
}

bool compare(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--)
    {
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                result_num += s[i];
            }
            else
            {
                go();
            }
        }

        // 마지막 숫자 토큰 처리
        go();
    }

    sort(a.begin(), a.end(), compare);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}


//틀렸었던 이유: 문자열을 stoi로 int형으로 바꿔서 sort를 했는데 숫자가 매우 큰 숫자이면 stoi는 런타임 에러(out of range)를 발생시킨다.