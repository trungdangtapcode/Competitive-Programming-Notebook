#include<bits/stdc++.h>

using namespace std;
int n;
unsigned long long int f[105];
string s = "01";

int main(){
	//freopen("bai2vungliem.inp","r",stdin);
	//freopen("bai2vungliem.out","w",stdout);
	int res = 0;
	cin >> n;
	f[1] = 1;
	for (int i = 2; i < n; i++) f[i] = f[i-1] + f[i-2], s += to_string(f[i]);
	cout << s << '\n';
	string s1 = to_string(n);
	for (int i = 0; i < s.length()-s1.length()+1; i++){
		res += (s1==s.substr(i,s1.length()));
	}
	cout << res;
	
	return 0;
}
