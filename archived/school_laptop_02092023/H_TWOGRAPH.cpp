#include<bits/stdc++.h>

using namespace std;

struct dsu{
	int cha[100005], tplt;
	dsu(int n){
		tplt = n;
		for (int i = 1; i <= n; i++) cha[i] = i;
	}
	int timcha(int x){
		return (cha[x]==x?x:cha[x]=timcha(cha[x]));
	}
	bool hop(int u, int v){
		int pu = timcha(u), pv = timcha(v);
		if (pu==pv) return false;
		cha[pu] = pv;
		tplt--;
		return true;
	}
};
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edge;
int n1, n2, m1, m2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n1 >> m1;
	for (int i = 0, u, v, c; i < m1; i++){
		cin >> u >> v >> c;
		edge.push_back({c,{u,v}});
	}
	cin >> n2 >> m2;
	for (int i = 0, u, v, c; i < m2; i++){
		cin >> u >> v >> c;
		edge.push_back({c,{-u,-v}});
	}
	sort(edge.begin(),edge.end());
	dsu dsu1 = dsu(n1), dsu2 = dsu(n2);
	long long res = 0;
	for (auto it: edge){
		int u = it.second.first, v = it.second.second, c = it.first;
		if (u>=0){
			if (dsu1.hop(u,v)) res += 1ll*c*dsu2.tplt;
		} else {
			if (dsu2.hop(-u,-v)) res += 1ll*c*dsu1.tplt;
		}
	}
	cout << res;
	
	
	return 0;
}
