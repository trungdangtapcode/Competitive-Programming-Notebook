#include<bits/stdc++.h>

using namespace std;

int a, b;

int main(){
	cin >> a >> b;
	for (int i = 0; i <= 10; i++){
		int k = i;
		cout << i << " " << a +k << " " << b + k<< " " << (a+k)*(b+k)/__gcd(a+k,b+k) << "\n";
	}
//	if (a<b) swap(a,b);
//	int x = a-b;
//	if (x==0){
//		cout << 0;
//		return 0;
//	}
//	int res = -b%x;
//	if (res<0) (res += x) %= x;
//	cout << res;
	
	return 0;
}
