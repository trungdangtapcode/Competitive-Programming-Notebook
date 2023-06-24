#include<bits/stdc++.h>

using namespace std;
int res[100005], n, z[100005];
string s;
int main(){
	
	cin >> s;
	n = s.length();
	s = "#" + s;
	z[1] = n;
	for (int i = 2, l = 1, r = 1; i <= n; i++){
		if (i>r){
			l = r = i;
			while (r<=n&&s[r]==s[r-l+1]) r++;
			r--;
			z[i] = r-l+1;
		} else {
			if (z[i-l+1]<r-i+1){
				z[i] = z[i-l+1];
			} else {
				l = i;
				while (r<=n&&s[r]==s[r-l+1]) r++;
				r--;
				z[i] = r-l+1;
			}
		}
	}
	for (int i = 1; i <= n; i++) res[z[i]]++;
	for (int i = n-1; i > 0; i--) res[i] += res[i+1];
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	return 0;
}
