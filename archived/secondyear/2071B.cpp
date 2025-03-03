#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	int p = 1;
	vector<int> res;
	for (int i = 1; i <= n; i++){
		while (1ll*i*(i+1)/2>1ll*p*p) p++;
		if (1ll*i*(i+1)/2==1ll*p*p){
			if (i==n){
				cout << -1 << "\n";
				return;
			}
			res.push_back(i+1);
			res.push_back(i);
			i++;
		} else {
			res.push_back(i);
		}
	}
	for (int x: res) cout << x << " "; cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

