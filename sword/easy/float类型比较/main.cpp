/*
float类型比较
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    float var = 0;
    const float ESPION = 0.000001; //float的小数精度为6
    if (var >= -ESPION && var <= ESPION)
    {
        cout << "var equals 0"<<endl;
        
    }
    return 0;
}