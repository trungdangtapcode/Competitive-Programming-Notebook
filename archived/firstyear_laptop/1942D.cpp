#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 5e3+5;
priority_queue<int> pq[maxN];
int n, a[maxN][maxN], k;
void print(priority_queue<int> pq){
	while (pq.size()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << "\n";
}
void solve(){
	cin >> n >> k;
	for (int i = 0; i <= n+1; i++) while(pq[i].size()) pq[i].pop();
	for (int i = 2; i <= n+1; i++){
		for (int j = i; j <= n+1; j++) cin >> a[i][j];
	}
	pq[0].push(0);
	pq[1].push(0);
	for (int i = 2; i <= n+1; i++){
//		cout << i << ": \n";
		priority_queue<ii> cur;
		vector<ii> vec;
		for (int j = 0; j < i; j++){
			cur.push({pq[j].top()+a[j+2][i],j});			
		}
		for (int j = 0; j < k && cur.size(); j++){
			pq[i].push(cur.top().first);
			vec.push_back(cur.top());
			int idx = cur.top().second;
//			cout << cur.top().first << " by " << idx << "\n";
			cur.pop();
			pq[idx].pop();
			if (pq[idx].empty()) continue;
			cur.push({pq[idx].top()+a[idx+2][i],idx});
		}
		for (auto it: vec){
			pq[it.second].push(it.first-a[it.second+2][i]);
		}
//		cout << " " << pq[i].size() << "\n";
//		cout << " "; print(pq[i]);
	}
	print(pq[n+1]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

