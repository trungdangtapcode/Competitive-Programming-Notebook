#include<bits/stdc++.h>

using namespace std;
int t, n, a[500005], ax[500005], ay[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		fill(ax,ax+n+1,0);
		fill(ay,ay+n+1,0);
		int x = 0, y = 0, xy = 0;
		for (int i = 1; i <= n; i++) if (a[i]!=i){
			ax[i] = 1;
			ax[a[i]] = 1;
		}
		for (int i = 1; i <= n; i++) if (a[i]!=n-i+1){
			ay[i] = 1;
			ay[n-a[i]+1] = 1;
		};
		
		for (int i = 1; i <= n; i++) x += ax[i], y += ay[i], xy += ax[i]&&ay[i];
//		cout << x << " " << xy << " " << y << endl;
		if (x<=y-xy) cout << "First\n";
		else if (y<x-xy) cout << "Second\n";
		else cout << "Tie\n";		
	}
	
	return 0;
}
