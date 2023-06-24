#include<bits/stdc++.h>

using namespace std;
long long int a, b, x, y, la, lb, ra, rb, na, nb, uc;
long double tmp1, tmp2;
void solve(){
	cin >> x >> y;
	a = 1; b = 1;
	la = 0; lb = 1;
	ra = 1; rb = 0;
	while (true){
		tmp1 = (long double)a/b, tmp2 = (long double)x/y;
		if (tmp1==tmp2){
			cout << "\n";
			return;
		}
		if (tmp1<tmp2){
			cout << "R";
			na = ra+a; nb = rb+b;
			la = a; lb = b;
		} else {
			cout << "L";
			na = la+a; nb = lb+b;
			ra = a; rb = b;
		}
		uc = __gcd(na,nb);
		na/=uc; nb/=uc;
		a = na; b = nb;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--) solve();
	
	return 0;
}
