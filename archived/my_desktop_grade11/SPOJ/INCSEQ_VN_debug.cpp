#include <bits/stdc++.h>

using namespace std;
int n, a[100005], val[100005], res[100005], k;
const int p = 5e6;

void reset(){
	memset(val,0,sizeof(val));
}
void update(int x, int y){
	cout << x << " " << y << endl;
	while (x<=1e5+1){
		cout << x << " ";
		//val[x] = (val[x]+y)%p;
		x += (x&-x);
		cout << bitset<32>(x) << endl;
	}
	cout << " Hi";
}
int getSum(int x){
	int res = 0;
	while (x>0){
		cout << x << " di nguoc" << endl;
		res = (res+val[x])%p;
		x -= (x&-x);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
//	update(1,1);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]++, res[i] = 1; //a[i] do cao (goi la cay)
	//update(1,1);
	//for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	update(1,1);
	for (int i = 0; i < k; i++){
		//reset();
		for (int j = 0; j < n; j++) {
			update(a[j],res[j]); 
			res[j] = getSum(a[j]-1); 
		}
	}
//	int sum = 0;
//	for (int i = 0; i < n; i++) sum = (sum+res[i])%p;
//	cout << sum;
	
	return 0;
}
