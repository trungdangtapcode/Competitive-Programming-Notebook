#include<bits/stdc++.h>

using namespace std;
long long n;
int main(){
	cin >> n;
	long long cur = 1, res = 0;
	for (int i = 0; i < 50; i++){
		res += (n-1+cur)/(2*cur)*cur;
		cur = cur*2;
	}
	cout << res;
	return 0;
}
