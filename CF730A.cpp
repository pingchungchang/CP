#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int n;
int big;
int arr[110];
vector<string> ans;

void calc(int k){
	vector<string> tans;
	priority_queue<pii,vector<pii>,less<pii>> pq;
	for(int i = 1;i<=n;i++){
		pq.push({arr[i],i});
	}
	while(!pq.empty()&&pq.top().fs>k){
		auto ta = pq.top();
		pq.pop();
		auto tb = pq.top();
		pq.pop();
		if(max(0,tb.fs-1) < k){
			bool flag = false;
			for(auto &i:tans){
				if(i[ta.sc] == '0'){
					i[ta.sc] = '1';
					flag = true;
					break;
				}
			}
			if(!flag)return;
			ta.fs = max(0,ta.fs-1);
			pq.push(ta);
			pq.push(tb);
		}
		else{
			ta.fs = max(0,ta.fs-1);
			tb.fs = max(0,tb.fs-1);
			tans.push_back(string(n+1,'0'));
			tans.back()[ta.sc] = tans.back()[tb.sc] = '1';
			pq.push(ta);
			pq.push(tb);
		}
	}
	while(!pq.empty()){
		if(pq.top().fs != k)return;
		pq.pop();
	}
	ans = tans;
	big = k;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 0;i<=100;i++){
		if(*min_element(arr+1,arr+n+1)<i)break;
		calc(i);
	}
	cout<<big<<'\n';
	cout<<ans.size()<<'\n';
	for(auto &i:ans){
		cout<<i.substr(1,n)<<'\n';
	}
	return 0;
}
