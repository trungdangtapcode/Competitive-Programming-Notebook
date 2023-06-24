#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int,pair<int,int>> id;
queue<id> q;
int dist[305][305][305];
int n, m, k;
char a[305][305];
string t;
int ur, uc, ud, vr, vc, vd;
int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	memset(dist,-1,sizeof(dist));
	cin >> n >> m >> k >> t; 
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j]==t[0]) q.push({1,{i,j}}), dist[1][i][j] = 1;
	while (!q.empty()){ 
		ur = q.front().second.first; 
		uc = q.front().second.second;
		ud = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++){
			vr = ur + dr[i];
			vc = uc + dc[i];
			if (vr<0||vr>=n||vc<0||vc>=m) continue;
			vd = ud + (t[ud]==a[vr][vc]); 
			if (dist[vd][vr][vc]!=-1) continue; 
			dist[vd][vr][vc] = dist[ud][ur][uc] + 1; 
			if (vd==k) {
				cout << dist[vd][vr][vc] << '\n';
				return 0;
			}
			q.push({vd,{vr,vc}});
		}
	}
	
	return 0;
}

//no clean
/*
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int>> id;
queue<id> q;
int dist[305][305][305];
int n, m, k;
char a[305][305];
string t;
int ur, uc, ud, vr, vc, vd;
int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};
int main(){
	memset(dist,-1,sizeof(dist));
	cin >> n >> m >> k >> t; 
	for (int i = 0; i < n; i++) scanf("%s",a[i]);//cin >> a[i][j];
//	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) q.push({0,{i,j}}), dist[i][j][0] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j]==t[0]) q.push({1,{i,j}}), dist[1][i][j] = 1;
	while (!q.empty()){ //[x][y]
		ur = q.front().second.first; //solve
		uc = q.front().second.second;
		ud = q.front().first;
//		cout << ur << " " << uc << " " << ud << " " << endl;
		q.pop();
		for (int i = 0; i < 4; i++){
			vr = ur + dr[i];
			vc = uc + dc[i];
			if (vr<0||vr>=n||vc<0||vc>=m) continue;
			vd = ud + (t[ud]==a[vr][vc]); //to calc vr, vc, vd
//			cout << t[ud] << " " << a[vr][vc] << " " << dist[vr][vc][vd]<< endl;
			if (dist[vd][vr][vc]!=-1) continue; //solved
			dist[vd][vr][vc] = dist[ud][ur][uc] + 1; //query solve new
			if (vd==k) {
	//			cout << dist[vr][vc][vd] << '\n';
				cout << dist[vd][vr][vc] << '\n';
				return 0;
			}
			q.push({vd,{vr,vc}});
		}
	}
	
	return 0;
}
*/
