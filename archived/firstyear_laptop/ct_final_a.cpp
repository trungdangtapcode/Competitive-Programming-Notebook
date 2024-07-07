#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
bool check(int x){
	int t = a[1]+x;
	int s = 0;
	for (int i = 2; i <= n; i++){
		if (a[i]*2<t) return false;
		s += a[i]-(t+1)/2;
//		cout << i << " -> " << a[i] << " "<< a[i]-(t+1)/2 << "\n";
	}
//	cout << t << "\n";
	return s>=x;
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >>a[i];
	sort(a+2,a+n+1);
	int l = 0, h = 2e9, res = 0;
	while (l<=h){
		int m = (l+h)/2;
		if (check(m)){
			res = m;
			l = m+1; 
		} else h = m-1;
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

