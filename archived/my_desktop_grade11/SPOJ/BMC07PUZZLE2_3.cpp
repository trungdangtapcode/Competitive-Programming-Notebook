#include <bits/stdc++.h>
#define fix cout << "fixed " << endl;

using namespace std;

long long int p = 1e9+7;
long long int factor[1000010],factorIn[1000010],numberIn[1000010];
long long int g[1000010];
long long int x, res;
int m , n;


long long int nCr(int n, int r){
	if (n < r||r < 0) return 0;
	return (factor[n]*factorIn[r]%p*factorIn[n-r]%p);
}
long long int countWay(int n, int m){
	return nCr(n+m-2,n-1);
}
long long int f(int d, long long int x1, long long int y1, long long int x2, long long int y2){
	int countX = (int)((long long int)(x2/d) - (long long int)(x1/d)) - ((x1%d==0)?0:1) + 1;
	int countY = (int)((long long int)(y2/d) - (long long int)(y1/d)) - ((y1%d==0)?0:1) + 1;
	return countWay(countX,countY);
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
	
	int t; cin >> t;
	while (t--){
		res = 0;
		cin >> x >> n >> m;
		if(m == 1 && n ==1){
			cout << x*x%p << '\n';
			continue;
		}else if(n==1 || m == 1){
			cout << x%p << '\n';
			continue;
		} 
		vector <int> d;
		int nGCD = __gcd(x,x+n-1);
		int mGCD = __gcd(x,x+m-1);
		for (int i = 1; i*i <= max(nGCD,mGCD); i++){
			if (nGCD%i==0) d.push_back(i), d.push_back(nGCD/i);
			if (mGCD%i==0) d.push_back(i), d.push_back(mGCD/i);
		}
		sort(d.begin(),d.end());
		d.resize(unique(d.begin(),d.end()) - d.begin());
		
		for (int i = d.size()-1; i >= 0; i--){
			g[d[i]] = f(d[i],x,x,x+n-1,x+m-1);
			for (int j = i+1; j < d.size(); j++) if (d[j]%d[i] == 0){
				g[d[i]] -= g[d[j]];
			}
			res = (res+d[i]*g[d[i]]%p)%p;
		}
		cout << res << '\n';
	}
	
	return 0;
}




//		for (int i = 1; i*i <= 5e5; i++) if (x%i==0){
//			if ((x+n-1)%i==0||(x+m-1)%i==0) d.push_back(i);
//			int j = x/i
//			int in = (n-1)/i; int im = (m-1)/i;
//			//if ((x+n-1)%j==0||(x+m-1)%j==0) d.push_back(j); 
//		}
//		sort(d.begin(),d.end());
//		d.resize(unique(d.begin(),d.end()) - d.begin());
