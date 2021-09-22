#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int giveIndex(int k1,int k2)
    {
        //1based index;
        if(k1 == 0 && k2 == 0)
            return 1;
        else if(k1 == 0 && k2 == 1)
            return 2;
        else if(k1 == 0 && k2 == 2)
            return 3;
        else if(k1 == 1 && k2 == 0)
            return 4;
        else if(k1 == 1 && k2 == 1)
            return 5;
        else if(k1 == 1 && k2 == 2)
            return 6;
        else if(k1 == 2 && k2 == 0)
            return 7;
        else if(k1 == 2 && k2 == 1)
            return 8;
        else
            return 9;

    }
    int checkWinner(vector<int>m,int f1)
    {
        //check for all the 8 possiblities.
       if(f1 == 1)
           f1 = 2;
        else
            f1 = 1;
      /*  cout<<f1<<endl;
        for(int i=0;i<m.size();i++)
            cout<<m[i]<<" ";
        cout<<endl;*/

        int flag = 0;
        if(m[1] == f1 && m[2]==f1 && m[3]==f1)
            flag =1;
        if(m[4] == f1 && m[5]==f1 && m[6]==f1)
            flag =1;
        if(m[7] == f1 && m[8]==f1 && m[9]==f1)
            flag =1;
        if(m[1] == f1 && m[4]==f1 && m[7]==f1)
            flag =1;
        if(m[2] == f1 && m[5]==f1 && m[8]==f1)
            flag =1;
        if(m[3] == f1 && m[6]==f1 && m[9]==f1)
            flag =1;
        if(m[1] == f1 && m[5]==f1 && m[9]==f1)
            flag =1;
        if(m[3] == f1 && m[5]==f1 && m[7]==f1)
            flag =1;

        //either return f1 as winner or -1
        if(flag == 1)
        { // cout<<"hi";
            return f1;
        }
        else
            return -1;
    }
    string tictactoe(vector<vector<int>>& moves) {
         vector<int>ans;
        int k1,k2,k;
        if(moves.size() < 5)
            return "Pending";
        else{
            vector<int>arr(10,0);

            int flag = 1;
            for(int i=0;i<moves.size();i++)
            {   flag = 0;
                for(int j=0;j<moves[0].size();j++)
                {
                    if(flag == 0)
                    {
                        k1 = moves[i][j];
                        flag = 1;
                    }else{
                        k2 = moves[i][j];
                    }
                }
                 k = giveIndex(k1,k2);
                    ans.push_back(k);
            }
            int y,f1=1;
            for(int i=0;i<ans.size();i++)
            {

                if(f1 == 1){
                arr[ans[i]] = 1;//A
                    f1 = 2;
                }else{
                    f1 = 1;
                    arr[ans[i]] = 2;//B
                }

                y = checkWinner(arr,f1);

                  if(y == 2)
                  return "B";
                 else if(y == 1)
                  return "A";

            }
        if(moves.size()==9 && y == -1) // && result = -1. sab hone ke baad bhi.
            return "Draw";
        else
            return "Pending";

        }
    }
};
int main()
{
    cout<<"Hello";
  //take input and use the tictactoe function to find the winner of the tictactow;
  //Problem Link : https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
}
