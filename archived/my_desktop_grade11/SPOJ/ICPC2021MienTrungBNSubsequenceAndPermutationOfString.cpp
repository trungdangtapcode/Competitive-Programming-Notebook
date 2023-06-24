#include <bits/stdc++.h>

using namespace std;
string s, t;
int nxt[100005][26], cnt[100005][26], cntT[26], ls, lt;

bool check(int pos, int c){
	int x = nxt[pos][c]-1; //xet luon ca tu vi tri cua char_c khoi can phai tru cntT[c]--
	for (int i = 0; i < 26; i++) if (cntT[i] > cnt[x][i]) return false;
	return true;
}
int main(){
	
	cin >> s >> t;
	ls = s.length();
	lt = t.length();
	
	for (int i = 0; i < 26; i++) nxt[ls][i] = ls + 1; //max = [ls-1]+1
	for (int i = ls-1; i >= 0; i--){
		for (int j = 0; j < 26; j++){
			nxt[i][j] = nxt[i+1][j];
			cnt[i][j] = cnt[i+1][j];
		}
		nxt[i][s[i]-'a'] = i+1;
		cnt[i][s[i]-'a']++;
	}
	for (int i = 0; i < lt; i++) cntT[t[i]-'a']++;
	//for (int i = 0; i < 26; i++) cout << (char)(i+'a') << " " << cntT[i] << endl;
	int start = 0; string res = "";
	for (int i = 0; i < lt; i++){
		bool b = true;
		for (int j = 0; j < 26; j++) if (cntT[j]>0&&check(start,j)){
			//cout << i << "->" << j << endl;
			start = nxt[start][j]; //i++
			cntT[j]--;
			res += (char)(j+'a');
			b = false;
			break;
		}
		if (b){
			cout << -1;
			return 0;
		}
	}
	cout << res;
	
	return 0;
}
