#include<bits/stdc++.h>

using namespace std;
int a, b, c;
void solve(){
	cin >> a >> b>> c;
	long long res = b/3 + a;
	b %= 3;
	if (b&&c+b>=3){
		c -= 3-b;
		b = 0;
		res++;
	}
	if (b){
		cout << -1 << "\n";
		return;
	}
	res += (c+2)/3;
	cout << res << "\n";
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

