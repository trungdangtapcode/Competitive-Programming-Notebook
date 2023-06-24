#include<bits/stdc++.h>

using namespace std;
int a, b, c;
int main(){
	freopen("input.inp","r",stdin);
	freopen("output.ans","w",stdout);
	cin >> a >> b >> c;
	for (int i = 1; i <= 1e6; i++){
		long long x = 1ll*i*i;
		if (x%a==0&&x%b==0&&x%c==0){
			cout << i << "\n";
			return 0;
		}
	}
	
	
	return 0;
}
