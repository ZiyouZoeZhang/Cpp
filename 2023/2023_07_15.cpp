    #include <iostream>
    #include <vector>
    #include <deque>
    using namespace std;
    string longestPalindrome(string s);

    int main(){
        string s;
        cin>>s;
        cout<<"hello";
        longestPalindrome(s);
        return 0;
    }

    string longestPalindrome(string s) {
        cout<<"ohhh";
        vector<pair<char, int> >vec;
        int max_length=0, max_i;
        vec.push_back(make_pair(s[0], 1));
        for (int i=1; i<s.size(); ++i){
            if (s[i]==vec[vec.size()-1].first) vec[vec.size()-1].second++;
            else{
                max_length=max(max_length, vec[vec.size()-1].second);
                vec.push_back(make_pair(s[i], 1));
            }
        }
        for (int i=0; i<vec.size(); i++){
            int cur_length=vec[i].second, length=1;
            while(vec[i-length].first==vec[i+length].first && vec[i-length].second==vec[i+length].second && i+length<vec.size() && i-length>0) ++length, cur_length+=(vec[i-length].second * 2);
            if(vec[i-length].first==vec[i+length].first) cur_length += (max(vec[i-length].second,vec[i+length].second) - min(vec[i-length].second,vec[i+length].second))*2;
            if (cur_length>max_length) max_length=cur_length, max_i=i;
        }
        cout<<max_length<<endl;
        int pre=0;
        for (int i=0; i<max_i; ++i) pre+=vec[i].second;
        pre+= (vec[max_i].second/2);
        cout<<pre<<endl;



        return "abab";
    }