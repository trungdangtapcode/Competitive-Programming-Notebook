#include <iostream>
#include <cstring>

using namespace std;

template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}

int t, n, in, a, b, c, sum, cnt[101];
int main(){
	
	read(t);
	while (t--){
		memset(cnt,0,sizeof(cnt));
		c = b = a = -1;
		read(n);
		for (int i = 0; i < n; i++){
			read(in);
			cnt[in]++;
		}
		sum = 0;
		for (int i = 0; i <= 100; i++){
			if (sum==n/4) c = i;
			if (sum==2*n/4) b = i;
			if (sum==3*n/4) a = i;
			sum += cnt[i];
		}
		if (a>=b&&b>=c&&c>-1) write(c), putchar(' '), write(b), putchar(' '), write(a), putchar('\n');
		else write(-1), putchar('\n');
	}
	
	return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//int t, n, in, a, b, c, sum, cnt[101];
//int main(){
//	ios::sync_with_stdio(0); 
//	cin.tie(0); cout.tie(0);
//	
//	cin >> t;
//	while (t--){
//		memset(cnt,0,sizeof(cnt));
//		c = b = a = -1;
//		cin >> n;
//		for (int i = 0; i < n; i++){
//			cin >> in;
//			cnt[in]++;
//		}
//		sum = 0;
//		for (int i = 0; i <= 100; i++){
//			if (sum==n/4) c = i;
//			if (sum==2*n/4) b = i;
//			if (sum==3*n/4) a = i;
//			sum += cnt[i];
//		}
//		if (a>=b&&b>=c&&c>-1) cout << c << ' ' << b << ' ' << a << '\n';
//		else cout << -1 << '\n';
//	}
//	
//	return 0;
//}
