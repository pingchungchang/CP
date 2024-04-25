#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long a,b;
    while(cin>>a>>b){
        long long k = max(a-b,b-a);
        cout<<k<<"\n";
    }
}