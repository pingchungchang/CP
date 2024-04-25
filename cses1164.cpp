#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll val;
	ll date;
	ll num;
	ll rm;
	node(ll a,ll b,ll c){
		date = a;
		val = b;
		num = c;
		rm = -1;
	}
};
bool cmp1(node a,node b){
	if(a.date == b.date){
		return a.val<b.val;
	}
	else return a.date<b.date;
}
int main(){
	ll nowroom = 0;
	queue<ll> q;
	vector<node> v;
	ll n;
	cin>>n;
	for(ll i =0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v.push_back(node(a,1,i));
		v.push_back(node(b+1,-1,i));
	}
	
	vector<ll> ans(n);
	sort(v.begin(),v.end(),cmp1);
	for(ll i =0;i<v.size();i++){
//		for(ll i =0;i<v.size();i++)cout<<v[i].rm<<' ';
//		cout<<endl<<endl;
		if(v[i].val>0){
			if(q.empty()){
				nowroom++;
				v[i].rm = nowroom;
			}
			else{
				v[i].rm = q.front();
				q.pop();
			}
			ans[v[i].num] = v[i].rm;
		}
		else{
			q.push(ans[v[i].num]);
		}
	}
	cout<<nowroom<<'\n';
	for(ll i =0;i<n;i++){
		cout<<ans[i];
		if(i != n-1)cout<<' ';
	}
	return 0;
}
