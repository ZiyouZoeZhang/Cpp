//finding # of numbers containing 4
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int cal(string input);
int main()
{
    int times;
    string s_target, s_solution = "";
    bool found=false;
    int test;
    cout<<"how many times? "<<endl;
    cin>>times;
    for (int i=0; i<times; i++)
    {
        s_solution ="";
        found=false;
        cout<<"which number would you like to find? "<<endl;
        cin>>s_target;

        for (int i=0; i<s_target.size(); i++)
        {
            if (s_target[i]=='4'&&found!=true){
                found=true;
                s_target[i]='3';
            }
            else if (found==true){
                s_solution.push_back(s_target[i]);
                s_target[i]='9';
            }
        }

        if (found==true)
        {
            if (s_solution=="") cout<<"solution: "<<cal(s_target)+1<<endl;
            else cout<<"solution: "<<cal(s_target)+stoi(s_solution)+1<<endl;
        }
        else cout<<"solution: "<<cal(s_target)<<endl;
    }  
    return 0;
}

int cal(string input)
{
    int solution=0;
    int thisCal=0;
    for (int i=0; i<input.size(); i++)
    {
        int this_char= (input[input.size()-i-1])-'0';
        if (this_char<4) solution+= thisCal*this_char;
        else if (this_char>3)
        {
            if (i==0) solution+= (thisCal*(this_char-1))+(1);
            else solution+= (thisCal*(this_char-1))+pow(10,i);
        }
        if (i==0) thisCal = 1;
        else thisCal=(thisCal*(9))+pow(10,i);
    }
    return solution;
}

/*
3 ->0
13 -> 1
23 -> 2

5 -> 1 because 5>1
15 -> 2 because 1+1
25 -> 2+1
35 -> 3+1
45 -> 10 + 3 + 1
55 -> 10 + 4 + 1

20 -> n*1
50 -> 10+(n-1)*1

100 -> 10 + 9
104 -> 10 + 9 + 1
140 -> 10 + 10
200 -> n*(10+9)

400 -> 100+ (n-1)*(10+9)

2000 -> 

*/
// 0*n/1+(0*n-1) (9)
// 4, 14, 24, 34, 54, 64, 74, 84, 94, + 10   = 1*n/10+ 1*n-1 (19)
// 19, 19, 19, 100, 19, 19, 19, 19, 19, 19 = 19*n/100 + 19*n-1 (100+19*8)
// = 1000 + （100+19*9）*9

//15 -
//solution = 0+(0+1)+(1)