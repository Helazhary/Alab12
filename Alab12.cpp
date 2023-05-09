#include <bits/stdc++.h>
using namespace std;


bool isPromising(int index, int currSum, int remainingSum, vector<int>& weights, int targetSum)
{
    int next = weights[index + 1];
    bool f1 = false, f2 = false;

    if ((next + currSum) <= targetSum)
        f1 = true;

    if ((currSum + remainingSum) >= targetSum)
        f2 = true;

    if (f1 && f2)
        return true;
    else
        return false;
}

void findSubsetSum(int index, vector<int>& weights, int targetSum, vector<int>& selected, int currSum, int remainingSum, int size)
{
    // if target reached, print subset
    if (currSum == targetSum)
    {
        for (int i = 0; i < size; i++)
        {
            if (selected[i] == 1)
                cout << weights[i] << "\t";
        }
        cout << endl;
        return;
    }
    // if the current node is promising and there are more nodes to check
    else if (isPromising(index, currSum, remainingSum, weights, targetSum) && index+1 < size)
    {
        // include 
        selected[index + 1] = 1;
        findSubsetSum(index + 1, weights, targetSum, selected, currSum + weights[index + 1], remainingSum - weights[index + 1], size);

        // exclude 
        selected[index + 1] = 0;
        findSubsetSum(index + 1, weights, targetSum, selected, currSum, remainingSum - weights[index + 1], size);
    }
}

int main()
{
    vector<int> weights = { 3, 4, 5, 6 };
    vector<int> selected = { 0, 0, 0, 0 };
    int totalSum = 0;
    for (int i = 0; i < 4; i++)
    {
        totalSum += weights[i];
    }
    findSubsetSum(-1, weights, 13, selected, 0, totalSum, 4);


    cout << "\n";

    vector<int> weights1 = { 5, 6, 11, 7, 20, 2 };
    vector<int> selected1 = { 0, 0, 0, 0, 0, 0, 0 };
    int totalSum1 = 0;
    for (int i = 0; i < 6; i++)
    {
        totalSum1 += weights1[i];
    }
    findSubsetSum(-1, weights1, 11, selected1, 0, totalSum1, 6);
}
