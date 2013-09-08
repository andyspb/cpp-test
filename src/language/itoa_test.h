#pragma once
#include <iostream>
namespace itoa_test
{
using namespace std;
    char * itoa(int i);
    void test()
    {
        int num = -593;
        cout<<"itoa_test itoa("<<num<<")="<<itoa(num)<<endl;
    }

    char * itoa(int num)
    {
        if ( num == 0 )
        {
            char * ret = (char*)malloc(2*sizeof(char));
            ret[0] = '0';
            ret[1] = '\0';
            return ret;
        } else 
        {
            char buf[8] = {0};
            bool neg = ( num < 0);
            buf[0] = '\0';

            if (neg) {
                num = num * (-1);
            }

            int i = 0;
            while (num != 0)
            {
                buf[++i] = num % 10 + char('0');
                num = num / 10;
            }

            if (neg) 
            {
                buf[++i] = '-';
            }
            int p = i>>1;
            for (int j = 0; j<=p; ++j)
            {
                char tmp = buf[j];
                buf[j] = buf[i-j];
                buf[i-j] = tmp;
            }
            
            char  * ret;
            ret = (char *)malloc((i+1) * sizeof(char));

            memcpy(ret, buf, (i+1) * sizeof(char));

            return ret;
        }
    }
}