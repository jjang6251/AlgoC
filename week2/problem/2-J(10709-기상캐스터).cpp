#include<bits/stdc++.h>
using namespace std;

int h, w;
char a[100][100];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < h; i++) {
        int prev = 0;
        for(int j = 0; j < w; j++) {
            if(a[i][j] == 'c') {
                cout << "0 "; 
                prev = 1;
            }
            if(prev >= 1 && a[i][j] == '.') {
                cout << prev << ' ';
                prev++;
            }
            if(prev == 0) {
                cout << "-1 "; 
            }
        }
        cout << '\n';
    }

    return 0;
}