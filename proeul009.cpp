#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int s;
	cin>>s;
	for(ll i = 1;i<s;i++){
		for(ll j = i+1;j<s;j++){
			ll k = s-i-j;
			if(k>0&&k*k==i*i+j*j){
				cout<<i<<' '<<j<<' '<<k<<endl;
				cout<<i*j*k;
				return 0;
			}
		}
	}
	cout<<"No Solution\n";
	return 0;
}
