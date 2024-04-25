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

const int mxn = 1e5+10;
int bit[mxn];
void modify(int p,int v){
	for(;p<mxn;p += p&-p){
		bit[p] += v;
	}
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e -= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}
struct node{
	int l,r,t;
	node(){
		l = r = t = 0;
	}
	bool operator<(const node&b)const{
		return r<b.r;
	}
}arr[mxn];
int n;
void solve(){
	memset(bit,0,sizeof(bit));
	for(int i = 0;i<n;i++)cin>>arr[i].l>>arr[i].r>>arr[i].t;
	set<int> st;
	for(int i = 0;i<=mxn;i++)st.insert(i);
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		auto now = arr[i];
		now.l++,now.r++;
		int cnt = getval(now.l,now.r-1);
		if(cnt>=now.t)continue;
		auto it = st.lower_bound(now.r);
		while(cnt<now.t){
			cnt++;
//			cout<<*it<<',';
			it--;
			modify(*it,1);
		}
		auto it2 = st.lower_bound(now.r);
//		if(*it2<*it){
//			auto now = clock();
//			while((clock()-now)/CLOCKS_PER_SEC<=1)continue;
//			return;
//		}
		st.erase(it,it2);
//		cout<<i<<endl;for(int j= 1;j<=10;j++)cout<<getval(j,j)<<' ';cout<<endl;
	}
//	cout<<"C "<<n<<endl<<endl;
	cout<<getval(1,mxn-1)<<'\n';
	return;
}
int main(){
	io
	while(cin>>n){
		if(!n)return 0;
		solve();
	}
}

