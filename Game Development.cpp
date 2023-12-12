#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void upmove(int arr[4][4])
{
    int l,r;

    //Go through each column
    for(int j=0;j<4;j++)
    {
        l=0; //initialize l to starting row index
        r=j; //initialize column index

        //go through each row in the column
        for(int i=1;i<4;i++)
        {
            if(arr[i][j]!=0)//check if current block is not empty
            {
                //check if above cell is empty or identical
                if(arr[i-1][j]==0 || arr[i-1][j]==arr[i][j])
                {
                    //merge identical values
                    if(arr[l][r]==arr[i][j])
                    {
                        arr[l][r]*=2;
                        arr[i][j]=0;
                    }
                    else
                    {
                        //move the block to an empty spot or the spot above
                        if(arr[l][r]==0)
                        {
                            arr[l][r]=arr[i][j];
                            arr[i][j]=0;
                        }
                        else
                        {
                            arr[++l][r]=arr[i][j];
                            arr[i][j]=0;
                        }
                    }
                }
                else l++;
            }
        }
    }
}

void downmove(int arr[4][4])
{
    int l,r;

    //go through every column
    for(int j=0;j<4;j++)
    {
        l=3; //initialize starting row index from bottom
        r=j; //initialize column index

        //go through every row in the column
        for(int i=2;i>=0;i--)
        {
            if(arr[i][j] != 0) //if current block is not empty
            {
                //check if below cell is empty or identical
                if(arr[i+1][j] == 0 || arr[i+1][j] == arr[i][j])
                {
                    if(arr[l][r] == arr[i][j])//merging identical blocks
                    {
                        arr[l][r] *= 2;
                        arr[i][j]=0;
                    }
                    else
                    {
                        //if below is empty
                        if(arr[l][r] == 0)
                        {
                            arr[l][r] = arr[i][j];
                            arr[i][j]=0;
                        }
                        else //if below cell is not empty
                        {
                            arr[--l][r] = arr[i][j];
                            arr[i][j]=0;
                        }
                    }
                }
                else//if below cell is not empty and not identical
                {
                    l--;
                }
            }
        }
    }
}


void leftmove(int arr[4][4])
{
    int l,r;

    //go through every row in the grid
    for(int i=0;i<4;i++)
    {
        l=i; //initialize row index
        r=0; //initialize starting column index

        //go through every column in row
        for(int j=1;j<4;j++)
        {
            //check if current block is not empty
            if(arr[i][j] != 0)
            {
                //check if the left cell is empty or identical
                if(arr[i][j-1] == 0 || arr[i][j-1] == arr[i][j])
                {
                    //merge identical blocks
                    if(arr[l][r] == arr[i][j])
                    {
                        arr[l][r]*=2;
                        arr[i][j]=0;
                    }
                    else
                    {
                        //if left cell is empty
                        if(arr[l][r]==0)
                        {
                            arr[l][r]=arr[i][j];
                            arr[i][j]=0;
                        }
                        else
                        {
                            arr[l][++r] = arr[i][j];
                            arr[i][j]=0;
                        }
                    }
                }
                else
                {
                    r++;
                }
            }
        }
    }
}


void rightmove(int arr[4][4])
{
    int l,r;

    //go through each row in the matrix
    for(int i=0;i<4;i++)
    {
        l=i;
        r=3;

        //go through every column in the row
        for(int j=2;j>=0;j--)
        {
            //check if current block is not empty
            if(arr[i][j]!=0)
            {
                //check is right block is empty or identical
                if(arr[i][j+1] == 0 || arr[i][j+1] == arr[i][j])
                {
                    //merge identical tiles
                    if(arr[l][r] == arr[i][j])
                    {
                        arr[l][r]*=2;
                        arr[i][j]=0;
                    }
                    else
                    {
                        //if the right block is empty
                        if(arr[l][r] == 0)
                        {
                            arr[l][r] = arr[i][j];
                            arr[i][j]=0;
                        }
                        else
                        {
                            arr[l][--r] = arr[i][j];
                            arr[i][j]=0;
                        }
                    }
                }
                else
                {
                    r--;
                }
            }
        }
    }
}

