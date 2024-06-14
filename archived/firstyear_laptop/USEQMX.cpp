#include<bits/stdc++.h>

using namespace std;
#define ld long double
const int maxN = 1e5 + 5;
int n, k;
ld a[maxN], b[maxN];
bool check(ld x){
	ld mn = 1e18;
	for (int i = 1; i <= n; i++){
		b[i] = a[i] - x, b[i] += b[i-1];
		if (i>=k) mn = min(mn,b[i-k]);
		if (b[i]>=mn) return 1;
	};
	return 0;
}
main(){
	cin >> n >> k;
	for (int i = 1, x; i <= n; i++){
		cin >> a[i];
	}
	ld l = -1e6, h = 1e6, m, res;
	for (int i = 0; i < 150; i++){
		m = (l+h)/2;
//		cout << l << " " << h << " => " << m<< "\n";
		if (check(m)){
			l = m;
			res = m;
		} else h = m;
	}
	cout << fixed << setprecision(5) << res;
	
	return 0;
}
