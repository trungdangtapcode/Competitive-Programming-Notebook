#include <bits/stdc++.h>
#define fix cout << "fixed " << endl;

using namespace std;

long long int p = 1e9+7;
long long int factor[500005];
long long int g[500005];
long long int x;
int m , n;

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
long long int nCr(int n, int r){
	if (n < r||r < 0) return 0;
	return (factor[n]*invertMul(factor[r])%p*invertMul(factor[n-r])%p);
}
long long int countWay(int n, int m){
	return nCr(n+m-2,n-1);
}
long long int f(int d, long long int x1, long long int y1, long long int x2, long long int y2){
	int countX = (long long int)(x2/d) - (long long int)(x1/d) - ((x1%d==0)?0:1) + 1;
	int countY = (long long int)(y2/d) - (long long int)(y1/d) - ((y1%d==0)?0:1) + 1;
	return countWay(countX,countY);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	factor[0] = 1;
	for (int i = 1; i <= 5e5; i++) factor[i] = factor[i-1]*i%p;
	
	int t; cin >> t;
	while (t--){
		memset(g,0,sizeof(g));
		long long int res = 0;
		cin >> x >> n >> m;
		vector <int> d;
		if(m == 1 && n ==1){
			cout << x*x%p << '\n';
			continue;
		}else if(n==1 || m == 1){
			cout << x%p << '\n';
			continue;
		} 
		for (int i = 5e5; i >= 1; i--) if (x%i==0&&((x+n-1)%i==0||(x+m-1)%i==0)) d.push_back(i);
		//for (int i = 0; i <d.size(); i++) cout << d[i] << " "; cout << endl;
		for (int i = 0; i <d.size(); i++){
			//g[d[i]] = f(d[i],x,x,x+n-1,x+m-1);
			g[d[i]] = nCr((n-1)/d[i]+(m-1)/d[i],(n-1)/d[i]);
			//cout << d[i] << " " << g[d[i]] << endl;
			for (int j = i-1; j >= 0; j--) if (d[j]%d[i] == 0){
				g[d[i]] -= g[d[j]];
			}
			res = (res+d[i]*g[d[i]]%p)%p;
		}
		cout << res << '\n';
	}
	
	return 0;
}
