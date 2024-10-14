#include<bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;
#define int long long

int n, a[N], b[N], w[N], inva[N], invb[N], cmp[N], p[N];
int mmin[N], sz[N], sum[N];
#define For(i,a,b) for(int i=a;i<=b;i++)

void solve(){
	memset(sum,0,sizeof(sum));
	memset(sz,0,sizeof(sz));
	memset(cmp,0,sizeof(cmp));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];	
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int gmin = 1e9;
	for (int i = 1; i <= n; i++){
		inva[a[i]] = i;
		invb[b[i]] = i;
		gmin = min(gmin,w[i]);
	}
	for (int i = 1; i <= n; i++){
		p[i] = invb[a[i]];
		assert(p[i]<=n&&p[i]>=1);
	}
	int cur = 0;
	int res = 0;
	for (int i = 1; i <= n; i++) if (!cmp[i]){ 
		int u = i;
		int mmin = w[a[u]], sum =0 , sz = 0, mmax = w[a[u]];
		while (!cmp[u]){
			cmp[u] = 1;
			sum += w[a[u]];
			sz++;
			mmin = min(mmin,w[a[u]]);
			mmax = max(mmax,w[a[u]]);
			u = p[u];
		}
		if (sz<2) continue;
		assert(sz!=0);
//		res += 2*sum-mmin;
		res += min(sum+(sz-2)*mmin, mmin*2+gmin*2+gmin*(sz-1)+(sum-mmin));
//		res += sum*2-mmax*2;
//		cout << cur << " from " << i << ": ";
//		cout << sz[cur] << " " << sum[cur] << " " << mmin[cur] << "\n";
	}
	cout << res << "\n";
//	for (int i = 1; i <= n; i++) cout << p[i] << " "; cout << "\n";
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif

	int tc = 1;
//	cin >> tc;
	while(tc--){
		solve();
	}

}



