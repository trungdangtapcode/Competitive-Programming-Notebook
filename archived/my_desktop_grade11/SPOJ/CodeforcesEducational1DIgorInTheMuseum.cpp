#include <bits/stdc++.h>

using namespace std;
string s[1005];
int cnt[1000005], id[1005][1005];
int vxx[4] = {0,1,0,-1};
int vyy[4] = {1,0,-1,0};
int n, m, k;

void dfs(int ux, int uy, int st){
	id[ux][uy] = st;
	for (int i = 0; i < 4; i++){
		int vx = ux + vxx[i];
		int vy = uy + vyy[i];
		if (vx>=n||vx<0||vy>=m||vy<0) continue;
		//if (s[vx][vy]=='.'&&id[vx][vy]==-1) cout << "(" << ux << "," << uy << ") -> (" << vx << "," << vy << ") \n";
		if (s[vx][vy]=='*') cnt[st]++;
		else if (id[vx][vy]==-1) dfs(vx,vy,st);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	memset(id,-1,sizeof(id));
	memset(cnt,0,sizeof(cnt));
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0, st = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j]=='.'&&id[i][j]==-1){
		dfs(i,j,st++);
	}
	int x, y;
	for (int i = 0; i < k; i++){
		cin >> x >> y;
		cout << cnt[id[x-1][y-1]] << '\n';
	}
	
	return 0;
}
