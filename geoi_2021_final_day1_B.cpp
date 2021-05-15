#include<bits/stdc++.h>
#define ll int
using namespace std;
string s;
int f[2000005],n,w[2000005],temp;
stack<int> st;
int fix(int l,int r)
{
	ll ans=0,anss=0;
	if (s[l+1]=='(' && w[l+1]==r-1)
	{
		f[l+1]++;
		f[r-1]++;
		return fix(l+1,r-1);
	}
	for (int i=l+1; i<=r-1; i++)
	{
		if (s[i]=='+' || s[i]=='-')
		{
			ans=1;
			continue;
		}
		if (s[i]=='&' || s[i]=='*' || s[i]=='/')
			continue;
		ll x=fix(i,w[i]),y=0;
		if (i!=l+1)
		{
			if (x && s[i-1]=='-')
				y=1;
			if (x && s[i-1]=='*')
				y=1;
			if (s[i-1]=='/')
				y=1;
		}
		if (w[i]!=r-1)
		{
			if (x && s[w[i]+1]=='*')
				y=1;
			if (x && s[w[i]+1]=='/')
				y=1;
		}
		if (!y)
		{
			f[i]=1;
			f[w[i]]=1;
		}
		i=w[i];
	}
	
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>s;
	n=s.size();
	for (int i=0; i<n; i++)
	{
		if (s[i]=='&' || s[i]=='+' || s[i]=='-' 
			|| s[i]=='*' || s[i]=='/')
			continue;
		if (s[i]=='(')
		{
			st.push(i);
			continue;
		}
		w[st.top()]=i;
		st.pop();
	}
	if (s[0]=='(' && w[0]==n-1)
	{
		f[0]++;
		f[n-1]++;
		ll temp=fix(0,n-1);
	}
	for (int i=0; i<=n-1; i++)
	{
		if (s[i]=='&' || s[i]=='*' || s[i]=='/' || s[i]==')' || s[i]=='+' || s[i]=='-')
			continue;
		ll x=fix(i,w[i]),y=0;
		if (i!=0)
		{
			if (x && s[i-1]=='-')
				y=1;
			if (x && s[i-1]=='*')
				y=1;
			if (s[i-1]=='/')
				y=1;
		}
		if (w[i]!=n-1)
		{
			if (x && s[w[i]+1]=='*')
				y=1;
			if (x && s[w[i]+1]=='/')
				y=1;
		}
		if (!y)
		{
			f[i]=1;
			f[w[i]]=1;
		}
		i=w[i];
	}
	
	for (int i=0; i<n; i++)
		if (!f[i])
			cout<<s[i];
	cout<<endl;
	return 0;
}
