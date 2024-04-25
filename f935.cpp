#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int biggest = 100;
    int smallest = 100;
    int nowbiggest = 100;
    int nowsmallest = 100;
    while(cin>>n){
        if(n == 0)break;
        if(n<nowsmallest){
            if(biggest-smallest<nowbiggest-nowsmallest){
                biggest = nowbiggest;
                smallest = nowsmallest;
            }
            nowsmallest = n;
            nowbiggest = n;
        }
        else{
            nowbiggest = max(nowbiggest,n);
        }
    }
    if(nowbiggest-nowsmallest>biggest-smallest){
        biggest = nowbiggest;
        smallest = nowsmallest;
    }
    if(biggest-smallest == 0)cout<<0<<' '<<-1<<' '<<-1;
    else cout<<biggest-smallest<<' '<<smallest<<' '<<biggest;
}
