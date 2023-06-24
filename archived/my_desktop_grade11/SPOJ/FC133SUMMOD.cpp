#include <bits/stdc++.h>

using namespace std;

long long int a, b ,c, res, p = 1e9 + 7;

long long int getSum(long long int x){
	long long int a = x, b = x + 1;
	if (a%2 == 0) a/= 2; else b/= 2;
	return (a%p*(b%p)%p);
}
long long int getSumRange(long long int x, long long int y){
	return (getSum(y)-getSum(x-1)+p*p)%p;
}

int main(){
	
	cin >> a >> b >> c;
	res = c%p*((b-a+1)%p)%p; //(sigma-modular) //=> sigma ganh team, modular acc
	for (long long int i = a, j = -1; i <= b; i = j+1){
		j = min(c/(c/i),b);
		res = (res - c/i%p*getSumRange(i,j)%p + p*p)%p;
		//cout << i << " " << j << "   " << c/i << endl;
	}
	cout << res;
	
	return 0;
}
