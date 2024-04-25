#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll ans = (n>>1)+(n&1);
	for(int i = 1;i<=60;i++){
		ll ts = 0;
		ll sum = 0;
		for(int j = i+1;j<=60;j++){
			sum |= (n&(1ll<<j));
		}
		sum >>= (i+1);
		ts += max(0ll,sum*(1ll<<i));
		if((1ll<<i)&n){
			sum = 0;
			for(int j = i-1;j>=0;j--){
				sum |= (1ll<<j)&n;
			}
			sum++;
			ts += sum;
		}
		//cout<<i<<":"<<ts<<endl;
		ans += ts;
	}
	cout<<ans;
}
