
long long allPathsCount(int i, int j, int m, int n){
    
    if(i == m && j == n)
        return 1;

    if(i > m || j > n)
        return 0;
    
    long long rightAllPaths = allPathsCount(i, j+1, m, n);
    long long downAllPaths = allPathsCount(i+1, j, m, n);
    
    return rightAllPaths + downAllPaths;
}
