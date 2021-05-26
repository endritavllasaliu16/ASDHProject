#include<iostream>
using namespace std;
void kthlargestElement(int arr[], int size, int k)
{
    int temp; // variable for swapping 

    for (int i = 0; i < k; i++)//outer loop
    {
        //After every iteration of outer loop the i-th largest element goes to
        //its sorted order position.
        for (int j = 0; j < size - 1; j++)//inner loop
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "K-th largest element is : " << arr[size - k] << endl;
}
int main()
{
    int size = 7;
    int arr[] = { 3, 21, 12, 9, 30, 2, 50 };
    int k = 4;
    kthlargestElement(arr, size, k);
    return 0;
}