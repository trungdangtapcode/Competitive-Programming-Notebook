#include<bits/stdc++.h>

using namespace std;
vector<int> v;
void calc(int x){
	vector<int> tmp(x+1,0);
	for (int i = 2; i <= x; i++) if (x%i==0){
		while (x%i==0) x/=i, tmp[i]++;
		v[i] = max(v[i],tmp[i]);
	} 
}

int main(){
	int a, b, c;
	long long int res = 1;
	cin >> a >> b >> c;
	v.assign(max({a,b,c})+1,0);
	calc(a);
	calc(b);
	calc(c);
	for (int i = 2; i <= max({a,b,c}); i++){
		if (v[i]%2==1) v[i]++;
		v[i] /= 2;
		for (int j = 1; j <= v[i]; j++) res *= i; 
	}
	cout << res;
	
	return 0;
}
