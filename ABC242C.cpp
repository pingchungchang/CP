#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 998244353;
int main(){
	int n;
	cin>>n;
	vector<ll> v1(10,1);
	vector<ll> v2;
	for(int i = 1;i<n;i++){
		v2 = vector<ll>(10,0);
		for(int j= 1;j<10;j++){
			if(j != 1){
				v2[j] += v1[j-1];
			}
			if(j != 9)v2[j] += v1[j+1];
			v2[j]+= v1[j];
		}
		for(int j = 0;j<10;j++){
			v1[j] = v2[j]%mod;
		}
	}
	ll ans = 0;
	for(int i = 1;i<10;i++)ans += v1[i];
	cout<<ans%mod;
}

