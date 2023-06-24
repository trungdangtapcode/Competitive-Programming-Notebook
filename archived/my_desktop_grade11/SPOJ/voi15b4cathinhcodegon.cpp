#include <bits/stdc++.h>
using namespace std;
int m, n, k;
long long int s[1005][1005];

long long int f(int x, int y, int u, int v){
	return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1];
}
long long int solve(){
	int x, y, u, v, l, h;
	long long int result = 1e18;
	cin >> x >> y >> u >> v;
	
	l = x, h = u;
	if (l+1==h) result = min(result,abs(f(x,y,l,v)-f(h,y,u,v)));
	while (l+1<h){
		int m = (l+h)/2;
		long long int s1 = f(x,y,m,v);
		long long int s2 = f(m+1,y,u,v);
		result = min(result,abs(s1-s2));
		if (f(x,y,m,v)>f(m+1,y,u,v)) h = m; else l = m;
		if (l+1==h) result = min(result,abs(f(x,y,l,v)-f(h,y,u,v)));
	}
	l = y, h = v;
	if (l+1==h) result = min(result,abs(f(x,y,u,l)-f(x,h,u,v)));
	while (l+1<h){
		int m = (l+h)/2;
		long long int s1 = f(x,y,u,m);
		long long int s2 = f(x,m+1,u,v);
		result = min(result,abs(s1-s2));
		if (f(x,y,u,m)>f(x,m+1,u,v)) h = m; else l = m;
		if (l+1==h) result = min(result,abs(f(x,y,u,l)-f(x,h,u,v))); 
	}
	return result; //O((log(n)+log(m))
}

int main() {
	cin >> m >> n >> k;
	memset(s,0,sizeof(s));
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++){
			cin >> s[i][j];
			s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}	
	
	for (int i = 1; i <= k; i++){ //O(k*(log(n)+log(m))
		cout << solve() << endl; 
	}
	
	return 0;
}
