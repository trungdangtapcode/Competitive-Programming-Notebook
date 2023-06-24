#include <bits/stdc++.h>
using namespace std;
int m, n, k;
long long int s[1005][1005];

long long int f(int x, int y, int u, int v){
	//cout << x<<" " << y <<" " << u << " " << v << " = " << s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1] << endl;
	return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1];
}
long long int solve(){
	int x, y, u, v;
	long long int result = 1e12;
	cin >> x >> y >> u >> v;
	//cat ngang
	int l = x, h = u;
	if (l+1==h) result = min(result,abs(f(x,y,l,v)-f(h,y,u,v)));
	while (l+1<h){
		int m = (l+h)/2;
		result = min(result,abs(f(x,y,m,v)-f(m+1,y,u,v)));
		//if (f(x,y,m,v)==f(m+1,y,u,v)) return 0;
		if (f(x,y,m,v)>f(m+1,y,u,v)) h = m; else l = m;
		if (l+1==h) result = min(result,abs(f(x,y,l,v)-f(h,y,u,v)));
	}
	//result = abs(f(x,y,m,v)-f(m+1,y,u,v));
	//cat doc
	l = y, h = v;
	if (l+1==h) result = min(result,abs(f(x,y,u,l)-f(x,h,u,v)));
	while (l+1<h){
		int m = (l+h)/2;
		result = min(result,abs(f(x,y,u,m)-f(x,m+1,u,v)));
		//if (f(x,y,u,m)==f(x,m+1,u,v)) return 0;
		if (f(x,y,u,m)>f(x,m+1,u,v)) h = m; else l = m;
		if (l+1==h) result = min(result,abs(f(x,y,u,l)-f(x,h,u,v))); 
	}
	//cout << result << " "<< abs(f(l,y,m,v)-f(m+1,y,h,v)) << endl;
	//return min(result,abs(f(x,y,u,m)-f(x,m+1,u,v)));
	return result;
}

int main() {
	cin >> m >> n >> k;
	memset(s,0,sizeof(s));
	//m dong, n cot
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++){
			cin >> s[i][j];
			s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}	
	
	//for (int i = 1; i <= m; i++) {
	//	for (int j = 1; j <= n; j++) cout << s[i][j]; cout << endl;}
	//f(1,1,3,3);
	
	
	for (int i = 1; i <= k; i++){
		cout << solve() << endl;
	}
	
	return 0;
}
