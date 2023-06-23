#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m, cha[200005], sz[200005], hand[200005][3], res[200005];
vector<int> s[200005];
vector<ii> query;
int timcha(int x){
	if (cha[x]==x) return x;
	return cha[x] = timcha(cha[x]);
}
void hop(int u, int v, int time){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	if (sz[pu]>sz[pv]) swap(pu,pv);
	if (pu==1) swap(pu,pv);
	if (pv==1){
		while (!s[pu].empty()) res[s[pu].back()] = time, s[pu].pop_back();
	}
	cha[pu] = pv;
	sz[pv] += sz[pu];
	while (!s[pu].empty()) s[pv].push_back(s[pu].back()), s[pu].pop_back();
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cha[i] = i, sz[i] = 1, s[i].push_back(i);
	for (int i = 1; i <= n; i++){
		cin >> hand[i][1] >> hand[i][2];
	}
	query.assign(m,{0,0});
	for (int i = 0, u, x; i < m; i++){
		cin >> u >> x;
		query[i].first = u;
		query[i].second = hand[u][x];
		hand[u][x] = -1;
	}
	for (int i = 1; i <= n; i++){
		if (hand[i][1]!=-1) hop(i,hand[i][1],-1);
		if (hand[i][2]!=-1) hop(i,hand[i][2],-1);
	}
	for (int i = m-1; i >= 0; i--){
		int u = query[i].first, v = query[i].second;
		hop(u,v,i);
	}
//	cout << "hi";
	res[1] = -1;
	for (int i = 1; i <= n; i++) cout << res[i] << "\n";
	return 0;
}
