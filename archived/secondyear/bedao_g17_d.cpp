#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
int memo[60][2][2], phi;
long long l, r;
int f(int pos, bool greater, bool smaller){
	if (pos==-1){
		return 1;
	}
	int &res = memo[pos][greater][smaller];
	if (res!=-1) return res;
	res = 0;
	for (int i = 0; i < 2; i++){
		int bl = l>>pos&1, br = r>>pos&1;
		if (!smaller&&i>br) continue;
		if (!greater&&i<bl) continue;
		int x = f(pos-1,greater||i>bl,smaller||i<br)*(i==0?1:2);
		if (x>=mod) x -= mod;
		res += x;
//		if (pos==3) cout << res << ".\n;
		if (res>=mod) res -= mod;
	}
	return res;
}
int g(long long n){
	n %= mod;
	return 1ll*(n+1)*(n+2)/2%mod;
}

void solve(){
	cin >> l >> r;
	memset(memo, -1, sizeof(memo));	
	int res =  f(59,0,0);
	if (phi==0){
		int total = (g(r)-g(l-1)-res)%mod+mod;
		total %= mod;
		cout << total << "\n";
	} else {
		cout << res << "\n";
	}
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t >> phi;
	while (t--)
	solve();
}

