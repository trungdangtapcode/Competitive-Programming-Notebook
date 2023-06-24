#include<bits/stdc++.h>

using namespace std;
int n;
string s;

bool check(int x){
	int pos_eated = -1, pos_not_eated = -1; //[pos can eat, pos not eat yet]
	for (int i = 0; i < n; i++){
		if (s[i]=='*'&&pos_eated<i&&pos_not_eated<=pos_eated) pos_not_eated = i; //the min that not eat
		if (s[i]=='P') 
			if (pos_eated<pos_not_eated){ //come back to eat
				if (i-pos_not_eated>x) return false;
				int d = i-pos_not_eated;
				pos_eated = max(i+(x-2*d),i+(x-d)/2); //the max can eat
			} else pos_eated = i+x; //just go on
	}
	return (pos_not_eated<=pos_eated);
}

int main(){
	freopen("PACKMAN.INP","r",stdin);
	freopen("PACKMAN.OUT","w",stdout);
	
	cin >> n;
	s.assign(n,'-');
	for (int i = 0; i < n; i++) cin >> s[i];
	int l = 0, h = 2*n, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			h = m-1;
			res = m;
		} else l = m+1;
	}
	cout << res;
	
	return 0;
}
