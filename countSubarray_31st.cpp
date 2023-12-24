#include <iostream>

/*
                        Q. Nmbr of subarrays with sum K

                explanation -  arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3},   K = 3
                            desired O/Ps - {1, 2},  {1, 2, 3, -3},  {3},  {2, 3, -3, 1}, {3, -3, 1, 1, 1}
                                           {1, 1, 1},  {4, 2, -3},  {-3, 1, 1, 1, 4, 2, -3}

                Brute force -  as we have done in one of the pevious problem
                                we assign 'i' & 'j' to the index 0 and move 'j' in fwd direction till last index, 
                                making subarrays, then moving 'i' to index 1 and moving 'j' from 'i' to last index,
                                repeat with all the elements

        pseudo code
cnt = 0;
for(i=0; i<n; i++)
{
    for(j=i; j<n; j++)
    {
        sum = 0
        for(k=i->j)
            sum = sum + arr[k];

        if(sum == k)
            cnt++;
    }
}

                TC - O(N^3)
                

                Better sol -  we will keep adding elements between 'i' and 'j' w/o taking 'k'

        pseudo code
cnt = 0;
for(i=0; i<n; i++)
{
    sum = 0
    for(j=i; j<n; j++)
    {
        sum = sum + arr[k];

        if(sum == k)
            cnt++;
    }
}

                TC - O(N^2)


                Optimal sol -  we will be using prefix sum as we have done in one of previous problem

                                arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3}
                                         |__________| |______|
                                             x-k          k
                                         |___________________|
                                                  x  

                                to find k we have to find x-k


                                arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3}
                                    
                                            
                                            | ( 9, 1) |
                                            | (12, 1) |
                                            | (10, 1) |                  at 1st
                                            | ( 5, 1) |
                                            | ( 4, 1) |
                                            | ( 6, 2) |
                                            | ( 3, 2) |
                                            | ( 1, 0) |
                                            | ( 0, 1) |
                                            -----------

                                            (preSum, cnt)

        Actual code
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}


                TC - O(N * logN)        // logN for unordered_map
                SC - O(N)
*/

int main()
{
    std::cout << "Hello World!\n";
}