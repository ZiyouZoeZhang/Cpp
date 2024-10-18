//二分构建 stack模拟
//read the question
//watch the video
//think about it

#include<bits/stdc++.h>
using namespace std;
int n,placed,base[100001];
vector<int> item[100001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x<placed)
		{
			cout<<i-1;
			return 0;
		}
		for(int j=x;j>0&&!base[j];j--)
			base[j]=x;
		while(!item[base[x]].empty()&&item[base[x]].back()<x)
		{
			placed=item[base[x]].back();
			item[base[x]].pop_back();
		}
		item[base[x]].push_back(x);
	}
	cout<<n;
	return 0;
}