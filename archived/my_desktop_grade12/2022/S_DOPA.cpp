#include<bits/stdc++.h>

using namespace std;
const int p = 1e9+7;
int getPow(long long a, int b){
	long long res = 1;
	while (b){
		if (b&1) res = res*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return res;
}
int n, res;
vector<int> d[100005];
int f[100005]; //sl xau nguyen thuy: chi mot cach chia (AB)
//=> cac xau doi xung kep la boi cua xau nguyen thuy
//=> so luong xau doi xung kep la tong cac uoc xau nguyen thuy
//=> do do se KHONG BI TRUNG vi moi xau chi co MOT CACH CHIA  tao thanh or mobius something idk :_)
//=> cong thuc tong doi xung kep (CO CA BI TRUNG) se de tinh voi moi vi tri
//luu y: BI TRUNG LA CACH VI TRI CHIA KHAC NHAU NHUNG RA CHUOI GIONG NHAU
//=> (ABA)(BAB) => co (l/d) cach de xau doi xung moi 
//la xau boi cua xau nguyen thuy (CAC VI TRI KHAC NHAU)
//=> tong cac uoc nhu vay se ra duoc tong xau kep (CO CA BI TRUNG) day du

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = i*2; j <= n; j+=i) d[j].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		//CT xau doi xung kep (CO CA BI TRUNG)
		int sum = 0;
		if (i%2==0){
			(sum += 1ll*getPow(26,i/2)*i/2%p+1ll*getPow(26,i/2+1)*i/2%p)%=p;
		} else (sum += 1ll*getPow(26,i/2+1)*i%p)%=p;
		f[i] = sum; //tinh xau nguyen thuy i
		for (int j: d[i]) (f[i] += -1ll*f[j]*i/j%p + p)%= p;
	}
	for (int i = 1; i <= n; i++){
		(res += f[i])%=p;
		for (int j: d[i]) (res += f[j])%=p;
	}
	cout << res;
	
	
	return 0;
}
