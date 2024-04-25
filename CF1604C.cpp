#include <bits/stdc++.h>
using namespace std;

struct node{
	int l;
	int val;
	int r;
	node(){
		l = -1;
		r = -1;
		val = -1;
	}
	node(int a,int b,int c){
		l = a;
		r = b;
		val = c;
	}
};
void solve(){
	int n;
	cin>>n;
	vector<node> v(n,node());
	for(int i = 0;i<n;i++){
		cin>>v[i].val;
		v[i] = node(i-1,i+1,v[i].val);
	}
	int last = n-1;
	int cnt = n;
	bool done = false;
	while(done == false){
		done = true;
		int now = last;
		int i = cnt;
		while(now != -1){
			if(v[now].val%(i+1) !=0){
				done = false;
				int form = v[now].l;
				int lat = v[now].r;
				cnt--;
				if(form != -1){
					v[form].r = lat;
				}
				if(lat != n){
					v[lat].l = form;
				}
				else{
					last = form;
				}
			}
			now = v[now].l;
			i--;
		}
		if(cnt == 0)done = true;
	}
	if(cnt == 0)cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
