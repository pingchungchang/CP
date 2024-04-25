#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

namespace BRUTE{
	const int mxn = 500;
	ll arr[300005];
	int dp[mxn][3],SG[mxn];
	int len;
	int x,y,z;
	int n;
	int mex(set<int> st){
		for(int i = 0;i<mxn;i++){
			if(st.find(i) == st.end())return i;
		}
		return -1;
	}
	int mex(multiset<int> st){
		for(int i = 0;i<mxn;i++){
			if(st.find(i) == st.end())return i;
		}
		return -1;
	}
	int getval(ll r,ll c){
		if(r<0)return 0;
		if(r<mxn)return dp[r][c];
		r %= len;
		r += len*30;
		return dp[r][c];
	}
	bool check(int s,int e,int l){
		for(int i = s;i+l<e;i++){
			for(int j = 0;j<3;j++){
				if(dp[i][j] != dp[i+l][j])return false;
			}
		}
		return true;
	}
	int get_len(int s,int e){
		len = 1;
		while(!check(s,e,len))len++;
		return len;
	}
	void GO(){
		cin>>n>>x>>y>>z;
		for(int i = 1;i<mxn;i++){
			multiset<int> st;
			if(i-x>=0)st.insert(dp[i-x][0]);
			else st.insert(0);
			if(i-y>=0)st.insert(dp[i-y][1]);
			else st.insert(0);
			if(i-z>=0)st.insert(dp[i-z][2]);
			else st.insert(0);
			dp[i][0] = mex(st);
			auto ts = st;
			if(i-y>=0)ts.erase(ts.find(dp[i-y][1]));
			else ts.erase(ts.find(0));
			dp[i][1] = mex(ts);
			ts = st;
			if(i-z>=0)ts.erase(ts.find(dp[i-z][2]));
			else ts.erase(ts.find(0));
			dp[i][2] = mex(ts);
		}

		len = get_len(mxn/2,mxn-1);
		/*
	   */
		for(int i = 1;i<mxn;i++){
			cout<<setw(3)<<i<<":"<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
		}cout<<len<<endl<<endl;
		int s = 0;
		for(int i = 1;i<=n;i++){
			cin>>arr[i];
			s ^= getval(arr[i],0);
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			int ts = s^getval(arr[i],0);
			ts ^= getval(arr[i]-x,0);
			if(!ts)ans++;
			ts = s^getval(arr[i],0);
			ts ^= getval(arr[i]-y,1);
			if(!ts)ans++;
			ts = s^getval(arr[i],0);
			ts ^= getval(arr[i]-z,2);
			if(!ts)ans++;
		}
		cout<<ans<<'\n';
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)BRUTE::GO();return 0;
}
