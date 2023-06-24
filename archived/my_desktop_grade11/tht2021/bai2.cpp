#include<bits/stdc++.h>

using namespace std;
int n;
string s;

int main(){
	freopen("bai2.inp","r",stdin);
	freopen("bai2.out","w",stdout);
	cin >> n;
	cin >> s;
	//for (auto& c: s) c = toupper(c);
	for (int i = 0; i < s.length()-n+1; i++){
		bool ok = true;
		for (int j = i; j <= i+n-1; j++){
			if (toupper(s[i])!=toupper(s[j])) ok = false;
		}
		if (ok){
			cout << i+1 << " " << s.substr(i,n) << '\n';
		}
	}
	return 0;
}
