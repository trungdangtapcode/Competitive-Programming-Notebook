#include<bits/stdc++.h>

using namespace std;
int t;
int main(){
	freopen("TRAMKG.INP","r",stdin);
	freopen("TRAMKG.OUT","w",stdout);
	cin >> t;
	if (t%4==0){
		cout << t+1 << " " << 0 << "\n" << (t+1)*159;
	} else if (t%4==1){
		cout << 0 << " " << t+1 << "\n" << (t+1)*159;
	} else if (t%4==2){
		cout << -t-1 << " " << 0 << "\n" << (t+1)*159;
	} else if (t%4==3){
		cout << 0 << " " << -t-1 << "\n" << (t+1)*159;
	};
	return 0;
}
