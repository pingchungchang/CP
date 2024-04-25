#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int arr[mxn];
int n;
int brr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++)cin>>arr[i];
	int head = 0;

	for(int i = 20;i>=0;i--){
		int cnt = 0;
		for(int j = 0;j<n;j++)cnt += (j&(1<<i)?1:0);
		int cnt2 = 0;
		int now = 0;
		for(int j = 1;j<n;j++){
			if((1<<i)&arr[j]){
				if(now == 0)now = 1<<i,cnt2++;
				else now = 0;
			}
			else{
				if(now != 0)now = 1<<i,cnt2++;
				else now = 0;
			}
		}
		if(cnt != cnt2)head^=1<<i;
	}

	brr[1] = head;
	for(int i = 1;i<n;i++){
		brr[i+1] = head^arr[i];
		head ^= arr[i];
	}
	for(int i = 1;i<=n;i++)cout<<brr[i]<<' ';cout<<'\n';
	return 0;
}
