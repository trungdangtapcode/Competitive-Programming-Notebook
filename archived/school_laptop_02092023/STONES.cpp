#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, s[100005], p[100005], g;
main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	for (int i = 0; i < n; i++){
		cin >> p[i];
		g = __gcd(g,p[i]);
	}
	for (int i = 0; i < n; i++) p[i] /= g;
	auto eval = [&](int x){
		int res = 0;
		for (int i = 0; i < n; i++) res += abs(s[i]-x*p[i]);
		return res;
	};
	int l = 0, h = 1e9, m, res = 1e9;
	while (l<=h){
		int m = (l+h)/2;
		if (eval(m)>eval(m+1)){
			res = min(res,eval(m+1));
			l = m+1;
		} else {
			res = min(res,eval(m));
			h = m-1;
		}
	}
	cout << res;
//	for (int i = 0; i <= n; i++) cout << eval(i) << " ";
	
	return 0;
}
