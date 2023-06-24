#include<bits/stdc++.h>
//bo de: min_a khi b vao het, max_a khi chon het a
//thi moi gia tri a trong khoang [min_a,max_a] deu co the lam do thi lien thong


using namespace std;
#define int long long
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii> va, vb;
int cha[100005], n, m, a[100005], b[100005];
bool mustA[100005], res[100005];

int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}
void reset(){
	for (int i = 1; i <= n; i++) cha[i] = i;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		va.clear(), vb.clear();
		for (int i = 1; i < n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) cin >> b[i];
		for (int i = 0, u, v, c; i < m; i++){
			cin >> u >> v >> c;
			if (c==1){
				va.push_back({{u,v},i+1});
			} else vb.push_back({{u,v},i+1});
		}
		int max_a = 0, min_a = n-1;
		reset();
		for (auto it: va) max_a += hop(it.first.first,it.first.second);
		reset();
		for (auto it: vb) min_a -= hop(it.first.first,it.first.second);
		for (int i = 0; i < va.size(); i++) res[va[i].second] = hop(va[i].first.first,va[i].first.second);
		reset();
		
		int idx_a = -1, mmin = 2e9+10;
		for (int i = min_a; i <= max_a; i++){
			if (mmin>a[i]+b[n-1-i]){
				mmin = a[i]+b[n-1-i];
				idx_a = i;
			}
		}
		
		for (int i = 0; i < va.size(); i++) if (res[va[i].second]) hop(va[i].first.first,va[i].first.second);
		idx_a -= min_a;
		
		for (int i = 0; i < va.size(); i++) if (!res[va[i].second]){
			if (idx_a<=0) break;
			if (hop(va[i].first.first,va[i].first.second)){
				idx_a--;
				res[va[i].second] = 1;
			}
		}
		for (int i = 0; i < vb.size(); i++){
			res[vb[i].second] = hop(vb[i].first.first,vb[i].first.second);
		}
	//	for (int i = 0; i < m; i++) cout << res[i] << "\n";
		for (int i = 1; i <= m; i++) if (res[i]) cout << i << " "; cout << "\n";
	}
	
	return 0;
}
