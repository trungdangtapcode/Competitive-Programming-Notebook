#include <bits/stdc++.h>

using namespace std;

int vx[8] = {-2,-1,1,2,2,1,-1,-2};
int vy[8] = {1,2,2,1,-1,-2,-2,-1};
string s; int n, k;
int maxx = 0, maxy = 0, minx = 0, miny = 0, x = 0, y = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++){
		x += vx[s[i]-'1']; y += vy[s[i]-'1'];
		maxx = max(maxx,x);
		maxy = max(maxy,y);
		minx = min(minx,x);
		miny = min(miny,y);
	} //vung di chuyen: (maxx-minx+1)*(maxy-miny+1)
	cout << max(n-(maxx-minx+1)+1,0)*max(n-(maxy-miny+1)+1,0) << '\n';
	
	
	return 0;
}
