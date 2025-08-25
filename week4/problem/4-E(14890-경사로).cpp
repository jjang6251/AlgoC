#include <bits/stdc++.h>
using namespace std;

int n, L;
int a[102][102];

bool check(const vector<int>& line, int L){
    int n = (int)line.size();
    vector<int> used(n, 0); // 경사로 중복 방지

    for(int i = 0; i < n - 1; i++){
        int cur = line[i], nxt = line[i + 1];
        if(cur == nxt) continue;

        if(nxt == cur + 1){ 
            // 오르막: i, i-1, ..., i-(L-1) 가 모두 cur 여야 함
            for(int k = 0; k < L; k++){
                int idx = i - k;
                if(idx < 0) return false;
                if(line[idx] != cur) return false;
                if(used[idx]) return false;
                used[idx] = 1;
            }
        }else if(nxt == cur - 1){
            // 내리막: i+1, i+2, ..., i+L 가 모두 nxt 여야 함
            for(int k = 1; k <= L; k++){
                int idx = i + k;
                if(idx >= n) return false;
                if(line[idx] != nxt) return false;
                if(used[idx]) return false;
                used[idx] = 1;
            }
        }else{
            return false; // 높이 차 2 이상은 불가
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int ret = 0;

    // 행 검사
    for(int i = 0; i < n; i++){
        vector<int> row(n);
        for(int j = 0; j < n; j++) row[j] = a[i][j];
        if(check(row, L)) ret++;
    }

    // 열 검사
    for(int j = 0; j < n; j++){
        vector<int> col(n);
        for(int i = 0; i < n; i++) col[i] = a[i][j];
        if(check(col, L)) ret++;
    }

    cout << ret << "\n";
    return 0;
}