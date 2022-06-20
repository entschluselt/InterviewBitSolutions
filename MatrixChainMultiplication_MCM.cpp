public:
    /*
    
        BASICALLY WE CREATE PARTITIONS STARTING FROM SECOND INDEX TO LAST
    
        LIKE THIS =>
    
                               ABCD
    
                A|BCD          AB|CD             ABC|D
    
            A|B|CD A|BC|D   A|B|CD AB|C|D    A|BC|D   AB|C|D
        NOW HERE WE CAN SEE OVERLAPPING SUBCASES 
        SO BASICALLY WE WE RECURSIVELY CALCLUATE AND MEMONISE THE VALUES AND
        AS SOON AS WE ARRIVE AT SOME
        ALREADY COMPUTED VALUE WE RETURN IT 
        RESULTING IN DECREASING TIME COMPLEXITY
    
        ANOTHER IMPORTANT THING IS CALCULATING THE NUMBER OF OPERATIONS
        SO IF WE MULTIPLY MATRIX OF DIMENSION A X B WITH B X D
        EVENTUALLY WE HAVE TO PERFORM A X B X D NUMBER OF OPERATIONS
    
        
    */
    
    
    int mcm(int i , int j , int a[], vector<vector<int>> &dp){
        if(i == j) return 0; // BASECASE => IF I AND J ARE EQUAL MEANS WE CANNOT PERFORM OPERATIONS OBVIOUSLY
        
        if(dp[i][j] != -1) return dp[i][j];  // IF WE ENCOUNTERED ALREADY COMPUTED VALUE THEN RETURN IT
        
        dp[i][j] = INT_MAX; 
        
        for(int k = i; k < j; k++)
            dp[i][j] = min(dp[i][j] , mcm(i,k,a,dp) + mcm(k+1,j,a,dp) + a[i-1]*a[k]*a[j]);
        
        return dp[i][j];
    }
    int matrixMultiplication(int n, int a[]){
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return mcm(1,n-1,a,dp);
    }
};
