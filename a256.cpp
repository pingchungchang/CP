#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	char c;
	cin>>c;
	char k;
	int ans = 0;
	while(cin>>k){
//		if(k =='0')break;
		if(c == k)ans++;
	}
	printf("There is/are %d \'%c\' in your input.",ans,c);
}
