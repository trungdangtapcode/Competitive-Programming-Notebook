#include <bits/stdc++.h>

using namespace std;

int n, k, pos[200005], mmin[200005];
pair<int,int> edge[200005];
int cha[200005];
long long int now, res[200005];
bool cycle[200005];

int timcha(int u) {
	return (cha[u]==u?u:cha[u]=timcha(cha[u]));
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv){
		if (!cycle[pu]){
			cycle[pu] = true;
			now += mmin[pu];
		}
		return;
	}
	if (!cycle[pu]) now += mmin[pu];
	if (!cycle[pv]) now += mmin[pv];
	cha[pv] = pu;
	mmin[pu] = min(mmin[pu],mmin[pv]);
	cycle[pu] = cycle[pu]||cycle[pv];
	if (!cycle[pu]) now -= mmin[pu];
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> mmin[i], cha[i] = i;
	for (int i = 1; i <= k; i++) cin >> edge[i].first >> edge[i].second;
	for (int i = 1; i <= k; i++) cin >> pos[i];
	for (int i = k; i >= 1; i--){
		res[i] = now;
		hop(edge[pos[i]].first,edge[pos[i]].second);
	}
	for (int i = 1; i <= k; i++){
		cout << res[i] << '\n';
	}
	
	return 0;
}
