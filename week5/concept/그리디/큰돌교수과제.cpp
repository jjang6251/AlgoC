#include<bits/stdc++.h>
using namespace std;
int n;
double temp;
priority_queue<double> pq;
vector<double> v;
int main() {
    scanf("%lf", &temp);
    if(pq.size() == 5) {
        pq.push(temp); pq.pop();
    } else pq.push(temp);
    while(pq.size()) {
        v.push_back(pq.top()); pq.pop();
    }
    reverse(v.begin(), v.end());
    for(double i : v) printf("%.2lf\n", i);
    return 0;
}