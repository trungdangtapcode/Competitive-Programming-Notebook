#include <bits/stdc++.h>

using namespace std;

int a[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> a[0]){
		cin >> a[1] >> a[2];
		sort(a,a+3);
		cout << (a[0]+a[1]==a[2]?"yes\n":"no\n");
	}
	return 0;
}
