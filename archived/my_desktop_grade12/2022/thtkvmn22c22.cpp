/*
a*abs(x-p[i]) + a*abs(y-p[j]) + b*(p[j]-p[i])
p[j]< y => delta = a*y - a*p[j] + b*p[j]
p[j]> y => delta = -a*y + a*p[j] + b*p[j]
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e6+5;
//int f[maxN], g[maxN], pref[maxN];
int n, m, q, a, b, p[maxN];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q >> a >> b;
	for (int i = 1; i <= m; i++) cin >> p[i];
	sort(p+1,p+m+1);
	p[m+1] = 1e9;
	p[0] = -1e9;
	
	while (q--){
		int x, y;
		cin >> x >> y;
		if (x>y) swap(x,y);
		int res = (y-x)*a;
		int pos1 = *lower_bound(p+1,p+m+1,x);
		int pos2 = *(upper_bound(p+1,p+m+1,y)-1);
		int pos3 = *(upper_bound(p+1,p+m+1,x)-1);
		int pos4 = *lower_bound(p+1,p+m+1,y);
//		cout << pos3 << " " << pos1 << " " << pos2 << " " << pos4 << "\n";
		res = min(res,a*abs(x-pos1) + a*abs(y-pos2) + b*(pos2-pos1));
		res = min(res,a*abs(x-pos1) + a*abs(y-pos4) + b*(pos4-pos1));
		res = min(res,a*abs(x-pos3) + a*abs(y-pos2) + b*(pos2-pos3));
		res = min(res,a*abs(x-pos3) + a*abs(y-pos4) + b*(pos4-pos3));
		cout << res << "\n"; 
	}
	
	return 0;
}
