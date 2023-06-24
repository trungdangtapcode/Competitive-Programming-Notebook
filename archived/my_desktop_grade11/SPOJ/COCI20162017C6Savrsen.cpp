#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7+5;
long long int f[maxN];
int a, b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b;
	//memset(f,0,sizeof(f));
	for (int i = 1; i <= b; i++) f[i] = i;
	for (int i = 1; i <= b; i++) {
		for (int j = 2*i; j <= b; j+=i){
			f[j] -= i;
			//cout << i << "-" << j << "   " << f[j] << endl;
		}
	}
	//for (int i = 1; i <= b; i++) cout << i << " " << f[i] << endl;
	f[0] = 0;
	for (int i = 1; i <= b; i++) f[i] = abs(f[i]) + f[i-1];
	cout << f[b]-f[a-1];
	
	
	return 0;
}
