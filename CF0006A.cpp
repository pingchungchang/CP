#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int arr[4];
	for(auto &i:arr)cin>>i;
	bool tri = false,seg = false;
	sort(arr,arr+4);
	do{
		int tmp[] = {arr[0],arr[1],arr[2]};
		sort(tmp,tmp+3);
		if(tmp[2]<tmp[1]+tmp[0])tri = true;
		else if(tmp[2] == tmp[1]+tmp[0])seg = true;
	}while(next_permutation(arr,arr+4));
	cout<<(tri?"TRIANGLE":(seg?"SEGMENT":"IMPOSSIBLE"));
}
