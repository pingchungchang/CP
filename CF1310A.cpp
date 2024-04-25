#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 2e9+10;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	map<ll,vector<ll>> mp;
	pll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs;
	}
	for(auto &i:arr){
		cin>>i.sc;
		mp[i.fs].push_back(i.sc);
	}
	mp[inf].push_back(0);
	sort(arr,arr+n);
	priority_queue<ll,vector<ll>,less<ll>> pq;
	ll ans = 0,sum = 0;
	ll pre = arr[0].fs;
	for(auto &i:mp){
		while(pre<i.fs&&!pq.empty()){
			pre++;
			ans += sum;
			sum -= pq.top();
			pq.pop();
		}
		ans += sum;
		for(auto &j:i.sc){
			sum += j;
			pq.push(j);
		}
		if(!pq.empty()){
			sum -= pq.top();
			pq.pop();
		}
		pre = i.fs+1;
	}
	cout<<ans;
}
