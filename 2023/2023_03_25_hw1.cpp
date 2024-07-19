/* 这是一道强密码 弱密码的检测问题 */

/* 
强密码的字符数在6～20位之间
包含一个大写
一个小写
一个符号
不可以有三个连续的字符
*/

#include <iostream>

using namespace std;

bool valid=false;
int steps=0;
int i_more=0;
int i_less=0;
bool upperCase=false;
bool lowerCase=false;
bool digit=false;
int consecutive=0;
int consecutive_more=0;
void check_valid(string password);
void cal_steps(string password);

int main()
{
    string password="";
    cout<<"please ender your password: "<<endl;
    cin>>password;
    check_valid(password);
    if (valid==1) cout<<"password is valid"<<endl;
    else 
    {
        cout<<"password is invalid"<<endl;
        cal_steps(password);
        cout<<steps<<" steps are needed to fix this password"<<endl;
    }
    return 0;
}

void check_valid(string password)
{
    if (password.length()<5) i_less=6-password.length();
    if (password.length()>21) i_more=password.length()-20;
    int every_2 =0;
    for (int i=0; i<password.length(); i++)
    {
        if (upperCase==false&&isupper(password[i])==true)upperCase=true;
        else if (lowerCase==false&&islower(password[i])==true) lowerCase=true;
        else if (digit==false&&isdigit(password[i])==true) digit=true;
        while (password[i]==password[i+1]&&password[i]==password[i+2]){
            consecutive+=1;
            i+=3;
        }
    }
    bool temp_entered_consec=false;
    for (int i=1; i<password.length(); i++)
    {
        if(password[i-1]==password[i-2]&&temp_entered_consec==false) temp_entered_consec=true;
        if (temp_entered_consec==true&&password[i]==password[i-1]) consecutive_more+=1;
        else temp_entered_consec=false;
    }
    if(i_more==0&&i_less==0&&upperCase==true&&lowerCase==true&&digit==true&&consecutive==0) valid=true;
    else valid=false;
}

void cal_steps(string password)
{
    int needs=0;
    if (upperCase==false) needs+=1;
    if (digit==false) needs+=1;
    if (lowerCase==false) needs+=1;
    //现有 needs，less｜｜more，consecutive
    if (i_less==0&&i_more==0) steps += (needs<consecutive) ? consecutive:needs;
    else if (i_less>0&&i_more==0) {
        //看一眼。。。
        steps += (needs<i_less) ? i_less:needs;
        //steps += consecutive;
    } else if (i_more>0&&i_less==0) {
        steps += (consecutive_more<i_more) ? i_more:consecutive_more;
        //
        steps += needs;
        if (password.length()-consecutive_more<6) steps+= (6-(password.length()-consecutive_more));
    }
}
//UUU3UUU3UUU3
//12345678901234567890
//aa2aabb2bbcc3ccdd4dd
//8