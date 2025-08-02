#include<bits/stdc++.h>

using namespace std;
const int maxP = 500, maxN = 1e4+5;
int n, f[maxN][2*maxP+5], p[maxN], a[maxN], b[maxN], pref[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i] >> a[i] >> b[i];
		pref[i] = pref[i-1] + b[i];
	}
	
	for (int i = 0; i <= 2*maxP; i++){
		f[n+1][i] = i;	
	}
	for (int i = n; i >= 1; i--){
		for (int j = 0; j <= 2*maxP; j++){
			if (j<=p[i]){
				int nmood = j+a[i];
				if(nmood>maxP){
					
//					for (int k = i+1; k <= n; k++) if (nmood-(pref[k]-pref[i])<=maxP){
//						
//					}
//					f[i][j] = nmood+pref[n]-pref[i];
				} else; 
				f[i][j] = f[i+1][nmood];
			} else {
				int nmood = max(0, j-b[i]);
				f[i][j] = f[i+1][nmood];
			}
		}
	}
	
	int q;
	cin >> q;
	while (q--){
		int p = -1;
		int x;
		cin >> x;
		int target = x - 2 * maxP;
	    auto it = lower_bound(pref, pref+n+1, target);
	    if (it != pref + n + 1) {
	        p = it - pref;
	    }
//		cout << x << " " << p << "\n";
		if (p==-1){
			cout << x-pref[n] << "\n";
		} else {
			int nmood = x-pref[p];
//			cout << nmood << " = ";
			cout << f[p+1][nmood] << "\n";
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

