#include<bits/stdc++.h>

using namespace std;
string s;
int cnt[26];
void solve(){
	cin >> s;
	for (char c: s){
		cnt[c-'a']++;
	}
	string p;
	char cm = '?';
	for (int i = 'a'; i <= 'z'; i++){
		while (cnt[i-'a']>=2){
			cnt[i-'a'] -= 2;
			p += (char)i;
		}
//		if (cm=='?'&&cnt[i-'a']==1){
//			cm = i;
//		}
	}
	if (p==""){
		sort(s.begin(),s.end());
		cout << s << "\n";
		return;
	}
	for (int i = p[0]+(p[0]!=*p.rbegin()); i <= 'z'; i++){
		if (cnt[i-'a']==1){
			cnt[i-'a'] -= 1;
			cm = i;
			break;
		}
	}
	if (cm=='?'){
		for (int i = p[0]; i >= 'a'; i--){
			if (cnt[i-'a']==1){
				cnt[i-'a'] -= 1;
				cm = i;
				break;
			}
		}	
	}
	
	sort(p.begin(),p.end());
	string p2 = p;
	reverse(p2.begin(),p2.end());
	string pl = cm=='?'?p + p2: p + cm + p2;
	for (int i = 'a'; i <= p[0]; i++){
		if (cnt[i-'a']==1){
			cout << (char)i;
		}
	}
	cout << pl << "";
	for (int i = p[0]+1; i <= 'z'; i++){
		if (cnt[i-'a']==1){
			cout << (char)i;
		}
	}
//	s = " " + s;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

