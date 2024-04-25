#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e6+10;
int arr[mxn];
int n;
int low[mxn*2];

inline int calc(vector<int> v,int sh){
	if(v.empty())return 0;
	low[0] = v[0]-1;
	int p = 0;
	int sum = 0;
	for(auto &i:v){
		p ^= arr[i];
		sum ^= arr[i];
		low[p>>sh] = min(low[p>>sh],i);
	}
	int re = v.back()-low[p>>sh];
	p = 0;
	for(int i = v.size()-1;i>=0;i--){
		int pos = v[i];
		p ^= arr[pos];
		//cout<<sh<<":"<<pos<<' '<<p<<' '<<sum<<' '<<(sum^p)<<endl;
		re = max(re,pos-low[(sum^p)>>sh]-1);
	}
	p = 0;
	low[p] = mxn;
	for(auto &i:v)p ^= arr[i],low[p>>sh] = mxn;
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:low)i = mxn*2;
	cin>>n;
	int ans = 0;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 20;i>=0;i--){
		vector<int> v;
		for(int j = 0;j<n;j++){
			if(arr[j]&(1<<i))v.push_back(j);
			else{
				ans = max(ans,calc(v,i));
				v.clear();
			}
		}
		ans = max(ans,calc(v,i));
	}
	cout<<ans;
}
