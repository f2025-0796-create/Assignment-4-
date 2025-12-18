#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
float temperature[7][4];
void dataInput()
{
    for (int i = 0; i < 7; i++)
    {
        cout << "Enter Temperature for Day " << i + 1 << ":\n";
        for (int j = 0; j < 4; j++)
        {
            cout << "Temperature " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
        cout << endl;
    }
}
float highestTemp(float temp[7][4]){
          float great = temp[0][0];
          for (int i = 0; i < 7; i++)
          {
            for (int j = 0; j < 4; j++)
            {
                if( temp[i][j] > great){
                    great = temp[i][j];
                }
            } 
          }
            return great;
}
float lowestTemp(float temp[7][4]){
          float low = temp[0][0];
          for (int i = 0; i < 7; i++)
          {
            for (int j = 0; j < 4; j++)
            {
                if( temp[i][j] < low){
                    low = temp[i][j];
                }
            } 
          }
            return low;
}
float average(float temp[7][4], int day){
    float sum=0;
    for (int i = 0; i < 4; i++)
    {
        sum += temp[day][i];
    }
    return sum/4;
}
void separater(int length){
    cout<<endl;
    for (int i = 1; i <= length; i++)
    {
        cout<<"-";
    }
    cout<<endl;
}
void display(float temps[7][4], vector<float> &avgTemps, float high, float low){
            cout<<"===========Weekly Temperature Report===========";
            separater(90);
            cout<<setw(15)<<left<<"Day"<<setw(15)<<left<<"Temp-1"<<setw(15)<<left<<"Temp-2"<<setw(15)<<left<<"Temp-3"<<setw(15)<<left<<"Temp-4"<<left<<"Average Temp\n";
            for (int i = 0; i < 7; i++)
            {
            cout<<setw(15)<<left<<i+1<<setw(15)<<left<<temps[i][0]<<setw(15)<<left<<temps[i][0]<<setw(15)<<left<<temps[i][0]<<setw(15)<<left<<temps[i][0]<<left<<avgTemps[i];
            cout<<endl;
            }
            separater(90);
            cout<<"Weekly Extremes:-"<<endl;
            cout<<"Highest Temperature: "<<high<<endl;
            cout<<"Lowest Temperature: "<<low<<endl;
            
}
int main()
{
    dataInput(); 
    vector<float> avgTemps;
    float highest = highestTemp(temperature);
    float lowest = lowestTemp(temperature);
    for (int  i = 0; i < 7; i++)
    {
        avgTemps.push_back(average(temperature, i));
    }
    display(temperature, avgTemps, highest, lowest);
    return 0;
}
