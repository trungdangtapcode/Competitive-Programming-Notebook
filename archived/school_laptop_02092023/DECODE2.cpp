#pragma comment(linker, "/STACK:128000000");
#include<bits/stdc++.h>
//The default stack size killed me :(


using namespace std;
int n;
string res1, res2;
int to[2005][30], cnt;
bool isLeaf[2005];
void them(string s){
	int u = 0;
	for (char c: s){
		if (to[u][c-'a']==0) to[u][c-'a'] = ++cnt;
		u = to[u][c-'a'];
	}
	isLeaf[u] = true;
}
typedef pair<int,int> ii;
typedef pair<int,ii> i2i;
ii memo[2005][2005];
//int a;
ii dfs(int x, int y, int edge){
//	cout << x << " " << y << endl;
	if (isLeaf[x]&&isLeaf[y]&&x!=y) return memo[x][y] = {0,edge};
	if (memo[x][y].first!=-1) return memo[x][y];
	memo[x][y] = {1e9,-1};
	for (int i = 'a'-'a'; i <= 'z'-'a'; i++){
//		if (x==350&&y==250) cout << (char)(i+'a') << endl;
//		if (x==350&&y==250) cout << "hi" << (char)(i+'a') << endl; ??
//		if (x==350&&y==250) cout << to[y][i] << endl;
		if (to[x][i]&&to[y][i]) memo[x][y] = min(memo[x][y],dfs(to[x][i],to[y][i],i));
//		if (x==350&&y==250) cout << (char)(i+'a') << endl;
		if (isLeaf[x]&&to[0][i]&&to[y][i]) memo[x][y] = min(memo[x][y],dfs(to[0][i],to[y][i],i));
		if (isLeaf[y]&&to[x][i]&&to[0][i]) memo[x][y] = min(memo[x][y],dfs(to[x][i],to[0][i],i));
//		if (isLeaf[y]&&to[x][i]&&to[0][i]) memo[x][y] |= dfs(to[x][i],to[0][i]);
//		if (memo[x][y]==1){
//			res1.push_back(i+'a');
//			res2.push_back(i+'a');
//			res2.push_back('+');
//			return true;
//		}
//		if (isLeaf[y]) yy = to[0][i];
//		if (xx&&yy) memo[x][y] |= dfs(xx,yy);
//		if (memo[x][y]==1){
//			res1.push_back(i+'a');
//			res2.push_back(i+'a');
//			return true;
//		}
	}
//	cout << x << " " << y << " " << memo[x][y].first << " trace " << memo[x][y].second.first << " " << memo[x][y].second.second << endl;
//	cout << x << " " << y << " " << memo[x][y].first << " trace " << (char)(memo[x][y].second+'a') << endl;
	return {++memo[x][y].first,edge};
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		them(s);
	}
	
	
	for (int i = 0; i <= cnt; i++) for (int j = 0; j <= cnt; j++) memo[i][j].first = -1;
	dfs(0,0,-1);
	if (memo[0][0].first>=1e8){
		cout << -1;
		return 0;
	}
	int x = 0, y = 0;
	while (memo[x][y].first!=0){
//	while (!isLeaf[x]||!isLeaf[y]||x==y){
//		cout << x << " " << y << endl;
		int xx = to[x][memo[x][y].second], yy = to[y][memo[x][y].second];
//		cout << " -> " << xx << " " << yy << endl;
		if (xx&&yy&&memo[xx][yy].first+1==memo[x][y].first){
			res1.push_back(memo[x][y].second+'a');
			res2.push_back(memo[x][y].second+'a');
			x = xx;
			y = yy;
			continue;
		}
		xx = to[0][memo[x][y].second], yy = to[y][memo[x][y].second];
//		cout << " -> " << xx << " " << yy << endl;
		if (isLeaf[x]&&xx&&yy&&memo[xx][yy].first+1==memo[x][y].first){
			res1.push_back('+');
			res1.push_back(memo[x][y].second+'a');
			res2.push_back(memo[x][y].second+'a');
			x = xx;
			y = yy;
			continue;
		}
		xx = to[x][memo[x][y].second], yy = to[0][memo[x][y].second];
//		cout << " -> " << xx << " " << yy << endl;
		if (isLeaf[y]&&xx&&yy&&memo[xx][yy].first+1==memo[x][y].first){
			res1.push_back(memo[x][y].second+'a');
			res2.push_back('+');
			res2.push_back(memo[x][y].second+'a');
			x = xx;
			y = yy;
			continue;
		}
	}
	
//	for (int i = 0; i <= cnt; i++){
//		for (int j = 0; j <= cnt; j++) cout << i << " " << j << " " << memo[i][j] <<endl;
//	}
//	reverse(res1.begin(),res1.end());
//	reverse(res2.begin(),res2.end());
//	if (res1=="") cout << -1;
	cout << res1 << "\n" << res2 << "\n";
	
	return 0;
}
