#include <bits/stdc++.h>

//0: Dong
//1: Bac
//2: Tay
//3: Nam

using namespace std;
int n, x, y, S;
typedef pair <int, int> toado;
toado ToaDo_chihuong[1005][1005][4]; //5000,5000: tu do
//toado TuDo[4] = {{0,5000},;
int S_loop[1005][1005][4];
bool mecung[1005][1005];
int vx[4] = {1,0,-1,0}, vy[4] = {0,-1,0,1};
const int INF = 1e9+100005;

int distance(toado a, toado b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	memset(S_loop,-1,sizeof(S_loop));
	cin >> n >> x >> y >> S;
	
	for (int i = 1; i <= n; i++){
		string str;
		cin >> str;
		for (int j = 1; j <= n; j++){
			mecung[j][i] = (str[j-1]=='#'); //[x (hoanh)][y (tung)]
		}
	}
	
	for (int i = 0; i <= n+1; i++){ //init Tay, Bac
		for (int j = 0; j <= n+1; j++){
			if (i==0||j==0){ //da bao trum toan bo nen khoi lo (Co So QHD)
				ToaDo_chihuong[j][i][1] = {j,-INF}; //Bac
				ToaDo_chihuong[j][i][2] = {-INF,i}; //Tay
			}else if (mecung[j][i]){
				ToaDo_chihuong[j][i][1] = {j,i+1}; //bi doi lai
				ToaDo_chihuong[j][i][2] = {j+1,i};
			} else {
				ToaDo_chihuong[j][i][1] = ToaDo_chihuong[j][i-1][1];
				ToaDo_chihuong[j][i][2] = ToaDo_chihuong[j-1][i][2];
			}
		}
	}
	for (int i = n+1; i >= 0; i--){ //init Dong, Nam
		for (int j = n+1; j >= 0; j--){
			if (i==n+1||j==n+1){ //tu do
				ToaDo_chihuong[j][i][3] = {j,INF}; //Nam
				ToaDo_chihuong[j][i][0] = {INF,i}; //Dong
			}else if (mecung[j][i]){
				ToaDo_chihuong[j][i][3] = {j,i-1}; //bi doi lai
				ToaDo_chihuong[j][i][0] = {j-1,i};
			} else {
				ToaDo_chihuong[j][i][3] = ToaDo_chihuong[j][i+1][3];
				ToaDo_chihuong[j][i][0] = ToaDo_chihuong[j+1][i][0];
			}
		}
	}
	
	int xx = x, yy = y, huongdi = 1; //Bac
	bool daXoaChuKi = false;
	while (S>0){ 
		if ((xx>=0&&xx<=n+1&&(huongdi==1||huongdi==3))||(yy>=0&&yy<=n+1&&(huongdi==0||huongdi==2))){ //vung xet: hinh chu thap (huong vao hoac ra me cung)
//			if (S_loop[min(max(xx,0),n+1)][min(max(yy,0),n+1)][huongdi]==-1) 
			S_loop[min(max(xx,0),n+1)][min(max(yy,0),n+1)][huongdi] = S;
//			cout << S << " at " << xx << " " << yy << " huong "<< huongdi << " -> ";
			toado tmp = ToaDo_chihuong[min(max(xx,0),n+1)][min(max(yy,0),n+1)][huongdi];
			S -= distance(tmp,{xx,yy});
			xx = tmp.first;
			yy = tmp.second;
//			cout << S << " at " << xx << " " << yy << " huong " << huongdi << '\n';
			huongdi = (huongdi+1)%4;
			int tmp2 = S_loop[min(max(xx,0),n+1)][min(max(yy,0),n+1)][huongdi];
			if (tmp2!=-1&&!daXoaChuKi&&S<tmp2)
				S %= (tmp2-S), daXoaChuKi = true;
		} else {
			xx += vx[huongdi]*S;
			yy += vy[huongdi]*S;
			S = 0;	
		}
	}
//	cout << S << " at " << xx << " " << yy << '\n';
	huongdi = (huongdi+1)%4;
	xx += vx[huongdi]*(-S);
	yy += vy[huongdi]*(-S);
	S = 0;
	cout << xx << " " << yy << '\n';
	
//	for (int i = 0; i <= n+1; i++){
//		for (int j = 0; j <= n+1; j++)
//			cout << mecung[j][i];
//		cout << endl;
//	}
	
//	for (int i = 0; i <= n+1; i++){
//		for (int j = 0; j <= n+1; j++)
//			cout << mecung[j][i] <<  "("<<ToaDo_chihuong[j][i][2].first << "," << ToaDo_chihuong[j][i][2].second << ") ";
//		cout << endl;
//	}
	
	return 0;
}
