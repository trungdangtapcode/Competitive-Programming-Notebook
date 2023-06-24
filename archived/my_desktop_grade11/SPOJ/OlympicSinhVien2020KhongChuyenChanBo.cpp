#include <bits/stdc++.h>

using namespace std;
long long int n, s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	cout << n*(n+1)/2-s;
	
	return 0;
}