void addBlock(int arr[4][4])
{
    int i1,i2;

    srand(time(0));

    while(1){
        i1 = rand()%4;
        i2 = rand()%4;

        if(arr[i1][i2] == 0){
            arr[i1][i2] = pow(2, i1%2 +1);
            break;
        }
    }
}

void display(int arr[4][4])
{
    cout<<"\n\t\tPress Esc anytime to quit the game";
    cout<<"\n\n\n\n";
    int i,j;
    for(i=0;i<4;i++)
    {
        cout<<"\t\t\t\t-----------------\n\t\t\t\t";
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0) cout<<"|   ";
            else
                cout<<"| "<<arr[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<"\t\t\t\t-----------------\n";
}

int check(int temp[4][4], int arr[4][4])
{
    int flag=1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(temp[i][j] != arr[i][j])
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}



int checkOver(int arr[4][4])
{
    //initialize flags
    int flag1=0,flag2=0;

    for(int i=0;i<4;i++)
    { //if there is any empty block
        for(int j=0;j<4;j++)
        {
            if(arr[i][j] == 0)
            {
                flag1 = 1;
                break;
            }
        }
    }

    for(int i=0;i<3;i++)
    { //if there are any identical blocks
        for(int j=0;j<3;j++)
        {
            if((arr[i+1][j] == arr[i][j]) || (arr[i][j+1] == arr[i][j]) )
            {
                flag2 =1;
                break;
            }
        }
    }

    if(flag1 || flag2)
        return 0;
    else
        return 1;
}

int main()
{
    //Print the title of the game
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t2048 GAME\n\n\t\t\t\t\t\tPress any key to continue"<<endl;

    //Get any character to continue from conio.h
    getch();

    //Clear console screen
    system("cls");

    //Declare required indices and the game space (4x4 matrix) and a temporary matrix
    int i1,i2,i3,i4,i,j;
    int arr[4][4]={0}, temp[4][4]={0};

    //Seed the random number generator with the current time
    srand(time(0));

    //Generate random indices
    i1 = rand()%4;
    i2 = rand()%4;

    while(1){
        i3 = rand()%4;
        i4 = rand()%4;
        if(i3!=i1 && i4!=i2){
            break;
        }
    }
    // (i1,i2) and (i3,i4) pairs should be different
    //cout<<endl<<"Randomly generated index pairs : "<<endl<<"i1 =  "<<i1<<"    i2 = "<<i2<<"    i3 = "<<i3<<"    i4 = "<<i4<<endl;

    //Set initial blocks of the matrix
    arr[i1][i2] = 2;
    arr[i3][i4] = 4;

    //Display initial state of the grid
    display(arr);

    cout<<"Use Arrow Keys to play the game : "<<endl;
    //Get character for users input (left,right,up,down arrows)
    int ch;

    while(1)
    {

        //Create temporary copy of the current grid
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                temp[i][j] = arr[i][j];
            }
        }

        ch = getch();
        system("cls");

        if(ch==72){ //up arow
            upmove(arr);
        }
        if(ch==80){ //down arrow
            downmove(arr);
        }
        if(ch==75){ //left arrow
            leftmove(arr);
        }
        if(ch==77){ //right arrow
            rightmove(arr);
        }
        if(ch==27){ //esc to quit
            break;
        }

        //Check if the game grid has changed, if changed, add a block
        if(!check(temp,arr))
        {
            addBlock(arr);
        }

        //display the updated grid
        display(arr);

        //check if game is over
        if(checkOver(arr))
        {
            cout<<"\n\n\t\tGAME OVER!!!\n\n\n";
            getch();
            break;
        }
    }
    return 0;
}
