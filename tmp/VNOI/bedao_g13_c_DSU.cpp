#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
bool check[maxN];
int n, a[maxN], p[maxN];
struct node{
	int sum = 0, suff = 0, pref = 0, maxsum = -1e9;
	node operator+(node x){
		node res;
		res.sum = sum + x.sum;
		res.suff = max(suff+x.sum,x.suff);
		res.pref = max(pref,sum+x.pref);
		res.maxsum = max({maxsum,x.maxsum,suff+x.pref});
		return res;
	}
} val[maxN];
int cha[maxN];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
void hop(int u, int v){
	if (u>v) swap(u,v);
	u = timcha(u), v = timcha(v);
	if (u==v) return;
	val[u] = val[u] + val[v];
	cha[v] = u;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cha[i] = i;
		cin >> a[i];
		val[i].sum = val[i].suff = val[i].pref = val[i].maxsum = a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	vector<int> res;
	for (int i = n, cur = -1e18; i > 0; i--){
		check[p[i]] = true;
		if (check[p[i]-1]) hop(p[i]-1,p[i]);
		if (check[p[i]+1]) hop(p[i]+1,p[i]);
		cur = max(cur,val[timcha(p[i])].maxsum);
		res.push_back(cur);
	}	
	reverse(res.begin(),res.end());
	for (int x: res) cout << x << "\n";
	return 0;
}
