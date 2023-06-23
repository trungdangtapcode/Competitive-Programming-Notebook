#include<bits/stdc++.h>

using namespace std;

int main(){
	long double AB, BC, va, vb, vc, timeB;
	cin >> AB >> BC >> va >> vb >> vc;
	timeB = (AB+BC)/(va+vc);
	cout << fixed << setprecision(4) << timeB*vb;
	
	return 0;
}
