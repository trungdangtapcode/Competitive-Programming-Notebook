#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int>> i3;
queue<i3> q; //uu tien theo dist = dist thuc + time lum da
//dist thap nhat -> dist thuc thap nhat vi time lum da kq luon = length(t);
int ux, uy, ud, vx, vy, vd, d[305][305][305];
char a[305][305];
string t;
int n, m, x, y;
int dx[5] = {0,0,1,0,-1}; //vl phai uu tien cho dam chan tai cho hay (0,0) ngay dau mang
int dy[5] = {0,1,0,-1,0}; //chu khong thoi dist co cung vay ma real dist do di zic zac truoc nen bi sai
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	memset(d,-1,sizeof(d));
	
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j]; //O[][]
	cin >> t;
	int l = t.length();
	
	d[0][x][y] = 0;
	q.push({0,{x,y}});
	while (!q.empty()){
		ux = q.front().second.first;
		uy = q.front().second.second;
		ud = q.front().first;
		q.pop();
		for (int i = 0; i < 5; i++){
			vx = ux + dx[i];
			vy = uy + dy[i];
			if (vx>n||vx<1||vy>m||vy<1) continue;
			vd = ud + (a[vx][vy]==t[ud]&&i==0); //[0..l-1]; i==0: tao do tre bfs (queue) cho nhung path di chuyen
			if (d[vd][vx][vy]!=-1) continue;
			d[vd][vx][vy] = d[ud][ux][uy] + (i!=0); //not i!=4 vay no se tham di zic zac hon
			if (vd==l){
				cout << d[vd][vx][vy] << '\n';
				return 0;
			}
			q.push({vd,{vx,vy}});
		}
	}
	
	return 0;
}


//		if (a[ux][uy]==t[ud]){ //huong di thu 5
//			q.push({ud+1,{ux,uy}});
//			if (ud+1==0)
//		}
