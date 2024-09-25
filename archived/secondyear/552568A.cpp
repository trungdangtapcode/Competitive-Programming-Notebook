#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e4+5;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
iii a[maxN];
int n, res[maxN], xx[maxN], r[maxN], m;

long long sqr(int x){
	return 1ll*x*x;
}
bool dist(int x, int y, int u, int r){
	return sqr(x-u)+sqr(y)<=sqr(r);
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i;
		res[i] = -1;
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) xx[i] = a[i].first.first;
	for (int i = 1; i <= n; i++) r[i] = a[i].first.second;
	
	cin >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		int pos2 = lower_bound(xx+1,xx+n+1,x)-xx;
		int pos1 = pos2-1;
//		cout << pos1 << " " << pos2 << "\n";
		if (1<=pos1&&pos1<=n){
			if (dist(x,y,xx[pos1],r[pos1])){
				int idx = a[pos1].second;
				if (res[idx]==-1) res[idx] = i;
			};
		}
		if (1<=pos2&&pos2<=n){
			if (dist(x,y,xx[pos2],r[pos2])){
				int idx = a[pos2].second;
				if (res[idx]==-1) res[idx] = i;
			};
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += res[i]!=-1;
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++){
		cout << res[i] << " ";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}
//https://codeforces.com/contest/84/A

