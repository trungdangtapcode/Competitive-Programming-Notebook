#include<bits/stdc++.h>

using namespace std;
int x, y;
void solve(){
	cin >> x >> y;
	int res = (y+1)/2;
	x -= res*15-4*y;
	if (x>0) res += (x+14)/15;
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

