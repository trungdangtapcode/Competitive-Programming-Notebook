#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;
int n;
string s;	
map <string, bool> m;

int main(){	
	cin >> n;
//	int vitri = 1;
	char lastChar = '&';
	for (int i = 0 ; i < n; i++){
		cin >> s;
		//cout << s << "->";
		if ((s[0]==lastChar&&!m[s])||i==0){
			m[s] = true;
			lastChar = s[s.length()-1];
//			vitri += s.length() + 1;
		} else {
			cout << "NO" << endl;
			cout << i + 1;
			return 0;
		}
		
	}
	cout << "YES";
	
	return 0;
}
