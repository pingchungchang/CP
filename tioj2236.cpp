#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long

const ll mod = 1e9+7;
const ll inf = 2e9+10;
vector<vector<ll>> arr,low,hig,lef,rig;
int n,m;
deque<int> dq;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	arr = vector<vector<int>>(n+2,vector<int>(m+2,inf));
	low = hig = lef = rig = vector<vector<int>>(n+2,vector<int>(m+2,0));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)cin>>arr[i][j];
	}
	for(int i = 1;i<=n;i++){
		dq = {0};
		for(int j = 1;j<=m;j++){
			while(arr[i][dq.back()]<=arr[i][j])dq.pop_back();
			lef[i][j] = j-dq.back()-1;
			dq.push_back(j);
		}
		dq = {m+1};
		for(int j = m;j>=1;j--){
			while(arr[i][dq.back()]<=arr[i][j])dq.pop_back();
			rig[i][j] = dq.back()-j-1;
			dq.push_back(j);
		}
	}
	for(int i = 1;i<=m;i++){
		dq = {0};
		for(int j = 1;j<=n;j++){
			while(arr[dq.back()][i]<=arr[j][i])dq.pop_back();
			hig[j][i] = j-dq.back()-1;
			dq.push_back(j);
		}
		dq = {n+1};
		for(int j = n;j>=1;j--){
			while(arr[dq.back()][i]<=arr[j][i])dq.pop_back();
			low[j][i] = dq.back()-j-1;
			dq.push_back(j);
		}
	}
	ll ans = 0;

	/*
	cout<<"H"<<endl;
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++)cout<<hig[i][j]<<' ';cout<<endl;
	}cout<<endl;cout<<"D"<<endl;
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++)cout<<low[i][j]<<' ';cout<<endl;
	}cout<<endl;cout<<"L"<<endl;
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++)cout<<lef[i][j]<<' ';cout<<endl;
	}cout<<endl;cout<<"R"<<endl;
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++)cout<<rig[i][j]<<' ';cout<<endl;
	}cout<<endl;
   */

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(!low[i][j]||!hig[i][j])continue;
			ll tans = 0;
			if(hig[i][j]<low[i][j]){
				tans += (hig[i][j]+1)*(hig[i][j])/2;
				tans %= mod;
				tans += hig[i][j]*(low[i][j]-hig[i][j])%mod;
				tans %= mod;
			}
			else{
				tans = (low[i][j]+1)*(low[i][j])/2;
				tans %= mod;
			}
			tans = tans*min(lef[i][j],rig[i][j])%mod;
			ans = mad(ans,tans);
			//cout<<i<<' '<<j<<":"<<tans<<endl;
		}
	}
	cout<<ans;
}
