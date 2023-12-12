#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;

void upmove(int a[4][4])
{
    int l,r;

    //Go through each column
    for(int j=0;j<4;j++)
    {
        l=0; //initialize l to starting row index
        r=j; //initialize column index

        cout<<"In Column["<<j<<"] l = "<<l<<" r = "<<r<<endl<<endl;

        //go through each row in the column
        for(int i=1;i<4;i++)
        {
            cout<<"In Row["<<i<<"]"<<" i = "<<i<<" j = "<<j<<endl<<endl;
            if(a[i][j] != 0) //check if current block is not empty
            {
                cout<<"Current Element a["<<i<<"]["<<j<<"] is not empty and it's value is "<<a[i][j]<<endl<<endl;
                //check if above cell is empty or identical
                if( a[i-1][j]==0 || a[i-1][j] == a[i][j])
                {
                    //merge identical values

                    cout<<"Big If ******* a["<<l<<"]["<<r<<"] = "<<a[l][r]<<" and a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl<<endl;
                    if(a[l][r] == a[i][j])
                    {
                        cout<<"Above cell is identical, so merge the identical values"<<endl<<endl;
                        a[l][r] *= 2;
                        a[i][j]=0;
                        cout<<"After merging, a["<<l<<"]["<<r<<"] = "<<a[l][r]<<" and a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl<<endl;
                    }
                    else
                    {
                        //move the block to an empty spot or the spot above
                        if(a[l][r] == 0)
                        {
                            cout<<"Above cell is empty, so replace it!"<<endl<<endl;
                            cout<<"Before replacing, a["<<l<<"]["<<r<<"] = "<<a[l][r]<<" and a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl<<endl;
                            a[l][r] = a[i][j];
                            a[i][j]=0;
                            cout<<"After replacing, a["<<l<<"]["<<r<<"] = "<<a[l][r]<<" and a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl<<endl;
                        }
                        else
                        {
                            cout<<"----------------------------"<<endl<<endl;
                            cout<<"Before ---------------------else, a["<<l<<"]["<<r<<"] = "<<a[l][r]<<" and a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl<<endl;
                            a[++l][r] = a[i][j];
                            a[i][j]=0;
                            cout<<"After ----------------------else, a["<<l<<"]["<<r<<"] = "<<a[l][r]<<" and a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"Above cell is not empty and not identical"<<endl<<endl;
                    cout<<"So, l = "<<l<<endl<<endl;
                    l++;
                }
            }
        }
    }
}

void display(int arr[4][4])
{
    cout<<"\n\t\t\t\t\tPress Esc to quit the game anytime"<<endl;
    cout<<"\n\n"; //for display template

    for(int i=0;i<4;i++){
        cout<<"\t\t\t\t\t-----------------------------"<<endl<<"\t\t\t\t\t";
        for(int j=0;j<4;j++){
            if(arr[i][j]==0){
                cout<<"|  ";
            }
            else{
                cout<<"| "<<arr[i][j]<<" ";
            }
        }
        cout<<"|\t\t\t\t\t"<<endl;
    }
        cout<<"\t\t\t\t\t-----------------------------"<<endl;

}

int main()
{
    int a[4][4] = {{2,0,0,0},
                   {0,0,0,0},
                   {0,0,16,0},
                   {0,0,0,0}};

    upmove(a);
    display(a);



    return 0;

}
