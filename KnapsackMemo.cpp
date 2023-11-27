int knapSackRec(int W, int wt[], int val[], int index, int** dp) 
{ 
    // base condition 
    if (index < 0) 
        return 0; 
    if (dp[index][W] != -1) 
        return dp[index][W]; 
  
    if (wt[index] > W) { 
  
        // Store the value of function call 
        // stack in table before return 
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp); 
        return dp[index][W]; 
    } 
    else { 
        // Store value in a table before return 
        dp[index][W] = max(val[index] 
                           + knapSackRec(W - wt[index], wt, val, 
                                         index - 1, dp), 
                       knapSackRec(W, wt, val, index - 1, dp)); 
  
        // Return value of table after storing 
        return dp[index][W]; 
    } 
} 

//use memset to fill the matrix with -1
//memset(dp,-1,sizeof(dp))
