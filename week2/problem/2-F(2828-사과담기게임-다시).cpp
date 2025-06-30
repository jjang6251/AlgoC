#include<bits/stdc++.h>
using namespace std;

int n, m, j, ret;
int a[10];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> j;

    ret = 0;

    //초기 배열 설정
    int left = 1;
    int right = m;

    for(int i = 0; i < j; i++) {
        int num;
        cin >> num;
        
        if(num < left) {
            ret += (left - num);
            right -= (left - num);
            left = num;
        }
        else if(num > right) {
            ret += (num - right);
            left += (num - right);
            right = num;
        }
    }

    cout << ret << '\n';

    return 0;

}