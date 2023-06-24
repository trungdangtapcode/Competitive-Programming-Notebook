#include <bits/stdc++.h>

using namespace std;

typedef tuple <int,int,int> block;
int n;
block x[1000]; //a, h, c
bool f[40005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
//	x[1] = block{0,1,2};
//	cout << get<2>(x[1]);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> get<1>(x[i]) >> get<0>(x[i]) >> get<2>(x[i]);
	}
	sort(x,x+n);
	
	memset(f,false,sizeof(f));
	f[0] = true;
	for (int i = 0; i < n; i++){
		for (int j = get<0>(x[i]); j >= 0; j--) if (f[j]) { //for (int j = 0; j <= get<0>(x[i]); j++){
			for (int k = 0; k <= get<2>(x[i]); k++){
				if (j+k*get<1>(x[i])>get<0>(x[i])) break;
				f[j+k*get<1>(x[i])] = true;
			}
		}
	}
	//for (int i = 0; i <= 100; i++) cout << i << " " << f[i] << endl;
	for (int i = 40000; i >= 0; i--) if (f[i]){
		cout << i;
		return 0;
	}
	
	return 0;
}
