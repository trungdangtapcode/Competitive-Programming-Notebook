#include <bits/stdc++.h>

using namespace std;

int n, res = 26, resL = -1, resR = -1;
vector<int> last(26,-1), sorted(27,-1); //farest at pos [-1] (contain full 26)
string s;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		sorted.erase(find(sorted.begin(),sorted.end(),last[s[i]-'a']));
		last[s[i]-'a'] = i;
		sorted.insert(sorted.begin(),i);
		for (int cnt = 1; cnt <= 26; cnt++){
			if (cnt*(resR-resL+1)<res*(i-sorted[cnt])){ //cnt/(i-sorted[cnt]) < res/(resR-resL+1)
				//contain cnt, at pos sorted[cnt+1] => contain [cnt-1] at pos sorted[cnt]
				res = cnt;
				resR = i;
				resL = sorted[cnt]+1;
			}
		}
	}
	cout << resL+1 << " " << resR+1;// << " " << res;
	
	return 0;
}
