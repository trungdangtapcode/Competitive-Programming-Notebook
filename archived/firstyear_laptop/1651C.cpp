#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], b[maxN];
int calc(int a[], int x){
	int pos = upper_bound(a+1,a+n+1,x)-a;
	if (pos>1&&abs(a[pos-1]-x)<abs(a[pos]-x)) pos--;
	return abs(a[pos]-x);
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int x = a[1], y = a[n], z = b[1], t = b[n];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	a[n+1] = b[n+1] = 1e12;
	int res = 1e12;
	
	//x-z
	res = min(res,calc(a,t)+calc(b,y)+abs(x-z));
	//x-t
	res = min(res,calc(a,z)+calc(b,y)+abs(x-t));		
	//y-z
	res = min(res,calc(a,t)+calc(b,x)+abs(y-z));
	//y-t
	res = min(res,calc(a,z)+calc(b,x)+abs(y-t));
	//x-z, y-t
	res = min(res,abs(x-z)+abs(y-t));
	//x-t, y-z
	res = min(res,abs(x-t)+abs(y-z));
	//none
	res = min(res,calc(a,z)+calc(a,t)+calc(b,x)+calc(b,y));
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

