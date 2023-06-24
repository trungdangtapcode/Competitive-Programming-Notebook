#include<bits/stdc++.h>

using namespace std;
int n, s, f[250005], t[30], d[30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= n; i++) cin >> d[i];
	
	for (int i = 1; i <= s; i++) f[i] = -1e9;
	for (int i = 1; i <= n; i++){
		for (int j = s; j >= t[i]; j--) f[j] = max(f[j],f[j-t[i]]+d[i]);
	}
	int res = 0;
	for (int i = 0; i <= s; i++) res = max(res,f[i]);
	cout << res;
	
	return 0;
}
