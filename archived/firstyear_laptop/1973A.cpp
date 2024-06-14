#include<bits/stdc++.h>

using namespace std;
int a, b, c;
void solve(){
	cin >> a >> b >> c;
	if ((a+b+c)%2){
		cout << -1 <<"\n";
		return;
	}
	int res = (a+b+c)/2 - max(c-b-a,0)/2;
	cout << res << "\n";
//	int res = a/2;
//	a -= res*2, b -= res*2, c -= res*2;
//	res *= 3;
//	res += b;
//	c -= b, b = 0;
////	cout << a <<" " << b <<" " << c << "\n";
//	if (c<a) swap(a,c);
//	if ((c-a)%2){
//		cout << -1 << "\n";
//		return;
//	}
//	cout << res+a << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

