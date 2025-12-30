#include <iostream>

using namespace std;


int pointX;
int pointY;

int countSurroundingSquares(int x, int y, int k)
{
    {
        if (k < 1)
        {
            return 0;
        }

        bool x_in_range = (pointX >= (x - k)) && (pointX <= (x + k));
        bool y_in_range = (pointY >= (y - k)) && (pointY <= (y + k));

        int count = (x_in_range && y_in_range) ? 1 : 0;

        if (k == 1)
        {
            return count;
        }
        
        int newK = k / 2;

        count += countSurroundingSquares(x - k, y - k, newK);
        
        count += countSurroundingSquares(x + k, y - k, newK);
        
        count += countSurroundingSquares(x - k, y + k, newK);
        
        count += countSurroundingSquares(x + k, y + k, newK);
        
        return count;
    }
}


int main()
{
    {
        int k_max;
        
        cout << "Enter size of largest square (1 <= k <= 512) ";
        if (k_max < 1 || k_max > 512)
        {
            {
                cin >> k_max;
            }
        }
        cin >> pointX >> pointY;
        
        int total_squares = countSurroundingSquares(1024, 1024, k_max);

        cout << total_squares << endl;

        return 0;
    }
}

























