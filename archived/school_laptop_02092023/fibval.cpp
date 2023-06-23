#include<bits/stdc++.h>

using namespace std;
int n, f[1005], mp[10][10], sz;
int main(){
//	cin >> n;
	n = 100;
	f[1] = 1, f[2] = 2;
	for (int i = 3; i <= n; i++) (f[i] = f[i-1] + f[i-2])%=7;
//	for (int i = 1; i <= n; i++) cout << i <<" "<< f[i] << "\n";
	for (int i = 1; i <= n; i++){
		if (mp[f[i]][f[i+1]]){
//			cout << i << "\n";
			sz = 16;
//			cout << mp[f[i]][f[i+1]] << "----\n";
			break;
		}
		mp[f[i]][f[i+1]] = i;
	} 
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		int u, v;
		cin >> u >> v;
		if (v-u+1<32){
			int res = -1;
			for (int i = u; i < v; i++) if (f[(i-1)%16+1]==f[(i+1-1)%16+1]) res = 2;
			cout << res << "\n";
			continue;
		} else cout << (v-u+1)/16*16 << "\n";
	}	
	
	return 0;
}
