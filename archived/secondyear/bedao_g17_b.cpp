#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
void solve(){
	int n = 1e6;
	unordered_map<long long,ii> mp;
	for (int i = 2; i <= n; i++){
		long long p = i, s = 1+i;
		int d = 1;
		while (p<=1e18/i){
			p *= i;
			s += p;
			d++;
			if (!mp.count(s)) mp[s] = {i,d};
			if (s>1e18) break;
		}
	}
	int t; cin >> t;
	while (t--){
		long long n;
		cin >> n;
		if (n==1){
			cout << -1 << "\n";
			continue;
		}
		if (mp.count(n)){
			auto it = mp[n];
			cout << it.first << " " << it.second << "\n";
			continue;
		}
		long double d = 1-4*(1-n);
		if (d>=0){
			d = sqrtl(d);
			if (abs(d-round(d))<1e-9){
				if ((-1+(long long)round(d))%2==0){
					cout << (-1+(long long)round(d))/2 << " " << 2 << "\n";
					continue;
				}
			}
		}
		cout << "-1\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

