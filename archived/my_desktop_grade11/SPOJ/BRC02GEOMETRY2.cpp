#include <bits/stdc++.h>

using namespace std;
long double pi = 4*atan(1), goc, canh, AHE, hinhcung, AC, ACK, r, x;

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);	
	cout << fixed << setprecision(9);
	
	int t; cin >> t;
	while (t--){
		cin >> r >> x;
		goc = 2*pi/5;
		canh = sqrt(r*r+r*r-2*r*r*cos(goc));
		AHE = canh*x*sin(pi-goc)/2;
		hinhcung = goc*r*r/2-r*r*sin(goc)/2;
		AC = sqrt(r*r+r*r-2*r*r*cos(2*goc));
		ACK = AC/2*tan(goc)*AC/2;
		cout << ACK+hinhcung+AHE << '\n';
	}
	
	return 0;
}
