#include <bits/stdc++.h>
using namespace std;


struct node{
	int l;
	int r;
	int t;
	int ans;
	node(int a,int b,int c){
		l = a;
		r = b;
		t = c;
		ans = 0;
	}
};
int n;
int nl,nr;
vector<int> all;
int times[(int)1e5*2] = {};
vector<int> v;
vector<node> ask;
int ans;
int x;
bool cmp(node a,node b){
	if(a.l/x != b.l/x){
		return a.l/x<b.l/x;
	}
	else return a.r<b.r;
}
/*int getval(int l,int r){
//	cout<<l<<' '<<r<<' '<<nl<<' '<<nr<<endl;
	if(nl == -1){
		nl = l;
		ans = 0;
		nr = r;
		for(int i = l;i<=r;i++){
			int now = v[i];
			if(times[now] == 0)ans++;
			times[now] += 1;
		}
		return ans;
	}
	else{
		while(nr<r){
			nr++;
			int now = v[nr];
			times[now]++;
			if(times[now] == 1){
				ans++;
			}
		}
		while(nl>l){
			nl--;
			int now = v[nl];
			times[now]++;
			if(times[now] == 1){
				ans++;
			}
		}
		while(nl<l){
			int now = v[nl];
			times[now]--;
			if(times[now] == 0)ans--;
			nl++;
		}
		while(nr>r){
			int now = v[nr];
			times[now]--;
			if(times[now] == 0)ans--;
			nr--;
		}
	}
//	for(int i = 0;i<times.size();i++)cout<<times[i]<<'.';
//	cout<<endl;
	return ans;
}*/
bool cc(node a,node b){
	return a.t<b.t;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>n>>q;
	x = sqrt(n);
	v = vector<int>(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		all.push_back(v[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 0;i<v.size();i++){
		v[i] = lower_bound(all.begin(),all.end(),v[i])-all.begin();
	}
	ask = vector<node>(q,node(0,0,0));
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		ask[i] = node(a,b,i);
	}
	sort(ask.begin(),ask.end(),cmp);
	nl = 0;
	nr = 0;
	times[v[0]] = 1;
	ans = 1;
	for(int asd = 0;asd<ask.size();asd++){
		
		int r = ask[asd].r;
		int l = ask[asd].l;
		while(nr<r){
			nr++;
			int now = v[nr];
			times[now]++;
			if(times[now] == 1){
				ans++;
			}
		}
		while(nl>l){
			nl--;
			int now = v[nl];
			times[now]++;
			if(times[now] == 1){
				ans++;
			}
		}
		while(nl<l){
			int now = v[nl];
			times[now]--;
			if(times[now] == 0)ans--;
			nl++;
		}
		while(nr>r){
			int now = v[nr];
			times[now]--;
			if(times[now] == 0)ans--;
			nr--;
		}
		
		ask[asd].ans = ans;
		
//		for(int i = 0;i<times.size();i++)cout<<times[i]<<'.';
//		cout<<endl;
	}
	sort(ask.begin(),ask.end(),cc);
	for(int i = 0;i<ask.size();i++)cout<<ask[i].ans<<'\n';
}
