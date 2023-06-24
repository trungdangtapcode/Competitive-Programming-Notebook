#include <bits/stdc++.h>

using namespace std;
int n;
string s[100];
string S0;

bool c[4*8+5];
string ch = "***ABCDEFGHIJKLMNOPQRSTUVWXYZ***";

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(c,false,sizeof(c));
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> S0;
	
	for (int i = 0; i < n; i++) if (s[i].substr(0,S0.length())==S0){
		int myMax = 0;
		for (int j = 0; j < n; j++) if (j!=i){
			int dem = 0;
			for (int k = S0.length(); k < s[j].length();k++){
				if (S0[k]==s[j][k]) dem++; else break;
			}
			myMax = max(myMax,dem);
		}
		
		for (int j = S0.length(); j < S0.length()+myMax; j++){
			for (int k = 0; k < ch.length(); k++) if (ch[k]==s[i][j]) c[k] = true;
		}
		if (S0.length()+myMax < s[i].length()) for (int k = 0; k < ch.length(); k++) if (ch[k]==s[i][S0.length()+myMax]) c[k] = true;
	}
	
	//for (int i = 0; i <= 4*8; i++) cout << c[i];
	for (int i = 0; i < 4*8; i++) {
		if (c[i]) cout << ch[i]; else cout << '*';
		if ((i+1)%8==0) cout << endl;
	}
		
	return 0;
}
