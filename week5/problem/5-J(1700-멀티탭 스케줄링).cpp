#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int k, n, a[104], visited[104], cnt;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> a[i];
    for(int i = 0; i < k; i++) {
        if(!visited[a[i]]) {
            //방문한 기록이 없는 기기라면
            //배열이 멀티탭 개수만큼이면 삭제
            if(v.size() == n) {
                int last_idx = 0, pos;
                for(int _a : v) {
                    int here_pick = INF;
                    for(int j = i+1; j < k; j++) {
                        if(_a == a[j]) {
                            here_pick = j; break;
                        }
                    }
                    if(last_idx < here_pick) {
                        last_idx = here_pick;
                        pos = _a; 
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            //추가해
            v.push_back(a[i]); visited[a[i]] = 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}