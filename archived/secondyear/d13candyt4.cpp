#include<bits/stdc++.h>

using namespace std;
/*
f[i][cur] = max(f[j-1][cur-d*(n-j+1)]+sum[j..i]*i) (d>1)
    	= max(f[l][cur-d*(n-l)]+pref[i]*i-pref[l]*i)
        = max(f[l][cur-d*(n-l)]-pref[l]*i)+pref[i]*i
        = max(g[l][cur]-pref[l]*i)+pref[i]*i
g[l][cur] = max(f[l][cur-d*(n-l)]) = max(f[l][cur-d*coef]) (d>1)
*/

struct linear_convex_hull{
	#define ll long long
	ll inf = LLONG_MAX;
	ll division(ll a, ll b) {
//		if ((a < 0) != (b < 0)) return a/b;
//		return (a+b-1) / b;
//	    return (a+b-1) / b + ((a < 0) != (b < 0) && a % b);
		return a / b - ((a < 0) != (b < 0) && a % b);
	}
	
	struct Line {
    	ll k, m, p;
	    bool operator<(const Line& o) const { return k < o.k; }
	    bool operator<(ll x) const { return p < x; }
	    ll eval(ll x) const { return k * x + m; }
	};
//	deque<Line> hull;
	vector<Line> hull;
	
	bool isect(Line &x, const Line &y) {
	    if (x.k == y.k) x.p = x.m > y.m ? inf : -inf;
	    else x.p = division(y.m - x.m, x.k - y.k);
	    return x.p <= y.p;
	}
	
	void add(ll k, ll m) {
	    Line L = {k, m, 0};
	    while ((int) hull.size() >= 2 && (isect(L, hull.back()),
	        isect(hull.back(), hull[(int) hull.size() - 2]), L.p > hull.back().p))
	        {
	        	hull.pop_back();
//	        	cout << "POped\n";
			}
	    hull.push_back(L);
	}
	
	ll query(ll x) {
		if (hull.empty()) return -1e15;
	    while ((int) hull.size() >= 2 && hull.back().eval(x) <= hull[(int) hull.size() - 2].eval(x))
	        hull.pop_back();
	    return hull.back().eval(x);
	}
};

#define int long long
const int maxN = 1e5+5;
int n, t, f[105][maxN], d[105], s, pref[105], g[maxN], flag[maxN];
bool check[105][maxN];
linear_convex_hull ch[maxN];

void solve(){
//	linear_convex_hull x;
//	x.add(0,0);		
//	x.add(-1,0);
//	x.add(-2,-1);
//	cout << x.query(-2) << '\n';
//	cout << x.query(-1) << '\n';
//	return;
	
	cin >> n >> t;
	for (int i = 1; i <= n; i++){
		cin >> d[i];
//		d[i] = rand()%(100001);
	}
	sort(d+1,d+n+1);
	for (int i = 1; i <= n; i++){
		pref[i] = d[i]+pref[i-1];
	}
	s = 1e5;
//	for (int i = 0; i <= n; i++) for (int j = 0; j <= s; j++) f[i][j] = -1e9;
//	f[0][0] = 0;
//	for (int j = 1; j <= s; j++) f[0][j] = -1e9;
//	for (int cur = 0; cur <= s; cur++) ch[cur].add(0,0);
//	cout << "ADD " << n << "  " << 0 << " " << 0 << '\n';
	for (int i = n; i <= s; i += n) ch[i].add(0,0);
//	vector<int> res;
	for (int i = 1; i <= n; i++){
		int coef = (n-i);
		for (int cur = 0; cur <= s; cur++){
			//with d = 1	
			//f[i][cur] = max(f[j-1][cur-d*(n-j+1)]+sum[j..i]*i)
			// = max(f[j-1][cur-coef_j]+pref[i]*i-pref[j-1]*i)
			// = max(f[j-1][cur-d*(n-j+1)]-pref[j-1]*i+pref[i]*i)
			
			//update f[j][_+d*(n-i)] (j>i) with f[i][_]-pref[i]*j+pref[j]*j
//			f[i][cur] = f[i-1][cur];
//			if (cur<coef) continue;
//			cout << "QUERY " << cur-coef << "  " << i << "\n";
//			cout << i << " " << cur << " = " << ch[cur-coef].query(i)+pref[i]*i << "\n";
//			int x = ch[cur-coef].query(i);
//			if (x!=-1e9)
//			f[i][cur] = max(x+pref[i]*i,f[i][cur]);
//			cout << "QUERY " << cur << "  " << i << "\n";
//			cout << i << " " << cur << " = " << ch[cur].query(i)+pref[i]*i << "\n";
			int x = ch[cur].query(i);
			if (x!=-1e15) f[i][cur] = x+pref[i]*i, check[i][cur] = 1;
		}
		
		memset(g,0,sizeof(g));
		memset(flag,0,sizeof(flag));
		
		for (int cur = coef; cur <= s; cur++) if (check[i][cur-coef])
			flag[cur] = 1, g[cur] = f[i][cur-coef];
		for (int cur = coef; cur <= s; cur++) if (flag[cur-coef])
			flag[cur] = 1,  g[cur]= max(g[cur-coef],g[cur]);
		
//		for (int cur = coef; cur <= s; cur++){
//			f[i][cur] = max(f[i][cur-coef],f[i][cur]);
//		}
//		for (int cur = coef; cur <= s; cur++){
//			f[i][cur] = max(f[i][cur-coef],f[i][cur]);
//		}
		
//		for (int cur = coef; cur <= s; cur++){
////			cout << "ADD " << cur << "  " << -pref[i] << " " << f[i][cur-coef] << '\n';
//			ch[cur].add(-pref[i],f[i][cur-coef]);
//		}
		for (int cur = 0; cur <= s; cur++) if (flag[cur]){
			ch[cur].add(-pref[i],g[cur]);
		}
	}
	int sum = n*pref[n];
	while (t--){
		int x; cin >> x;
		cout << sum-f[n][x] << " ";
	}
//	cout << sum-f[3][3] << "\n";
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


//			for (int d = 0; j+d*(n-i+1)<=s; d++){
//				int cost = i;
//				f[i][j+d*(n-i+1)] = max(x+cost,f[i][j+d*(n-i+1)]);
//			}
