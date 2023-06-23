#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, c, a[200005];
typedef pair<int,int> ii;
ii b[200005];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> c;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			b[i] = {min(a[i]+i,a[i]+n+1-i),a[i]+i};
		}
		sort(b+1,b+n+1);
		for (int i = 1; i <= n; i++) b[i].first += b[i-1].first;
		int res = 0;
		for (int i = 1; i <= n; i++) if (c>=b[i].second){
			res = max(res,1ll);
			int x = c - b[i].second;
			int pos = upper_bound(b+1,b+n+1,ii{x,1e9}) - b - 1;
			if (pos==0) continue; 
			if (i<=pos){
				x += b[i].first-b[i-1].first;
				if (pos<n&&x>=b[pos+1].first) pos++;
				res = max(res,pos);
			} else res = max(res,pos+1);
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
