#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, l, r;
int a[maxN], f[maxN];
void solve(){
	cin >> n >> l >> r;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int sumpl = 0, sumpr = 0, mmax = 0;
	multiset<int> ms;
	ms.insert(0);
	for (int i = 1, pl = 1, pr = 1; i <= n; i++){
		sumpl += a[i];
		sumpr += a[i];
		while (sumpr-a[pr]>=l){
			sumpr -= a[pr];
			pr++;
			ms.insert(f[pr-1]);
		}
		while (sumpl>r){
			sumpl -= a[pl];
			ms.erase(ms.find(f[pl-1]));
			pl++;
		}
		f[i] = mmax;
		if (sumpr>=l&&sumpl<=r)
			f[i] = max((ms.size()?*ms.rbegin()+1:0), f[i]);
		mmax = max(mmax, f[i]);
//		cout << pl << ".." << pr << "\n";
	}
//	for (int i = 1; i <= n; i++){
//		cout << f[i] << " ";
//	}
	cout << f[n] << "\n";
	//https://onecompiler.com/cpp/42j9a2yks
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

