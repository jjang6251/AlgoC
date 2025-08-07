#include<bits/stdc++.h>
using namespace std;
int N, mp, mf, ms, mv;
int arr[17][5];
int minin[1][4];
int sum[1][5];
int minPrice = INT_MAX;
vector<vector<int>> v2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < 4; i++) {
        cin >> minin[0][i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    int total = 1 << N;

    for(int i = 1; i < total; i++) {
        memset(sum, 0, sizeof(sum));
        vector<int> v;
        bool check = true;
        for(int j = 0; j < N; j++) {
            if(i & (1<<j)) {
                for(int k = 0; k < 5; k++) {
                    sum[0][k] += arr[j][k];
                }
                v.push_back(j+1);
            }
        }
        for(int j = 0; j < 4; j++) {
            if(minin[0][j] > sum[0][j]) {
                check = false;
                break;
            }
        }
        if(check) {
            if(minPrice == sum[0][4]) {
                v2.push_back(v);
            } else if(minPrice > sum[0][4]) {
                minPrice = sum[0][4];
                v2.clear();
                v2.push_back(v);
            }
        } else {
            continue;
        }
    }

    sort(v2.begin(), v2.end());

    if(v2.empty()) {
        cout << -1 << "\n";
    } else {
        cout << minPrice << "\n";
        for(int x : v2[0]) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}