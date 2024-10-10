#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, k;
int f(int x){
	return k*x+x*(x-1)/2;
}
void solve(){
	cin >> n >> k;
	int l = 1, h = n, m, res =-1;
	while (l<=h){
		m = (l+h)>>1;
		if (f(n)-2*f(m)<=0){
			h = m-1;
			res = m;
		} else l = m+1;
	}
	res -= (res>1&&abs(f(n)-2*f(res))>abs(f(n)-2*f(res-1)));
	cout << abs(f(n)-2*f(res)) << "\n";
//	exit(0);
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

