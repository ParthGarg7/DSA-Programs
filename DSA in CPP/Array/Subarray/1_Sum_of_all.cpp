#include <iostream>
#include <vector>

using namespace std;

int contributionTechnique(vector<int> &arr)
{

    int n = arr.size();
    int sum = 0;

    /* The idea is to calculate that how many times any particular element
    will appear in sum of all subarray

    how many times does an element appear?

    Take element at index i.

    How many ways can we choose start?
    → Any index from 0 to i
    → So (i + 1) choices

    How many ways can we choose end?
    → Any index from i to n-1
    → So (n − i) choices

    Therefore,
    ✔ Total subarrays that include arr[i]:
    Contribution(i) = (i + 1) × (n − i)
    This is the magic formula.*/

    int app;

    // Time complexity  - O(n)
    // space complexity - O(1)    
    for (int i = 0; i < n; i++)
    {
        app = (i + 1) * (n - i);
        sum += (app * arr[i]);
    }


    return sum;
}

int prefixSum(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    vector<int> prefixSum(n);

    // The loop used to create the prefix sum array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        prefixSum[i] = sum;
    }

    // The prefix sum array is used in many parts
    //  we can find sum of any subarray using the prefix sum array

    // Calculation of sum of all subarray using prefix sum
    //  Time complexity - O(n*2)
    //  space complexity - O(n)

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == 0)
                sum += prefixSum[j];
            else
                sum += (prefixSum[j] - prefixSum[i - 1]);
        }
    }
    return sum;
}

int bruteForce1(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;

    // Time complexity - O(n*3)
    // space complexity - O(1)
    for (int start = 0; start < n; start++)
    {
        for (int indx = start; indx < n; indx++)
        {
            for (int end = start; end <= indx; end++)
                sum += arr[end];
        }
    }
    return sum;
}

int bruteForce2(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;

    // Time complexity - O(n*2)
    // space complexity - O(1)
    for (int start = 0; start < n; start++)
    {
        int runningSum1 = 0, runningSum2 = 0;

        for (int end = start; end < n; end++)
        {
            runningSum1 += arr[end];
            runningSum2 += runningSum1;
        }
        sum += runningSum2;
    }

    return sum;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int sum;
    sum = bruteForce1(arr);
    cout << sum << endl;
    sum = bruteForce2(arr);
    cout << sum << endl;
    sum = prefixSum(arr);
    cout << sum << endl;
    sum = contributionTechnique(arr);
    cout << sum << endl;
    return 0;
}
