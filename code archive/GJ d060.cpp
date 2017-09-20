/**********************************************************************************/
/*  Problem: d060 "3.物理實驗" from 101年彰雲嘉區複賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 254KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-05 20:21:09                                        */
/**********************************************************************************/

    #include <cmath>
    #include <iostream>
    #include <string.h>
    #include <sstream>
    #include <stdio.h>
    #include <vector>
    using namespace std;
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int k=1;k<=n;k++)
        {
            double hz;
            string data;
            stringstream ss;
            vector<double> pos,mov,spd,a;
            scanf("%lf",&hz);
            getline(cin,data);
            ss<<data;
            while(true)
            {
                double tmp;
                ss>>tmp;
                if(ss.fail()) break;
                //cout<<tmp<<" ";
                pos.push_back(tmp);
            }
            mov.push_back(0);
            for(int i=1;i<pos.size();i++) mov.push_back(pos[i]-pos[i-1]);
            for(int i=1;i<pos.size();i++) spd.push_back(mov[i]/(1/hz));
            for(int i=1;i<pos.size()-1;i++){a.push_back((spd[i]-spd[i-1])/(1/hz));if(a[i-1]>-0.01&& a[i-1]<0.01) a[i-1]=0;}
            printf("實驗%d\n位置",k);
            for(int i=0;i<pos.size();i++) cout<<" "<<pos[i];
            printf("\n位移");
            for(int i=0;i<pos.size();i++) cout<<" "<<mov[i];
            printf("\n平均速度 x");
            for(int i=0;i<pos.size()-1;i++) cout<<" "<<spd[i];
            printf("\n加速度 x x");
            for(int i=0;i<pos.size()-2;i++) cout<<" "<<a[i];
            printf("\n運動類型 ");
            if(a[0]==0)
            {
                if(spd[0]!=0) printf("等速運動");
                else printf("靜止");
            }
            else if(a[0]>0) printf("等正加速度運動");
            else printf("等負加速度運動");
            printf("\n加速度 ");cout<<a[0]<<"\n速度 ";
            if(a[0]==0) cout<<spd[0]<<"\n";
            else printf("x\n");
        }
    }

