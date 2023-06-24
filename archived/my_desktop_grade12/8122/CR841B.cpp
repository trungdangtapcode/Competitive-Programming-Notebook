#include<bits/stdc++.h>

using namespace std;
long long int n;
const long long int p = 1e9+7;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie();
	int t; cin >> t;
	while (t--){
		cin >> n;
		if (n*(n+1)%3==0) cout << ((n*(n+1)/3%p*(2*n+1)%p-n*n%p+n*(n+1)/2%p-n)*2022%p+p)%p;
		else cout << ((n*(n+1)%p*((2*n+1)/3)%p-n*n%p+n*(n+1)/2%p-n)*2022%p+p)%p;
		cout << "\n";
	}
	
	return 0;
}
