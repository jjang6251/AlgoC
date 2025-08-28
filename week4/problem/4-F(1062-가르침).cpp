#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> words;
int baseMask;              // 'a','n','t','i','c'
vector<int> cand;          // 배울 후보 알파벳 인덱스
int need;                  // 추가로 배워야 할 개수 (K-5)
int bestAns = 0;

int countReadable(int learnedMask) {
    int cnt = 0;
    for (int w : words) {
        if ((w & ~learnedMask) == 0) cnt++;  // w가 learnedMask의 부분집합이면 읽기 가능
    }
    return cnt;
}

void dfs(int idx, int learnedMask, int taken) {
    if (taken == need) {
        bestAns = max(bestAns, countReadable(learnedMask));
        return;
    }
    if (idx == (int)cand.size()) {
        // 더 고를 후보가 없음
        bestAns = max(bestAns, countReadable(learnedMask));
        return;
    }

    // 가지치기: 남은 후보를 전부 다 골라도 need를 못 채우면 중단
    if (taken + ((int)cand.size() - idx) < need) return;

    // 1) cand[idx]를 배운다
    dfs(idx + 1, learnedMask | (1 << cand[idx]), taken + 1);
    // 2) cand[idx]를 배우지 않는다
    dfs(idx + 1, learnedMask, taken);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<string> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    if (K < 5) { cout << 0 << "\n"; return 0; }
    if (K == 26) { cout << N << "\n"; return 0; }

    // 기본 5글자: a n t i c
    baseMask = 0;
    for (char c : string("antic")) baseMask |= (1 << (c - 'a'));

    // 각 단어를 비트마스크로 변환
    words.reserve(N);
    vector<int> appear(26, 0);
    for (auto &s : arr) {
        int m = 0;
        for (char c : s) {
            m |= (1 << (c - 'a'));
        }
        words.push_back(m);
        // 후보 알파벳 등장 체크 (기본 5글자는 제외)
        int only = m & ~baseMask;
        for (int b = 0; b < 26; ++b) {
            if (only & (1 << b)) appear[b] = 1;
        }
    }

    // 후보 목록 구성
    cand.clear();
    for (int b = 0; b < 26; ++b) {
        if (!(baseMask & (1 << b)) && appear[b]) cand.push_back(b);
    }

    need = K - 5;

    // 후보 수가 need보다 작으면 전부 배우고 끝
    if ((int)cand.size() <= need) {
        cout << countReadable(baseMask | [&]{
            int m = 0; for (int b : cand) m |= (1 << b); return m;
        }()) << "\n";
        return 0;
    }

    // DFS로 조합 탐색
    dfs(0, baseMask, 0);
    cout << bestAns << "\n";
    return 0;
}