#include<bits/stdc++.h>

using namespace std;
int n, cnt[26], cnt2[26];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		s = "#" + s;
		memset(cnt,0,sizeof(cnt));
		memset(cnt2,0,sizeof(cnt2));
		int num1 = 0, num2 = 0;
		for (int i = 1; i <= n; i++){
			cnt[s[i]-'a']++;
			if (cnt[s[i]-'a']==1) num1++;
		}
		int res = num1;
		for (int i = n; i >= 1; i--){
			cnt[s[i]-'a']--;
			if (cnt[s[i]-'a']==0) num1--;
			cnt2[s[i]-'a']++;
			if (cnt2[s[i]-'a']==1) num2++;
			res = max(res,num1+num2);
		}
		cout << res << "\n";
	}
	
	
	return 0;
}
