#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
pii arr[mxn];
int bit[mxn];

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].sc>>arr[i].fs,arr[i].fs++,arr[i].sc++;
	sort(arr,arr+n);
	int p = n-1;
	ll ans = 0;
	for(int i = n-1;i>=0;i--){
		while(arr[p].fs>arr[i].fs){
			modify(arr[p].sc,1);
			p--;
		}
		ans += getval(1,arr[i].sc);
	}
	cout<<ans;
}
