#include <iostream>
using namespace std;

int main(){
	char c;
	int ans = 0;
	while(cin>>c){
//		if(c == '0')break;
		if(c>='a'&&c<='z'){
			ans += (c-'a'+1);
		}
		else if(c>='A'&&c<='Z'){
			ans += (c-'A'+1);
		}
	}
	cout<<ans;
}
