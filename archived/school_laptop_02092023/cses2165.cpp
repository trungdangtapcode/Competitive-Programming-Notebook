#include<bits/stdc++.h>

using namespace std;
int n;
void doi(int s, int t, int tmp, int cnt){
	if (cnt==1){
		cout << s << " " << t << "\n";
		return;
	}
	doi(s,tmp,t,cnt-1);
	doi(s,t,tmp,1);
	doi(tmp,t,s,cnt-1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cout << (1ll<<n)-1 << "\n";
	doi(1,3,2,n);
	
	return 0;
}
