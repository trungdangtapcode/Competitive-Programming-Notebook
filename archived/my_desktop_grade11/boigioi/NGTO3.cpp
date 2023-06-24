#include <bits/stdc++.h>

using namespace std;
int f[100005];
int n;
int main(){
	cin >> n; 
	memset(f,0,sizeof(f));
	for (int i = 1; i <= 100005; i++) f[i] = i;
	for (int i = 2; i <= 100005; i++){
		if (f[i] == i)for (int j = i; j <= 100005; j+=i) f[j]-=f[j]/i;
	}
	for (int i = 2; i < 100; i++) cout << i << " " << f[i] << endl;
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
