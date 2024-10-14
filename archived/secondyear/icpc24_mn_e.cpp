#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

#define For(i,a,b) for(int i=a;i<=b;i++)

int n, d[N];
vector<int> adj[N];
int fin[N], fout[N], timer = 0;

void dfs(int u, int p=-1){
	fin[u] = ++timer;
	for(int v: adj[u]){
		if(v == p) continue;
		dfs(v, u);
	}
	fout[u] = timer;
}

int check(int x, int y){
	return (fin[y] >= fin[x] && fin[y] <= fout[x]);
}

void solve(){	
	cin >> n;
	For(i,1,n) adj[i].clear();
	For(i,2,n){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		d[y]++;
	}
	timer =0;
	for (int i = 1; i <= n; i++) if (d[i]==0){
		
		dfs(i);
		break;
	}
	
//	For(i,1,n) cout  << fin[i] << " "; cout << "\n";
//	For(i,1,n) cout  << fout[i] << " "; cout << "\n";
	
	int m; cin >> m;
	while(m--){
		int x, y; cin >> x >> y;
		if(check(x, y)){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
}


int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	
		
	solve();
}


