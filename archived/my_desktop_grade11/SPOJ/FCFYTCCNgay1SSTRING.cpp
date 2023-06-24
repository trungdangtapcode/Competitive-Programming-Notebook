#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cout << 0;
	for (int i = 1; i <= n; i++) cout << 1;
	cout << '\n';
	for (int i = 1; i < n; i++) cout << 0;
	cout << "10";
	for (int i = 1; i < n; i++) cout << 1;

//	for (int i = 1; i <= n; i++) cout << 1;
//	for (int i = 1; i <= n; i++) cout << 0;
//	cout << '\n';
//	for (int i = 1; i < n; i++) cout << 1;
//	cout << "01";
//	for (int i = 1; i < n; i++) cout << 0;
	return 0;
}
