#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pair<int,int> arr[n];
	for(auto &i:arr){
		char a;
		int b;
		int aa = 0;
		cin>>a>>b;
		if(a == 'S')aa = 4;
		else if(a == 'H')aa = 3;
		else if(a == 'D')aa = 2;
		else aa = 1;
		i = {b,aa};
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	int k;
	cin>>k;
	k--;
	if(arr[k].sc == 4)cout<<"S";
	else if(arr[k].sc == 3)cout<<"H";
	else if(arr[k].sc == 2)cout<<"D";
	else cout<<"C";
	cout<<" "<<arr[k].fs;
	return 0;
}
