#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int arr[mxn],big[mxn],small[mxn];
int n;
ll ans = 0;

void dc(int l,int r){
	/*

   */
	if(r-l+1<40){
		for(int i = l;i<=r;i++){
			pii p = {i,i};
			for(int j = i+1;j<=r;j++){
				if(arr[j]<arr[p.fs])p.fs = j;
				if(arr[j]>arr[p.sc])p.sc = j;
				if(p.fs<p.sc)ans++;
			}
		}
		return;
	}
	if(l == r)return;
	int mid = (l+r)>>1;
	dc(l,mid);
	dc(mid+1,r);
	big[mid] = small[mid] = arr[mid];
	big[mid+1] = small[mid+1] = arr[mid+1];
	for(int i = mid-1;i>=l;i--){
		big[i] = max(big[i+1],arr[i]);
		small[i] = min(small[i+1],arr[i]);
	}
	for(int i = mid+2;i<=r;i++){
		big[i] = max(big[i-1],arr[i]);
		small[i] = min(small[i-1],arr[i]);
	}

	pii p = {mid+1,mid+1};
	int pt = mid;
	for(int i = mid+2;i<=r;i++){
		if(arr[p.fs]>arr[i])p.fs = i;
		if(arr[p.sc]<arr[i])p.sc = i;
		while(pt>=l){
			if(small[i]<small[pt]&&big[i]>big[pt])pt--;
			else break;
		}
		if(p.fs<p.sc)ans += mid-pt;
	}
	//cout<<"1:"<<l<<' '<<mid<<' '<<r<<":"<<ans<<endl;

	p = {mid,mid};
	pt = mid+1;
	for(int i = mid-1;i>=l;i--){
		if(arr[p.fs]>arr[i])p.fs = i;
		if(arr[p.sc]<arr[i])p.sc = i;
		while(pt<=r){
			//cout<<i<<":"<<small[i]<<','<<big[i]<<' '<<pt<<":"<<small[pt]<<' '<<big[pt]<<endl;
			if(small[i]<small[pt]&&big[i]>big[pt])pt++;
			else break;
		}
		if(p.fs<p.sc)ans += pt-mid-1;
	}
	//cout<<"2:"<<l<<' '<<mid<<' '<<r<<":"<<ans<<endl;

	pt = r;
	p = {mid+1,mid+1};
	for(int i = mid;i>=l;i--){
		while(p.fs<=r){
			if(big[i]>big[p.fs])p.fs++;
			else break;
		}
		p.sc = max(p.sc,p.fs);
		while(p.sc<=r){
			if(big[i]<big[p.sc]&&small[i]<small[p.sc])p.sc++;
			else break;
		}
		ans += p.sc-p.fs;
	}
	//cout<<"3:"<<l<<' '<<mid<<' '<<r<<":"<<ans<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	dc(0,n-1);
	cout<<ans;
}
