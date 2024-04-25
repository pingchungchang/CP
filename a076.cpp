#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	node* l;
	node* r;
	int val;
	node(){
		val = -1;
		l = nullptr;
		r = nullptr;
	}
};
void p(node* pos,node* now){
	if(pos->val>now->val){
		if(pos->l == nullptr){
			pos->l = now;
		}
		else p(pos->l,now);
	}
	else{
		if(pos->r == nullptr){
			pos->r = now;
		}
		else p(pos->r,now);
	}
	
}

int dfs(node* now){
	if(now == nullptr)return 0;
	return max(dfs(now->r),dfs(now->l))+1;
}
int main(){
	int n;
	node* root = new node;
	root->val = INT_MAX;
	while(cin>>n){
		node* now = new node();
		now->val = n;
		p(root,now);
	}
	cout<<dfs(root->l);
}

