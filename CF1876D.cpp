#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 2e5+10;
const ll mod = 998244353;
int pre[mxn];
int arr[mxn];
int dsu[mxn],sz[mxn];
int n;
set<int> st;
deque<int> dq;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	 a= root(a),b = root(b);
	 if(a == b)return;
	 if(sz[a]<sz[b])swap(a,b);
	 dsu[b] = a;
	 sz[a] += sz[b];
}

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<mxn;i++)dsu[i] = i,sz[i] = 1;
	for(int i = 1;i<=n;i++){
		st.insert(arr[i]);
		if(!pre[arr[i]])pre[arr[i]] = i;
		else{
			pre[arr[i]] = 0;
			arr[i] = -arr[i];
		}
	}
	bool flag = false;
	for(int i = 1;i<=n;i++){
		if(arr[i]>0)dq.push_back(arr[i]);
		else if(arr[i]+dq.front()!=0){
			flag = true;
			break;
		}
		else dq.pop_front();
	}
	ll base = pw(2,st.size()-1);
	if(*max_element(pre,pre+mxn) != 0||flag){
		cout<<base;
		return 0;
	}
	int sum = 0;
	int pivot = -1;
	for(int i = 1;i<=n;i++){
		if(arr[i]<0){
			sum--;
			if(!sum)pivot = -1;
		}
		if(arr[i]>0){
			if(!sum)pivot = arr[i];
			sum++;
			onion(pivot,arr[i]);
		}
	}
	int C = 0;
	for(auto &i:st)if(dsu[i] == i)C++;
	cout<<mub(base,pw(2,C-1))<<'\n';
}
