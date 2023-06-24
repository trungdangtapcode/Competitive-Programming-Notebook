#include<bits/stdc++.h>

using namespace std;
string s, ans = "hello#";
int main(){
	cin >> s;
	int p = 0;
	for (auto c: s){
		if (c==ans[p]){
			p++;
			if (ans[p]=='#'){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	
	return 0;
}
