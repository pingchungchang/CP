#include <iostream>
using namespace std;

bool notprime[10000001]={1,1};
int main(){
	int a,b;
	cin>>a>>b;
	for(int i = 2;i<=b;i++){
		if(notprime[i] == true)continue;
		else{
			for(int j = 2*i;j<=b;j+=i){
				notprime[j] = true;
			}
		}
	}
	for(int i =a;i<=b;i++){
		if(notprime[i] == false)cout<<i<<' ';
	}
}
