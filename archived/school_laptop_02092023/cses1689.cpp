#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int dx[8] = {2,1,-1,-2,-2,-1,1,2}, dy[8] = {1,2,2,1,-1,-2,-2,-1};
int x, y, board[9][9];

int danhgia(int x, int y){
	int res = 0;
	for (int i = 0; i < 8; i++){
		int xx = x + dx[i], yy = y + dy[i];
		if (xx>=1&&xx<=8&&yy>=1&&yy<=8&&!board[xx][yy]) res++;
	}
	return res;
}
bool dien(int x, int y, int move){
	if (move==64){
		for (int i = 1; i <= 8; i++){
			for (int j = 1; j <= 8; j++) cout << board[i][j] << " ";
			cout << "\n";
		}
		return true;
	}
	vector<iii> v;
	for (int i = 0; i < 8; i++){
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1||xx>8||yy<1||yy>8||board[xx][yy]) continue;
		v.push_back({danhgia(xx,yy),{xx,yy}});
	}
	sort(v.begin(),v.end());
	for (auto it: v){
		int x = it.second.first, y = it.second.second, d = it.first;
		board[x][y] = move+1;
//		cout << x << " " << y << " " << d << " " << move << endl;
		if (dien(x,y,move+1)) return true;
		board[x][y] = 0;
	}
	
	return false;
}

int main(){
	cin >> x >> y;
	swap(x,y);
	board[x][y] = 1;
	dien(x,y,1);
	
	
	return 0;
}
