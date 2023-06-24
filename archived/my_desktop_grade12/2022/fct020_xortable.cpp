#include<bits/stdc++.h>

using namespace std;
int a[105], n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cout << (a[i]^a[j]) << " ";
		cout << "\n";
	}
	
	
	return 0;
}
