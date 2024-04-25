#include <iostream>

using namespace std;

int main(){
	int a,b;
	char c;
	while(cin>>a>>c>>b){
		int ans;
		if(c == '/'){
			if(b == 0){
				cout<<"wrong expression\n";
				continue;
			}
			ans = a/b;
		}
		else if(c == '+')ans = a+b;
		else if(c == '-')ans = a-b;
		else if(c == '*')ans = a*b;
		else if(c == '%'){
			if(b == 0){
				cout<<"wrong expression\n";
				continue;
			}
			ans = a%b;
		}
		else{
			return 0;
		}
		cout<<a<<' '<<c<<' '<<b<<" = "<<ans<<'\n';
	}
}
