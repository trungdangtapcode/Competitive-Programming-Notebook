#include<bits/stdc++.h>

using namespace std;

string s;
int n, cur, res;

int main(){
	cin >> n;
	cin >> s;
	s = "#"+s;
	for (int i = 1; i <= n-2;){
		if (s[i]+s[i+1]+s[i+2]=='a'+'b'+'a'){
			cur++;
			res = max(res,cur);
			i = i+2;
		} else {
			cur = 0;
			i = i+1;
		}
	}
	cout << 'a';
	while (res--) cout << "ba";
	
	return 0;
}
