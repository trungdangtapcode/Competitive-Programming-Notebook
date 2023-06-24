#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a, b;
	cin >> a >> b;
	int x = a;
	a = (a+1)/2; 
	b = (b+1)/2;
	cout << 1ll*b*b - 1ll*a*a + (x&1?x:0);
	
	return 0;
}
