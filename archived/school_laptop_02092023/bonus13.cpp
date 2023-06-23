#include<bits/stdc++.h>

using namespace std;
const int n = 8, dx[] = {1,2,2,1,-1,-2,-2,-1}, dy[] = {2,1,-1,-2,-2,-1,1,2}, vx[] = {-1,-1,-1,0,1,1,1,0}, vy[] = {-1,0,1,1,1,0,-1,-1};
int freex[65], freey[65], a[9][9], k, x[65], y[65], check[10][10];
typedef pair<int,int> ii;
ii go[10][10][10];

int main(){
	cin >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = -1;
	for (int i = 0, c; i < k; i++){
		cin >> x[i] >> y[i] >> c;
		a[x[i]][y[i]] = c;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		go[i][j][0] = go[i-1][j-1][0];
		go[i][j][1] = go[i-1][j][1];
		go[i][j][7] = go[i][j-1][7]; 
		if (a[i][j]!=-1) go[i][j][0] = go[i][j][1] = go[i][j][7] = {i,j};
	}
	for (int i = n; i > 0; i--) for (int j = n; j > 0; j--){
		go[i][j][4] = go[i+1][j+1][4];
		go[i][j][5] = go[i+1][j][5];
		go[i][j][3] = go[i][j+1][3]; 
		if (a[i][j]!=-1) go[i][j][4] = go[i][j][5] = go[i][j][3] = {i,j};
	}
	for (int i = 1; i <= n; i++) for (int j = n; j > 0; j--){
		go[i][j][2] = go[i-1][j+1][0];
		if (a[i][j]!=-1) go[i][j][2] = {i,j};
	}
	for (int i = n; i > 0; i--) for (int j = 1; j <= n; j++){
		go[i][j][6] = go[i+1][j-1][6];
		if (a[i][j]!=-1) go[i][j][6] = {i,j};
	}
	int cnt =0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (a[i][j]==-1){
		freex[cnt] = i, freey[cnt] = j;
		cnt++;
	}
	vector<int> hau_move({0,1,2,3,4,5,6,7});
	vector<int> xe_move({1,3,5,7});
	vector<int> tuong_move({0,2,4,6});
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
		cout << "\n";
	}
	long long res = 0;
	for (int hau = 0; hau < cnt; hau++) for (int xe = 0; xe < cnt; xe++) if (hau!=xe) for (int tuong = 0; tuong < cnt; tuong++) if (tuong!=hau&&tuong!=xe) for (int ma = 0; ma < cnt; ma++) if (ma!=tuong&&ma!=xe&&ma!=hau){
//		if (xe==0&&tuong==1&&ma==2) cout << hau << " " << xe << " " << tuong << "\n";
		for (int i = 0; i < k; i++) check[x[i]][y[i]] = false;
		for (int it: hau_move){
			int i = freex[hau], j = freey[hau];
			while (i&&j){
				check[i][j] = true;
				tie(i,j) = make_tuple(go[i+vx[it]][j+vy[it]][it].first,go[i+vx[it]][j+vy[it]][it].second);
			};
		}
		for (int it: xe_move){
			int i = freex[xe], j = freey[xe];
			while (i&&j){
				check[i][j] = true;
				tie(i,j) = make_tuple(go[i+vx[it]][j+vy[it]][it].first,go[i+vx[it]][j+vy[it]][it].second);
			};
		}
		for (int it: tuong_move){
			int i = freex[tuong], j = freey[tuong];
			while (i&&j){
				check[i][j] = true;
				tie(i,j) = make_tuple(go[i+vx[it]][j+vy[it]][it].first,go[i+vx[it]][j+vy[it]][it].second);
			};
		}
		int pi = freex[ma], pj = freey[ma]; 
		for (int i = 0; i < 8; i++){
			int ni = pi + dx[i], nj = pj + dy[i];
			if (ni<1||nj<1||ni>n||nj>n) continue;
			check[ni][nj] = true;
		} 
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= n; j++){
//				if (a[i][j]==-1) cout << 0 << " ";
//				else cout << check[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << freex[hau] << "," << freey[hau] << "\n";
//		cout << freex[tuong] << "," << freey[tuong] << "\n";
//		cout << freex[xe] << "," << freey[xe] << "\n";
//		cout << freex[ma] << "," << freey[ma] << "\n";
		long long cur = 0;
		for (int i = 0; i < k; i++) if (check[x[i]][y[i]]) cur += a[x[i]][y[i]];
		res = max(res,cur);
	}
	cout << res;
	return 0;
}
