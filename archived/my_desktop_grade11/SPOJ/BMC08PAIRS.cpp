#include <bits/stdc++.h>

using namespace std;
map <long long int, bool> chinhphuong;
int f[10000005];
long long int m, n;

int main(){
	
	cin >> n >> m;
	for (int i = 1; i*i <= m; i++) chinhphuong[i*i] = true;
	
	for (int i = 2; i <= n; i++){
		for (int j = /*2*/i; j <= n; j += i) if (i > j/i) { //1 lo k khong de k lo 1
			f[i] += chinhphuong[j];
		}
		//f[i] += f[i-1];
	}
	//for (int i = 1; i < 5; i++) cout << f[i] << " " ;
	long long int res = 0;
	for (int i = 1; i <= n; i++) res += f[i];
	cout << res;
	
	return 0;
}
