#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], b[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}
	int mmin = 1e15;
	for (int i = 1; i <= n; i++){
		int x = b[i];
		if (x+1>2*mmin){
			cout  << "NO\n";
			return;
		}
		mmin = min(mmin, x);
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

