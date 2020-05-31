#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
        int sum = 0;
        vector<int> sumarr;
        for(int x=0;x<4;x++ )
        {
            for(int y=0;y<4;y++ )
            {
                sum = 0;
                for(int i = x;i<(x+3);i++)
                {
                    for(int j = y;j<(y+3);j++)
                    {
                        if ( (i == x+1) && ( j == y || j == (y+2) )  )
                            continue;
                        sum = sum + arr[i][j];
                    }
                }
                sumarr.push_back(sum);
            }
        }
        int i=0;
        sum = sumarr.at(i);
        for(i=1;i<16;i++)
        {
            if(sumarr.at(i) > sum )
                sum = sumarr.at(i);
        }
        return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
