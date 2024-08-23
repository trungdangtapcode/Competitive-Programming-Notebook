#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], b[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i-1] = b[i+1] = 0;
	}
	for (int i = 1; i <= n; i++){
		if (i!=1&&b[a[i]-1]==0&&b[a[i]+1]==0){
			cout << "NO\n";
			return;
		}
		b[a[i]] = 1;
	}
	cout << "YES\n";
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

