#include<bits/stdc++.h>

using namespace std;
int x;
typedef pair<int,int> ii;
void solve(){
//	ii res = {0,0};
	cin >> x;
//	for (int i = 1; i < x; i++) res = max(res,ii{__gcd(x,i)+i,i});
	cout << x-1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

