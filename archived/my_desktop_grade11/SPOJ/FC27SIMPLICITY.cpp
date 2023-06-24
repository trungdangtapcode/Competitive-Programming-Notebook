#include <bits/stdc++.h>

using namespace std;
int cnt[26];
string s;
int main(){
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		cnt[s[i]-'a']++;
	}
	sort(cnt,cnt+26);
	cout << s.length()-cnt[25]-cnt[24];
	return 0;
}
