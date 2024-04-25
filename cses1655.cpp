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
	node *pl,*pr;
	int val;
	node(){
		val = 0;
		pl = pr = 0;
	}
	node(int k){
		val = k;
		pl = pr = 0;
	}
};
node* trie;
void build(int k){
	node* now = trie;
	for(int i = 30;i>=0;i--){
		if(!(k&(1<<i))){
			if(!now->pl){
				now->pl = new node(now->val);
			}
			now = now->pl;
		}
		else{
			if(!now->pr){
				now->pr = new node(now->val|(1<<i));
			}
			now = now->pr;
		}
	}
	return;
}
int getval(int k){
	auto now = trie;
	for(int i = 30;i>=0;i--){
		if(k&(1<<i)){ 
			if(now->pl)now = now->pl;
			else now = now->pr;
		}
		else{
			if(now->pr)now = now->pr;
			else now = now->pl;
		}
	}
	return now->val;
}
int main(){
	io
	int n;
	cin>>n;
	int pre =0;
	int ans = 0;
	trie = new node();
	build(0);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		pre ^= k;
		build(pre);
		ans = max(ans,getval(pre)^pre);
	}
	cout<<ans;
}

