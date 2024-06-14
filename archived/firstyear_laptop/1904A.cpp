#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int dx[] = {1,1,0,3,2,2,3,0}, dy[] = {3,0,1,1,0,3,2,2};
int a, b, xk, yk, xq, yq;
void solve(){
	cin >> a >> b >> xk >> yk >> xq >> yq;
	vector<int> v = {a,b,-b,-a};
	set<ii> sk, sq;
	for (int i = 0; i < 8; i++){
		int x = xk + v[dx[i]], y = yk + v[dy[i]];
		sk.insert({x,y});
	}
	int res = 0;
	for (int i = 0; i < 8; i++){
		int x = xq + v[dx[i]], y = yq + v[dy[i]];
		if (!sq.count({x,y})&&sk.count({x,y})) res++;
		sq.insert({x,y});
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

