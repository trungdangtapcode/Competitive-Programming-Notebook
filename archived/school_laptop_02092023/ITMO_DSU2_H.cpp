#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<long long,int> li;
vector<pair<li,ii>> edgelist;
int n, cha[50005], m;
long long int s;
int timcha(int x){
	return cha[x] = (cha[x]==x?x:timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 0, u, v; i < m; i++){
		long long c;
		cin >> u >> v >> c;
		edgelist.push_back({{c,i},{u,v}});
	}
	sort(edgelist.begin(),edgelist.end());
	vector<li> vec;
	vector<int> res;
	for (int i = m-1; i >= 0; i--){
		int u = edgelist[i].second.first, v = edgelist[i].second.second, pos = edgelist[i].first.second;
		long long c = edgelist[i].first.first;
		if (!hop(u,v)) vec.push_back({c,pos});
	}
	sort(vec.begin(),vec.end());
	for (auto it: vec){
		long long c = it.first;
		int pos = it.second;
		if (s>=c){
			res.push_back(pos);
			s-=c;
		} else break;
	}
	
	sort(res.begin(),res.end());
	cout << res.size() << "\n";
	for (auto pos: res) cout << pos+1 << " ";
	
	return 0;
}
