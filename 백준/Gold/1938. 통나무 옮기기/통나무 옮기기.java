import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static class Point{
		int x,y,rot;
		
		public Point(int x , int y , int rot)
		{
			this.x=x;
			this.y=y;
			this.rot=rot;
		}
	}
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,1,-1};
	
	static int[][] board;
	static int[][][] visited;
	static int n;
	static int Ans = Integer.MAX_VALUE;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		n = Integer.parseInt(br.readLine());
		int rot=4;
		int x = 0,y = 0;
		board= new int[n][n];
		visited= new int[n][n][2];
		for(int i=0;i<n;i++)
		{
			st= new StringTokenizer(br.readLine());
			String str= st.nextToken();
			for(int j=0;j<str.length();j++)
			{
				
				if(str.charAt(j)=='B')
				{
					board[i][j]=2;
				}
				else if (str.charAt(j)=='E')
				{
					board[i][j]=3;
				}
				else
				{
					board[i][j]=str.charAt(j)-'0';					
				}
			}
			
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==2)
				{
					int check = find(i, j);
					if(check==1)
					{
						rot=0;
						x=i;
						y=j;
					}
					if(check==2)
					{
						rot=1;
						x=i;
						y=j;
					}
				}
			}
		}
		//여기서 bfs
//		print();
//		System.out.println(x + " " + y + " " + rot);
		bfs(x,y,rot);
		if(Ans== Integer.MAX_VALUE)System.out.println(0);
		else System.out.println(Ans-1);

	}
	
	public static void print()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				System.out.print(board[i][j] +" ");
			}
			System.out.println();
		}
	}
	static Queue<Point> q = new ArrayDeque<>();
	public static void bfs(int x ,int y, int rot)
	{
		q.offer(new Point(x,y,rot));
		visited[x][y][rot]=1;
		
		while(!q.isEmpty())
		{
			Point p = q.poll();
			int curx = p.x;
			int cury = p.y;
			
			if(goal(curx, cury, p.rot))
			{
				Ans = visited[curx][cury][p.rot];
				return;
			}
			//상하좌우
			for(int i=0;i<4;i++)
			{
				int nx= curx + dx[i];
				int ny = cury + dy[i];
				if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
				if(board[nx][ny]==1)continue; //통나무면 갈수 없다.
				if(visited[nx][ny][p.rot]>0)continue;
				//넘어간 좌표에서 해당 방향으로 통나무를 설치할수 있을지
				//성공하면방문처리하고 q에 담음
				if(traincheck(nx, ny, p.rot))
				{
//					System.out.println(nx + " " + ny + "회전 :  " + p.rot);
					visited[nx][ny][p.rot]= visited[curx][cury][p.rot]+1;
					q.offer(new Point(nx,ny,p.rot));
				}
			}
			//회전
			int nrot = (p.rot + 1 )%2;
			if(visited[curx][cury][nrot]==0 && traincycle(curx, cury, nrot))
			{
//				System.out.println(curx + " " + cury + "방향전환 :  " + nrot);
				visited[curx][cury][nrot]= visited[curx][cury][p.rot]+1;
				q.offer(new Point(curx,cury,nrot));
			}
			
		}
	}
	
	public static boolean traincheck(int x, int y,int rot)
	{
		int curx = x;
		int cury = y;
		//가로
		if(rot==0)
		{
			for(int i=0;i<3;i++)
			{
				int nx= curx;
				int ny= cury + move[i];
				//설치할수 없음
				if(nx<0 || nx>=n || ny<0 || ny>=n)return false;
				if(board[nx][ny]==1)return false;
			}
		}
		//세로
		else
		{
			for(int i=0;i<3;i++)
			{
				int nx= curx + move[i];
				int ny= cury;
				//이동할수 없음
				if(nx<0 || nx>=n || ny<0 || ny>=n)return false;
				if(board[nx][ny]==1)return false;
			}
		}
		
		return true;
	}
	public static boolean traincycle(int x, int y,int rot)
	{
		int curx = x;
		int cury = y;
		
		
		for(int i = curx-1;i<=curx+1;i++)
		{
			for(int j=cury-1; j<=cury+1;j++)
			{
				if(i<0 || i>=n || j<0 || j>=n)return false;
				if(board[i][j]==1)return false;
			}
		}
		return true;
	}
	public static boolean goal(int x, int y, int rot)
	{
		int curx= x;
		int cury =y;
		//가로일때
		int cnt=0;
		if(rot==0)
		{
			for(int i=0;i<3;i++)
			{
				int nx= curx;
				int ny= cury + move[i];
				//이동할수 없음
				if(nx<0 || nx>=n || ny<0 || ny>=n)return false;
				if(board[nx][ny]==1)return false;
				if(board[nx][ny]==3)cnt++;
				
			}
			if(cnt==3)return true;
		}
		else
		{
			for(int i=0;i<3;i++)
			{
				int nx= curx + move[i];
				int ny= cury;
				//이동할수 없음
				if(nx<0 || nx>=n || ny<0 || ny>=n)return false;
				if(board[nx][ny]==1)return false;
				if(board[nx][ny]==3)cnt++;
				
			}
			if(cnt==3)return true;
		}
		return false;
	}
	static int[] move= {-1,0,1};
	public static int find(int x, int y)
	{
		int curx =x;
		int cury =y;
		//가로
		int cnt=0;
		for(int i=0;i<3;i++)
		{
			int nx= curx;
			int ny= cury + move[i];
			//이동할수 없음
			if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
			if(board[nx][ny]==2)cnt++;
		}
		if(cnt==3)return 1;
		cnt=0;
		//세로
		for(int i=0;i<3;i++)
		{
			int nx= curx + move[i];
			int ny= cury;
			//이동할수 없음
			if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
			if(board[nx][ny]==2)cnt++;
		}
		if(cnt==3)return 2;
		
		//아무것도 아님
		return 0;
		
		
	}

}