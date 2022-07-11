class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        
        
        int r = m -1;
        double res = 1;
        
        
        for(int i = 1 ; i <= r ; i++){
            //10c3 = 8*9*10/3*2*1
            res = res*(N - r + i )/i;
        }
        
        return (int)res;
        
    }
};