#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	node* pre,*nxt;
	int val;
	node(){
		pre =nxt = 0;
		val = -1;
	}
	node(node* s,node* e,int k){
		pre = s,nxt = e;
		val = k;
		if(s)s->nxt = this;
		if(e)e->pre = this;
		return;
	}
};
const int mxn = 1e6+10;
int main(){
	io
	int q;
	cin>>q;
	node* head = new node();
	node* lst = new node(head,head->nxt,-1);
	vector<node*> v(mxn,nullptr);
//	cout<<q<<endl;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int n;
			cin>>n;
			v[n] = new node(head,head->nxt,n);
		}
		else if(t == 2){
			int n;
			cin>>n;
			v[n] = new node(lst->pre,lst,n);
		}
		else if(t == 3){
			int n,a;
			cin>>n>>a;
			if(!v[a]){
				cout<<"peko\n";
			}
			else{
				v[n] = new node(v[a]->pre,v[a],n);
			}
		}
		else if(t == 4){
			int n,a;
			cin>>n>>a;
			if(!v[a])cout<<"peko\n";
			else v[n] = new node(v[a],v[a]->nxt,n);
		}
		else if(t == 5){
			int k;
			cin>>k;
			if(!v[k])cout<<"peko\n";
			else if(!v[k]->pre||v[k]->pre->val == -1)cout<<"NULL\n";
			else cout<<v[k]->pre->val<<'\n';
		}
		else if(t == 6){
			int k;
			cin>>k;
			if(!v[k])cout<<"peko\n";
			else if(!v[k]->nxt||v[k]->nxt->val == -1)cout<<"NULL\n";
			else cout<<v[k]->nxt->val<<'\n'; 
		}
		else{
			int k;
			cin>>k;
			if(!v[k])cout<<"peko\n";
			else{
				v[k]->pre->nxt = v[k]->nxt;
				v[k]->nxt->pre = v[k]->pre;
				v[k] = nullptr;
			}
		}
	}
	return 0;
}

