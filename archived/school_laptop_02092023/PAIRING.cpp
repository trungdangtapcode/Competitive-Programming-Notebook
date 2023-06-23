#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
	cin >> a >> b >> c >> d;
	cout << a%2&&!(b-min(b,d))+c%2&&!(d-min(b,d))+abs(b-d);
	return 0;
}
