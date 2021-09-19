#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T; //No. of test cases
    string s;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int N, K; //Length of string and goodness score
        cin >> N >> K;
        cin >> s;

        int x = 0;
        for (int i = 0; i < N / 2; i++) //Checking indices from first half with the other half of the stiring
        {
            if (s[i] != s[N - i - 1]) //if the corresponding indices are not equal, x is increased by 1
                x++;
        }

        /*
        Case 1: X=K,
        The string already has a goodness score of K. Therefore number of operations required is 0.

        Case 2: X>K,
        The string has a goodness score of X which is greater than K, so the minimum operations to change the string with 
        goodness score of K is X - K.

        Case 3: X<K,
        The string has a goodness score of X which is lesser than K, so the minimum operations to change the string with 
        goodness score of K is K - X.
        */

        int minOp = K - x;
        if (minOp < 0)
            minOp = -minOp;
        printf("Case #%d: %d\n", i, minOp);
    }
    return 0;
}