#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    ll N;
    cin>>N;
    vector<bool> cow(N,false);
    ll count=0, minCount=9999999999;
    bool begun=false;
    for (int i=0; i<N; i++){
        char a;
        cin>>a;
        if (a=='1') {
            cow[i]=true;
            count++;
        } else if (count>0 && begun==true){
            minCount=min(count, minCount);
            count=0;
        } else begun=true;
    }
    //min count inportant
    int a=0;
    ll begin=0, end=0;
    while(a<cow.size() && cow[a]==true) begin++, a++;
    a=cow.size()-1;
    while (a>=0 && cow[a]==true) end++, a--;
    if (begin==0 && minCount!=0) begin=minCount;
    if (begin==0 && end!=0) begin=end;
    if (end==0 && minCount!=0) end=minCount;
    if (end==0 && end!=0) end=begin;
    minCount=(minCount+1)/2;
    ll nights=min(begin-1, end-1);
    nights=min(nights, minCount-1);
    //--------
    if (nights<0) nights=0;
    ll solution=0;
    count=0;

    for (int i=0; i<N; i++){
        if (cow[i]==true) {
            count++;
        } if ((cow[i]==false && count>0) || i==N-1){
            //count!!
            solution+=(count/((nights*2)+1));
            if (count%((nights*2)+1)>0) solution++;
            count=0;
        }
    }
    cout<<solution<<endl;
}