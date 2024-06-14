#include<bits/stdc++.h>

using namespace std;
const int maxN = 55;
int n, a[maxN][maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (a[i][j]!=1){
		bool flag = 0;
		for (int s = 1; s <= n && !flag; s++) for (int t = 1; t <= n; t++) if (a[i][j]==a[i][s]+a[t][j]){
			flag = 1;
			break;
		}
		if (!flag){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

