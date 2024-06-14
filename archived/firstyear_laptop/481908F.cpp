#include<bits/stdc++.h>

using namespace std;
const int maxQ = 1e5+5, maxN = 1e3+5;
int cnt = 1, n, m, q;
struct myq{
	int x, y, t, u;
} query[maxQ];
typedef pair<int,int> ii;
int res[maxQ];
vector<ii> edge[maxQ];
vector<int> ans[maxQ];
bitset<maxN> book[maxN], full;
int cur = 0;
void dfs(int u){
//	int cur = 0;
//	for (int i =0; i < n; i++) cout << book[i] << "\n";
//	cout << "\n";
//	for (int i = 0; i < n; i++) cur += (book[i]&full).count(); 
	for (int x: ans[u]) res[x] = cur;
	for (auto it: edge[u]){
		int v = it.first, idx = it.second;
		bool done = 0;
		int tmp = cur;
		if (query[idx].t==1){
			if (!book[query[idx].x-1][query[idx].y-1]) done = 1, cur++;
			book[query[idx].x-1][query[idx].y-1] = 1;
		} else if (query[idx].t==2){
			if (book[query[idx].x-1][query[idx].y-1]) done = 1, cur--;
			book[query[idx].x-1][query[idx].y-1] = 0;
		} else {
			done = 1;
			cur += m-2*book[query[idx].x-1].count();
			book[query[idx].x-1] ^= full;
		}
		dfs(v);
		if (!done) continue;
		cur = tmp;
		if (query[idx].t==1) book[query[idx].x-1][query[idx].y-1] = 0;
		else if (query[idx].t==2) book[query[idx].x-1][query[idx].y-1] = 1;
		else book[query[idx].x-1] ^= full;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	bitset<100> s(1);
//	cout << (s<<20|bitset<100>(1));
//	return 0;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++){
		bitset<maxN> s(1);
		full |= (s<<i);
	}
	query[0].u = 1;
	for (int i = 1, u = 1; i <= q; i++){
		cin >> query[i].t;
		if (query[i].t<=2) cin >> query[i].x >> query[i].y;
		else cin >> query[i].x;
		if (query[i].t==4){
			u = query[query[i].x].u;
		} else {
			edge[u].push_back({++cnt,i});
			u = cnt;
		}
		query[i].u = u;
		ans[u].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
	
	return 0;
}
