#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll cross(pair<ll,ll> a,pair<ll,ll> b){
	return a.first*b.second-b.first*a.second;
}
ll dis(pair<ll,ll> a,pair<ll,ll> b){
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
void solve(){
	vector<pair<ll,ll>> v;
	vector<pair<ll,ll>> v2;
	for(int i =0 ;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
		v2.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	stack<pair<pair<ll,ll>,pair<ll,ll>>> st;
	st.push(make_pair(v[0],make_pair(0,0)));
	for(int i = 1;i<v.size();i++){
		pair<ll,ll> dir = make_pair(v[i].first-st.top().first.first,v[i].second-st.top().first.second);
		while(st.size()>1&&cross(dir,st.top().second)<=0){
			st.pop();
			dir = make_pair(v[i].first-st.top().first.first,v[i].second-st.top().first.second);
		}
		st.push(make_pair(v[i],make_pair(-dir.first,-dir.second)));
	}
	vector<pair<ll,ll>> in;
	while(!st.empty()){
		in.push_back(st.top().first);
		st.pop();
	}
	st.push(make_pair(v[v.size()-1],make_pair(0,0)));
	for(int i = v.size()-2;i>=0;i--){
		pair<ll,ll> dir = make_pair(v[i].first-st.top().first.first,v[i].second-st.top().first.second);
		while(st.size()>1&&cross(dir,st.top().second)<=0){
			st.pop();
			dir = make_pair(v[i].first-st.top().first.first,v[i].second-st.top().first.second);
		}
		st.push(make_pair(v[i],make_pair(-dir.first,-dir.second)));
	}
	while(!st.empty()){
		in.push_back(st.top().first);
		st.pop();
	}
	sort(in.begin(),in.end());
	in.erase(unique(in.begin(),in.end()),in.end());
//	for(int i = 0;i<in.size();i++)cout<<in[i].first<<' '<<in[i].second<<',';
//	cout<<endl;
	for(int i = 0;i<n;i++){
		pair<ll,ll> now = v[i];
		ll val = 0;
		for(int j = 0;j<in.size();j++){
			val = max(val,dis(v2[i],in[j]));
		}
		cout<<val<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		solve();
	}
	
}

//1 2,1 3,2 1,2 4,3 1,3 4,4 2,4 3,
