#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int last = 0, res = 1e9;
	if (a[1]!=a[n]){
		cout << 0 << "\n";
		return;
	}
	for (int i = 1; i <= n; i++){
		if (a[i]!=a[1]){
			res = min(res,i-last-1);
			last = i;
		} else {
			
		}
	}
	if (last!=0) res = min(res,n-last);
	cout << (res==1e9?-1:res) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

