#include <stdio.h>

int main() {
    int y10,y5,y2,y1,times;
    times = 0;
    for(y10=1;y10<=10;y10++)
    {
        for(y5=1;y5<=16;y5++)
        {
            for(y2=1;y2<=40;y2++)
            {
                for(y1=1;y1<=40;y1++)
                {
                    if (10*y10+5*y5+2*y2+y1==100 && y10+y5+y2+y1==40)
                    {
                        times = times+1;
                    }
                }
            }
        }
    }
    printf("%d",times);
    return 0;
}

