#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

struct node{
	ll ha;
	string last,head;
	node(){
		ha = 0;
		last = head = "";
	}
	node(string s){
		ha = 0;
		for(int i = 0;i+4<=s.size();i++)if(s.substr(i,4) == "haha")ha++;
		if(s.size()>=3)head = s.substr(0,3),last = s.substr(s.size()-3,3);
		else head = last = s;
	}
	node operator+(node b)const{
		node re;
		re.ha = ha+b.ha;
		string tmp = last+b.head;
		re.head = head;
		re.last = b.last;
		for(int i = 0;i+4<=tmp.size();i++)if(tmp.substr(i,4) == "haha")re.ha++;
		if(re.head.size()<3){
			if(tmp.size()>=3)re.head = tmp.substr(0,3);
			else re.head = tmp;
		}
		if(re.last.size()<3){
			if(tmp.size()>=3)re.last = tmp.substr(tmp.size()-3,3);
			else re.last = tmp;
		}
		return re;
	}
};

void solve(){
	map<string,node> mp;
	int n;
	cin>>n;
	while(n--){
		string s,op;
		cin>>s>>op;
		if(op == ":="){
			string val;
			cin>>val;
			mp[s] = node(val);
		}
		else{
			string a,b;
			cin>>a>>b>>b;
			mp[s] = mp[a]+mp[b];
		}
		if(!n){
			cout<<mp[s].ha<<'\n';
		}
	}
	/*
	for(auto &i:mp){
		cout<<i.fs<<":"<<i.sc.head<<' '<<i.sc.last<<';';
	}
	cout<<'\n';

   */
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
