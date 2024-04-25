#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const ll mxn = 550;

ll arr[mxn][mxn],brr[mxn][mxn],crr[mxn][mxn],drr[mxn][mxn];
ll N,M,K;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++)cin>>arr[i][j];
	}
	for(int i = 0;i<M;i++){
		for(int j = 0;j<K;j++)cin>>brr[i][j];
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<K;j++){
			for(int k = 0;k<M;k++){
				crr[i][j] += arr[i][k]*brr[k][j];
			}
		}
	}
	for(int i = 0;i<N;i++)for(int j = 0;j<K;j++)drr[j][i] = crr[i][j];
	for(int i = 0;i<K;i++){
		for(int j = 0;j<N;j++)cout<<drr[i][j]<<' ';cout<<'\n';
	}
	return 0;
}
