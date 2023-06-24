#include <bits/stdc++.h>

using namespace std;
int fact[1000005], inNum[1000005], inFact[1000005], f[1000005];
int a, b, q, x, t, pos1, pos2, cur, res;
const int p = 1e9 + 7;

int nCr(int n, int r){
	return 1ll*fact[n]*inFact[r]%p*inFact[n-r]%p;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fact[0] = fact[1] = inNum[0] = inNum[1] = inFact[0] = inFact[1] = 1;
	for (int i = 2; i <= 1e6; ++i){ //2e6
		fact[i] = 1ll*fact[i-1]*i%p;
		inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p;
		inFact[i] = 1ll*inFact[i-1]*inNum[i]%p;
	}
	cin >> a >> b >> q;
	if (a>b) swap(a,b);
	f[0] = 1;
	for (int i = 1; i <= a; ++i){
		f[i] = (f[i-1]+1ll*nCr(a,i)*nCr(b,i))%p;
	}
	while (q--){
		cin >> x >> t;
		pos1 = max(x-t,0);
		pos2 = min(x+t,a);
		if (pos1>a||pos2<0){
			res = f[a];
			cout << res << '\n';
			continue;
		}
		cur = f[pos2];
		if (pos1>0) cur -= f[pos1-1];
		res = f[a] - cur;
		res = (res%p+p)%p;
		cout << res << '\n';
	}
}
