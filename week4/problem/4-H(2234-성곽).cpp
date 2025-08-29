#include <bits/stdc++.h>
using namespace std;

// 2234: 벽 비트는 W(1), N(2), E(4), S(8)
int W[4] = {1, 2, 4, 8};
int dx[4] = {-1, 0, 1, 0}; // W, N, E, S
int dy[4] = {0, -1, 0, 1};

int N, M;                          // N: 행(세로), M: 열(가로)
int a[52][52];                     // 성 정보
int compId[52][52];                // 컴포넌트 라벨
vector<int> compSize;              // 각 컴포넌트 넓이 (index = compId)

int bfs(int sy, int sx, int id){
    queue<pair<int,int>> q;
    q.push({sy, sx});
    compId[sy][sx] = id;
    int cnt = 1;
    while(!q.empty()){
        auto [y, x] = q.front(); q.pop();
        for(int d=0; d<4; d++){
            // 벽이 있으면 못 감
            if(a[y][x] & W[d]) continue;
            int ny = y + dy[d], nx = x + dx[d];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(compId[ny][nx] != -1) continue;
            compId[ny][nx] = id;
            cnt++;
            q.push({ny, nx});
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력은 M(열) N(행) 순서!
    cin >> M >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> a[i][j];
        }
    }

    // 1) 방의 개수 & 2) 가장 넓은 방
    memset(compId, -1, sizeof(compId));
    int rooms = 0;
    int maxRoom = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(compId[i][j] == -1){
                int id = rooms;
                int sz = bfs(i, j, id);
                compSize.push_back(sz);
                rooms++;
                maxRoom = max(maxRoom, sz);
            }
        }
    }

    // 3) 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방
    // 인접한 서로 다른 컴포넌트를 벽 하나로 연결 가능한 경우의 합 최대
    int maxMerge = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int id1 = compId[i][j];
            for(int d=0; d<4; d++){
                int ny = i + dy[d], nx = j + dx[d];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                int id2 = compId[ny][nx];
                if(id1 == id2) continue; // 같은 방이면 합칠 필요 없음
                // 실제로 그 방향에 벽이 있을 때만 "허문다" 가정
                if(a[i][j] & W[d]){
                    maxMerge = max(maxMerge, compSize[id1] + compSize[id2]);
                }
            }
        }
    }

    cout << rooms << "\n" << maxRoom << "\n" << maxMerge << "\n";
    return 0;
}


/*
	•	입력 순서: M(열), N(행).
	•	이동 조건: if (a[y][x] & W[d]) continue; → 그 방향에 벽이 있으면 못 간다.
	•	한 번의 라벨링(BFS/DFS)으로 각 방 크기 구한 뒤, 벽 비트가 있는 인접 칸이 서로 다른 라벨이면 두 크기의 합으로 maxMerge 갱신.
*/