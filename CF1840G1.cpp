#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int ask(int k){
	if(k>0)cout<<"+ ";
	else cout<<"- ";
	cout<<k<<endl;
	int re;
	cin>>re;
	return re;
}

int main(){
	int s,n;
	cin>>s;
	n = s;
	vector<int> v = {n};
	for(int i = 0;i<1010;i++){
		v.push_back(n = ask(1));
		if(v.back() == s){
			cout<<"! "<<v.size()-1<<endl;
			return 0;
		}
	}
	map<int,int> mp;
	for(int i = 0;i<v.size();i++)mp[v[i]] = i;
	for(int i = 1;i<=1010;i++){
		n = ask(1010);
		if(mp.find(n) != mp.end()){
			cout<<"! "<<v.size()+i*1010-mp[n]-1<<endl;
			return 0;
		}
	}
}
