#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5e5+10;
int N;
pll arr[mxn];
ll sum = 0;
priority_queue<ll,vector<ll>,less<ll>> pq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0;i<N;i++)cin>>arr[i].fs;
	for(int i = 0;i<N;i++)cin>>arr[i].sc;
	sort(arr,arr+N,[](pll a,pll b){return a.fs+a.sc<b.fs+b.sc;});
	for(int i = 0;i<N;i++){
		if(sum>arr[i].sc){
			if(pq.top()>arr[i].fs){
				sum -= pq.top();pq.pop();
				sum += arr[i].fs;pq.push(arr[i].fs);
			}
		}
		else{
			pq.push(arr[i].fs);
			sum += arr[i].fs;
		}
	}
	cout<<pq.size()<<'\n';
	return 0;
}
