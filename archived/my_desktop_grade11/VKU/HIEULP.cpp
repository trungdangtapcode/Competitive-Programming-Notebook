#include <bits/stdc++.h>

using namespace std;
long long int a; 
int q;
bool check(long long int x){
	if (x<2) return false;
	for (long long int i = 2; i*i <= x; i++){
		if (x%i==0) return false; 
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> q;
	while (q--){
		cin >> a;
		cout << check(3*a*a-3*a+1) << '\n';
	}
	
	return 0;
}
