import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,r;
	static int[][] board;
	static int[][] v;
	
	
	//아래 오른쪽 위 왼쪽
	static int[] dx= {1,0,-1,0};
	static int[] dy= {0,1,0,-1};
	static int starx=1;
	static int stary=1;
	static int temp=0;
	public static void main(String[] args) throws NumberFormatException, IOException  {
		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st =new StringTokenizer(br.readLine());
		
		
		n= Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		board = new int[n+1][m+1];
		v= new int[n+1][m+1];
		for(int i=1; i<=n;i++)
		{
			st= new StringTokenizer(br.readLine());
			for(int j=1;j<=m;j++) {
				board[i][j]= Integer.parseInt(st.nextToken());
			}
		}
	
		
		for(int i=0;i<r;i++) {			
			rotation(board[1][1],1,1,0);
			v= new int[n+1][m+1];
		}
		
		print();
	   
	  
		
		

	}
	
	//대입되야할 값을 넘겨주고 그 대상의 값은 넘겨주기위해 내가 들고 있어야함
	
	public static void rotation(int temp,int x, int y, int rot) {
		
	
		//4가 되었으면 한바퀴를 다 돈것
		if(rot == 4) {
		
			if(v[x+1][y+1] == 0) {
				rotation(board[x+1][y+1],x+1,y+1,0);
			}
			return;
			
		   
		}
		
		
		int nx= x + dx[rot];
		int ny = y + dy[rot];
		
		//방향전환
	    
		if(nx <= 0 || ny<= 0 || nx>n || ny>m || v[nx][ny]==1) {
		
			
			rotation(temp,x,y,rot+1);
			
		}else {
			
			int temp2 = board[nx][ny];
			board[nx][ny]=temp;
			v[nx][ny]=1;
			rotation(temp2,nx,ny,rot);
		}
		
	}
	
	public static void print() {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
	}

}
