#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    deque<ld> pos,neg;
    ld arr[n];
    for(int i = 0;i<n;i++){
        ll k;
        cin>>k;
        arr[i] = k;
        if(k>0)pos.push_back(k);
        else neg.push_back(k);
    }
    sort(pos.rbegin(),pos.rend());
    sort(neg.begin(),neg.end());
    ld big = (arr[0]+arr[1]+arr[2])/(arr[0]*arr[1]*arr[2]);
	ld small = big;
	vector<ld> all;
	for(int i = 0;i<3;i++)if(!neg.empty())all.push_back(neg.back()),neg.pop_back();
	for(int i = 0;i<3;i++)if(!neg.empty())all.push_back(neg.front()),neg.pop_front();
	for(int i = 0;i<3;i++)if(!pos.empty())all.push_back(pos.back()),pos.pop_back();
	for(int i = 0;i<3;i++)if(!pos.empty())all.push_back(pos.front()),pos.pop_front();
	for(int i = 0;i<all.size();i++){
		for(int j = i+1;j<all.size();j++){
			for(int k = j+1;k<all.size();k++){
				big = max(big,(all[i]+all[j]+all[k])/all[i]/all[j]/all[k]);
				small = min(small,(all[i]+all[j]+all[k])/all[i]/all[j]/all[k]);
			}
		}
	}
	cout<<fixed<<setprecision(20)<<small<<'\n'<<big;
	return 0;
}
