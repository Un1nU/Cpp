#include <vector>

using namespace std;

class Solution 
{
private:
    void dfs(vector<vector<int>>& rooms, int nextNo, vector<bool>& isVisited, int& visitCnt)
    {
        isVisited[nextNo] = true;
        visitCnt++;
        
        for (int i = 0; i < rooms[nextNo].size(); ++i)
        {
            int keyNo = rooms[nextNo][i];
            if (!isVisited[keyNo])
            {
                dfs(rooms, keyNo, isVisited, visitCnt);
            }
                
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int roomNum = rooms.size();
        if (roomNum == 0) return false;
        if (rooms[0].size() == 0) return false;

        int visitCnt = 0;
        vector<bool> isVisited(roomNum, false);

        dfs(rooms, 0, isVisited, visitCnt);

        return roomNum == visitCnt;
    }
};