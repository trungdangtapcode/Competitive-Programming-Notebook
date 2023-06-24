#include <stack>
#include <iostream>

using namespace std;
int n, q;
char str[100005]; //string
stack <int> sta;

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


int main(){
	cin >> n >> q;
	//memset(str,'#',sizeof(str[0])*n);
	for (int i = 0; i < n; i++) str[i] = '#';
	for (int i = 0; i < n; i++){
		int x;
		if (sta.empty()){
			sta.push(i);
			continue;
		}
		putchar('?'); putchar(' '); write(sta.top()+1); putchar(' '); write(i+1); putchar('\n');
		read(x);
		if (x){
			str[sta.top()] = '(';
			str[i] = ')';
			sta.pop();
		} else sta.push(i);
	}
	
	if (!sta.empty()){
		int stackSize = sta.size();
		for (int i = 0; i < stackSize/2; i++) {
			str[sta.top()] = '(';
			sta.pop();
		} 
		for (int i = 0; i < stackSize/2; i++){
			str[sta.top()] = ')';
			sta.pop();	
		}		
	}
	putchar('!'); putchar(' ');  // << str;
	for (int i = 0; i < n; i++) putchar(str[i]); 
	
	
	return 0;
}

