#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> s;
	string s0 = s;
	while (s0.back()=='0') s0.pop_back();
	reverse(s0.begin(),s0.end());
	if (s0.length()<s.length()){
		cout << s0 << " < " << s;
		return 0;
	}
	for (int i = 0; i < s.length(); i++){
		if (s0[i]>s[i]){
			cout << s0 << " > " << s;
			return 0;
		} else if (s0[i]<s[i]){
			cout << s0 << " < " << s;
			return 0;
		}
	}
	cout << s0 << " = " << s;
	
	return 0;
}
