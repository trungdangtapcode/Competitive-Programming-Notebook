#include <bits/stdc++.h>
#define fix cout << "fixed " << endl;

using namespace std;

long long int p = 1e9+7;
long long int factor[1000010],factorIn[1000010],numberIn[1000010];
int g[1000010];
long long int x, cnt;
int m , n;


long long int nCr(int n, int r){
	if (n < r||r < 0) return 0;
	return (factor[n]*factorIn[r]%p*factorIn[n-r]%p);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	factor[0] = 1; numberIn[0] = 1; factorIn[0] = 1; 
	factor[1] = 1; numberIn[1] = 1; factorIn[1] = 1; 
	for (int i = 2; i <= 1e6+5; i++){
		factor[i] = factor[i-1]*i%p;
		numberIn[i] = numberIn[p % i] * (p - p / i) % p;
		factorIn[i] = factorIn[i-1]*numberIn[i]%p;
	}
	//cout << "nCr = "<< nCr(500000,499999) << endl;
	int t; cin >> t;
	while (t--){
		memset(g,0,sizeof(g));
		long long int res = 0;
		cin >> x >> n >> m;
		if(m == 1 && n ==1){
			cout << x*x%p << '\n';
			continue;
		}else if(n==1 || m == 1){
			cout << x%p << '\n';
			continue;
		} 
		vector <int> d;
		for (int i = 5e5; i >= 1; i--) if (x%i==0&&((x+n-1)%i==0||(x+m-1)%i==0)) d.push_back(i);
		for (int i = 0; i <d.size(); i++){
			g[d[i]] = nCr((n-1)/d[i]+(m-1)/d[i],(n-1)/d[i]);
			for (int j = i-1; j >= 0; j--) if (d[j]%d[i] == 0){
				g[d[i]] -= g[d[j]];
			}
			res = (res+d[i]*g[d[i]]%p)%p;
		}
		cout << res << '\n';
	}
	
	return 0;
}
