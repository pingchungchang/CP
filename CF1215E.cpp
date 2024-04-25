#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 20;
vector<ll> v[22];
ll sum[22];
ll dp[1<<21];
ll aux[22][22];//aux[i][j]:sum of number of people b_l for b_l = j smaller than a_k for all a_k = i

string parse(int k){
	string re;
	for(int i = 0;i<mxn;i++){
		if(k&(1<<i))re += '1';
		else re += '0';
	}
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		k--;
		sum[k]+=i;
		v[k].push_back(i);
	}

	for(int i = 0;i<mxn;i++){
		for(int j = 0;j<mxn;j++){
			int pt = 0;
			for(int k = 0;k<v[i].size();k++){
				while(pt<v[j].size()&&v[j][pt]<v[i][k])pt++;
				aux[i][j] += pt;
			}
		}
	}

	/*
	for(int i = 0;i<mxn;i++){
		for(int j =0;j<mxn;j++)cout<<aux[i][j]<<' ';cout<<endl;
	}
   */

	for(int i = 1;i<(1<<mxn);i++){
		dp[i] = 1e18;
		for(int j = 0;j<mxn;j++){
			if(i&(1<<j)){
				int tsum = sum[j];
				for(int k = 0;k<mxn;k++){
					if(i&(1<<k)){
						tsum -= aux[j][k];
					}
				}
				dp[i] = min(dp[i],dp[i^(1<<j)]+tsum);
			}
		}
		//cout<<parse(i)<<":"<<dp[i]<<'\n';
	}
	cout<<dp[(1<<mxn)-1];
}
