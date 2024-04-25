	#include <bits/stdc++.h>
	using namespace std;
	
	#define ll long long
	
	vector<ll> vv;
	ll rec(int l,int r){
		if(r-l <= 1){
			if(vv[r]<vv[l]){
				swap(vv[l],vv[r]);
				return 1;
			}
			else return 0;
		}
		ll ans = 0;
		int mid = (l+r)/2;
		ans += rec(l,mid);
		ans += rec(mid+1,r);
		queue<ll> q1;
		queue<ll> q2;
		int now = l;
		for(int i = l;i<=mid;i++)q1.push(vv[i]);
		for(int i = mid+1;i<=r;i++)q2.push(vv[i]);
		while(!q1.empty()&&!q2.empty()){
			if(q1.front()<=q2.front()){
				vv[now] = q1.front();
				q1.pop();
			}
			else{
				ans += q1.size();
				vv[now] = q2.front();
				q2.pop();
			}
			now++;
		}
		while(!q2.empty()){
			vv[now] = q2.front();
			q2.pop();
			now++;
		}
		while(!q1.empty()){
			vv[now] = q1.front();
			q1.pop();
			now++;
		}
		return ans;
	}
	int main(){
		ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int n;
		ll m;
		cin>>n>>m;
		vector<pair<ll,ll>> v(n);
		for(int i = 0;i<n;i++)cin>>v[i].first;
		for(int i = 0;i<n;i++)cin>>v[i].second;
		sort(v.begin(),v.end());
		vv = vector<ll>(n);
		for(int i = 0;i<n;i++)vv[i] = v[i].second;
		cout<<rec(0,n-1);
		return 0;
	}
