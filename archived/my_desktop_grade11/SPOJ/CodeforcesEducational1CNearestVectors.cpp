#include <bits/stdc++.h>

using namespace std;
int n;
const double pi = 4*atan(1);
pair <double, int> a[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		int vx, vy;
		cin >> vx >> vy;
		double angle = atan2(vx,vy);
		while (angle>=2*pi)	angle -= 2*pi;
		while (angle<0) angle += 2*pi;
		a[i] = {angle,i};
	}
	sort(a,a+n);
	a[n] = {a[0].first+2*pi,0};
	//for (int i = 0; i <= n; i++) cout << a[i].first/pi*180 << '\n';
	double mmin = 1e3; int imin = -1;
	for (int i = 0; i < n; i++){
		if (mmin>a[i+1].first-a[i].first){
			mmin = a[i+1].first-a[i].first;
			imin = i;
		}
	}
	cout << a[imin].second+1 << " " << a[imin+1].second+1;
	
	return 0;
}
