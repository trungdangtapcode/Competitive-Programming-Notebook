#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5, mod = 1e9+7;
bool p[maxN];
vector<int> prime, vlist, pref;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 2; i <= 1e6; i++) p[i] = 1;
	for (int i = 2; i*i <= 1e6; i++){
		for (int j = i*i; j <= 1e6; j += i) p[j] = 0;
	}
	vlist.push_back(0);
	prime.push_back(0);
	for (int i = 2; i <= 1e6; i++) if (p[i]) prime.push_back(i), vlist.push_back(((vlist.empty()?0:vlist.back())+1ll*vlist.size()*i%mod)%mod);
	for (int x: prime) pref.push_back(((pref.empty()?0:pref.back())+x)%mod);
	int t; cin >> t;
	while (t--){
		int l, r;
		cin >> l >> r;
		int pl = lower_bound(prime.begin(),prime.end(),l)-prime.begin();
		int pr = upper_bound(prime.begin(),prime.end(),r)-prime.begin()-1;
		cout << ((vlist[pr]-vlist[pl-1]-1ll*(pref[pr]-pref[pl-1])*(pl-1)%mod)%mod+mod)%mod << "\n";
	}	
	
	return 0;
}
