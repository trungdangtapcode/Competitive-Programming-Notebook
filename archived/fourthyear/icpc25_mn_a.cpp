
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5+5;
typedef pair<int,int> ii;
int n, C, D;
int a[N], b[N];

void solve(){
	cin >> n >> C >> D;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}
	vector<ii> v1, v2;
	for (int i = 1; i <= n; i++){
		v1.push_back({a[i], b[i]});
		v2.push_back({b[i], a[i]});
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	long long x = v1.back().first-C, y = v2.back().first-D, xx = 1LL<<60, yy = 1LL<<60;
	long long mn = 1LL<<60, mx = -(1LL<<60);
	for (int i = 1; i <= n; i++) mn = min(mn, 1LL*a[i]-b[i]), mx = max(mx, 1LL*a[i]-b[i]);
	if (mx-mn > 1LL*C+D) {cout << -1 << "\n"; return;}
	x = max(x, 1LL*v2.back().first-D+mx-C);
	y = max(y, 1LL*v1.back().first-C-mn-D);
	long long res = 0;
	for (int i = 1; i <= n; i++){
//		if (x>a[i]){
//			xx=1;
//		}
//		if (y>b[i]){
//			yy=1;
//		}
		long long step = max(x-a[i], y-b[i]);
		step = max(step,0LL);
		a[i] += step;
		b[i] += step;
		res += step;
//		if (a[i]>x+C||b[i]>y+D){
//			if (a[i]-xx<=C&&a[i]>x+C){
//				x += a[i]-(x+C);	
//			} else if (b[i]-yy<=D&&b[i]>y+D) {
//				y += b[i]-(y+D);
//			} else {
//				cout << -1 << "\n";
//				return;
//			}
//		}
		if (a[i]-xx>C||b[i]-yy>D){
			cout << -1 << "\n";
			return;
		}
		if (a[i]>x+C){
			x += a[i]-(x+C);
		}
		if (b[i]>y+D){
			y += b[i]-(y+D);
		}
		xx = min(xx,a[i]);
		yy = min(yy,b[i]);
//		x = max(x, xx);
//		y = max(y, yy);
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

