#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e7+10;
int lpf[mxn];
vector<int> primes;
vector<int> cnt;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			primes.push_back(i);
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	int tar;
	cin>>tar;
	ll sum = 0;
	for(ll i = 1;i<mxn;i++){
		sum += i;
		ll now = sum;
		ll ans = 1;
		for(int j = 0;j<primes.size();j++){
			if(now<primes[j])break;
			int cnt = 0;
			while(now%primes[j] == 0){
				now/=primes[j];
				cnt++;
			}
			ans *= cnt+1;
		}
		cout<<sum<<":"<<ans<<endl;
		if(ans>=tar){
			cout<<sum<<endl;
			return 0;
		}
	}
	cout<<"No soltuion";
}
