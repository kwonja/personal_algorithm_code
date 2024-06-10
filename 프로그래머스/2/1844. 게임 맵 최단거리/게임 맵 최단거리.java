import java.util.*;

class Solution {
    
    static class Pair{
        int x,y;
        public Pair(int x ,int y)
        {
            this.x= x;
            this.y= y;
        }
    }
    static int[] dx= {1,-1,0,0};
    static int[] dy={0,0,1,-1};
    static Queue<Pair> q = new ArrayDeque<>();
    static int[][] visited;
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        visited = new int[n][m];
        
        bfs(maps,n,m);
        if(visited[n-1][m-1]==0)return -1;
        else return visited[n-1][m-1];
    }
    
    public void bfs(int[][] maps,int n,int m)
    {
        q.offer(new Pair(0,0));
        visited[0][0]=1;
        while(!q.isEmpty())
        {
            Pair p = q.poll();
            int curx = p.x;
            int cury = p.y;
            for(int i=0;i<4;i++)
            {
                int nx= curx + dx[i];
                int ny = cury + dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
                if(maps[nx][ny]==0 || visited[nx][ny]>0)continue;
                visited[nx][ny]=visited[curx][cury]+1;
                q.offer(new Pair(nx,ny));
            }
        }
    }
}