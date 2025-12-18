#include <iostream>
#include <vector>
using namespace std;
void inputSales(int sales[7][5])
{
    for (int i = 0; i < 7; i++)
    {
        cout << "Enter Sales for Day " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++)
        {
            cout << "Product " << j + 1 << ": ";
            cin >> sales[i][j];
        }
        cout << endl;
    }
}
void weeklySales(int sales[7][5], vector<int> &weekly_Sales)
{

    for (int i = 0; i < 5; i++)
    {
        int w_sales = 0;
        for (int j = 0; j < 7; j++)
        {
            w_sales += sales[j][i];
        }
        weekly_Sales.push_back(w_sales);
    }
}
int maxProduct(vector<int> &weekly_Sales)
{
    int great = weekly_Sales[0];
    int max = 0;
    for (int i = 0; i < 7; i++)
    {
        if (weekly_Sales[i] > great)
        {
            max = i;
            great = weekly_Sales[i];
        }
    }
    return max + 1;
}
void bestDay(int sales[7][5], vector<int> &daySales)
{

    int prevSales = 0;
    int best_Day = 0;
    for (int i = 0; i < 7; i++)
    {
        int day_Sales = 0;
        for (int j = 0; j < 5; j++)
        {
            day_Sales += sales[i][j];
        }
        daySales.push_back(day_Sales);
    }
}
int main()
{
    int sales[7][5];
    vector<int> weekly_Sales;
    vector<int> daySales;
    inputSales(sales);
    weeklySales(sales, weekly_Sales);
    int max = maxProduct(weekly_Sales);
    bestDay(sales, daySales);
    int best_day = maxProduct(daySales);
    for (int i = 0; i < weekly_Sales.size(); i++)
    {
        cout << "Product " << i + 1 << " Sales: " << weekly_Sales[i] << endl;
    }
    cout << "\nProduct " << max << " generated the max revenue...." << endl;
    cout << "Best Sales day was Day " << best_day;
    return 0;
}
