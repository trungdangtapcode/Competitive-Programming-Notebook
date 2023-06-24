#include <bits/stdc++.h>

using namespace std;
int f[1005], k, n;
int main(){
	
	f[1] = f[2] = 1;
	n = 2;
	for (int i = 3; f[i-1] <=1000000; i++, n++) f[i] = f[i-1] + f[i-2];
	cin >> k;
	cout << (binary_search(f+1,f+n+1,k)?"true":"false");
}
