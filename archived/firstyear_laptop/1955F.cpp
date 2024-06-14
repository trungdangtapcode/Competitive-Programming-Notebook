#include<bits/stdc++.h>

using namespace std;
const int maxN = 205;
int f[maxN][maxN][maxN];
int p[5];

int g(int c1, int c2, int c3){
	return (((c1%2*1)^(c2%2*2)^(c3%2*3))==0);
}

int calc(int c1, int c2, int c3, int c0 = 0){
//	cout << c1 << " " << c2 << " " << c3 << " " << f[c1][c2][c3]<<" \n";
	if (f[c1][c2][c3]!=-1) return f[c1][c2][c3];
	int &res = f[c1][c2][c3]; 
	res = 0;
	if (c1) res = max(res,calc(c1-1,c2,c3)+g(c1,c2,c3) );
	if (c2) res = max(res,calc(c1,c2-1,c3)+g(c1,c2,c3) );
	if (c3) res = max(res,calc(c1,c2,c3-1)+g(c1,c2,c3) );
	return res;
}

void solve(){
	cin >> p[1] >> p[2] >> p[3] >> p[4];
	int res = calc(p[1],p[2],p[3]);
//	cout << res << " " << g(p[1],p[2],p[3])<< "\n";
//	if (g(p[1],p[2],p[3])){
//		if (p[0]==0) res--;
//		else {
//			p[0]--;
//			if (res) res += p[0];
//		}
//	} else {
//		if (p[0]==0){
//			
//		} else {
//			if (res) res += p[0];
//		}
//	}
	cout << res+p[4]/2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 200; i++) for (int j = 0; j <= 200; j++) for (int k = 0; k <= 200; k++) f[i][j][k] = -1;
	f[0][0][0] = 0;
	int t; cin >> t;
	while (t--)
	solve();
}

