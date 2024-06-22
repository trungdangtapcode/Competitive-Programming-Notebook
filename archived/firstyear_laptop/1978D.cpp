#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, c, a[maxN];
void solve(){
	cin >> n >> c;
	int mmax = -1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mmax = max(mmax,a[i]);
	}
	mmax = max(mmax,a[1]+c);
	int s = c, pos = (a[1]+c==mmax?1:-1);
	for (int i = 1; i <= n; i++){
		if (a[i]==mmax&&pos==-1) pos = i;
		if (i==pos){
			cout << 0 << " ";
		} else cout << i-1+(a[i]+s<mmax) << " ";
		s += a[i];
	}
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

