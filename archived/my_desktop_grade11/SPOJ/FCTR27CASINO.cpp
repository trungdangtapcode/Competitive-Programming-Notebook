#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
map<ii,int> m;
int n, pos[3][300005], res;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0, x; i < 3; i++){
		for (int j = 0; j < n; j++){
			cin >> x;
			x--;
			pos[i][x] = j;
		}
	}
	for (int i = 0, forw1, forw2; i < n; i++){
		forw1 = (pos[0][i]-pos[1][i]+n)%n;
		forw2 = (pos[0][i]-pos[2][i]+n)%n;
		m[{forw1,forw2}]++;
	}
	for (auto it: m) res = max(res,it.second);
	cout << res;
	
	return 0;
}
