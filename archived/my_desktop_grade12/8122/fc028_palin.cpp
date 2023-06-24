#include<bits/stdc++.h>

using namespace std;

int n, f[5005][5005];
string s;
int main(){
	cin >> n >> s;
	s = "#" + s;
	for (int i = 1; i <= n; i++){
		for (int j = i; j >= 1; j--){
			f[j][i] = min(f[j+1][i]+1,f[j][i-1]+1);
			if (s[j]==s[i]) f[j][i] = min(f[j][i],f[j+1][i-1]);
		}
	}	
	cout << f[1][n];
	
	return 0;
}
