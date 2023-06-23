#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int n, m, d[1005][1005][4];
string s[1005];
iii x;
ii y;

void bfs(){
	queue<iii> q;
	q.push(x);
	while (!q.empty()){
		iii u = q.front();
		q.pop();
		int ux = u.first.first, uy = u.first.second, des = u.second;
		for (int i = 0; i < 2; i++){
			int vx = ux + dx[(des+i)%4], vy = uy + dy[(des+i)%4];
			if (vx<1||vx>n||vy<1||vy>m) continue;
			if (s[vx][vy]=='#') continue;
			if (d[vx][vy][(des+i)%4]>d[ux][uy][des]+1){
				d[vx][vy][(des+i)%4] = d[ux][uy][des]+1;
				q.push({{vx,vy},(des+i)%4});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = "#" + s[i];
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		d[i][j][0] = d[i][j][1] = d[i][j][2] = d[i][j][3] = 1e9; 
		if (s[i][j]=='D'){
			y.first = i;
			y.second = j;
		}
		if (s[i][j]=='E'){
			x.first.first = i;
			x.first.second = j;
			x.second = 0;
		}
		if (s[i][j]=='S'){
			x.first.first = i;
			x.first.second = j;
			x.second = 1;
		}
		if (s[i][j]=='W'){
			x.first.first = i;
			x.first.second = j;
			x.second = 2;
		}
		if (s[i][j]=='N'){
			x.first.first = i;
			x.first.second = j;
			x.second = 3;
		}
	}
	bfs();
	for (int i = 1; i <= n; i++)
	
	return 0;
}

/*TEST:
17 19
...................
.#.#.###.#.#.#.###.
.....###.#.#.#.###.
.#.#.###.#.#.#.###.
.###...............
.###.#.#.###.###.#.
.###..D..###.###.#.
.###.###.###.###.#.
.....###...........
.#.#.###.#.###.#.#.
...........###.....
.#.#.###.#.###.#.#.
...........###.....
.#.#.###.#.###.#.#.
.###......E........
.#.#.###.#.###.#.#.
...................
*/

