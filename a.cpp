#include <bits/stdc++.h>
using namespace std;

string str, front, back, ret, result;
int num, location;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    cin >> str;

    location = str.find('*');

    front = str.substr(0, location);
    back = str.substr(location + 1);

    for (int i = 0; i < num; i++)
    {
        cin >> ret;
        if (front.size() + back.size() > ret.size())
        {
            result += "NE\n";
        }
        else
        {
            if (front == ret.substr(0, front.size()) && back == ret.substr(ret.size() - back.size()))
                result += "DA\n";
            else
                result += "NE\n";
        }
    }

    cout << result;

    return 0;
}