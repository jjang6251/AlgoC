//{0, 0}좌표에서 dy, dx를 만들어 8방향(위, 오른쪽, 아래, 왼쪽 및 대각선방향포함)을 탐색하며 좌표를 출력하시오.
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
    int y = 0, x = 0;

    for(int i = 0; i<8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << ny << " : " << nx << '\n';
    }
    return 0;
}