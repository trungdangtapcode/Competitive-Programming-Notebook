#include <bits/stdc++.h>

using namespace std;

int r, x1, x2, y1, y2;
long double d;
int main(){
	cin >> r >> x1 >> y1 >> x2 >> y2;
	d = sqrt(1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2));
	cout << (long long int)(ceil(d/(2*r))); //-1e-10
	
	return 0;
}
