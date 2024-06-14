#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e5+5;
int n, b[maxN], ch[maxN], cnt;
ii a[maxN];
int tim(int x){
	return (ch[x]==x?x:ch[x]=tim(ch[x]));
}
bool hop(int u, int v){
	u = tim(u);
	v = tim(v);
	if (u==v) return false;
	ch[u] = v;
	cnt++;
	return true;
}
void solve(){
	cin >> n;
	cnt =  0;
	int res = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first;
		b[i] = a[i].first;
		a[i].second = i;
		ch[i] = i;
		res += max(0ll,a[i].first-a[i-1].first);
	}
//	sort(a+1,a+n+1);
//	reverse(a+1,a+n+1);
//	a[n+1].first = 0;
//	for (int i = 1; i <= n; i++){ 
//		if (a[i].second>1) hop(a[i].second,a[i].second-1);
//		if (a[i].second<n) hop(a[i].second,a[i].second+1);
//		if (a[i].first!=a[i+1].first){
////			cout << i << " " << a[i].first << "\n";
//			res += cnt*(a[i].first-a[i+1].first);
//		}
//	}
	cout << res-1 << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
