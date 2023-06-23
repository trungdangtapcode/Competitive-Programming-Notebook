#include<bits/stdc++.h>

using namespace std;
int n, s, f[6005][6055], a[6005], b[6005];
const int p = 1e9+7;

int main(){
	cin >> n >> s;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= s; j++){
			f[i][j] += f[i-1][j];
			f[i][j] %= p;
			f[i][min(j+(a[i]+1)*b[i],s+50)] -= f[i-1][j];
			f[i][min(j+(a[i]+1)*b[i],s+50)] %= p;
		}
		for (int j = b[i]; j <= s+50; j++) f[i][j] = (f[i][j]+f[i][j-b[i]])%p;
	}
	cout << (f[n][s]+p)%p;
	
	return 0;
}
