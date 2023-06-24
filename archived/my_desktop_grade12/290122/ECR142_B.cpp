#include<bits/stdc++.h>

using namespace std;
int res, a2, a3, a4;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> res >> a2 >> a3 >> a4;
		int x = res, y = res;
		if (res==0){
			cout << 1 << "\n";
			continue;
		}
		int mmin = min(a2,a3);
		res += 2*mmin;
		a2 -= mmin, a3 -= mmin;
		if (a2==0){
			if (x<a3){
				cout << res + min(a3,x)+1 << "\n";
				continue;
			}
			res += a3;
			x -= a3;
		} else {
			if (y<a2){
				cout << res + min(a2,y)+1 << "\n";
				continue;
			}
			res += a2;
			y -= a2;
		}
		cout << res + min(a4,min(x+1,y+1)) << "\n";
	}
	
	return 0;
}
