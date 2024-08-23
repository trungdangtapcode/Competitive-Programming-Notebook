#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
typedef pair<int,int> ii;
int n, a[maxN], c[maxN], h;
bool check(int t){
	t--;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		int cnt = t/c[i]+1;
		sum += cnt*a[i];
		if (sum>=h) return 1;
	}
	return 0;
}
void solve(){
	cin >> h >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
//	cout << check(0) << "\n";
//	return;
	int l = 1, r = 4e10, m, res = -1;
	while (l<=r){
//		cout << m << '\n';
		m = (l+r)/2;
		if (check(m)){
			r = m-1;
			res = m;	
		} else l = m+1;
	}
	cout << res << "\n";
}

int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

