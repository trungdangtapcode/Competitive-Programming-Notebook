#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
map<ii,int> mxy;
map<int,int> mx, my;
main(){
	int n, res = 0; cin >> n;
	for (int i = 1,x, y; i <= n; i++){
		cin >> x >> y;
		res += mx[x] + my[y] - mxy[{x,y}];
		mx[x]++;
		my[y]++;
		mxy[{x,y}]++;
	}
	cout << res;
	
	return 0;
}
