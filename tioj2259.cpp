#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 1e9+7;
ll dp[3];
ll now[3][3],tmp[3][3];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	n--;
	for(int i = 0;i<3;i++)now[i][i] = 1;
	tmp[0][0] = tmp[0][2] = 1;
	tmp[1][0] = 2,tmp[1][1] = 1;
	tmp[2][0] = tmp[2][1] = 1;
	while(n){
		if(n&1){
			ll tt[3][3];
			memset(tt,0,sizeof(tt));
			for(int i = 0;i<3;i++){
				for(int j = 0;j<3;j++){
					for(int k = 0;k<3;k++){
						tt[i][j] += now[i][k]*tmp[k][j];
					}
				}
			}
			for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)now[i][j] = tt[i][j]%mod;
		}
		n>>=1;
		ll tt[3][3];
		memset(tt,0,sizeof(tt));
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				for(int k = 0;k<3;k++){
					tt[i][j] += tmp[i][k]*tmp[k][j];
				}
			}
		}
		for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)tmp[i][j] = tt[i][j]%mod;
	}
	cout<<now[2][0];
}
