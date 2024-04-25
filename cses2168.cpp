#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll s;
	ll e;
	ll num;
	node(ll a,ll b,ll c){
		s = a;
		e = b;
		num=c;
	}
};
bool cmp(node a,node b){
	if(a.s!= b.s)return a.s<b.s;
	else return a.e>b.e;
}
int main(){
	ll n;
	cin>>n;
	vector<node> v;
	for(ll i =0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v.push_back(node(a,b,i));
	}
	vector<pair<bool,bool>> arr(n,make_pair(false,false));
	sort(v.begin(),v.end(),cmp);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,less<pair<ll,ll>>> pq;
	ll edge = 0;
	for(ll i =0;i<n;i++){
		while(!pq.empty()&&v[i].e<=pq.top().first){
			arr[pq.top().second].first = true;
			pq.pop();
		}
		if(edge>=v[i].e)arr[v[i].num].second = true;
		edge= max(v[i].e,edge);
		pq.push(make_pair(v[i].e,v[i].num));
	}	
	for(ll i =0;i<n;i++){
		if(arr[i].first == true){
			cout<<1;
		}
		else cout<<0;
		if(i != n-1)cout<<' ';
		else cout<<'\n';
	}
	for(ll i =0;i<n;i++){
		if(arr[i].second == true){
			cout<<1;
		}
		else cout<<0;
		if(i !=n-1)cout<<' ';
	}
}
