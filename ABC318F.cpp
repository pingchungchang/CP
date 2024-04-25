#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<ll> all;
const ll mxn = 202;
const ll inf = 3e18;
ll pos[mxn],len[mxn];
int n;

bool check(ll cen){
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i = 0;i<n;i++){
		pq.push(abs(pos[i]-cen));
	}
	for(int i = 0;i<n;i++){
		if(pq.top()>len[i])return false;
		pq.pop();
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	all = {-inf,inf};
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>pos[i];
	}
	for(int i = 0;i<n;i++)cin>>len[i];
	for(int i = 0;i<n;i++){
		for(int j =0 ;j<n;j++){
			for(int k = 0;k<4;k++){
				all.push_back(pos[i]+len[j]+k);
				all.push_back(pos[i]+len[j]-k);
				all.push_back(pos[i]-len[j]+k);
				all.push_back(pos[i]-len[j]-k);
			}
		}
		for(int j = 0;j<4;j++){
			all.push_back(pos[i]+j);
			all.push_back(pos[i]-j);
		}
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	ll ans = 0;
	for(int i = 1;i<all.size();i++){
		//cout<<all[i]<<":"<<check(all[i])<<' '<<all[i-1]+1<<":"<<check(all[i-1]+1)<<'\n';
		if(check(all[i])&&check(all[i-1]+1))ans += all[i]-all[i-1];
		else assert(!check(all[i]));
	}
	cout<<ans;
}
