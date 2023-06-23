#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
#define int long long

gp_hash_table<int, bool> m;
int pow31[1000005], l, r, g, hashT[1000005];
string w[1000005], t;
const int MOD = (1ll<<53)-1;

inline int mul(int x, int y){
	x%=MOD, y%=MOD;
	int res = 0;
	while (y){
		if (y&1) res = (res+x);
		if (res>=MOD) res -= MOD;
		x = (x<<1);
		if (x>=MOD) x -= MOD;
		y = (y>>1);
	}
	return res;
}

int getHash(int i, int j){
	return (hashT[j]-mul(hashT[i-1],pow31[j-i+1])+30*MOD)%MOD;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	pow31[0] = 1;
	for (int i = 1; i <= 1e6; i++) pow31[i] = pow31[i-1]*31%MOD;
	cin >> l >> r;
	g = 0;
	for (int i = 0; i < l; i++){
		cin >> w[i];
		g = __gcd(g,(int)w[i].length());
	}
	for (int i = 0, x; i < r; i++){
		cin >> x;
		g = __gcd(g,x);
	}
	for (int i = 0; i < l; i++){
		int tmp = 0;
		for (int j = 0; j < w[i].length(); j++){
			tmp = (31*tmp + w[i][j] - 'a' + 2)%MOD;
			if ((j+1)%g==0)m[tmp] = 1;
		}
	}
	int q; cin >> q;
	while (q--){
		cin >> t;
		int n = t.length();
		t = "#" + t;
		for (int i = 1; i <= n; i++){
			hashT[i] = (hashT[i-1]*31+t[i] - 'a' + 2)%MOD;
		}
		bool res = false;
		for (int i = n, j = n; i > 0; i--, j--){
			while (i>1&&(!m[getHash(i,j)]||(j-i+1)%g)) i--;
//			cout << i << " " << j << endl;
			if (m[getHash(i,j)]&&(j-i+1)%g==0){
				j = i;
				if (j==1){
					res = true;
					break;
				}
			}
		}
		cout << (res?"Yes\n":"No\n");	
	}
	return 0;
}
