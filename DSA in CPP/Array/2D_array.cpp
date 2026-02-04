#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> arr;

    cout << "Enter elements: " << endl;
    for (int i = 0; i < 3; i++)
    {
        vector<int> arr1;
        for (int j = 0; j < 3; j++)
            arr1.push_back(i+j);
        arr.push_back(arr1);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}