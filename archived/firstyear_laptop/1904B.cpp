#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 1e5+5;
int n, f[maxN], b[maxN], res[maxN];
ii a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) b[i] = a[i].first + b[i-1];
	a[n+1].first = 1e15;
	for (int i = n; i >= 1; i--){
		f[i] = (b[i]>=a[i+1].first?f[i+1]:i);
		res[a[i].second] = f[i];
	}
	for (int i = 1; i<= n; i++) cout << res[i]-1 << " ";
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

