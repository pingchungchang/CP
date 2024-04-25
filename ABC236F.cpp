#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 17;
pll arr[1<<mxn];
int n;
int base[mxn];

ll add(ll k){
	for(int i = 17;i>=0;i--){
		if(k&(1<<i)){
			if(base[i])k ^= base[i];
			else return base[i] = k;
		}
	}
	return k;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<(1<<n);i++){
		cin>>arr[i].fs;
		arr[i].sc = i;
	}
	sort(arr+1,arr+(1<<n));
	ll ans = 0;
	for(int i = 1;i<(1<<n);i++){
		if(add(arr[i].sc))ans += arr[i].fs;
	}
	cout<<ans;
}
