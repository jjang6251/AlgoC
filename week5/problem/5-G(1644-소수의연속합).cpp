#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false, isPrime[1] = true;

    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) primes.push_back(i);
    }

    int start = 0; int end = 0;
    int sum = 0, cnt = 0;

    while(true) {
        if(sum >= n) {
            sum -= primes[start++];
        }
        else {
            if(end == primes.size()) break;
            sum += primes[end++];
        }
        if(sum == n) cnt++;
    }
    cout << cnt << "\n";
}