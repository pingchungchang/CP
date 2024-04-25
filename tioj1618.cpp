#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 5e5+10;
int arr[mxn],ans[mxn],brr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	int k;
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)cin>>brr[i];
	int sum = 0;
	deque<int> dq;
	for(int i = 0;i<n;i++){
		while(!dq.empty()&&dq.front()<=i-k)sum -= brr[dq.front()],dq.pop_front();
		while(!dq.empty()&&arr[dq.back()]<=arr[i])sum -= brr[dq.back()],dq.pop_back();
		dq.push_back(i);
		sum += brr[i];
		ans[i] = sum;
	}
	pii p = {ans[0],0};
	for(int i =1;i<n;i++){
		p = max(p,make_pair(ans[i],-i));
	}
	cout<<-p.sc+1<<' '<<p.fs<<'\n';
}
