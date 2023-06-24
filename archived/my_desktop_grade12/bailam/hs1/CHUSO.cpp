#include<bits/stdc++.h>

using namespace std;
long long int n;

string int2string(long long int n){
	string res = "";
	while (n>0){
		res.push_back((n%10)+'0');
		n /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	freopen("CHUSO.INP","r",stdin);
	freopen("CHUSO.OUT","w",stdout);
	
	cin >> n;
	long long int k = 1, logk = 0;
	while (n>9*(logk+1)*k){
		n -= 9*(logk+1)*k;
		logk++;
		k *= 10;
	}
	//n > 0. n >= 1
	long long int r = (n-1)%(logk+1), p = (n-1)/(logk+1);
	cout << int2string(k+p)[r];
	
	return 0;
}
