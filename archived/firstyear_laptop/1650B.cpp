#include<bits/stdc++.h>

using namespace std;
int l, r, a;
int pref(int x){
	return x*(x+1)/2;
}
int calc1(){
	int ll = l/a+1, rr = r/a;
	return (pref(r%a)+pref(a-1)-pref(l%a-1)+ pref(a-1)*(rr-ll));
}
int calc2(){
	int res = 0;
	for (int i = l; i <= r;){
		int j = min(r+1,(i/a+1)*a);
		res += i/a*(j-i);
		i = j;
	}
	return res;
}
void solve(){
	cin >> l >> r >> a;
//	cout << calc1() + calc2() << "\n";
	int res = r/a+r%a;
	if (r/a*a-1>=l) res = max(res,r/a-1+a-1);
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

