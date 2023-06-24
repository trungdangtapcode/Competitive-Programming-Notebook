#include <bits/stdc++.h>

using namespace std;
long long int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	long long int x = n;
	int res = 0;
	while (x>0){
		res += (x%10);
		x /= 10;
	}
	if (res==0) cout << 1; else cout << (n%res==0);
	
	return 0;
}
