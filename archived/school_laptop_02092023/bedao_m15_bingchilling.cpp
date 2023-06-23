#include<bits/stdc++.h>

using namespace std;
int n, x, y, a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y >> a;
		cout << (a/(x+y)*x*5+min(a%(x+y),x)*5) << "\n";
	}	
	return 0;
}
