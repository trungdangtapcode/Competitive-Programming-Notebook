#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	set<int> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) s.insert(a[i]);
	sort(a+1,a+n+1);
	int g = 0;
	for (int i = 1; i < n; i++) g = __gcd(g,a[n]-a[i]);
	g = max(g,(int)1);
	a[n+1] = a[n]+g;
	for (int i = a[n]-g, j = 0; j < n; i -= g, j++){
		if (s.find(i)==s.end()){
			a[n+1] = i;
			break;
		}
	};
	long long res = 0;
	int x = max(a[n],a[n+1]);
	for (int i = 1; i <= n+1; i++){
		assert((x-a[i])%g==0);
//		if ((x-a[i])%g){
//			cout << n << "-";
//			for (int i = 1; i <= n; i++) cout << a[i] << "-";
//			return;
//		}
		res += (x-a[i])/g;
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
