#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	long long tmp = 1;
	cin >> n;
	vector<int> res({1});
	for (int i = 2; i <= n; i++){
		if (tmp*3 > 1e9){
			cout << "NO\n";
			return;
		}
		res.push_back(tmp*=3);
	}
	cout << "YES\n";
	for (int x: res) cout << x << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

