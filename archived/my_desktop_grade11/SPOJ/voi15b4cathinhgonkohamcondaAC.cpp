#include <bits/stdc++.h>
using namespace std;
int m, n, k;
long long s[1005][1005];

long long f(int x, int y, int u, int v){
	return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n >> k;
	
	for (int i = 0; i <= m; i++) s[i][0] = 0;
	for (int i = 0; i <= n; i++) s[0][i] = 0;
	
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++){
			cin >> s[i][j];
			s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}	
	
	int x, y, u, v, l, h,m;
	long long result, s, s1;
	for (int i = 1; i <= k; i++){ //O(k*(log(n)+log(m))
		result = 1e18;
		cin >> x >> y >> u >> v;
	
		s = f(x,y,u,v);
		l = x, h = u;
		if (l+1==h) result = min(result,abs(f(x,y,l,v)-f(h,y,u,v)));
		while (l+1<h){
			m = (l+h)/2;
			s1 = f(x,y,m,v);
			result = min(result,abs(2*s1-s));
			if (2*s1>s) h = m; else l = m;
			if (l+1==h) result = min(result,abs(f(x,y,l,v)-f(h,y,u,v)));
		}
		l = y, h = v;
		if (l+1==h) result = min(result,abs(f(x,y,u,l)-f(x,h,u,v)));
		while (l+1<h){
			m = (l+h)/2;
			s1 = f(x,y,u,m);
			result = min(result,abs(2*s1-s));
			if (2*s1>s) h = m; else l = m;
			if (l+1==h) result = min(result,abs(f(x,y,u,l)-f(x,h,u,v))); 
		}
		printf("%lld\n", result); //DUNG COUT KO AC WTF 
	}
	
	return 0;
}
