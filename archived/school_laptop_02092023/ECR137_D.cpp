#include<bits/stdc++.h>

using namespace std;
int n;
string s;
int main(){
	cin >> n >> s;
	if (s[0]=='0') for (int i = 0; i < n-1; i++){
		if (s[i]=='0'&&s[i+1]=='1'){
			s = s.substr(i+1,n-1-(i+1)+1);
			break;
		}
		if (i==n-2&&s[i+1]=='0'){
			cout << 0;
			return 0;
		}
	}
	n = s.length();
	
	
	string t = s;
	for (int i = 0; i < n; i++) if (s[i]=='0') {
		for (int l = 0, r = i; r < n; r++, l++){
			if (s[r]=='1'||t[l]=='1') s[r] = '1';
		}
		break;
	}
	cout << s << "\n";
	
	return 0;
}
