#include<bits/stdc++.h>

using namespace std;
string toString(int x){
	string res;
	while (x){
		res.push_back(x%10+'0');
		x /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}
int main(){
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) s += toString(i);
	for (int i = 0; i < s.length()-1; i++){
		int j = i+1;
		if (s[i]-1!=s[j]) continue;
		cout << s[i];
		while (j<s.length()-1&&s[j]-1==s[j+1]){
			cout << s[j++];
		};
		cout << s[j] <<  "\n";
		i = j;
	}
	
	
	return 0;
}
