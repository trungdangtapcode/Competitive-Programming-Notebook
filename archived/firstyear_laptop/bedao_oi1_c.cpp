#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int idx = 1, n, m, a[105];
const int mod = 1e9+7;
struct mat{
	int a[105][105];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator*(mat other){
		mat res;
		for (int i = 1; i <= idx; i++){
			for (int j = 1; j <= idx; j++){
				for (int k = 1; k <= idx; k++){
					(res.a[i][j] += 1ll*a[i][k]*other.a[k][j]%mod)%=mod;
				}
			}
		}
		return res;
	}
	void print(){
		vector<ii> res;
		for (int i = 1; i <= idx; i++){
			for (int j = 1; j <= idx; j++){
				cout << a[i][j] << " ";
				if (a[i][j]) res.push_back({i,j});
			}
			cout << "\n";
		}
		for (auto x: res) cout << x.first << " " << x.second << " = " << a[x.first][x.second]<< "\n";
		cout << "\n";
	}
};
mat power(mat a, int n){
	mat res;
	for (int i = 1; i <= idx; i++) res.a[i][i] = 1;
	while (n>0){
		if (n%2) res = res*a;
		a = a*a;
		n /= 2; 
	}
	return res;
}

int main(){
	freopen("nequation.inp","r",stdin);
	freopen("nequation.out","w",stdout);
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	mat matA;
	
	matA.a[1][1] = 1;
	int u = 1;
	for (int i = 1; i <= n; i++){
		matA.a[u][++idx] = 1;
		int v = idx;
		for (int j = 1; j < a[i]; j++) matA.a[idx][++idx] = 1;
		matA.a[idx][v] = 1;
		u = v;
	}
	auto res = power(matA,m-sum+n);
//	res.print();
//	cout << u << "\n";
	cout << res.a[1][u];
	
	
	return 0;
}
