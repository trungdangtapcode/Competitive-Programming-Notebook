#include<bits/stdc++.h>

using namespace std;
long double ab, bc, va, vb, vc;
int main(){
	cin >> ab >> bc >> va >> vb >> vc;
	cout << setprecision(4) << fixed << (ab+bc)/(va+vc)*vb;
	
	return 0;
}
