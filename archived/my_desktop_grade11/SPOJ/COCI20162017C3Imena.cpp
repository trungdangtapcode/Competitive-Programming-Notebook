#include <bits/stdc++.h>
using namespace std;
int n,q;
string s;


bool check(string s){
	int n = s.length();
	if (s[0]<'A'||s[0]>'Z') return false;
	for  (int i = 1; i < n; i++){
		if (s[i]<'a'||s[i]>'z') return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin.ignore(1); //2
	getline(cin,s);
	int j = -1, res =0;
	for (int i = 0; i < s.length(); i++){
		//cout << i << " " << s[i] << endl;
		if (s[i]==' '||s[i]=='.'||s[i]=='?'||s[i]=='!'){
			//cout << j+1 << "->" << i-1-(j+1)+1 << endl;
			//cout <<"|" << s.substr(j+1,i-1-(j+1)+1) <<"|" << endl;
			if (check(s.substr(j+1,i-1-(j+1)+1))){
				//cout << "bulontranem" << endl; 
				res++;
			}
			j = i;
			if (s[i]=='.'||s[i]=='?'||s[i]=='!') cout << res << endl, res = 0;
		}
		//j = i;
	}
	
	return 0;
}
