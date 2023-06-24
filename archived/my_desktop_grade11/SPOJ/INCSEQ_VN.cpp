#include <bits/stdc++.h>

using namespace std;
int n, a[100005], val[100005], res[100005], k;
const int p = 5e6;

void reset(){
	memset(val,0,sizeof(val));
}
void update(int x, int y){
//	cout << x << " " << y << endl;
	while (x<=1e5+1){
//		cout << x << " ";
		val[x] = (val[x]+y)%p;
		x += (x&-x);
//		cout << bitset<32>(x) << endl;
	}
//	cout << " Hi";
}
int getSum(int x){
	int res = 0;
	while (x>0){
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
	for (int i = 0; i < n; i++) cin >> a[i], a[i]++, res[i] = 1; //a[i] do cao (goi la cay), a[i]++ vi khong hoat dong voi do dai = 0
//	for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	for (int i = 2; i <= k; i++){
		reset();
		for (int j = 0; j < n; j++) {
			update(a[j],res[j]); //cap nhat cay o do dai (k-1)
			res[j] = getSum(a[j]-1); //tong cay ngan hon a[i] do dai (k-1) => do dai (k-1) ket thuc = a[i]
		}
//		for (int i = 0; i < n; i++) cout << res[i] << " "; cout << endl;
	}
	int sum = 0; //tong cac kq cay do cao a[i] ket thuc
	for (int i = 0; i < n; i++) sum = (sum+res[i])%p;
	//int sum = 0; //tong cac cay ket thuc
	//for (int i = 0; i <= 1e6; i++) sum = (sum+val[i])%p; //the same (no reset()) neu do dai (k-1)
	cout << sum;
	
	return 0;
}
