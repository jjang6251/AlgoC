//재귀함수 -> 4개 이상 뽑을 경우
//중첩for문 -> 3개 이하 뽑을 경우

#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5}; //인덱스를 기반으로 뽑는다.(요소를 기반으로 뽑으면 중복이 있을 경우 헷갈림.)
void print(vector<int> b) {
    for(int i : b)cout << i << " ";
    cout << '\n';
}

void combi(int start, vector<int> b) {
    if(b.size() == k) {
        print(b);
        return;
    }
    for(int i = start + 1; i<n; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main() {
    vector<int> b;
    combi(-1, b);
    return 0;
}

