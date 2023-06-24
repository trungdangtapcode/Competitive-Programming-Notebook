#include <bits/stdc++.h>

using namespace std;

typedef pair<long long int, long long int> toado;
vector<toado> a;
int n;
const double pi = 4*atan(1);

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		long long int x, y;
		cin >> x >> y;
		a.push_back({x,y});
	}
	int res = 0;
	for (int i = 0; i < n; i++){
		vector <double> v;
		for (int j = 0; j < n; j++) if (i != j) {
			double angle = atan2(a[i].second-a[j].second,a[i].first-a[j].first);
			while (angle >= 2*pi) angle -= 2*pi;
			while (angle < 0) angle += 2*pi;
			v.push_back(angle);
		}
		sort(v.begin(),v.end());
		//for (auto& j: v) cout << j/pi*180 << " "; cout << endl;
		for (auto& it: v){
			double BSangle1 = it + pi/2;
			if (BSangle1 >= 2*pi) BSangle1 -= 2*pi;
			double BSangle2 = it - pi/2;
			if (BSangle2 < 0) BSangle2 += 2*pi;
			//cout << BSangle1/pi*180 << " " << BSangle2/pi*180<<" - " <<upper_bound(v.begin(),v.end(),BSangle1) - lower_bound(v.begin(),v.end(),BSangle1) << " " <<upper_bound(v.begin(),v.end(),BSangle2) - lower_bound(v.begin(),v.end(),BSangle2)   << endl;
			res += upper_bound(v.begin(),v.end(),BSangle1+1e-15) - lower_bound(v.begin(),v.end(),BSangle1-1e-15); //1e-0 (1) => 1e-5 (2) => 1e-10 (6) => 1e-15 (AC)
		}
	}
	cout << res << endl;
	
	return 0;
}
