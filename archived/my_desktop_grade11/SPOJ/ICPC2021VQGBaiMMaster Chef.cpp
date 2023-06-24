#include <bits/stdc++.h>

using namespace std;
int n;
int f(int x, int y){
	return (x*n+y);
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	if (n==1){
		cout << 1 << '\n' << 1 << '\n';
		return 0;
	}
	if (n==2){
		cout << 3  << '\n';
		cout << 1 << ' ' << 2 << '\n';
		cout << 1 << ' ' << 3 << '\n';
		cout << 2 << ' ' << 3 << '\n';
		return 0;
	}
//	cout << 1 + (n-1)*(n-1) << '\n';
//	for (int i = 1; i <= n; i++) cout << i << ' '; cout << '\n';
//	for (int i = 1; i <= n-1; i++){
//		cout << 2 << ' ';
//		for (int j = 1; j <= n-1; j++) cout << f(i,j) << ' ';
//		cout << '\n';
//	}
//	for (int i = 3; i <= n; i++){
//		for (int j = 1; j <= n-1; j++){
//			cout << i << ' ';
//			for (int k = 1; k <= n-1; k++){
//				cout << f(k,(j+(i-2)*(k-1)-1)%(n-1)+1) << ' ';
//			}
//			cout << '\n';
//		}
//	}
//	int dem = 1;
//	freopen("test.txt", "w", stdout);
	cout << 1 + n*(n-1) << '\n';
	for (int i = 1; i <= n; i++) cout << i << ' '; cout << '\n';
	for (int i = 1; i <= n-1; i++){
		cout << 1 << ' ';
		for (int j = 1; j <= n-1; j++) cout << i*(n-1)+j+1 << ' ';
		cout << '\n';
	}
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n-1; j++){
			cout << i << ' ';
			for (int k = 1; k <= n-1; k++) cout << k*(n-1)+1+1+(j-1+(i-1)*(k-1))%(n-1) << ' '; 
			cout << '\n';
		}
	}
	
	return 0;
}
