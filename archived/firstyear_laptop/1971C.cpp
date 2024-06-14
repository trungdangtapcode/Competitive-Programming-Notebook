#include<bits/stdc++.h>

using namespace std;
int a, b, c, d;
void solve(){
	cin >> a >> b >> c >> d;
	if (a>b) swap(a,b);
	if (c>d) swap(c,d);
	if (a>c) swap(a,c), swap(b,d);
	cout << (c<b&&b<d&&a<c?"YES\n":"NO\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

