#include <bits/stdc++.h>

using namespace std;
int a[100], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	for (int i = 0; i < n-1; i++){
		if (a[i+1]-a[i]>1) {cout << "NO"; return 0;}
	}
	cout << "YES";
	return 0;	
}
