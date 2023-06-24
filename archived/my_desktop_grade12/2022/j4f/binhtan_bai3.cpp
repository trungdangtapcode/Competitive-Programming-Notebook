#include<bits/stdc++.h>

using namespace std;

string int2string(int x){
	string res = "";
	while (x){
		res.push_back(x%10+'0');
		x /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}
int n;
string s;

int main(){
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) s += int2string(i);
	for (int i = 0; i < s.length()-1;){
		if (s[i]==s[i+1]-1){
			res++;
			i++;
			while (i<s.length()-1&&s[i]==s[i+1]-1) i++;
		} else i++;
	}
	cout << res;
	
	
	return 0;
}
