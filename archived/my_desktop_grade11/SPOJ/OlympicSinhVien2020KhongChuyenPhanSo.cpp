#include <bits/stdc++.h>

using namespace std;
int spf[1000005];
int g[1000005];
int n, x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 0; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i*i <= 1e6; i++) if (spf[i]==i){
		for (int j = i*i; j <= 1e6; j += i) if (spf[j]==j) spf[j] = i;
	}
	
	int t; cin >> t;
	while (t--){
		memset(g,0,sizeof(g));
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> x; //cant be 0
			while (x!=1) g[spf[x]]++, x /= spf[x];
		}
		for (int i = 0; i < n; i++){
			cin >> x; //cant be 0
			while (x!=1) g[spf[x]]--, x /= spf[x];
		}
		bool ok = true;
		for (int i = 2; i <= 1e6; i++) if (g[i]<0&&i!=2&&i!=5) ok = false;
		cout << (ok?"finite":"repeating") << '\n';
	}
	
	return 0;
}
