#include<bits/stdc++.h>

using namespace std;
int a[405][405], n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) a[i][j] = i*j;
	}
	for (int i = 0, b; i < n; i++){
		cin >> b;
		for (int j = 0; j < n; j++) a[i][j] += b - i*i;
		for (int j = 0; j < n; j++) cout << (a[i][j]%n+n)%n << " "; cout << "\n";
	}
	return 0;
}
