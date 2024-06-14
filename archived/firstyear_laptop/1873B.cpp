#include<bits/stdc++.h>

using namespace std;
//string s;
long long a[100005];
void solve(){
	long long n, mmin = 1e9, res = 0, p = 1;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		p *= a[i];
		mmin = min(mmin,a[i]);
	}
	for (int i = 0; i< n; i++){
		if (a[i]==mmin){
			res = 1;
			for (int j = 0; j < n; j++) if (i!=j) res *= a[j];
			cout << res*(a[i]+1) << "\n"; 
			return;
		}
	}
//	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

