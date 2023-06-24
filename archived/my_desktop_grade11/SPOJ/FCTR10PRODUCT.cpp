#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a, b;
	cin >> a >> b;
	if (a*b==0) cout << 0;
	else cout << a/abs(a)*b/abs(b);
}
