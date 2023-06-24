#include <bits/stdc++.h>

using namespace std;
int a, b, x, y;

long long int floorup(long long int x, long long int y){
	if (x<0&&y<0) x = -x, y = -y;
	if (y<0) x = -x, y = -y;
	return (x/y+(x%y>0?1:0));
}
long long int floordown(long long int x, long long int y){
	if (x<0&&y<0) x = -x, y = -y;
	if (y<0) x = -x, y = -y;
	return (x/y-(x%y<0?1:0));
}

bool check(int n){
	//k: so nguoi x xanh & y do => (n-k): so nguoi y xanh & x do
//	long long int kmax = floordown((a-1ll*y*n),(x-y));
//	long long int kmin = floorup((b-1ll*x*n),(y-x));
//	long long int kmax = (a-1ll*y*n)/(x-y) - ((a-1ll*y*n)%(x-y)<0?1:0);
//	long long int kmin = (b-1ll*x*n)/(y-x) + ((b-1ll*x*n)%(y-x)>0?1:0);
	long double kmax = (a-(long double)y*n)/(x-y); //ll
	long double kmin = (b-(long double)x*n)/(y-x);
//	if (n==5){
//		cout << fixed << setprecision(9) << kmax << " " << kmin << endl;
//	}
//	if (kmin>kmax) swap(kmin,kmax);
	if ((long long int)kmax<kmin) return false; //(long long int) =))
	if (kmax<0||kmin>n) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> a >> b >> x >> y;
		if (x==y){
			cout << min(a,b)/x << '\n';
			continue;
		}
		if (y>x) swap(x,y);
		int l = 0, h = 1e9, m, res = 0;
		while (l<=h){
			m = (l+h)/2;
//			cout << l << " " << h << " " << m << endl;
			if (check(m)){
				res = m;
				l = m + 1;
			} else h = m - 1;
		}
		cout << res << '\n';
	}
	
	return 0;
}
