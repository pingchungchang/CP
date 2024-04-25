#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	stack<int> a;
	stack<int> b;
	stack<int> station;
	stack<int> rail;
	for(int i = n;i>=1;i--)a.push(i);
	for(int i =0;i<n;i++){
		int k;
		cin>>k;
		if(!a.empty()&&k>=a.top()){
			while(k!= a.top()){
				station.push(a.top());
				a.pop();
			}
			a.pop();
		}
		else{
			while(station.top()!= k){
				rail.push(station.top());
				station.pop();
			}
			station.pop();
			if(rail.size()>m){
				cout<<"no";
				return 0;
			}
			while(!rail.empty()){
				station.push(rail.top());
				rail.pop();
			}
		}
	}
	cout<<"yes";
	return 0;
}
