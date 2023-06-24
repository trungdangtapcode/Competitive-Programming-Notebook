#include <bits/stdc++.h>

using namespace std;
int n, a[2005], b[2005], order[2005];

struct binary{
	int bit1, bit2, bit3;
	
	binary(int x, int y, int z){
		if (y<z) swap(y,z);
		if (x<y) swap(x,y);
		if (y<z) swap(y,z);
		
		if (x==y){
			bit1 = x+1;
			bit2 = z;
			bit3 = -1;
		} else if (y==z){
			if (x==y+1){
				bit1 = x+1;
				bit2 = -1;
				bit3 = -1;
			} else {
				bit1 = x;
				bit2 = y+1;
				bit3 = -1;
			}
		} else {
			bit1 = x;
			bit2 = y;
			bit3 = z;
		}
//		cout << x << " " << y << " " << z << " -> " <<
//		bit1 << " " << bit2 << " " << bit3 << endl;
	}
	
	bool operator<(binary other){
//		cout << bit1 << " " << bit2 << " " << bit3 << " vs " <<
//		other.bit1 << " " << other.bit2 << " " <<other.bit3 << endl;
		if (bit1!=other.bit1) return (bit1<other.bit1);
		if (bit2!=other.bit2) return (bit2<other.bit2);
		return (bit3<other.bit3);
	}
	bool operator<=(binary other){
		if (bit1!=other.bit1) return (bit1<other.bit1);
		if (bit2!=other.bit2) return (bit2<other.bit2);
		return (bit3<=other.bit3);
	}
	bool operator>(binary other){
		if (bit1!=other.bit1) return (bit1>other.bit1);
		if (bit2!=other.bit2) return (bit2>other.bit2);
		return (bit3>other.bit3);
	}
	bool operator>=(binary other){
//		cout << bit1 << " " << bit2 << " " << bit3 << " vs " <<
//		other.bit1 << " " << other.bit2 << " " <<other.bit3 << endl;
		if (bit1!=other.bit1) return (bit1>other.bit1);
		if (bit2!=other.bit2) return (bit2>other.bit2);
		return (bit3>=other.bit3);
	}
};

bool checkBest(int k, int player){ //kiem tra co the hang cao hon k thang bat ki k
//	if (k==n) return true;
	binary bplayer = binary(a[player],b[player],1);
	for (int i = n-k+1, j = n-1; i <= n; i++, j--){
		if (order[j]==player) j--;
		if (binary(a[order[j]],b[order[j]],i)<bplayer) return false; //co thang hon!
	}
	return true;
}
int findBest(int player){
	int l = 0, h = n-1, m, res = 0;
	while (l<=h){
		m = (l+h)/2;
//		cout << m << " " << l << " " << h << endl;
		if (checkBest(m,player)){
			l = m+1;
			res = m;
		} else h = m-1;
	}
	return (n-res); //co n thang hon res thang vay la dung hang n-res
}
bool checkWorst(int k, int player){ //kiem tra thap hon k thang on-top
	binary bplayer = binary(a[player],b[player],n);
	for (int i = k, j = 0; i >= 1; i--, j++){
		if (order[j]==player) j++;
//		cout << order[j] << "+" << i << " vs " << player <<"+" << n << endl;
		if (binary(a[order[j]],b[order[j]],i)>=bplayer) return false; //co thang ga hon!
	}
	return true;
}
int findWorst(int player){
	int l = 0, h = n-1, m, res = 0;
	while (l<=h){
		m = (l+h)/2;
		if (checkWorst(m,player)){
			l = m+1;
			res = m;
		} else h = m-1;
	}
	return (res+1); 
}

bool cmp(int x, int y){
	return (binary(a[x],b[x],-1)<binary(a[y],b[y],-1));
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) order[i] = i;
	sort(order,order+n,cmp);
	//cout << checkBest(1,2);
	//cout << findBest(1);
	//cout << checkWorst(1,1);
	//cout << findWorst(2);
	for (int i = 0; i < n; i++) cout << findBest(i) << ' ' << findWorst(i) << '\n';
	//for (int i = 0; i < n; i++) cout << order[i] << " ";
	//cout << (binary(1,4,-1)<binary(3,3,-1)) << endl;
	
	return 0;
}


//bool checkBest(int k, int player){ //kiem tra co the hang cao hon k thang bat ki k
////	if (k==n) return true;
//	binary bplayer = binary(a[player],b[player],1);
//	for (int i = n-k+1, j = n-1; i <= n; i++, j--){
//		if (order[j]==player) j--;
//		if (binary(a[order[j]],b[order[j]],i)<bplayer) return false; //co thang hon!
//	}
//	return true;
//}

//bool checkBest(int k, int player){ //kiem tra k thang nho hon
////	if (k==n) return true;
//	binary bplayer = binary(a[player],b[player],1);
//	for (int i = n-k+1, j = n-1; i <= n; i++, j--){
//		if (order[j]==player) j--;
//		if (binary(a[order[j]],b[order[j]],i)>=bplayer) return false; //co thang lon hon hoac bang!
//	}
//	return true;
//}
