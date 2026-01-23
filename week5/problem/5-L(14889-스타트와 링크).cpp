#include <bits/stdc++.h>
using namespace std;

int n, a[30][30];
int ret = INT_MAX;
bool inStart[30];

void calmin(const vector<int>& startTeam) {
    vector<int> linkTeam;
    linkTeam.reserve(n/2);

    // inStart 초기화
    fill(inStart, inStart + n, false);
    for (int x : startTeam) inStart[x] = true;

    // link 팀 구성
    for (int i = 0; i < n; i++) {
        if (!inStart[i]) linkTeam.push_back(i);
    }

    int sumS = 0, sumL = 0;

    // 스타트 팀 시너지
    for (int i = 0; i < (int)startTeam.size(); i++) {
        for (int j = i + 1; j < (int)startTeam.size(); j++) {
            int x = startTeam[i], y = startTeam[j];
            sumS += a[x][y] + a[y][x];
        }
    }

    // 링크 팀 시너지
    for (int i = 0; i < (int)linkTeam.size(); i++) {
        for (int j = i + 1; j < (int)linkTeam.size(); j++) {
            int x = linkTeam[i], y = linkTeam[j];
            sumL += a[x][y] + a[y][x];
        }
    }

    ret = min(ret, abs(sumS - sumL));
}

void combi(int idx, vector<int>& startTeam) {
    if ((int)startTeam.size() == n/2) {
        calmin(startTeam);
        return;
    }
    if (idx == n) return;

    // 가지치기: 남은 사람 다 넣어도 n/2 못 채우면 종료
    if ((int)startTeam.size() + (n - idx) < n/2) return;

    // idx 선택
    startTeam.push_back(idx);
    combi(idx + 1, startTeam);
    startTeam.pop_back();

    // idx 미선택
    combi(idx + 1, startTeam);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> startTeam;
    // 중복 제거: 0번은 무조건 스타트팀에 넣고 시작
    startTeam.push_back(0);
    combi(1, startTeam);

    cout << ret << "\n";
    return 0;
}