#include <stdio.h>

int main()
{
    int x=0;
    int y=0;
   int yy=2;
    char *maap[yy];
    maap[0]= "1111111111";
    maap[1]= "1000000001";
    int m_x=0;
    int m_y=0;
 
    
    
    while (yy>0)
    {
        m_x=0;
        x=0;
        while (maap[m_y][m_x])
        {
            if(maap[m_y][m_x]=='1')
                printf("w");
            if(maap[m_y][m_x]=='0')
                printf("o");
            x+=64;
            m_x++;
        }
        m_y++;
        y+=64;

        yy--;
        
    }
    

}