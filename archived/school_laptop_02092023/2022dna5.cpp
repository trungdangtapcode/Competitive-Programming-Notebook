#include<bits/stdc++.h>

using namespace std;
long long int memo[3005][1005][2][2], sum111[3005];
int n, k;
const int p = 1e9+7;

int calc(int x, int pos){
	int base2 = 1 << 2-(pos-1)%3;
	pos = (pos-1)/3+1;
	return 1ll*pos*x*base2%k*sum111[n-pos+1]%k;
}

int cnt = 0;
int f(int x, int y, int ok1, int ok2){
	if (x==0) return 0;
	if (memo[x][y][ok1][ok2]!=-1) return memo[x][y][ok1][ok2];
	long long int res = 0;
//	if (ok1) res += f(x-1,(y-calc(,x)+k)%p,);
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int l = 0; l < 2; l++) for (int u = 0; u < 2; u++) for (int v = 0; v < 2; v++){
		if (!ok1&&(i!=j||u)) continue;
		if (!ok2&&(j!=l||v)) continue;
		if (ok1&&i==j&&!u) continue;
		if (ok2&&j==l&&!v) continue;
		if (!u&&i>j) continue;
		if (!v&&j>l) continue;
//		if (x==3) cout << i << " " << j << " " << l << " " << u << " " << v << " " << res<< endl;
		res += f(x-1,(y-calc(i,x)-calc(j,x)-calc(l,x)+5*k)%k,u,v);
		res %= p;
//		if (ok1) res += f(x-1,(y-calc(i,x)+k)%k,1,ok2) + f(x-1,(y-calc(i,x)+k)%k,0,ok2);
	}
	
//	cout << x << " " << y << " " << ok1 << " " << ok2 << " -> " << res << endl;
	return memo[x][y][ok1][ok2] = res;
}

int main(){
	cin >> n >> k;
//	n = 2, k = 11;
	memset(memo,-1,sizeof(memo));
	for (int i = 1; i <= 3*n; i++) sum111[i] = (sum111[i-1]*10+1)%k;
	for (int i = 0; i < k; i++) memo[1][i][0][0] = memo[1][i][0][1] = memo[1][i][1][0] = memo[1][i][1][1] = 0;
	for (int i = 0; i < k; i++) memo[3][i][0][0] = memo[3][i][0][1] = memo[3][i][1][0] = memo[3][i][1][1] = 0;
	for (int i = 1; i < 8; i++) for (int j = i; j < 8; j++) for (int l = j; l < 8; l++)
		memo[3][(calc(i,3)+calc(j,3)+calc(l,3))%k][i<j][j<l]++;
//	cout << f[1][];
//	cout << memo[1][2][0][0];
	cout << f(3*n,0,1,1);
//	cout << f(3*n,0,1,1);
	cout << " " << cnt;
	return 0;
}
