#include <bits/stdc++.h>
using namespace std;

vector<int> segtree;
void maketree(int pos,int val,int now,int l,int r){
	if(l == r){
		segtree[now]+=val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos){
		maketree(pos,val,now*2+1,l,mid);
	}
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now] = segtree[now*2+1]+segtree[now*2+2];
	return;
}
int getval(int s,int e,int now,int l,int r){
	if(s == -1)return 0;
	if(s == l&&r == e){
		return segtree[now];
	}
	int mid = (l+r)/2;
	if(mid>=e){
		return getval(s,e,now*2+1,l,mid);
	}
	else if(mid<s){
		return getval(s,e,now*2+2,mid+1,r);
	}
	else{
		return getval(s,mid,now*2+1,l,mid)+getval(mid+1,e,now*2+2,mid+1,r);
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	vector<int> all;
	vector<int> v(n);
	vector<vector<int>> req(q);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		all.push_back(v[i]);
	}
	for(int i = 0;i<q;i++){
		char a;
		int b,c;
		cin>>a>>b>>c;
		if(a == '!'){
			req[i] = {1,b,c};
			all.push_back(c);
		}
		else{
			req[i] = {2,b,c};
		}
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 0;i<n;i++){
		v[i] = lower_bound(all.begin(),all.end(),v[i])-all.begin();
	}
	for(int i = 0;i<q;i++){
		if(req[i][0] == 1){
			req[i][1]--;
			req[i][2] = lower_bound(all.begin(),all.end(),req[i][2])-all.begin();
		}
		else{
			int p1 = lower_bound(all.begin(),all.end(),req[i][1])-all.begin();
			int p2 = upper_bound(all.begin(),all.end(),req[i][2])-all.begin();
			p2--;
			if(p1 == all.size()||p1>p2)p1 = -1;
			req[i][1] = p1;
			req[i][2] = p2;
		}
	}
	segtree = vector<int>(all.size()*4,0);
	for(int i = 0;i<v.size();i++){
		maketree(v[i],1,0,0,all.size()-1);
	}
	
	for(int i = 0;i<req.size();i++){
		if(req[i][0] == 1){
			int p1 = req[i][1];
			maketree(v[p1],-1,0,0,all.size()-1);
			v[p1] = req[i][2];
			maketree(v[p1],1,0,0,all.size()-1);
		}
		else{
//			cout<<req[i][1]<<' '<<req[i][2]<<endl<<endl;
			cout<<getval(req[i][1],req[i][2],0,0,all.size()-1)<<'\n';
		}
	}
}
