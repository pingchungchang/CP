#include <iostream>
#include <vector>
using namespace std;

constexpr int SIZE = 250001;
bool notprime[SIZE]={1,1};
int main(){
	int n;
	vector<int> primelist;
	cin>>n;
	for(int i = 2;i<=n;i++){
		if(notprime[i] == true)continue;
		else{
			primelist.push_back(i);
			for(int j = 2*i;j<=n;j+=i){
				notprime[j] = true;
			}
		}
	}
	if(n==1){
		cout<<"1^1";
		return 0;
	}
	vector<int> times(primelist.size(),0);
	while(n > 1){
		for(int i =0;i<primelist.size();i++){
			if(n%primelist[i] == 0){
				n /= primelist[i];
				times[i]++;
				break;
			}
		}
	}
	bool done =false;
	for(int i =0;i<times.size();i++){
		if(times[i] !=0){
			if(done==true)cout<<"*";
			done = true;
			cout<<primelist[i]<<'^'<<times[i];
		}
	}
	return 0;
}

