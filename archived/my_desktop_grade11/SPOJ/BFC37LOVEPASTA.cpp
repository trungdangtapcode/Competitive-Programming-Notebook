#include <bits/stdc++.h>

using namespace std;
int n;
string S1, S2;
int u, v;

bool check(int u){
	int v = 0;
	for (int i = 0; i < n; i++) if (S1[i]=='*'||S2[i]=='*') {
		v = i;
		break;
	}
	//v--
	for (int i = v; i < n; i++){
		//cout << u;
		if ((u==0)&&(S1[i]=='*')){
			if (S2[i]=='*') u = 1; else u = 0;
			continue;
		}
		if ((u==1)&&(S2[i]=='*')){
			if (S1[i]=='*') u = 0; else u = 1;
			continue;
		}
		if (S2[i]=='.'&&S1[i]=='.') {
			bool x = false;
			for (int j = i; j < n; j++) x = x||S2[j]=='*'||S1[j]=='*';
			//if (x) cout << "NO"; else cout << "YES";
			return (!x);
		}
		//cout << "NO";
		return false;
	}
	//cout << "YES";
	return true;
}

void solve(){
	cin >> n;
	cin >> S1 >> S2;
	cout << ((check(0)||check(1))?"YES":"NO") << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
