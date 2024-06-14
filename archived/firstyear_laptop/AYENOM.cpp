#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5, INF = 1e18;
int n, t, a[maxN], d[maxN], locked[maxN]; 
main(){
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < a[0]; i++) d[i] = INF;
	d[0] = 0;
	for (;;){
		int u = -1;
		for (int j = 0; j < a[0]; j++) if (locked[j]==0)
			if (u==-1||d[j]<d[u]) u = j;
		if (u==-1||d[u]==INF) break;
		locked[u] = 1;
		for (int i = 1; i < n; i++){
			int v = (u+a[i])%a[0];
			d[v] = min(d[v],d[u]+a[i]);
		}
	}
	int res = 0;
	for (int i = 0; i < a[0]; i++) if (d[i]<=t){
		res += (t-d[i])/a[0] + 1;
	}
	cout << res;
	
	return 0;
}
