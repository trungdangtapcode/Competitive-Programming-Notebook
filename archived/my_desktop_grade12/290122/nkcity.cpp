#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edgelist;
int n, m, cha[100005], res;
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edgelist.push_back({c,{u,v}});
	}
	sort(edgelist.begin(),edgelist.end());
	for (auto it: edgelist){
		int u = it.second.first, v = it.second.second, c= it.first;
		res = max(res,(hop(u,v))*c);
	}
	cout << res;
	
	return 0;
}
