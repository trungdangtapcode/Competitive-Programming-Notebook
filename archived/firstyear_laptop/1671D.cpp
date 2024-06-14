#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], x;
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mmax = -1e9, mmin = 1e9;
	for (int i = 1; i <= n; i++) mmax = max(mmax, a[i]), mmin = min(mmin, a[i]);
	int res = 0;
	for (int i = 1; i < n; i++) res += abs(a[i+1]-a[i]);
	if (mmax<x) res += min({2*(x-mmax),x-a[1],x-a[n]});
	if (mmin>1) res += min({2*(mmin-1),a[1]-1,a[n]-1});
	cout << res << "\n";
}


main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

/*
int dist(int a, int b, int c, int d){
	return abs(a-b) + abs(b-c) + abs(c-d);
}
int calc(int a, int b, int c, int d){
	return min(dist(a,b,c,d),dist(a,c,b,d));
}
*/
/*
	pref[i] = (i==1?0:pref[i-1]+abs(a[i]-a[i-1]));
	if (mmax<x&&1<mmin){
		f[0] = dist(1,1,a[1],a[1]);
		for (int i = 1; i < n; i++) f[i] = min(f[i-1],calc(a[i],1,1,a[i+1]));
		int res = 0;
		a[n+1] = x;
		for (int i = 1; i <= n; i++){
			res = min(res,calc(a[i],x,x,a[i+1]));
		}
	}
*/

/*
	f[0] = 0;
	f[1] = (1<mmin?min({
		calc(mmin-1,mmin-1,1,a[1]),
		calc(1,1,mmin-1,a[1]),
		calc(mmin-1,mmin-1,1,a[n]),
		calc(1,1,mmin-1,a[n])})
		:0);
	f[2] = (x>mmax?min({
		calc(mmax+1,mmax+1,x,a[1]),
		calc(x,x,mmax+1,a[1]),
		calc(mmax+1,mmax+1,x,a[n]),
		calc(x,x,mmax+1,a[n])})
		:0);
	f[3] = (1<mmin&&x>mmax?
		min({calc(1,1,x,a[1]),calc(x,x,1,a[1]),calc(1,1,x,a[n]),calc(x,x,1,a[n]),
		min(calc(1,1,a[1],a[1]),calc(mmin-1,mmin-1,a[1],a[1]))+min(calc(x,x,a[n],a[n]),calc(mmax+1,mmax+1,a[n],a[n])),
		min(calc(1,1,a[n],a[n]),calc(mmin-1,mmin-1,a[n],a[n]))+min(calc(x,x,a[n],a[1]),calc(mmax+1,mmax+1,a[n],a[1]))
		}):
		1<mmin?f[1]:x>mmax?f[2]:f[0]
		);
	int res = 0;
	for (int i = 2; i <= n; i++){
		if (i<=n) res += abs(a[i]-a[i-1]);
		if (1<mmin&&x>mmax) f[3] = min(f[3], min(calc(a[i-1],x,1,a[i-1]),calc(a[i-1],1,x,a[i-1])));
		if (1<mmin) f[3] = min(f[3], f[2] + min(calc(a[i-1],mmin-1,1,a[i-1]),calc(a[i-1],1,mmin-1,a[i-1])));
		if (x>mmax) f[3] = min(f[3], f[1] + min(calc(a[i-1],mmax+1,x,a[i-1]),calc(a[i-1],x,mmax+1,a[i-1])));
		
		if (1<mmin) f[1] = min(f[1], min(calc(a[i-1],mmin-1,1,a[i-1]),calc(a[i-1],1,mmin-1,a[i-1])));
		if (x>mmax) f[2] = min(f[2], min(calc(a[i-1],mmax+1,x,a[i-1]),calc(a[i-1],x,mmax+1,a[i-1])));
	}
	cout << f[3]+res << "\n";
*/
