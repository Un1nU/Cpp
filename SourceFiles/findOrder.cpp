#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    /*解法1：BFS，思路与 课程表I (canFinish.cpp) 相同*/
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> courses(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> studyed;
        queue<int> canStudy;

        for (auto coursePair : prerequisites)
        {
            ++inDegree[coursePair[0]];
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
            studyed.push_back(preCourse);

            for (auto postCourse : courses[preCourse])
            {
                --inDegree[postCourse];
                if (inDegree[postCourse] == 0) canStudy.push(postCourse);
            }
        }

        // 注意，如果课程不能全部修完，要返回空
        if (studyed.size() == numCourses) return studyed;
        else return {};
    }
};