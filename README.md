class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> arr;

        for(int i=0;i<n;i++)
        {
            arr.push_back(0);
        }
         int count=0;

         if(connections.size() < n-1)
         {
             return -1;
         }

         for(int i=0;i<connections.size();i++)
         {
             arr[connections[i][0]]=1;
             arr[connections[i][1]]=1;
         }
         for(int i=0;i<n;i++)
         {
             if(arr[i]==1)count++;
         }
         return n-count;
    }
