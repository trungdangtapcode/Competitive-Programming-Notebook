#include <bits/stdc++.h>
#define fix cout << "fixed " << endl;

using namespace std;

long long int p = 1e9+7;
long long int factor[100005];
long long int g[500005];
long long int x, m , n;

long long int invertMul(long long int x){
	long long int y = p - 2;
	long long int res = 1;
	while (y!=0){
		if (y%2==1) res = res*x%p;
		y = y/2;
		x = x*x%p;
	}
	return res;
}
long long int nCr(long long int n, long long int r){
	//if (n < r) return -1;
	if (n < r) return 0;
	//if (r == 0) return 0;
	return (factor[n]*invertMul(factor[r])%p*invertMul(factor[n-r])%p);
}
long long int countWay(long long int n, long long int m){
	return nCr(n+m-2,n-1); //or m-1
}
long long int f(long long int d, long long int x1, long long int y1, long long int x2, long long int y2){ 
	//TREN LUOI OXY CHIA CHET CHO D KHONG PHAN BIET DAU/CUOI (COI CO DI DUONG TU DINH DAU TOI CUOI KHONG)
	long long int countX = 0, countY = 0;
	for (long int i = x1; i <= x2; i++) if (i%d==0) countX++;
	for (long int i = y1; i <= y2; i++) if (i%d==0) countY++;
	return countWay(countX,countY);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	factor[0] = 1;
	for (int i = 1; i <= 100000; i++) factor[i] = factor[i-1]*i%p;
	
	//x = 1; n = 2; m = 3;
	int t; cin >> t;
	while (t--){
		memset(g,0,sizeof(g));
		cin >> x >> n >> m;
		for (int i = 5e5; i >= 1; i--) if (x%i==0&&((x+n-1)%i==0||(x+m-1)%i==0)){
			g[i] = f(i,x,x,x+n-1,x+m-1);
			cout << i << " " << g[i] << endl;
			for (int j = 2*i; j <= 5e5; j += i){
				g[i] -= g[j];
			}
		}
		long long int res = 0;
		for (int i = 5e5; i >= 1; i--){
			res += i*g[i]%p;
			res %= p;
		}
		cout << res << endl;
//		for (int i = 30; i >= 1; i--){
//			cout << i << " " << g[i] << endl;
//		}
	}
	//cout << f(1,1,1,2,3);
	//cout << countWay(2,3);
	//cout << nCr(5,2);
	
	return 0;
}
