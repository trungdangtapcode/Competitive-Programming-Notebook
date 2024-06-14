#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 1e3+5, mod = 998244353;
int n, m, a[maxN][maxN], f[maxN][maxN];
vector<ii> pos[maxN*maxN];

int getPow(int a, int n){
	int res = 1;
	a %= mod;
	while (n){
		if (n&1) res = res*a%mod;
		n /= 2;
		a = a*a%mod;
	}
	return res;
}
int inv(int a){
	return getPow(a,mod-2);
}

main(){
	cin >> n >> m;
	vector<int> vec;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			vec.push_back(a[i][j]);
		}
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			a[i][j] = lower_bound(vec.begin(),vec.end(),a[i][j])-vec.begin()+1;
			pos[a[i][j]].push_back({i,j});
		}
	}
	assert(vec.size()<=m*n);
	//(i-x)^2 + (j-x)^2 => i^2 + j^2 - 2ix - 2jy + x^2 + y^2 => +(i^2+j^2, -2i, -2j, 1) 
	int coef = 0, coef_x = 0, coef_y = 0, coef_2 = 0;
	for (int i = 1; i <= n*m; i++){
		if (i!=*vec.begin()) for (auto it: pos[i]){
			int x = it.first, y = it.second;
			f[x][y] = (coef + coef_x*x + coef_y*y + coef_2*(x*x%mod + y*y%mod))%mod;
			f[x][y] = f[x][y]*inv(coef_2)%mod;
		}
		for (auto it: pos[i]){
			int x = it.first, y = it.second;
			(coef += x*x + y*y + f[x][y])%= mod;
			(coef_x -= 2*x)%= mod;
			(coef_y -= 2*y)%= mod;
			(coef_2 += 1)%= mod;
		}
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			cout << f[i][j]*2%mod << " ";
//		}
//		cout << "\n";
//	}
	int x, y;
	cin >> x >> y;
	(f[x][y] += mod)%=mod;
	cout << f[x][y] << "\n";
	
	
	return 0;
}
