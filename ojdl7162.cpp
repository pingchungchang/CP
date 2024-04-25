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
const ll mxn = 1e5+10;
ll arr[mxn];
ll ans = 0;
bool cmp(ll a,ll b){
	return a>b;
}
void dc(int l,int r){
	int mid = (l+r)>>1;
	if(l == r){
		ans++;
		return;
	}
	dc(l,mid);dc(mid+1,r);
	ll sl = mid-l+1,sr = r-mid;
	ll left[mid-l+1],right[r-mid],prel[mid-l+1],prer[r-mid];
	for(int i = 0;i<sl;i++)left[sl-i-1] = arr[i+l];
	for(int i = 0;i<sr;i++)right[i] = arr[mid+i+1];
	for(int i = 0;i<sl;i++)prel[i] = left[i];
	for(int i = 0;i<sr;i++)prer[i] = right[i];
	
	for(int i = 1;i<sl;i++)left[i] = max(left[i],left[i-1]);
	for(int i = 1;i<sr;i++)right[i] = max(right[i],right[i-1]);
	for(int i = 1;i<sl;i++)prel[i] += prel[i-1];
	for(int i = 1;i<sr;i++)prer[i] += prer[i-1];
	ll tmp = 0;
	ll p = 0;
	for(int i = 0;i<sl;i++){
		while(p != sr&&left[i]>right[p])p++;
		ll pp = upper_bound(prer,prer+sr,left[i]*left[i]-prel[i])-prer;
		tmp += min(p,pp);
	}
	p = 0;
	for(int i = 0;i<sr;i++){
		while(p != sl&&left[p]<=right[i])p++;
		ll pp = upper_bound(prel,prel+sl,right[i]*right[i]-prer[i])-prel;
		tmp += min(p,pp);
	}
//	cout<<l<<' '<<mid<<' '<<r<<' '<<tmp<<endl;
	ans += tmp;
	return;
}
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	dc(0,n-1);
	cout<<ans;
}

