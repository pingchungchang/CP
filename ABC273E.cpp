#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

struct node{
	node* nxt,*pre;
	ll val;
	node(){
		pre = nxt = this;
		val = -1;
	}
	node(node* p,ll v){
		pre = p;
		nxt = 0;
		val = v;
	}
};
int main(){
	io
	map<int,node*> mp;
	int q;
	cin>>q;
	node* now= new node();
	while(q--){
		string s;
		ll k;
		cin>>s;
		if(s != "DELETE")cin>>k;
//		cout<<s<<':'<<k<<endl;
		if(s == "ADD"){
			now = new node(now,k);
		}
		else if(s == "DELETE"){
			now = now->pre;
		}
		else if(s == "SAVE"){
			mp[k] = now;
		}
		else{
			if(mp[k] == 0){
				now = new node();
				mp[k] = now;
			}
			else now = mp[k];
		}
		cout<<now->val<<' ';
	}
	return 0;
	
}

