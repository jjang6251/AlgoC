#include<bits/stdc++.h>
using namespace std; 
int n, a, b, ret; 
vector<pair<int, int>> v; 
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> a >> b; v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){ 
        pq.push(v[i].second);
        if(pq.size() > v[i].first){ 
            pq.pop();
        } 
    } 
    while(pq.size()){
    	ret += pq.top(); pq.pop();
	}
    cout << ret << "\n";
}