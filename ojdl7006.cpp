#include <bits/stdc++.h>
using namespace std;


const int mxn = 1e5+10;
int bit[mxn];
int arr[mxn];
int ans[mxn];
void modify(int p,int v){
	for(;p<mxn;p += p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e -= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}

struct Q{
	int tp;
	int ql,qr,k,id;
	Q(){}
};

void dc(int l,int r,vector<Q> &req){
	// cout<<l<<' '<<r<<":";for(auto &i:req)cout<<i.tp<<' '<<i.ql<<' '<<i.qr<<',';cout<<endl;
	if(l == r||req.empty()){
		for(auto &i:req){
			if(i.tp){
				ans[i.id] = l;
			}
		}
		return;
	}
	vector<Q> q1,q2;
	int mid = (l+r)>>1;
	for(auto &i:req){
		if(!i.tp){
			if(i.qr>mid){
				modify(i.ql,1);
				q2.push_back(i);
			}
			else q1.push_back(i);
		}
		else{
			// if(i.tp&&i.id == 0){
			// 	cout<<";"<<i.ql<<' '<<i.qr<<' '<<getval(i.ql,i.qr)<<' '<<i.k<<endl;
			// }
			if(getval(i.ql,i.qr)>=i.k)q2.push_back(i);
			else{
				auto tmp = i;
				tmp.k -= getval(tmp.ql,tmp.qr);
				q1.push_back(tmp);
			}
		}
	}
	for(auto &i:q2){
		if(!i.tp)modify(i.ql,-1);
	}
	dc(l,mid,q1);
	dc(mid+1,r,q2);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> all = {0};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 1;i<=n;i++){
		arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
	}
	vector<Q> req;
	for(int i = 1;i<=n;i++){
		req.push_back(Q());
		req.back().tp = 0;
		req.back().ql = i;
		req.back().qr = arr[i];
	}
	for(int i = 0;i<k;i++){
		req.push_back(Q());
		req.back().tp = 1;
		req.back().id = i;
		cin>>req.back().ql>>req.back().qr>>req.back().k;
	}
	dc(0,all.size()-1,req);
	for(int i= 0;i<k;i++)cout<<ans[i]<<'\n';
	return 0;
}