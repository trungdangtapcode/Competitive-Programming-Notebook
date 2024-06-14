#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e6+5;
int n, a[maxN], val[maxN], res[maxN];
void rs(){
	for (int i = 1; i <= 2*n; i++) val[i] = 0;
}
void updt(int x, int v = 1){
	for (; x <= 2*n; x += x&-x) val[x] += v;
}
int gett(int x){
	int res= 0;
	x = min(x,2*n);
	for (; x; x -= x&-x) res += val[x];
	return res;
}
void solve(){
//	multiset<int> ms;
//	ms.insert(0);
	cin >> n;
	rs();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) if (i <= a[i]) updt(a[i]+n);
	for (int i = n; i > 0; i--){
		int x = (i <= a[i]? a[i]: a[i] + n);
		res[a[i]] = (a[i]-i+n)%n - gett(x);
		updt(x);
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " "; cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
