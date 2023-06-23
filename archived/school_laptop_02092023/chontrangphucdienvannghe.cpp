#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
priority_queue<iii,vector<iii>,greater<iii>> segment;
priority_queue<ii,vector<ii>,greater<ii>> pq;
vector<ii> b;
int n, m, x, y;
int main(){
	cin >> n >> m >> x >> y;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		segment.push({{a-x,a+y},i});
	}
	for (int i = 1, x; i <= m; i++){
		cin >> x;
		b.push_back({x,i});
	}
	sort(b.begin(),b.end());
	vector<ii> res;
//	while (segment.size()){
//		auto it = segment.top(); segment.pop();
//		cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
//	}
	for (auto it: b){
		int x = it.first, idx = it.second;
		while (!segment.empty()&&segment.top().first.first<=x) pq.push({segment.top().first.second,segment.top().second}), segment.pop();
		while (!pq.empty()&&pq.top().first<x) pq.pop(); 
		if (pq.size()){
			res.push_back({pq.top().second,idx});
			pq.pop();
		}
	}
//	sort(res.begin(),res.end());
	cout << res.size() << "\n";
	for (auto it: res) cout << it.first << " " << it.second << "\n";
	return 0;
}
