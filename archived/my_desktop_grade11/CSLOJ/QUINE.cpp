#include <stdio.h>
char*s="#include <stdio.h>%cchar*s=%c%s%c;%cint main(void){printf(s,10,34,s,34,10,10);}%c";
int main(void){printf(s,10,34,s,34,10,10);}

/*
#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen(__FILE__,"r",stdin);
	char c;
	while ((c=getchar())!=EOF){
		cout << c;
	}
	fclose(stdin);
	return 0;
}
*/
