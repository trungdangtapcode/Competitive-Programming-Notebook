#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v, p;
int n, q, a, b, m;
int f(int x){
	int res = 0;
	for (int y: v) res += x/y;
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 2; i*i <= n; i++){
		if (n%i==0){
			p.push_back(i);
			while (n%i==0) n /= i;
		}
	}
	if (n!=1) p.push_back(n);
	int m = p.size();
	for (int i = 0; i < (1<<m); i++){
		int tmp = 1;
		for (int j = 0; j < m; j++) if (i&(1<<j)){
			tmp *= -p[j];
		}
		v.push_back(tmp);
	}
	
	while (q--){
		cin >> a >> b;
		cout << f(b) - f(a-1) << "\n";
	}
	
	return 0;
}
