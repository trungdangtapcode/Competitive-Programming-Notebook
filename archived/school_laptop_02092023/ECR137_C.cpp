#include<bits/stdc++.h>

using namespace std;
int n, a[200005], f[200005][2];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		s = "#" + s;
		long long int res = 0;
		a[0] = -1e9; f[0][1] = f[0][0] = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			if (s[i]=='1'){
				f[i][1] = max(f[i-1][1],f[i-1][0])+a[i];
				f[i][0] = f[i-1][0]+a[i-1];
			} else {
				f[i][0] = max(f[i-1][1],f[i-1][0]);
				f[i][1] = -1e9;
			}
		}
		cout << max(f[n][0],f[n][1]) << "\n";
	}
	
	return 0;
}
