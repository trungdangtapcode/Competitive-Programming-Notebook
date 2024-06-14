#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, k, q, a[maxN], b[maxN];
void solve(){
	cin >> n >> k >> q;
	for (int i = 1; i <= k; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) cin >> b[i];
	b[k+1] = b[k]+1;
	a[k+1] = a[k]+1;
	for (int i = 0; i < q; i++){
		int d; cin >> d;
		int x = upper_bound(a,a+k+1,d)-a-1;
		cout << b[x] + (d-a[x])*(b[x+1]-b[x])/(a[x+1]-a[x]) << " ";
	}
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
