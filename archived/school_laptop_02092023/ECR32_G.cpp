#include<bits/stdc++.h>

using namespace std;

int to[32*200005][2], nTrie;
struct Trie{
	int root ;
	Trie(){
		root = ++nTrie;
	}
	void push(int x){
		int u = root;
		for (int i = 30; i >= 0; i--){
			bool c = x>>i&1;
			if (to[u][c]==0) to[u][c] = ++nTrie;
			u = to[u][c];
		}
	}
	int query(int k, int x){
		int u = root, res = 0;
		for (int i = 30; i >= 0; i--){
			bool c = x>>i&1;
			if (i>k){
				if (to[u][c]) res = res*2+(c), u = to[u][c];
				else return -1;
			} else if (i==k){
				if (to[u][!c]) res = res*2+(!c), u = to[u][!c];
				else return -1;
			} else {
				if (to[u][c]) res = res*2+(c), u = to[u][c];
				else if (to[u][!c]) res = res*2+(!c), u = to[u][!c];
				else return -1;
			} 
		}
		return res;
	}
};
int cha[200005];
struct DSU{
	int n;
	DSU(int n){
		this->n = n;
		for (int i = 1; i <= n; i++) cha[i] = i;
	}
	int timcha(int x){
		return (cha[x]==x?x:cha[x]=timcha(cha[x]));
	}
	bool hop(int u, int v){
		u = timcha(u), v = timcha(v);
		if (u==v) return false;
		cha[u] = v;
		return true;
	}
};

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edgelist;
int n, a[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;	
	DSU s(n);
	Trie t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	map<int,int> mp;
	for (int i = 1; i <= n; i++) {
		mp[a[i]] = mp.size();
		for (int k = 0; k < 30; k++){
			int x = t.query(k,a[i]);
			if (x==-1) continue;
			edgelist.push_back({x^a[i],{mp[x],mp[a[i]]}});
		}
		t.push(a[i]);
	}
	sort(edgelist.begin(),edgelist.end());
	long long res = 0;
	for (auto it: edgelist){
		int c = it.first, u = it.second.first, v = it.second.second;
		if (s.hop(u,v)) res += c;
	}
	cout << res;
	
	
	
	return 0;
}
