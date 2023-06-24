#include<bits/stdc++.h>

using namespace std;
#define ull unsigned long long

ull f(ull x){
	if (x%4==0) return x;
	if (x%4==1) return 1;
	if (x%4==2) return x+1;
	return 0;
}

ull a, b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> b;
		cout << (f(b)^f(a-1)) << "\n";	
	}
	
	return 0;
}
