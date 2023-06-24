#include <bits/stdc++.h>

using namespace std;
int n;
bool check(int x){
	int res = 0;
	while (x!=0){
		res += x%10;
		x /= 10;
	}
	return (res%4==0);
}
int main(){
//	cin >> n;
	scanf("%d", &n);
	while (!check(n++));
	cout << n-1;
	
	return 0;
}
