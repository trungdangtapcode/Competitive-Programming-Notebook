#include<bits/stdc++.h>

using namespace std;
string s;
int n, k;
void solve(){
	cin >> s >> k;
	n = s.length();
//	s.push_back('0'-1);
	s.push_back('9'+1);
	vector<int> st;
	vector<bool> res(n, true);
	for (int i = 0; i <= n; i++){
//		int c = s[i]-'0';
		while (st.size()&&s[st.back()]<s[i]&&k>0){
			int j = st.back();
			res[j] = false;
			st.pop_back();
			k--;
		}
		st.push_back(i);
	}
	string ss;
	int isFirst = true;
	for (int i = 0; i < n; i++) if (res[i]){
		if (s[i]!='0'){
			isFirst = false;
			ss.push_back(s[i]);
		} else {
			if (!isFirst)
				ss.push_back(s[i]);
		}
	}
	cout << ss << "\n";
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

