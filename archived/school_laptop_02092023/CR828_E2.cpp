#include<bits/stdc++.h>

using namespace std;
int n, a, b, c, d;
vector<int> da, db;

void solve(){
	cin >> a >> b >> c >> d;
	da.clear(); db.clear();
	for (int i = 1; i*i <= a; i++) if (a%i==0){
		da.push_back(i);
		da.push_back(a/i);
	}
	for (int i = 1; i*i <= b; i++) if (b%i==0){
		db.push_back(i);
		db.push_back(b/i);
	}
	for (int i: da) for (int j: db){
		int a1 = i, a2 = a/i, b1 = j, b2 = b/j;
		long long int x = 1ll*a1*b1, y = 1ll*a2*b2;
		long long int l1 = a/x+1, r1 = c/x, l2 = b/y+1, r2 = d/y;
		if (l1<=r1&&l2<=r2){
			cout << l1*x << " " << l2*y << "\n";
			return;
		}
	}
	cout << -1 << " " << -1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
