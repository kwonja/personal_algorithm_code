import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m;
	static int[] dx= {1,-1,0,0};
	static int[] dy= {0,0,1,-1};
	static int[][] board;
	static boolean[][] v;
	static int cnt=0;
	static int res=0;
	static ArrayDeque<Pair> q = new ArrayDeque<Pair>();
 	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st =new StringTokenizer(br.readLine());
		
		n= Integer.parseInt(st.nextToken());
		m= Integer.parseInt(st.nextToken());
		
		board = new int[n+1][m+1];
		v= new boolean[n+1][m+1]; //기본값 false
		
		for(int i=1;i<=n;i++)
		{
			st= new StringTokenizer(br.readLine());
			for(int j=1;j<=m;j++) {
				board[i][j]= Integer.parseInt(st.nextToken());
			}
		}
//		print();
		
		// 2차원 벽에 1을 찾고, 그리고 방문한 1이면 지나감
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if((board[i][j] == 1) && !v[i][j]) {
					cnt++;
					int temp = bfs(i,j);
					res= Math.max(temp, res);
			
				}
			}
		}
		System.out.println(cnt);
		System.out.println(res);
		
		
 	}
 	
 	//
 	public static int bfs(int startx, int starty) {
 		
 		//처음은 무조건 1의 넓이를 가짐
 		int width=1;
 		q.offer(new Pair(startx,starty));
 		v[startx][starty]=true;
 		
 		
 		while(!q.isEmpty()) {
 		
 			Pair p = q.poll();
 			int curx = p.x;
 			int cury = p.y;
 		
 			
 			for(int i=0;i<4;i++) {
 				int nx= curx + dx[i];
 				int ny = cury + dy[i];
 				if(nx <= 0 || ny <=0 || nx>n || ny>m)continue;
 				if(board[nx][ny] == 0 || v[nx][ny]) continue;
 				
 				v[nx][ny]=true;
 				width++;
 				q.add(new Pair(nx,ny));
 			}
 		}
 		
 		return width;
 	}
 	
 	
 	
 	
 	public static void print() {
 		for(int i=1;i<=n;i++) {
 			for(int j=1;j<=m;j++) {
 				System.out.print(board[i][j] + " ");
 			}
 			System.out.println();
 		}
 	}
 	
   public static class Pair{
	   int x, y;
	   
	   
	   public Pair(int x, int y) {
		   this.x=x;
		   this.y=y;
	
	   }
   }

}
