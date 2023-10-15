//combination or subset generator
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> m;

void combination(string &v, string &sub, int i)
{
    
    if(i<v.size())
    {
        //i th element nebo na
        combination(v,sub,i+1);
        
        //i th element niye recursion
        sub.push_back(v[i]);
        
        combination(v,sub,i+1);
        /*for(auto x:sub)
        {
            cout<<x<<"";
        }
        cout<<"   ";*/
        int n=sub.size();
        m.push_back({n,sub});
        
        //pop na korle v unchanged thakbe
        sub.pop_back();
    }
}


int main()
{

    //vector<char> v={'a','b','c','d','e'};
    string v="abcde";
    cout<<"Enter a string: ";
    cin>>v;
    cout<<"Subsets of "<<v<<" are :\n";
    string sub;
    combination(v,sub,0);
    
    sort(m.begin(),m.end());
    for(auto [x,y]:m)
    {
        cout<<"{";
        int n=y.size();
        
        for(int a=0; a<n; a++)
        {
            if(a+1<n)
            cout<<y[a]<<",";
            else cout<<y[a];
        }
        cout<<"}\n";
    }
    
    

    return 0;
}
