#include<bits/stdc++.h>

using namespace std;
int n, x, y;
string s;
int main(){
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		if (s[i]=='L') x--;
		if (s[i]=='R') x++;
		if (s[i]=='U') y--;
		if (s[i]=='D') y++;
	}
	if (n%2) return cout << -1,0;
	cout << (abs(x) + abs(y))/2;
	
	return 0;
}
