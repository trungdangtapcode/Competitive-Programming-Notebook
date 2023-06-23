#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<char,ii> cii;
cii query[200005];
vector<iii> offln[200005];
int cha[200005], n, q, s, u, v;
bool res[200005];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	cha[pu] = pv;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 0; i < q; i++){
		cin >> query[i].first;
		if (query[i].first=='Q'){
			cin >> s >> u >> v;
			offln[s].push_back({i,{u,v}});
		} else if (query[i].first!='C') cin >> query[i].second.first >> query[i].second.second;
	}	
	for (auto it: offln[0]) res[it.first] = timcha(it.second.first)==timcha(it.second.second);
	for (int i = 0, c = 0; i < q; i++){
		if (query[i].first=='A') hop(query[i].second.first,query[i].second.second);
		if (query[i].first=='?') res[i] = timcha(query[i].second.first)==timcha(query[i].second.second);
		if (query[i].first=='C'){
			c++;
			for (auto it: offln[c]) res[it.first] = timcha(it.second.first)==timcha(it.second.second);
		}
	}
	for (int i = 0; i < q; i++) if (query[i].first=='?'||query[i].first=='Q') cout << (res[i]?"Y":"N");
	
	return 0;
}
