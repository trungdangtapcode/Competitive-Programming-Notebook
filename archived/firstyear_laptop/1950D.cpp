#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, f[100005];
vector<int> bd;
void solve(){
	cin >> n;
	cout << (f[n]?"YES\n":"NO\n");
	return;
}
bool check(int n){
	while (n>0){
		int x = n%10;
		if (x!=0&&x!=1){
			return 0;
		}
		n /= 10;
	}
	return 1;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 0; i <= 1e5; i++) if (check(i)) bd.push_back(i), f[i] = 1;
	for (int i = 0; i <= 1e5; i++){
		for (int j: bd) if (j!=0&&i%j==0){
			f[i] |= f[i/j];
		}
	}
//	cout << bd.size() << "\n";
	int t; cin >> t;
	while (t--)
	solve();
}

