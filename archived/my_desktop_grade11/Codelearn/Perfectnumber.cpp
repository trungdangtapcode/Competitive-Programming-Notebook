#include <bits/stdc++.h>
using namespace std;
bool checkPerfectNumber(int n){
	long long int sum = 1; //loai n; dung long long cho chac
	for (int i = 2; 1ll*i*i <= n; i++) if (n%i==0){
		sum += i;
		if (1ll*i*i!=n) sum += n/i; //loai trung
	}
	return (sum==n);
}
int main(){
	int n; cin >> n;
	cout << checkPerfectNumber(n);
	return 0;
}
