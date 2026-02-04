#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    vector<vector<int>> jagged;
    vector<int> output;

    int key;
    cout << "enter number of rows: " << endl;
    cin >> key;

    for (int i = 0; i < key; i++)
    {
        vector<int> jag;
        for (int j = i; j < arr.size(); j += key)
            jag.push_back(arr[j]);
        jagged.push_back(jag);
    }

    for (int i = 0; i < jagged.size(); i++)
    {
        for (int j = 0; j < jagged[i].size(); j++)
        {
            output.push_back(jagged[i][j]);
            cout << jagged[i][j] << " ";
        }

        cout << endl;
    }


    for(auto x : output)
    cout << x << " ";

    return 0;
}