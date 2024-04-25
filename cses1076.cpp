#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,k;
	cin>>n>>k;
	multiset<ll> l;
	multiset<ll> r;
	vector<ll> v(n);
	for(ll i =0;i<n;i++){
		cin>>v[i];
		if(i<k){
			r.insert(v[i]);
		}
	}
	while(r.size()>l.size()){
		l.insert(*r.begin());
		r.erase(r.begin());
	}
	cout<<*l.rbegin()<<'\n';
	for(ll i = k;i<n;i++){
//		for(auto it = l.begin();it!= l.end();it++){
//			cout<<*it<<' ';
//		}
//		cout<<endl;
//		for(auto it = r.begin();it != r.end();it++){
//			cout<<*it<<' ';
//		}
//		cout<<endl<<endl;
		if(l.find(v[i-k]) != l.end()){
			l.erase(l.find(v[i-k]));
		}
		else r.erase(r.find(v[i-k]));
		while(r.size()>l.size()){
			l.insert(*r.begin());
			r.erase(r.begin());
		}
		while(l.size()>r.size()+1){
			r.insert(*l.rbegin());
			l.erase(--l.end());
		}
		if(r.size()==l.size()){
			if(!r.empty()&&v[i]>*r.begin()){
				l.insert(*r.begin());
				r.erase(r.begin());
				r.insert(v[i]);
			}
			else{
				l.insert(v[i]);
			}
		}
		else{
			if(v[i]<*l.rbegin()){
				r.insert(*l.rbegin());
				l.insert(v[i]);
				l.erase(--l.end());
			}
			else{
				r.insert(v[i]);
			}
		}
		cout<<*l.rbegin()<<'\n';
	}
}
