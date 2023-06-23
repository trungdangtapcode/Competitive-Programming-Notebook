#include<bits/stdc++.h>

using namespace std;
string s, ans;

string getOR(string a, string b){
	int st = a.length()-b.length();
	for (int i = 0; i < b.length(); i++) if (b[i]=='1') a[i+st] = '1';
	return a;
}
bool bigger(string a, string b){
//	a = a.substr(a.find('1'),n-a.find('1'));
//	b = b.substr(b.find('1'),n-b.find('1'));
//	if (a.length()!=b.length()) return a.
	for (int i = 0; i < a.length(); i++) if (a[i]<b[i]) return false; else if (a[i]>b[i]) return true;
	return false;
}

int main(){
	int n;
	cin >> n >> s;
	int pos1 = s.find('1');
	if (pos1==string::npos){
		cout << 0;
		return 0;
	}
	int pos2 = s.find('0',pos1);
	if (pos2==string::npos){
		cout << s.substr(pos1,n-pos1);
		return 0;
	}
	int pos3 = min(1ll*s.find('1',pos2),1ll*n-1); //or 1llu (online judge codeforce size type is llu)
	ans = s;
	for (int i = pos1; i <= pos3; i++){
		string tmp = getOR(s,s.substr(pos1,n-i));
		if (bigger(tmp,ans)) ans = tmp;
	}
	cout << ans.substr(pos1,n-pos1);
	
	return 0;
}
