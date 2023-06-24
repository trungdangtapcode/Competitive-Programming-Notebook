#include <bits/stdc++.h>

using namespace std;
int n, m;
string s;
const int INF = 1e4;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	vector<vector<bool>> b(n,vector<bool>(m));
	for (int i = 0; i < n; i++){
		cin >> s;
		for (int j = 0; j < m; j++) b[i][j] = (s[j]=='1');
	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++) cout << b[i][j] << " ";
//		cout << endl;
//	}
	vector<vector<int>> v(n,vector<int>(m,INF));
	vector<int> f(max(n,m)); //nay ghi n len RTE
	//trai qua phai
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			f[j] = b[i][j];
			if (b[i][j]&&j>0) f[j] = f[j-1] + 1;
			v[i][j] = min(v[i][j],f[j]);
		}
	}
	//phai qua trai
	for (int i = 0; i < n; i++){
		for (int j = m-1; j >= 0; j--){
			f[j] = b[i][j];
			if (b[i][j]&&j<m-1) f[j] = f[j+1] + 1;
			v[i][j] = min(v[i][j],f[j]);
		}
	}
	//tren xuong duoi
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			f[j] = b[j][i];
			if (b[j][i]&&j>0) f[j] = f[j-1] + 1;
			v[j][i] = min(v[j][i],f[j]);
		}
	}
	//duoi len tren
	for (int i = 0; i < m; i++){
		for (int j = n-1; j >= 0; j--){
			f[j] = b[j][i];
			if (b[j][i]&&j<n-1) f[j] = f[j+1] + 1;
			v[j][i] = min(v[j][i],f[j]);
		}
	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++) cout << v[i][j] << " ";
//		cout << endl;
//	}
	int res = 0, resR = -1, resC = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) if (v[i][j] > res){
			res = v[i][j];
			resR = i;
			resC = j;
		};
	}
	if (res==0) cout << -1 << '\n';
	else cout << res*4 - 3 << '\n' << resR+1 << ' ' << resC+1 << '\n';
	
	return 0;
}
