//{
#include<bits/stdc++.h>
using namespace std;


#define REP(i,n) for(int i=0;i<n;i++)


#define ALL(_a) _a.begin(),_a.end()
#define pb push_back

//}




#ifdef brian
char johnken[101][3];
#endif

void count_win_times(int n, int &ref_min_win, int &ref_hua_win, int &ref_mei_win)
{
  map<pair<char,char>,bool > mp;
  mp[make_pair('P','S')]=0;
  mp[make_pair('P','T')]=1;
  mp[make_pair('S','T')]=0;

  REP(i,n)
  {

    vector<char> tmp;
    REP(j,3)tmp.pb(johnken[i][j]);
    sort(ALL(tmp));
    tmp.resize(unique(ALL(tmp))-tmp.begin());
    if(tmp.size()!=2)continue;
    REP(j,3)if(mp[make_pair(tmp[0],tmp[1])]==(johnken[i][j]==tmp[0]))
    {
      if(j==0)ref_min_win++;
      else if(j==1)ref_hua_win++;
      else ref_mei_win++;
    }
  }
}

#ifdef brian
int main()
{
    int min_win=0,hua_win=0,mei_win=0;
    int &ref_min_win=min_win,&ref_hua_win=hua_win,&ref_mei_win=mei_win;
    int i,j,n;
    std::cin>>n;
    for(i=0; i < n; i++){
        for(j=0; j < 3; j++)
            std::cin>>johnken[i][j];
    }
    count_win_times(n,ref_min_win,ref_hua_win,ref_mei_win);
    std::cout<< min_win<<" "<< hua_win<<" "<< mei_win<< std::endl;
    return 0;
}
#endif
