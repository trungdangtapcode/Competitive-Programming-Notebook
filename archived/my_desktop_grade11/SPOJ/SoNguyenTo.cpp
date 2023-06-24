#include <bits/stdc++.h>

using namespace std;
long long int n;

bool check(long long int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i==0) return false;
	}
	return true;
}

long long int AmuB(long long int a, int b){
	long long res = 1;
	while (b>0){
		if (b%2==1) res *= a;
		a *= a;
		b /= 2;  
	}
	return res;
}
long long int canAcuaB (int a, long long int b){ //x^a = b;
	long long int l = 1, h = 2*pow(b,1.0/a), m;	
	while (l <= h){
		m = (l+h)/2;
		long long int x = AmuB(m,a);
		if (x==b) return m;
		if (x>b) h = m - 1; else l = m + 1;
	}
	return (AmuB(m,a)==b?m:-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 2; i <= 60; i++){
		//cout <<i<<" "<<canAcuaB(i,n) << endl;
		long long int layCan = canAcuaB(i,n);
		if (layCan==-1) continue;
		if (check(layCan)) {cout << layCan << " " << i << endl; return 0;}
	}
	cout << 0;
	
	return 0;
}
