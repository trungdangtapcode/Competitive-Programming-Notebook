#include <bits/stdc++.h>

using namespace std;
long long int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	if (n%2==0){
		cout << (n/2);
	} else cout << (n/2)-n;
	
	return 0;
}
