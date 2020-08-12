#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    /*解法1：BFS，通过遍历课程对的列表 (prerequisites)，建立课程间的邻接表 courses
       同时，计算每门课程表示的图结点的入度，入度就表示该门课程的先修课程数。
       如果一门课程入度为0，表示没有先修课程，加入队列中，即BFS的起点。
       之后每次取出队列中的元素，并将其后修课程的入度减1，入度变为0的又可以加入到队列中。
       遍历完成后，如果队列中遍历过的元素个数为 numCourses，说明所有课程都可以修完，否则无法修完
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> courses(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> canStudy;

        for (auto coursePair : prerequisites)
        {
            inDegree[coursePair[0]]++;
            courses[coursePair[1]].push_back(coursePair[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0) canStudy.push(i);
        }

        while (!canStudy.empty())
        {
            int preCourse = canStudy.front();
            canStudy.pop();
            numCourses--;

            for (auto postCourse : courses[preCourse])
            {
                inDegree[postCourse]--;
                if (inDegree[postCourse] == 0) canStudy.push(postCourse);
            }
        }

        return numCourses == 0;
    }
};