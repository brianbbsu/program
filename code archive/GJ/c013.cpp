#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    int nf=0,f=0,y=0;
    for(int i=0;i<n;i++)
    {
        string tmp1;
        int tmp2;
        cin>>tmp1>>tmp2;
        if(tmp2==0) nf++;
        else if(tmp2==2) y++;
        else
        {
            f++;
            s=tmp1;
        }
    }
    if(nf!=0|| f>1)
    {
        if(y==1&&f>0) cout<<"You, "<<s<<" and "<<nf+f-1<<" others like this.";
        else if(y==1) cout<<"You and "<<nf<<" others like this.";
        else if(f>0) cout<<s<<" and "<<nf+f-1<<" others like this.";
        else cout<<nf<<" people like this.";
    }
    else
    {
        if(y==1&&f==1) cout<<"You and "<<s<<" like this.";
        else if(y==1) cout<<"You like this.";
        else cout<<s<<" like this.";
    }
}
