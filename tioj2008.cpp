#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1500010;
const int inf = INT_MAX;
pii arr[mxn];
int len[mxn];
deque<int> dq;

inline bool check(pii a,pii b){
	if(a.fs<=b.fs&&a.sc<b.sc)return true;
	else if(a.fs<b.fs&&a.sc<=b.sc)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	arr[0] = arr[n+1] = {inf,inf};
	dq.push_back(0);
	for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&check(arr[dq.back()],arr[i]))dq.pop_back();
		len[i] += i-dq.back()-1;
		dq.push_back(i);
	}
	dq.clear();
	dq.push_back(n+1);
	for(int i = n;i>=1;i--){
		while(!dq.empty()&&check(arr[dq.back()],arr[i]))dq.pop_back();
		len[i] += dq.back()-i-1;
		dq.push_back(i);
	}
	cout<<*max_element(len+1,len+n+1);
}
