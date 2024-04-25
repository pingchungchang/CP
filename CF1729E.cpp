#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll ask(ll a,ll b){
	cout<<"? "<<a<<' '<<b<<'\n';
	cout.flush();
	ll re;
	cin>>re;
	return re;
}

int main(){
	ll ans = -1;
	for(ll i = 2;i<=26;i++){
		ll a = ask(1,i),b = ask(i,1);
		if(a == -1){
			cout<<"! "<<i-1<<'\n';cout.flush();
			return 0;
		}
		if(a != b){
			cout<<"! "<<a+b<<endl;
			return 0;
		}
	}
	assert(false);
}

