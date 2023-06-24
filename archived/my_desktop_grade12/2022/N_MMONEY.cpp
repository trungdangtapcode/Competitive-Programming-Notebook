#include<bits/stdc++.h>

using namespace std;
int n, s, f[6005], new_f[6005];
const int p = 1e9+7;
int main(){
	cin >> n >> s;
	f[0] = 1;
	for (int i = 1, a, b; i <= n; i++){
		cin >> a >> b;
		memset(new_f,0,sizeof(new_f));
		for (int j = 0; j <= s; j++){
			(new_f[j] += f[j])%=p;
			(new_f[min(s+1,j+(a+1)*b)] -= f[j])%= p;
		}
		for (int j = 0; j <= s; j++) if (j>=b) (new_f[j] += new_f[j-b])%=p;
		for (int j = 0; j <= s; j++) f[j] = new_f[j];
	}
	cout << (f[s]+p)%p << "\n";
	return 0;
}
