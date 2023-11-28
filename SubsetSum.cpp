//Recursive solution
bool isSubsetSum(int set[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
 
    
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
 
   
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

//Memoization
int subsetSum(int a[], int n, int sum)
{   
 
    if (sum == 0)
        return 1;
         
    if (n <= 0)
        return 0;
   
   
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
   
    
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {      
        s
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) || 
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

//Tabulation
bool isSubsetSum(int set[], int n, int sum)
{
   
    bool subset[n + 1][sum + 1];
 
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j]
                    = subset[i - 1][j]
                      || subset[i - 1][j - set[i - 1]];
        }
    }
 
    return subset[n][sum];
}
