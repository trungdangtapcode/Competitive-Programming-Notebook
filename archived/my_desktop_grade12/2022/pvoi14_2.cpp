#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edgelist;
int n, cha[1000005], sz[1000005], a[1005][1005];

int idx(int i, int j){
	return (i-1)*n+j;
}
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	cha[pu] = pv;
	sz[pv] += sz[pu];
}
void tach(int u, int v){
	cha[u] = u;
	cha[v] = v;
	sz[u] = sz[v] = 1;
}


int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		if (i>1) edgelist.push_back({abs(a[i][j]-a[i-1][j]),{idx(i,j),idx(i-1,j)}});
		if (j>1) edgelist.push_back({abs(a[i][j]-a[i][j-1]),{idx(i,j),idx(i,j-1)}});
	}
	sort(edgelist.begin(),edgelist.end());
	for (int i = 1; i <= n*n; i++) cha[i] = i, sz[i] = 1;
	int res = 0;
	for (int i = 0, j = 0; i < edgelist.size(); i++){
		while (j<edgelist.size()&&edgelist[j].first==edgelist[i].first) j++;
		j--;
		for (int k = i; k <= j; k++){
			int u = edgelist[k].second.first, v = edgelist[k].second.second;
			hop(u,v);
			res = max(res,max(sz[timcha(u)],sz[timcha(v)]));
		}
		for (int k = i; k <= j; k++){
			int u = edgelist[k].second.first, v = edgelist[k].second.second;
			tach(u,v);
		}
//		cout << edgelist[i].first << " " << i << " " << j << "\n";
		i = j++;
	}
	cout << res;
	
	
	return 0;
}
