#include<bits/stdc++.h>

using namespace std;
int n, cha[200005], m, u, v, sz[200005], added[200005], inq[200005];
vector<int> s[200005];
string q;

int timcha(int x){
	if (cha[x]==x) return x;
	else return cha[x] = timcha(cha[x]);
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	if (sz[pu]>sz[pv]) swap(pu,pv);
	cha[pu] = pv;
	sz[pv] += sz[pu];
	while (!s[pu].empty()){
		int x = s[pu].back(); s[pu].pop_back();
		s[pv].push_back(x);
		added[x] += inq[pu]-inq[pv]; 
	}
}
void them(int x, int val){
	int px = timcha(x);
	inq[px] += val;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cha[i] = i, sz[i] = 1, s[i].push_back(i);
	while (m--){
		cin >> q >> u;
		if (q=="join"){
			cin >> v;
			hop(u,v);
		} else if (q=="add"){
			cin >> v;
			them(u,v);
		} else {
			cout << added[u]+inq[timcha(u)] << "\n";
		}
	}
	return 0;
}
