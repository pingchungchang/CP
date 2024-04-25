#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mod = 1e9+7;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b;
	cin>>a>>b;
	a++,b++;
	ll tar = __gcd(a,b);
	tar--;
	ll now[2][2] = {{1,0},{0,1}};
	ll arr[2][2] = {{1,1},{1,0}};
	while(tar){
		ll buf[2][2];
		if(tar&1){
			memset(buf,0,sizeof(buf));
			for(int i = 0;i<2;i++){
				for(int j = 0;j<2;j++){
					for(int k = 0;k<2;k++){
						buf[i][j] += arr[i][k]*now[k][j]%mod;
					}
				}
			}
			for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)now[i][j] = buf[i][j]%mod;
		}
		memset(buf,0,sizeof(buf));
		for(int i = 0;i<2;i++){
			for(int j = 0;j<2;j++){
				for(int k = 0;k<2;k++){
					buf[i][j] += arr[i][k]*arr[k][j]%mod;
				}
			}
		}
		for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)arr[i][j] = buf[i][j]%mod;
		tar>>=1;
	}
	cout<<(now[0][0])%mod;
}
