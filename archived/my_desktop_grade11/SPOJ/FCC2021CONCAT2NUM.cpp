#include <bits/stdc++.h>

using namespace std;
int n,t;
long long int l, r, base10, a[100005], res = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--){
		cin >> n >> l >> r;
		for (int i = 0; i < n; i++) cin >> a[i];
		//v = a[pos]*base10+a[j] => (v-a[j])/base10 + (epsilon);
		sort(a,a+n);
		res = 0;
		for (int i = 0; i < n; i++){
			base10 = 10; //not 1 
			while (base10 <= a[i]) base10 *= 10;
			//int pos1 = (int)(lower_bound(a,a+n,(l-a[i])/base10) - a); //
			int pos1 = (int)(lower_bound(a,a+n,(l-a[i]+base10-1)/base10) - a);
			int pos2 = (int)(upper_bound(a,a+n,(r-a[i])/base10) - a - 1);
			//cout << t << ". " << pos1 << " " << pos2 << endl;
			res += pos2 - pos1 + 1;
			//if (pos1 <= i&& i <= pos2) res--; accept with i == j
		}
		cout << res << '\n';
		
	}
	return 0;
}
