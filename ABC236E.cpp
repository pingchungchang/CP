#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
ll arr[mxn];
int n;

namespace AVG{
	double dp[mxn];
	bool f(double k){
		//sum/len = k
		//sum >= k*len
		//sum(sum-k)>=len
		for(int i = 0;i<=n;i++)dp[i] = 0;
		dp[1] = arr[1]-k;
		for(int i = 2;i<=n;i++){
			dp[i] = max(dp[i-1],dp[i-2])+arr[i]-k;
		}
		return max(dp[n-1],dp[n])>=0;
	}
	void GO(){
		double l = 0,r = 1e9;
		for(int i= 0;i<100;i++){
			auto mid = (l+r)/2;
			if(f(mid))l = mid;
			else r = mid;
		}
		cout<<fixed<<setprecision(10)<<l<<'\n';
		return;
	}
}

namespace MED{
	bitset<mxn> dp;
	bool f(int k){
		dp.reset();
		int big = 0;
		for(int i = 1;i<=n;i++){
			if(arr[i]>=k)big++,dp[i] = true;
		}
		for(int i = 2;i<=n;i++){
			if(!dp[i]&&!dp[i-1]){
				dp[i] = true;
				big--;
			}
		}
		return big>=1;
	}
	void GO(){
		int l = 0,r = 1e9;
		while(l != r){
			int mid = (l+r+1)>>1;
			if(f(mid))l = mid;
			else r = mid-1;
		}
		cout<<l<<'\n';
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	AVG::GO();
	MED::GO();
	return 0;
}
