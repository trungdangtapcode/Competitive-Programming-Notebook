#include <bits/stdc++.h>

using namespace std;

bool check(long long int x){
	if (x<=1) return false;
	for (long long int i = 2; i*i <= x; i++){
		if (x%i==0) return false;
	}
	return true;
}

long long int n;
int main(){
	cin >> n;
	cout << (check(n)?"YES":"NO");
	
	
	return 0;
}
