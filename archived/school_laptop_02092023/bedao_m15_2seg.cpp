#include<bits/stdc++.h>

using namespace std;
int n, f[5005][5005], res, a[5005];
int cnt[1000005];

int cha[100005], sz[100005];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	cha[pu] = pv;
	sz[pv] += sz[pu];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++) f[i][j] = 0;
			for (int j = i; j <= n; j++) if (!cnt[a[j]]) f[i][j] = f[i][j-1]+1, cnt[a[j]] = 1;
			else break;
			for (int j = i; j <= n; j++) f[i][j] = max(f[i][j],f[i][j-1]), cnt[a[j]] = 0;
		}
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++) cnt[a[j]]++;
			for (int j = i-1; j <= n; j++) cha[j] = j, sz[j] = 1;
			res = max(res,f[i][n]);
			for (int j = n; j >= i; j--){
				cnt[a[j]]--;
				if (cnt[a[j]]==0) hop(j-1,j);
				res = max(res,f[i][j-1]+sz[timcha(j)]-1);
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}
