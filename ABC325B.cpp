#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1010;
int n;
pii arr[mxn];
pii range[mxn];
int cnt[24];


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<9;j++){
			cnt[(arr[i].sc+j)%24]+=arr[i].fs;
		}
	}
	cout<<*max_element(cnt,cnt+24);
}
