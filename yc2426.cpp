#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 1e18;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	string ans;
	while(n != 1){
		if(n&1){
			ll tmp = (n*3)/2;
			if(tmp&1){
				ans += "+/";
				n = tmp+1;
			}
			else{
				ans += "-/";
				n = tmp;
			}
		}
		else{
			ans += '/';
			n>>=1;
		}
	}
	cout<<ans.size()<<'\n';
	cout<<ans;
}
