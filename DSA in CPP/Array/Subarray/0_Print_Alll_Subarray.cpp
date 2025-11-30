#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    int n = arr.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = k; i < n; i++)
        {
            for (int j = k; j <= i; j++)
                cout << arr[j] << " ";
            cout << "  ";
        }
    }

    return 0;
}