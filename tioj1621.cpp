#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int n;
	cin>>n;
	map<int,ll> m;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>> pq;
	for(int i = 0;i<n;i++){
		ll d,w;
		cin>>d>>w;
		if(i !=0){
			if(m.rbegin()->second == w)continue;
		}
		m[i] = w;
		pq.push(make_pair(w,i));
	}
	int ans = 0;
	while(!pq.empty()&&m.size()>0){
		int n = pq.top().second;
		pq.pop();
		if(m.count(n) == 0)continue;
		ans++;
		auto it = m.find(n);
//		for(auto it = m.begin();it != m.end();it++)cout<<it->second<<' ';
//		cout<<endl;
		auto it2 = m.find(n);
		if(it->first != m.begin()->first&&it->first != m.rbegin()->first){
			it--;
			it2++;
			if(it->second == it2->second)m.erase(++m.find(n)); 
		}
		m.erase(m.find(n));
	}
	cout<<ans;
}
/*
int main(){
	int n;
	cin>>n;
	vector<ll> v;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>> pq;
	vector<int> all;
	for(int i = 0;i<n;i++){
		ll d,w;
		cin>>w>>d;
		if(i != 0){
			if(d == v[v.size()-1])continue;
		}
		all.push_back(i);
		v.push_back(d);
		pq.push(make_pair(d,i));
	}
	ll ans = 0;
	while(!pq.empty()&&all.size()>0){
		int pos = lower_bound(all.begin(),all.end(),pq.top().second)-all.begin();
		if(all[pos] != pq.top().second){
			pq.pop();
			continue;
		}
		pq.pop();
//		cout<<all.size()<<'\n';
//		for(int i = 0;i<all.size();i++)cout<<all[i]<<' ';
//		cout<<endl<<endl;
		ans++;
		if(pos+1<v.size()&&pos-1>=0){
			if(v[pos+1] == v[pos-1]){
				v.erase(v.begin()+pos,v.begin()+pos+2);
				all.erase(all.begin()+pos,all.begin()+pos+2);
			}
			else{
				v.erase(v.begin()+pos);
				all.erase(all.begin()+pos);
			}
		}
		else{
			v.erase(v.begin()+pos);
			all.erase(all.begin()+pos);
		}
	}
	cout<<ans;
}*/
