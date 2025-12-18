#include<iostream>
using namespace std;
int main(){
    int o;
    cout<<"Enter the order of the snake pattern matrix: ";
    cin>>o;     
    int matrix[o][o];
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<o;i++){
        for(int j=0;j<o;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"The snake pattern matrix is:"<<endl;
    for (int i = 0; i < o; i++)
    {
        for (int j = 0; j < o; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        
    }
    return 0;

}
