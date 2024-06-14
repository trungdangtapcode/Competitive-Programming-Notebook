#include<bits/stdc++.h>

using namespace std;
int n, k, cnt[31];
void solve(){
	cin >> n >> k;
	memset(cnt,0,sizeof(cnt));
	for (int i = 1; i <= n; i++){
		int a; cin >> a;
		for (int j = 30; j >= 0; j--) cnt[j] += (a>>j&1);
	}
	int res = 0;
	for (int j = 30; j >= 0; j--){
		if (k>=n-cnt[j]){
			res |= (1<<j);
			k -= n-cnt[j];
		}
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

