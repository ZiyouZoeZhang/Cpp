#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


//边界 1=1； 2=2； 3=2
//either n-1
//or if n%2=0; n/2
//or if n%3=0; 2*(n/3)




int n=0;
map<int,int>temp;

void check(int ini, int now, int which){
    if (which == -1){
        //
    }
}

int cal(int cur){
    //cout<<cur<<endl;
    if (temp.count(cur)) return temp[cur];
    if (cur%2!=0 && cur%3!=0){
        //当没路可走
        temp[cur]=cal(cur-1)+1;
        if (cur==n){
            cout<<temp[cur];
            cout<<"cur-1"<<endl;
            n=cur-1;
        }
    }
    else{
        if (cur%2==0 && cur%3==0){
            //有三个选项，取最好
            if (cal(cur-1)<=cal(2*(cur/3)) && cal(cur-1)<=cal(cur/2)){
                temp[cur]=cal(cur-1)+1;
                if (cur==n){
                    cout<<temp[cur];
                    cout<<"cur-1"<<endl;
                    n=cur-1;
                }
            } else if (cal(cur/2)<=cal(2*(cur/3))){
                //当cur-1不是最优, 看cur/2是不是最优
                temp[cur]=cal(cur/2)+1;
            } else {
                //当cur-1与cur/2都不是最优
                temp[cur]=cal(2*(cur/3))+1;
            }
        } else if (cur%2==0 && cal(cur/2)<=cal(cur-1)) {
            temp[cur]=cal(cur/2)+1;
        } else if (cur%3==0 && cal(2*(cur/3))<=cal(cur-1)) {
            temp[cur]=cal(2*(cur/3))+1;
        } else {
            temp[cur]=cal(cur-1)+1;
        }
    }
    return temp[cur];
}

int main(){
    temp[2]=2;
    temp[3]=2;
    temp[1]=1;
    cin>>n;
    cal(n);
    cout<<temp[n];
    return 0;
}



/*
int n=0;
map<int, int> temp;


//给temp[cur]赋值
//6 ->3  4/2
//6->3
int cal(int cur){
    cout<<"000"<<endl;
    if(cur==2) return 1;
    if(cur==1) return 0;
    if (cur%2==0){//even
    
        cout<<"111    "<<cur<<endl;
        temp[cur]=cal(cur/2)+1;
    } 
    else{//odd
        if (cal(cur+1)<cal(cur-1)) {
            
            cout<<"222    "<<cur<<endl;
            temp[cur]=cal(cur+1)+1;
        } 
        else {
            cout<<"333    "<<cur<<endl;
            temp[cur]=cal(cur-1)+1;
        }
    }

    return temp[cur];
}

int main(){
    cin>>n;
    cal(n);
    cout<<temp[n];
    return 0;
}



int cal(int number){
    int count;
    if(number==3){
        count=3;
    } else count=cal(number-1)+cal(number-2);
    return count;
}

int main(){
    //从第一百级台阶倒推
    //假设1级 = 1
    //2=2
    //3=2+1

    int nOfSteps=45, var1=0, var2=0;


    for (int i=0; i<nOfSteps; i++){
        //count for 100 = count for 99 + count for 98
        //count for 
        
        


    }




    return 0;
}
*/

