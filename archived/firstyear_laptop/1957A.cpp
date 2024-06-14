#include<bits/stdc++.h>

using namespace std;
int n, a[105];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int res = 0;
	for (int i = 1, last = -1,cnt = 0; i<= n; i++){
		if (last!=a[i]){
			cnt = 1;
		} else {
			cnt++;
			if (cnt==3) res++, cnt = 0;
		}
		last = a[i];
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

