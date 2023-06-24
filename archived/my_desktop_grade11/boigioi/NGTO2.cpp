#include <bits/stdc++.h>

using namespace std;
int f[9000050];
int n;
int main(){
	cin >> n; 
	memset(f,0,sizeof(f));
	for (int i = 2; i <= 9000005; i++){
		for (int j = 2*i; j <= 9000005; j+=i) f[j]++;
	}
	//for (int i = 2; i < 100; i++) cout << i << " " << f[i] << endl;
	int cnt = 0;
	for (int i = 2; i <= 9000005; i++) if (!f[i]){
		cnt++;
		//cout << i <<" "<< cnt << " == " <<n << endl;
		if (cnt==n){
			cout << i << endl;
			break;
		}
	}
	//cout << res;
	
	return 0;
}
