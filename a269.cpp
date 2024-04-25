#include <iostream>

using namespace std;
double trans(int now){
	return (((double)(now-32))*5/9);
}
int main(){
	int n;
	cin>>n;
	cout<<trans(n);
}
