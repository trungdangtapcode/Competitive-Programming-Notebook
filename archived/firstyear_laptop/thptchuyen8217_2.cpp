#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5, mod = 1e9+7;
//bool p[maxN];
bitset<maxN> p;
long long prime[maxN/10], vlist[maxN/10], pref[maxN/10];
int nprime, t, l, r, pl, pr, prv[maxN], nxt[maxN];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 2; i <= 1e6; ++i) p[i] = 1;
	for (int i = 2; i*i <= 1e6; i = p._Find_next(i)){
		for (int j = i*i; j <= 1e6; j += i) p[j] = 0;
	}
	for (int i = 2; i <= 1e6; ++i) if (p[i]){
		++nprime;
		prime[nprime] = i;
		pref[nprime] = pref[nprime-1] + i;
		vlist[nprime] = vlist[nprime-1] + 1ll*nprime*i;
	} 
	for (int i = 1; i <= 1e6; i++) prv[i] = prv[i-1]+p[i];
	nxt[1000001] = prv[1000000]+1;
	for (int i = 1e6; i >= 0; i--) nxt[i] = nxt[i+1]-p[i];
	
	cin >> t;
	while (t--){
		cin >> l >> r;
		assert(l>0);
		pl = nxt[l];
		pr = prv[r];
		cout << (vlist[pr]-vlist[pl-1]-(pref[pr]-pref[pl-1])*(pl-1))%mod << "\n";
	}	
	
	return 0;
}
