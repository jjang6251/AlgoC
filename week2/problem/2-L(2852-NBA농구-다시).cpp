#include <bits/stdc++.h>
using namespace std;

int n, team;
int ret1, ret2;
int time1, time2;

int changeToInt(string s)
{
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

void print(int time) {
    string d = "00" + to_string(time / 60); 
    string e = "00" + to_string(time % 60); 
    cout << d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2) << '\n';
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    string time;
    int prev;
    int now;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        time = "";
        team = 0;
        now = 0;
        cin >> team;
        cin >> time;

        if (team == 1)
        {
            ret1++;
        }
        else
        {
            ret2++;
        }

        now = changeToInt(time);

        if (i == n - 1)
        {
            if (ret1 > ret2)
            {
                if (prev != 0)
                {
                    time1 += (48*60) - prev;
                }
            }
            else if (ret1 < ret2)
            {
                if (prev != 0)
                {
                    time1 += (48*60) - prev;
                }
            }
        }

        if (ret1 > ret2)
        {
            if (prev != 0)
            {
                time1 += now - prev;
            }
        }
        else if (ret1 < ret2)
        {
            if (prev != 0)
            {
                time2 += now - prev;
            }
        }

        prev = now;
    }
    print(time1);
    print(time2);

    return 0;
}