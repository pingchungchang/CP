#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1<<20;
int lbit[mxn],rbit[mxn];
const int lg = 19;

void modify(int bit[],int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}

int getval(int bit[],int p){
	int re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

int bisearch(int bit[],int k){
	int re = 0;
	for(int i = lg;i>=0;i--){
		//cout<<(re^(1<<i))<<":"<<bit[re^(1<<i)]<<' '<<k<<endl;
		if(bit[re^(1<<i)]<k){
			re |= 1<<i;
			k-= bit[re];
		}
	}
	return re+1;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n+1];
	int cnt[n+1] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i],arr[i]++;
	for(int i = 1;i<=n;i++){
		modify(rbit,arr[i],1);
	}
	for(int i = 1;i<=n;i++){
		modify(rbit,arr[i],-1);
		int re = mxn;
		int t1,t2;
		if((t1 = getval(rbit,arr[i])) != (t2 = getval(rbit,mxn-1))){
			re = min(re,bisearch(rbit,t1+(t2-t1-1)/2+1));
		}
		if((t1 = getval(lbit,arr[i])) != (t2 = getval(lbit,mxn-1))){
			re = min(re,bisearch(lbit,t1+(t2-t1-1)/2+1));
		}
		modify(lbit,arr[i],1);
		//cout<<arr[i]<<":"<<re<<endl;
		if(re<mxn){
			cnt[re]++;
			cnt[arr[i]]++;
		}
	}
	cout<<*max_element(cnt+1,cnt+n+1);
}
