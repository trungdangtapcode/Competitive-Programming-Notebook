#include<bits/stdc++.h>

using namespace std;
int cnt[1005], n;

int ucln(int a, int b){
	if (a<b) swap(a,b);
	if (b==0) return a;
	return ucln(a%b,b);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= 1000; i++) cnt[i] = 0;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			cnt[a] = i+1;
		}
		int res = -1;
		if (cnt[1]!=0) res = max(res,cnt[1]*2);
		for (int i = 1; i <= 1000; i++) for (int j = i+1; j <= 1000; j++) if (ucln(i,j)==1&&cnt[i]!=0&&cnt[j]!=0){
			res = max(res,cnt[i]+cnt[j]);
		}
		cout << res << "\n";
		
	}
	
	return 0;
}
