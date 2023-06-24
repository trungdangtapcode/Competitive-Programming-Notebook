#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
ii edgelist[100005];
int res[100005], query[100005], edgeInQuery[100005], cha[100005], n, m, q;

int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 1; i <= m; i++) cin >> edgelist[i].first >> edgelist[i].second;
	for (int i = 1; i <= q; i++){
		cin >> query[i];
		edgeInQuery[query[i]] = i;
	}
	
	int cur = n;
	for (int i = 1; i <= m; i++) if (edgeInQuery[i]==0) cur -= hop(edgelist[i].first,edgelist[i].second);
	
	for (int i = q; i > 0; i--){
		res[i] = cur;
		cur -= hop(edgelist[query[i]].first,edgelist[query[i]].second);
	}
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
	
	return 0;
}
