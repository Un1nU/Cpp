#include <string>

using namespace std;

class Solution 
{
public:
    bool judgeCircle(string moves) 
    {
        if (moves.empty()) return true;
        if (moves.length() % 2 != 0) return false;

        int veritical = 0;
        int horizontal = 0;
        for (auto step : moves)
        {
            if (step == 'U')
                veritical++;
            else if (step == 'D')
                veritical--;
            else if (step == 'L')
                horizontal++;
            else
                horizontal--;
        }

        return horizontal == 0 ? veritical == 0 : false;
    }
};