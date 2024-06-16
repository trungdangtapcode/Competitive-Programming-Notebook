#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxN = 2e6+6, mod1 = 1e9+7, mod2 = 1e9+9;
int val[maxN*8], a[maxN*2], n;
int hash1[maxN*2], pow3[maxN*2], hash2[maxN*2], pow5[maxN*2];
string s;
//int pi[maxN*3];
void build(int k, int l, int r){
	if (l>r) return;
	if (l==r){
		val[k] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = min(val[2*k],val[2*k+1]);
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 1e9;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return min(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}
int gHash1(int i, int j){
	return (hash1[j]-1ll*hash1[i-1]*pow3[j-i+1]%mod1+mod1)%mod1;
}
int gHash2(int i, int j){
	return (hash2[j]-1ll*hash2[i-1]*pow5[j-i+1]%mod2+mod2)%mod2;
}
void solve(){
	cin >> n >> s;
//	string t = s + "$" + s + s;
	s = " " + s;
//	for (int i = 1; i < t.length(); i++) {
//        int j = pi[i-1];
//        while (j > 0 && t[i] != t[j])
//            j = pi[j-1];
//        if (t[i] == t[j])
//            j++;
//        pi[i] = j;
//    }
//    for (int i = 0; i < t.length(); i++){
//    	cout << t[i] << ", " << pi[i] << "\n";
//	}
	pow3[0] = 1;
	pow5[0] = 1;
	for (int i = 1; i <= 2*n; i++){
		a[i] = a[i-1] + (s[(i-1)%n+1]=='('?1:-1);
		hash1[i] = (1ll*hash1[i-1]*3 + (s[(i-1)%n+1]=='('?1:2))%mod1;
		hash2[i] = (1ll*hash2[i-1]*5 + (s[(i-1)%n+1]=='('?1:2))%mod2;
		pow3[i] = 1ll*pow3[i-1]*3%mod1;
		pow5[i] = 1ll*pow5[i-1]*5%mod2;
//		cout << a[i] << " ";
	}
//	cout << gHash(4,5);
//	cout << "\n";
	build(1,1,2*n);
	int res = 0;
//	unordered_set<int> s1, s2;
	unordered_set<ll> st;
	for (int i = 1; i <= n; i++){
		int j = i+n-1;
//		cout << i << " -> " << j << "\n";
//		if (s1.count(gHash1(i,j)) and s2.count(gHash2(i,j))) continue;
//		s1.insert(gHash1(i,j));
//		s2.insert(gHash2(i,j));
		ll x = 1ll*gHash1(i,j)*mod2+gHash2(i,j);
		if (st.count(x)) continue;
		st.insert(x);
		if (a[j]!=a[i-1]) continue;
		if (gett(1,1,2*n,i,j)<a[i-1]) continue;
//		cout << i << " " << gett(1,1,2*n,i,j) << " " << i << ".." << j << "\n";
		res++;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}

