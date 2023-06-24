#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	long long int n;
	while (t--){
		cin >> n;	
		//r = n - floor(n/x)*x
		//miniumize floor(n/x)*x
		//miniumize floor(n/x) better (derivative x)
		//=> floor(n/x) = 1
		//=> x in [(n+1)/2;n]
		//n/2 is the line that floor(n/x) = 2 so x we need is n/2 + 1
		//n/2 + 1 because it is middle whem n odd and even. That is a right answer
		//=> r = n - 1*floor((n+1)/2) when x = floor((n+1)/2)
		cout << n/2 + 1 << '\n';
	}
	
	
	return 0;
}
