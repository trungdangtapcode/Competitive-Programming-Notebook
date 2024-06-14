#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], f[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		f[i] = 1e9;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i-1; j > 1; j--) f[j-1] = min(f[j-1],f[j]);
		f[i] = min(f[i],f[max(0,i-a[i])]+1);
		int mmin = f[i-1];
		for (int j = i+1; j <= min(n,i+a[i]-1); j++){
			mmin = min(mmin,f[min(i-1,max(0,j-a[j]))]+1);
			f[j] = min(f[j],mmin+1);
		}
//		for (int j = 1; j <= n; j++) cout << f[j] << " "; cout << "\n";
	}
	cout << f[n] << "\n";
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) 
	solve();
	
	return 0;
}
