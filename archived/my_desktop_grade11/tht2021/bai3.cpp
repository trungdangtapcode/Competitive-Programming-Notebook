#include<bits/stdc++.h>

using namespace std;
int n;
string s;

int calc(int x){
	int res = 0;
	for (int i = x; i <= x+7; i++){
		res = res << 1;
		if (s[i]=='1'){
			res = res|1;
		}
	}
	return res;
}

int main(){
	freopen("bai3.inp","r",stdin);
	freopen("bai3.out","w",stdout);
	cin >> s;
	while (s.length()%8!=0) s = "0" + s;
	n = s.length();
	for (int i = 0; i < n; i++) if (i%8==0){
		cout << calc(i) << " ";
	}
	return 0;
}
