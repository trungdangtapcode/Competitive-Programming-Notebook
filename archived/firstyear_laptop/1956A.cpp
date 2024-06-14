#include<bits/stdc++.h>

using namespace std;
int k, q, a[105], n[105];
void solve(){
	cin >> k >> q;
	for (int i = 0; i < k; i++) cin >> a[i];
	sort(a,a+k);
	for (int i = 0; i < q; i++) cin >> n[i];
	for (int i = 0; i < q; i++){
		cout << min(a[0]-1,n[i]) << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

