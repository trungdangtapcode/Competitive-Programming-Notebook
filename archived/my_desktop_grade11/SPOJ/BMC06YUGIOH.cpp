#include <bits/stdc++.h>

using namespace std;

int f[1000005], n, x, res;
bool p[1000005];
int main(){
	
	memset(p,true,sizeof(p));
	p[0] = p[1] = false;
	for (int i = 2; i*i <= 1e6; i++) if (p[i]){
		for (int j = i*i; j <= 1e6; j+=i) p[j] = false;
	}
	
	cin >> n >> x;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		f[i] = f[i-1];
		if (a>=2&&a<=x) if (p[a]) f[i]++;
	}
	
	res = f[n]; //n
	for (int l = 1, r = f[n]; r <= n; l++, r++){
		res = min(res,f[n]-(f[r]-f[l-1]));
	}
	cout << res;
	
	return 0;
}
