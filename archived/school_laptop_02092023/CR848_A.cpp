#include<bits/stdc++.h>


using namespace std;
int n, a[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		bool ok = false;
		int res = 0;
		for (int i = 1; i < n; i++) if (a[i]==a[i+1]&&a[i]==-1){
			a[i] = a[i+1] = 1;
			ok = true;
			break;
		}
		if (!ok) for (int i = 1; i < n; i++) if (a[i]!=a[i+1]) ok = true;
		if (!ok) for (int i = 1; i < n; i++) if (a[i]==a[i+1]&&!ok) a[i] = a[i+1] = -1, ok = true;
		for (int i = 1; i<= n; i++) res += a[i];
		cout << res << "\n";
	}
	
	return 0;
}
