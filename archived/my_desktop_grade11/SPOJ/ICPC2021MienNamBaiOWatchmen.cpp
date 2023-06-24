#include <bits/stdc++.h>

using namespace std;
int n, x, y;
map<int,int> cntX, cntY;
map<pair<int,int>,int> cntXY;
long long int res = 0;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		res += cntX[x]+cntY[y]-cntXY[{x,y}]; //truoc sau gi cung access vo cnt[i]; bao ham
		cntX[x]++; cntY[y]++; cntXY[{x,y}]++;
	}
	cout << res;
	
	return 0;
}
