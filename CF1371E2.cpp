#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,p;
	cin>>n>>p;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	deque<ll> dq,dq2;
	ll start = arr[n-1]-2e5;
	start = max(start,1LL);
	for(auto &i:arr)dq.push_back(i);
	dq2 = dq;
	ll small = 0;
	ll shift = 0;
	multiset<ll> st;
	for(int i = 0;i<dq.size();i++)dq2[i] -= i,st.insert(dq2[i]);
	vector<ll> ans;
	for(ll x = start;x<arr[n-1];x++){
		while(!dq.empty()&&dq.front()<=x){
			st.erase(st.find(dq2.front()));
			dq.pop_front();
			dq2.pop_front();
			small++;
			shift++;
		}
		if(small>=p){
			continue;
		}
		bool flag = true;
		if(small+x<*st.rbegin()+shift)flag = false;
		//cout<<x<<":"<<flag<<endl;
		if(st.find(small+1-shift+x-p) != st.end())flag = false;
		if(flag)ans.push_back(x);
		/*
		   small+i-sh+x>=dq[i]->small+x-sh>=dq[i]-i
		   small+(i-sh)+1-(dq[i]-x) != p->small+1-sh+x-p != dq[i]-i
	   */
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
