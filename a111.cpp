#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	queue<pair<int,int>> q;
	int now = 0;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int k,s;
		cin>>k>>s;
		if(q.empty()||now<k){
			while(!q.empty()&&now<k){
				now += q.front().second;
				q.pop();
			}
			if(now <k){
				now = k+s;
			}
			else{
				q.push(make_pair(k,s));
			}
		}
		else{
			q.push(make_pair(k,s));
		}
		ans = max(ans,(int)q.size());
	}
	cout<<ans;
}
