#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e6+10;
int N;
int arr[mxn];
bitset<mxn> ch;
bitset<mxn> vis;
vector<pii> ans;
vector<pii> psyco;

void change(int a,int b){
	swap(arr[a],arr[b]);
	swap(arr[N-a+1],arr[N-b+1]);
	return;
}

void combine(int a,int b){
	ans.push_back(pii(a,b));
	change(a,b);
	return;
}

void work(int h){
	int now = min(arr[h],N+1-arr[h]);
	while(now != h){
		//cerr<<now<<":"<<h<<":"<<ch[now]<<endl;
		if(arr[h]>arr[N+1-h]){
			swap(arr[h],arr[N+1-h]);
			swap(arr[now],arr[N+1-now]);
			ans.push_back(pii(h,N+1-now));
		}
		else{
			ans.push_back(pii(h,now));
		}
		swap(arr[h],arr[now]);
		swap(arr[N+1-h],arr[N+1-now]);
		now = min(arr[h],N+1-arr[h]);
	};
	//for(int i = 1;i<=N;i++)cerr<<ch[i];cerr<<endl;
	return;
}

void calc(){
	vector<int> odds;
	for(int i = 1;i+i<=N;i++){
		if(vis[i])continue;
		psyco.push_back(pii(i,0));
		int now = i;
		do{
			vis[now] = true;
			psyco.back().sc += ch[now];
			int nxt = min(arr[now],N+1-arr[now]);
			now = nxt;
		}while(now != i);
		if(psyco.back().sc&1){
			odds.push_back(i);
			psyco.pop_back();
		}
	}
	for(int i = 0;i<odds.size();i+=2){
		combine(odds[i],odds[i+1]);
	}
	for(int i = 1;i+i<=N;i++){
		ch[i] = false;
		if(arr[i]>arr[N+1-i])ch[i] = true;
	}
	//for(int i = 1;i<=N;i++)cerr<<ch[i];cerr<<endl;
	for(auto &i:psyco)work(i.fs);
	for(int i = 0;i<odds.size();i+=2)work(odds[i]);
}

void solve(){
	for(int i = 0;i<=N;i++)vis[i] = ch[i] = false;
	psyco.clear();
	ans.clear();
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	int f = 0;
	for(int i = 1;i+i<=N;i++){
		if(arr[i]+arr[N-i+1] != N+1){
			cout<<"-1\n";
			return;
		}
		if(arr[i]>arr[N-i+1]){
			f++;
			ch[i] = true;
		}
	}
	//for(int i = 1;i<=N;i++)cerr<<ch[i];cerr<<endl<<endl;
	if(f&1){
		cout<<"-1\n";
		return;
	}
	calc();
	cout<<ans.size()<<' '<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
