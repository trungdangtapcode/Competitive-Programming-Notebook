#include <bits/stdc++.h>

using namespace std;
int x1, y1, x2, y2;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> x1 >> y1 >> x2 >> y2;
	cout << abs(x1-x2)*abs(y1-y2);
	
	return 0;
}
