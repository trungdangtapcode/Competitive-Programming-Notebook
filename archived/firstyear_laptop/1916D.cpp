#include<bits/stdc++.h>

using namespace std;
int a[1000];
void solve(){
	int n; cin >> n;
	if (n==1){
		cout << 1 << "\n";
		return;
	}
	a[0] = 1;
    for (int i = 1, j = 2; j < n; i+=1, j+=2){
    	a[i] = 6;
    	a[j] = 9;
    	for (int j = 0; j < n; j++) cout << a[j]; cout << "\n";
    	a[i] = a[j] = 0;
	}
	a[0] = 9;
    for (int i = 1, j = 2; j < n; i+=1, j+=2){
    	a[i] = 6;
    	a[j] = 1;
    	for (int j = 0; j < n; j++) cout << a[j]; cout << "\n";
    	a[i] = a[j] = 0;
	}
	a[0] = 1;
    for (int i = 1, j = 2; j < n; i+=1, j+=2){
    	a[i] = 9;
    	a[j] = 6;
    	for (int j = 0; j < n; j++) cout << a[j]; cout << "\n";
    	a[i] = a[j] = 0;
    	break;
	}
}

main(){
 	ios::sync_with_stdio(0);
 	cin.tie(0); cout.tie(0);
 	int t; cin >> t;
 	while (t--)
	solve();
	
	return 0;
}
