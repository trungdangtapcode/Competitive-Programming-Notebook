#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[200005], b[200005], m, nxt[200005];
bool ok[200005];
set<int> notOk;

bool solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	cin >> m;
	multiset<int> razor;
	for (int i = 1, x; i <= m; i++){
		cin >> x;
		razor.insert(x);
	}
	for (int i = 1; i <= n; i++) if (a[i]<b[i]) return false;
	for (int i = 1; i <= n; i++) ok[i] = (a[i]==b[i]);
	notOk.clear();
	for (int i = 1; i <= n; i++) if (!ok[i]){
		notOk.insert(i);
	}
	memset(nxt,0,sizeof(nxt));
	stack<int> st;
	for (int i = 1; i <= n; i++){
		while (st.size()&&b[st.top()]<=b[i]){
			if (b[st.top()]==b[i]) nxt[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
//	for (int i = 1; i <= n; i++) cout << nxt[i] << " "; cout << endl;
	while (notOk.size()){
		int x = *notOk.begin();
		if (razor.find(b[x])==razor.end()) return false;
		razor.erase(razor.find(b[x]));
		ok[x] = true;
		notOk.erase(x);
		while (nxt[x]){
			x = nxt[x];
			if (!ok[x]){
				ok[x] = true;
				notOk.erase(x);
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) cout << (solve()?"YES\n":"NO\n");
	
	return 0;
}
