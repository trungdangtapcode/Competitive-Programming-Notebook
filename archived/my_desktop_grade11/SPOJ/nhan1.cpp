#include <bits/stdc++.h>
#define fix cout<<"fix"<<endl;
using namespace std;
long int n, t;
vector<short int> a(1e7+5);

void solve(){
	cin >> n;
	long int k = 0;
	for (long int i = 1; i <= n; i++){
		k+= i;
		a[i] = k%10;
		k /= 10;
	} 
	for (long int i = n+1; i <= 2*n; i++){
		k += 2*n-i;
		a[i] = k%10;
		k /= 10;
	}
	for (long int i = 2*n-1; i >= 1; i--){
		cout << a[i];
	}
	cout << endl;
}

int main(){
	cin >> t;
	for (long int i = 0; i < t; i++){
		solve();
	}
	
	
	//memset(dp,-1,sizeof(dp));
	//cout << dp_set(0,n-1,0) - dp_set(0,n-1,1);
}
