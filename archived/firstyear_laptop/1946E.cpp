#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5, mod = 1e9+7;
int n, a[maxN], fact[maxN], inv[maxN], m1, m2, f[maxN];
int nCr(int n, int r){
	if (r>n||r<0) return 0;
	return 1ll*fact[n]*inv[r]%mod*inv[n-r]%mod;
}
set<int> intersection(set<int> s1, set<int> s2){
	set<int> res;
	for (int i: s1) if (s2.find(i)!=s2.end()) res.insert(i);
	return res;
}
void solve(){
	cin >> n >> m1 >> m2; 
	fact[0] = 1, inv[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++) fact[i] = 1ll*i*fact[i-1]%mod;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*inv[i]*inv[i-1]%mod;
//	set<int> s1, s2;
	vector<int> s1, s2;
	for (int i = 1, x; i <= m1; i++){
		cin >> x;
//		s1.insert(x);
		s1.push_back(x);
	}
	for (int i = 1, x; i <= m2; i++){
		cin >> x;
//		s2.insert(x);
		s2.push_back(x);
	}
	if (s1[m1-1]!=s2[0]||s1[0]!=1||s2[m2-1]!=n){
		cout << 0 << "\n";
		return;
	}
	int f = 1, g = 1, t = nCr(n-1,s2[0]-1);
	for (int i = 1; i < m1; i++){
		f = 1ll*f*nCr(s1[i]-2,s1[i]-s1[i-1]-1)%mod*fact[s1[i]-s1[i-1]-1]%mod;
	}
	for (int i = 0; i < m2; i++) s2[i] = n-s2[i]+1;
	reverse(s2.begin(),s2.end());
	for (int i = 1; i < m2; i++){
		g = 1ll*g*nCr(s2[i]-2,s2[i]-s2[i-1]-1)%mod*fact[s2[i]-s2[i-1]-1]%mod;
	}
	
	cout << 1ll*f*g%mod*t%mod << "\n";

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

	/* NHAM DE :D
	auto si = intersection(s1,s2);
	if (si.size()>=2){
		cout << 0 << "\n";
		return;
	}
	if (si.size()==0){
		cout << 1ll*nCr(n,m1)*nCr(n-m1,m2)%mod*fact[n-m1-m2]%mod << "\n";
		return;
	}
	int x = *si.begin(), im = 0, dm = 0;
	for (int i: s1) im += (i<x);
	for (int i: s2) dm += (i>x);
	int ib = m1-im-1, db = m2-dm-1;
	cout << 1ll*nCr(n,m1+m2-1)*nCr(im+dm,im)%mod*nCr(ib+db,ib)%mod*fact[n-m1-m2+1]%mod << "\n";
	*/
//	if (*s1.rbegin()>*s2.begin()){ permutation === swap ccbm
//		cout << 0 << "\n";
//		return;
//	}
//	bool eq =(*s1.rbegin()==*s2.begin());
//	f[0] = 1;
//	for (int i = 1, e = *s1.rbegin(), last = 1; i <= e; i++){
//		while (s1.size()&&*s1.begin()<=i) last = *s1.begin(), s1.erase(s1.begin());
//		f[i] = (i-last+1)*f[i-1];
//	}
//	f[n+1] = 1;
//	for (int i = n, e = *s2.begin(), last = n; i >= e; i--){
//		while (s2.size()&&*s2.rbegin()>=i) last = *s2.rbegin(), s2.erase(*s2.rbegin());
//		f[i] = (last-i+1)*f[i+1];
//	}

//	int f = 1, last = 0;
//	for (int i: s1){
//		int d = i-last-1;
//		f = 1ll*f*nCr(i-1,d)%mod*fact[d]%mod;
//		last = i;
//	}
//	int g = 1;
//	last = n+1;
//	reverse(s2.begin(),s2.end());
//	for (int i: s2){
//		int d = last-i-1;
//		g = 1ll*g*nCr(n-i,d)%mod*fact[d]%mod;
//		last = i;
//		cout << g << "\n";
//	}
//	cout << f << " " << g << "\n";

//	res = 1ll*nCr(n-s2[0]+1-m2,n-s2[m2-1])*fact[s2[m2-1]-s2[0]+1-m2]%mod*res%mod;
//	res = 1ll*res*nCr(n-1,s2[0]-1)%mod;
//	cout << res << "\n"; 
