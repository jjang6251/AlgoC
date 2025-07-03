#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int two = 0, five = 0;
        cin >> n;
        for (int j = 2; j <= n; j *= 2)
        {
            two += n / j;
        }
        for (int j = 5; j <= n; j *= 5)
        {
            five += n / j;
        }
        cout << min(two, five) << '\n';
    }
    return 0;
}


//5의 배수 세는 것만으로도 할 수 있음.