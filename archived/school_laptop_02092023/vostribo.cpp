#include<bits/stdc++.h>

using namespace std;
#define int long long
const int p = 1e15+7;
struct matrix{
	int a[4][4];
	matrix(){
		memset(a,0,sizeof(a));
	}
	decltype(a[0])& operator[](int x){
		return a[x];
	}
	void setNum(){
		for (int i = 0; i < 4; i++) a[i][i] = 1;
 	}
	matrix operator*(matrix other){
		matrix res = matrix();
		for (int i = 0; i < 4; i++) for (int j= 0; j < 4; j++) for (int k = 0; k < 4; k++){
			(res[i][j] += (__int128)a[i][k]*other[k][j]%p)%=p;
		}
		return res;
	}
} coef, ans;
matrix getPow(matrix a, int b){
	matrix res = matrix();
	res.setNum();
	while (b){
		if (b&1) res = res*a;
		a = a*a;
		b >>= 1;
	}
	return res;
}

int n;
void solve(){
	cin >> n;
	if (n==1) cout << 1;
	else if (n==2) cout << 3;
	else if (n==3) cout << 6;
	else cout << (ans*getPow(coef,n-3))[0][3];
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	coef = matrix();
	coef[0][0] = 0; coef[0][1] = 0; coef[0][2] = 1; coef[0][3] = 1; 
	coef[1][0] = 1; coef[1][1] = 0; coef[1][2] = 1; coef[1][3] = 1; 
	coef[2][0] = 0; coef[2][1] = 1; coef[2][2] = 1; coef[2][3] = 1; 
	coef[3][0] = 0; coef[3][1] = 0; coef[3][2] = 0; coef[3][3] = 1; 
	ans = matrix();
	ans[0][0] = 1; ans[0][1] = 2; ans[0][2] = 3; ans[0][3] = 6; 
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
