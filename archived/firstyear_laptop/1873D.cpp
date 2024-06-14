#include<bits/stdc++.h>

using namespace std;
//string s;
//long long a[100005];
//int a[100005];
void solve(){
	int res = 0, n, k;
	cin >> n >> k;
	for (int i = 1, r = 0; i <= n; i++){
		char c;
		cin >> c;
//		a[i] = (c=='B');
		if (c=='B'&&r<i){
			res++;
			r = i+k-1;
		}
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

