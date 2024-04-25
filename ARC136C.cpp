#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	int val;
	node* l;
	node* r;
	node(){
		val = -1;
		l = nullptr;
		r = nullptr;
	}
	node(node* le){
		l = le;
	}
};
class Compare{
public:
	bool operator()(node* a,node* b){
		return a->val<b->val;
	}
};
int main(){
	int n;
	cin>>n;
	node* head = new node;
	node* now = head;
	priority_queue<node*,vector<node*>,Compare> pq;
	for(int i = 0;i<=n;i++){
		int k;
		if(i != n)cin>>k;
		else k = 0;
		now->val = k;
		pq.push(now);
		now->r = new node(now);
		now = now->r;
	}
	now = now->l;
	now->r = head;
	head->l = now;
	ll ans= 0;
	while(!pq.empty()){
		node* tmp = pq.top();
		pq.pop();
		tmp->r->l = tmp->l;
		tmp->l->r = tmp->r;
		ans += tmp->val-max(tmp->r->val,tmp->l->val);
	}
	cout<<ans;
}

