#include <bits/stdc++.h>
using namespace std;
//중첩 for문 구현

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5}; //인덱스를 기반으로 뽑는다.(요소를 기반으로 뽑으면 중복이 있을 경우 헷갈림.)
void print(vector<int> b) {
    for(int i : b)cout << i << " ";
    cout << '\n';
}

int main() {
    vector<int> b;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < i; j++) {
    //         for(int k = 0; k < j; k++) {
    //             cout << i << " : " << j << " : " << k << "\n";
    //         }
    //     }
    // }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                cout << i << " : " << j << " : " << k << "\n";
            }
        }
    }

    

    return 0;
}