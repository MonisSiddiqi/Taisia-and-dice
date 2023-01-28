#include<iostream>
#include<vector>
using namespace std;
bool flag = false;
void solve(vector<int> &dice, int r, int i, vector<int> ans, int size)
{   
    if(flag == true)
     return;
     
    if(i==dice.size())
    {   
        if(r==0 && ans.size()==size)
        {
            for(int i: ans)
            cout<<i<<" ";
            cout<<endl;
            flag=true;
        }
        return;
    }

    if(dice[i]<=r)
    {  
        ans.push_back(dice[i]);
        solve(dice,r-dice[i],i,ans,size);
        ans.pop_back();
    }
    solve(dice,r,i+1,ans,size);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,r;
        cin>>n>>s>>r;
        vector<int> dice;
        int max = s-r;
        for(int i=1; i<=max; i++)
        {
            dice.push_back(i);
        }
        vector<int> ans;
        ans.push_back(max);
        solve(dice,r,0,ans,n);
        flag = false;
    }
}