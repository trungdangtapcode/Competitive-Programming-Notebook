#include <bits/stdc++.h>

using namespace std;

int l;
string s, res;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	getline(cin,s);
	while (n--){
		getline(cin,s);
		l = s.length();
		res.clear();
		for (int i = 0; i < l; i++){
			if (s[i]==' '&&!res.empty()&&res.back()!=' ') res.push_back(s[i]);
			if (tolower(s[i])>='a'&&tolower(s[i])<='z') 
				if (res.empty()||res.back()==' ') res.push_back(toupper(s[i]));
				else res.push_back(tolower(s[i]));
		}
		while (res.back()==' ') res.pop_back();
		cout << res << '\n';
	}
	return 0;
}
