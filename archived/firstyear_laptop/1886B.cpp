#include<bits/stdc++.h>

using namespace std;
#define ld long double
ld x[4], y[4];
int nearO, nearP;
ld sqr(ld x){
	return x*x;
}
ld dis(int i, int j){
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}
void solve(){
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	x[3] = y[3] = 0;
	if (dis(1,3)>dis(2,3)){
		nearO = 2;
	} else nearO = 1;
	if (dis(1,0)>dis(2,0)){
		nearP = 2;
	} else nearP = 1;
	if (nearO==nearP){
		cout << max(dis(3,nearO),dis(0,nearP)) << "\n";
	} else cout << max(dis(1,2)/2,max(dis(3,nearO),dis(0,nearP))) << "\n";
}

int main(){
	cout << fixed << setprecision(9);
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
