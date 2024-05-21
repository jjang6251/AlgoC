#include <bits/stdc++.h>
using namespace std;

vector<int> v{2, 2, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};

int main() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); //erase(from, to) from -> 포함, to -> 포함X
    //unique는 결괏값으로 중복이 아닌 수들 다음에 위치를 리턴한다.
    for(int i : v) cout << i << " ";
    cout << '\n';
    return 0;
}