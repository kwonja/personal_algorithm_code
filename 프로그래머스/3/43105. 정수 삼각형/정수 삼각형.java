class Solution {
    
    static int[][] dp;
    public int solution(int[][] triangle) {
        int answer=0;
        int r= triangle.length;
        int c= triangle[triangle.length-1].length;
        dp = new int[r][c];
        
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.length;i++)
        {
            dp[i][0]=dp[i-1][0] + triangle[i][0];
            for(int j=1;j<=i;j++)
            {
                dp[i][j]= Math.max(dp[i-1][j] +  triangle[i][j], dp[i-1][j-1] +  triangle[i][j]);
            }
        }
        
        for(int i=0;i<c;i++)
        {
            answer = Math.max(dp[r-1][i],answer);
        }
        
        return answer;
    }
}

//테이블 설정
// arr[i][j] i,j에 오는 삼각형의 합의 최대값

//dp[i][j]=  max (dp[i-1][j] + arr[i][j], dp[i-1][j-1] + arr[i][j])