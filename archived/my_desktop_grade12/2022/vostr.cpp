#include<bits/stdc++.h>

using namespace std;
#define int long long
const int base = 29;
const int p = 1e9+7;
int n, m, powBase[1000005], a[1000005], b[1000005], q, x, y, u, v;
string s, t;

int getA(int i, int j){
	return (a[j]-a[i-1]*powBase[j-i+1]+p*p)%p;
}
int getB(int i, int j){
	return (b[j]-b[i-1]*powBase[j-i+1]+p*p)%p;
}
char cmp(int a, int b){
	if (a==b) return '=';
	if (a>b) return '>';
	return '<';
}


main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	powBase[0] = 1;
	for (int i = 1; i <= 1e6; i++) powBase[i] = powBase[i-1]*base%p; 
	cin >> n >> m >> s >> t;
	s = "#" + s;
	t = "#" + t;
	
	for (int i = 1; i <= n; i++) a[i] = (a[i-1]*base + s[i] - 'a' + 1)%p;
	for (int i = 1; i <= m; i++) b[i] = (b[i-1]*base + t[i] - 'a' + 1)%p;
	
	cin >> q;
	while (q--){
		cin >> x >> y >> u >> v;
		int l = x-1, h = min(y,x+(v-u)), m1, m2, res1, res2;
		while (l<=h){
			m1 = (l+h)/2;
			m2 = u+(m1-x);
			if (getA(x,m1)==getB(u,m2)){
				res1 = m1;
				res2 = m2; 
				l = m1+1;
			} else h = m1-1;
		}
		if (res1==y||res2==v){
			cout << cmp(y-x,v-u);
		} else {
			cout << cmp(s[res1+1],t[res2+1]);
		}
//		cout << x << "->" << res1 << " " << u << "->" << res2 << endl;
//		cout << getA(1,6) << " " << getB(1,6) << endl;
	}
	
	
	return 0;
}
