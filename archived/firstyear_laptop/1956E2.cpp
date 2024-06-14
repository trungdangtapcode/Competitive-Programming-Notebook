#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
bool check(){
	for (int i = 0; i < n; i++){
		if (a[i]&&a[(i+1)%n]&&a[(i+2)%n]&&a[(i+3)%n]) return 0;
	}
	return 1;
}

void solve(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n==2){
		while (a[0]&&a[1]){
			a[1] -= min(a[1],a[0]);
			a[0] -= min(a[1],a[0]);
		}
		cout << (a[0]!=a[1]) << "\n";
		if (a[0]!=a[1]) cout << (a[0]>a[1]?1:2) << "\n";
		else cout << "\n";
		return;
	}
	if (n==3){
		while (true){
			bool ch = 0;
			if (a[0]&&a[1]) a[1] -= min(a[1],a[0]), ch = 1;
			if (a[1]&&a[2]) a[2] -= min(a[2],a[1]), ch = 1;
			if (a[2]&&a[0]) a[0] -= min(a[0],a[2]), ch = 1;
			if (!a[0]||!a[1]||!a[2]) break;
		}
		if (!a[0]&&!a[1]&&!a[2]) cout << "0\n\n";
		else cout << "1\n" << (a[0]&&!a[2]?1:a[1]&&!a[0]?2:3) << "\n";
		return;
	}
	while (!check()){
		for (int i = 0; i < n; i++){
			a[(i+1)%n] -= min(a[(i+1)%n],a[i]);
		}
	}
//	for (int i = 0; i < n; i++){
//		a[(i+1)%n] -= min(a[(i+1)%n],a[i]);
//	}
//	for (int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
	for(int p=0;p<n;p++) 
  			if(a[p]&&a[(p+1)%n]) a[(p+1)%n]=max(0,a[(p+1)%n]-a[p]);
		else break;

	for (int i = 0; i < n; i++) if (!a[i]&&a[(i+1)%n]){
		int &x = a[(i+1)%n], &y = a[(i+2)%n], &z = a[(i+3)%n];
		int t = y/x;
		z -= min(1ll*y*t - 1ll*t*(t+1)/2*x, 1ll*z);
		y = 0;
//		i += 3;
	}
	int res = 0;
	for (int i = 0; i < n; i++) res += (a[i]!=0);
	cout << res << "\n";
	for (int i = 0; i < n; i++) if (a[i]) cout << i+1 << " ";
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

