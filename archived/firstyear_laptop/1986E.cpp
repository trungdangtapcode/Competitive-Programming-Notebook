#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], k;
int calc(vector<int>& v){
	sort(v.begin(),v.end());
	int n = v.size();
	if (n==1){
		return 0;
	}
	vector<int> f(n);
	for (int i = 1; i < n; i+=2) f[i] = (i==1?0:f[i-2])+v[i]-v[i-1];
	if (n%2){
		int sm = 0, res = f[n-2];
		for (int i = n-2; i >= 1; i -= 2){
			sm += v[i+1]-v[i];
			int cur = (i==1?0:f[i-2])+sm;
			res = min(res,cur);
		}
		return res;
	}
	return f[n-1];
	
}
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<int> v({1,2,3,4,7});
//	cout << calc(v) << "\n";
	sort(a+1,a+n+1,[](int a, int b){
		if (a%k==b%k) return a<b;
		return a%k<b%k;
	});
	int res = 0, ch = 0;
	vector<int> vec;
	for (int i = 1; i <= n; i++){
		vec.push_back(a[i]/k);
		if (a[i]%k!=a[i+1]%k||i==n){
			if (vec.size()%2){
				if (ch){
					cout << -1 << "\n";
					return;
				}
				ch = 1;
			}
			res += calc(vec);
			vec.clear();
		}
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

