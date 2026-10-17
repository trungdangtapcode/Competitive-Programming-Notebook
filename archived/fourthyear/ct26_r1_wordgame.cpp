#include<bits/stdc++.h>

using namespace std;
const int N = 1.5e6+5;
typedef pair<int,int> ii;
int To[N][26], Sz=2;
ii Val[N];
unordered_map<string, ii> mp;

//void uUpdate(const string& s, int op, int tm, int To[][26], ii Val[], int& Sz){
void uUpdate(const string& s, int op, int tm, int rt){
	int idx = rt;
	for (char c: s){
		if (To[idx][c-'a']!=0){
			idx = To[idx][c-'a'];
		} else {
			To[idx][c-'a']=(++Sz);
			idx = To[idx][c-'a'];
		}
	}
	
		Val[idx] = ii{tm, op};
}
ii gGet(const string& s, int rt){
	int idx = rt;
	ii res = {0, 0};
	for (char c: s){
		if (To[idx][c-'a']!=0){
			idx = To[idx][c-'a'];
		} else {
			break;
		}
		res = max(res,Val[idx]);
	}
	return res;
}


void solve(){
	int q;
	cin >> q;
	string s;
	string rs;
	for (int i = 1; i <= q; i++){
		int op;
		cin >> op >> s;
		rs = s;
		reverse(rs.begin(), rs.end());
		ii ans = {0, 0};
		if (op==1||op==2){
			mp[s]=ii{i,op};
		} else if (op==3||op==4){
			uUpdate(s, op, i, 1);
		} else if (op==5||op==6) {
			uUpdate(rs, op, i, 2);
		} else {
			ans = max(ans, gGet(s, 1));
			ans = max(ans, gGet(rs, 2));
			if (mp.count(s)) ans = max(ans, mp[s]);
			int fans = ans.second;
			if (fans==0||fans==1||fans==3||fans==5){
				cout << "Y\n";
			} else {
				cout << "N\n";
			}
		}
	}
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

