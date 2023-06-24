#include<bits/stdc++.h>
//#define int long int

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> i4;
int dx[] = {0,1,0,-1}; //O[][]
int dy[] = {1,0,-1,0};
int n, m, k, dimension[3], S[1005][1005];
bool visited[1005][1005][3][3];
int sweep[1005][1005];
int getS(int x1, int y1, int x2, int y2){
	return S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1];
}
bool checkS(int x1, int y1, int x2, int y2){
	if (x1<1||x2>n||y1<1||y2>m) return false;
	return (getS(x1,y1,x2,y2)==0);
}
bool check(int x, int y, int d1, int d2){
//	cout << x << " " << y << " " << dimension[d1] << " " << dimension[d2] << " -> ";
	if (!checkS(x,y,x+dimension[d1]-1,y+dimension[d2]-1)) return false;
//	cout << !visited[x][y][d1][d2] << endl;
	return !visited[x][y][d1][d2];
}
void bfs(){
	queue<i4> q;
	q.push({{1,1},{0,1}});
	visited[1][1][0][1] = true;
	while (!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d1 = q.front().second.first;
		int d2 = q.front().second.second;
		int d3 = 3-d1-d2;
		q.pop();
//		cout << x << " " << y << endl;
		//day phai, duoi, trai, len
		for (int i = 0; i < 4; i++){
			int xx = x + dx[i], yy = y + dy[i];
			if (!check(xx,yy,d1,d2)) continue;
//			if (visited[xx][yy][d1][d2]) continue;
			q.push({{xx,yy},{d1,d2}});
			visited[xx][yy][d1][d2] = true;
		}
		//lat tren
//		if (check(x-dimension[d3],y,d3,d2)) if (visited[x-dimension[d3]][y][d3][d2]){
		if (check(x-dimension[d3],y,d3,d2)){
			q.push({{x-dimension[d3],y},{d3,d2}});
			visited[x-dimension[d3]][y][d3][d2] = true;
		}
		//lat xuong
		if (check(x+dimension[d1],y,d3,d2)){
			q.push({{x+dimension[d1],y},{d3,d2}});
			visited[x+dimension[d1]][y][d3][d2] = true;
		}
		//lat trai
		if (check(x,y-dimension[d3],d1,d3)){
			q.push({{x,y-dimension[d3]},{d1,d3}});
			visited[x][y-dimension[d3]][d1][d3] = true;
		}
		//lat phai
		if (check(x,y+dimension[d2],d1,d3)){
			q.push({{x,y+dimension[d2]},{d1,d3}});
			visited[x][y+dimension[d2]][d1][d3] = true;
		}
	}
}

int32_t main(){
	cin >> dimension[0] >> dimension[1] >>  dimension[2] >> n >> m >> k;
	for (int i = 0, x, y; i < k; i++){
		cin >> x >> y;
		S[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1];
	}
	bfs();
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++){
		for (int d1 = 0; d1 < 3; d1++) for (int d2 = 0; d2 < 3; d2++) if (visited[i][j][d1][d2]){
			sweep[i][j]++; sweep[i][j+dimension[d2]]--;
			sweep[i+dimension[d1]][j]--; sweep[i+dimension[d1]][j+dimension[d2]]++;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		sweep[i][j] += sweep[i-1][j] + sweep[i][j-1] - sweep[i-1][j-1];
		if (sweep[i][j]) res++;
	}
	cout << res;
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++){
//		for (int d1 = 0; d1 < 3; d1++) for (int d2 = 0; d2 < 3; d2++){
//			//if (visited[i][j][d1][d2]) cout << i << " " << j << " " << dimension[d1] << " " << dimension[d2] << endl;
//			//if (visited[i][j][d1][d2]) cout << i << " " << j << " " << d1 << " " << d2 << endl;
//		}
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++) cout << S[i][j] << " ";
//		cout << endl;
//	}
	
	return 0;
}

//ti sweep for theo chieu ngang (O[i][j])
