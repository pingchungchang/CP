#include <bits/stdc++.h>
using namespace std;

#define ll long long
void recursive(ll start,ll target,ll n){
	if(n==1)cout<<start<<' '<<target<<'\n';
	else{
		recursive(start,6-target-start,n-1);
		cout<<start<<' '<<target<<'\n';
		recursive(6-target-start,target,n-1);
	}
}
int main(){
	ll n;
	cin>>n;
	ll k=1;
	for(ll i =0;i<n;i++)k*=2;
	cout<<k-1<<endl;
	recursive(1,3,n);
}
