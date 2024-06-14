#include<bits/stdc++.h>

using namespace std;
int n, k;
void solve(){
	cin >> n >> k;
	int x = 2023, res = 1;
	for (int i = 0; i < n; i++){
		int tmp; cin >> tmp;
		if (x%tmp==0){
			x /= tmp;
		} else res = 0;
	}
	cout << (res?"YES\n":"NO\n");
	if (res){
		cout << x << " ";
		for (int i = 1; i < k; i++) cout << 1 << " "; cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
