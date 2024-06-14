#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 8e5+5, mod = 1e9+9, base = 7;
string s, s0;
int n, h[maxN], p[maxN], f[maxN], hr[maxN];
int qhash(int i, int j){
	int l = j-i+1;
	return ((h[j]-h[i-1]*p[l])%mod+mod)%mod;
}
int qhashr(int i, int j){
	int l = j-i+1;
	return ((hr[i]-hr[j+1]*p[l])%mod+mod)%mod;
}
void solve(){
	cin >> n >> s0;
	s.clear();
	s.push_back('3');
	for (int i = 1; i <= n; i++){
		s.push_back(s0[i-1]);
		s.push_back('3');
	}
	n = 2*n + 1;
	s = "@" + s;
	p[0] = 1;
	h[0] = h[n+1] = 0;
	for (int i = 1; i <= n; i++){
		p[i] = (p[i-1]*base)%mod;
		h[i] = (h[i-1]*base + s[i] - '0' + 1)%mod;
	}
	for (int i = n; i > 0; i--){
		hr[i] = (hr[i+1]*base + s[i] - '0' + 1)%mod;
	}
//	cout << s << "\n";
	
//	cout << qhash(1,2) << " " << qhashr(2,3) << "\n";
//	return 0;
	for (int i = 1; i <= n; i++){
		f[i] = 0;
		int l = 0, h = min(i-1,n-i), m;
//		cout << l << ".." << h << "\n";
		while (l<=h){
			m = (l+h)/2;
//			cout << m << " " << i-m << "," << i << "="<< qhash(i-m,i) << " " << i <<"," <<i+m<< "="<<qhash(i,i+m) << "\n";
			if (qhash(i-m,i)==qhashr(i,i+m)){
				f[i] = m;
				l = m+1;
			} else {
				h = m-1;
			}
		}
		if (i%2==0){
			f[i] = f[i];
		} else {
			f[i] = f[i];
		}
//		cout << f[i] << " ";
	}
//	cout << "\n";
	int res = 0;
	for (int i = 3; i <= n; i++){
		int cur = min(f[i],f[i-2]+2);
		if (cur>=3){
			res += ((cur-1)/2);
		}
//		if (cur>=3) cout << i << ". " << cur << "\n";
	}
	cout << res << "\n";
//	cout << qhash(1,2) << ' ' << qhash(4,5);
	
}

main(){
//	solve();
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
