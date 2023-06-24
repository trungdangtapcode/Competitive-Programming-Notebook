#include <bits/stdc++.h>

using namespace std;
int n;
int a[100005], f[100010], trace[100010];
bool danhdau[100005];
int main(){
	memset(f,1,sizeof(f));
	
	//ifstream fi("daykg.inp");
	//ofstream fo("daykg.out");
	
	cin >> n;
	int myMax = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	f[0] = -1e15;
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(f,f+n+5,a[i])-f;
		f[pos] = a[i];
		myMax = max(myMax,pos);
	}
	//for (int i = 0; i <= 10; i++) cout << f[i] << " ";
	memset(f,1,sizeof(f));
	f[0] = -1e15;
	memset(danhdau,false,sizeof(danhdau));
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(f,f+n+5,a[i])-f;
		f[pos] = a[i];
		trace[pos] = i;
		if (pos==myMax) for (int j = pos; j > 0; j--){
			if (!danhdau[trace[j]]){
				danhdau[trace[j]] = true;
			} else break;
		}
	}
	for (int i = 0; i < n; i++) cout << danhdau[i] << " "; cout << endl;
	cout << myMax;
	//fi.close();
	//fo.close();
	
	return 0;
}
