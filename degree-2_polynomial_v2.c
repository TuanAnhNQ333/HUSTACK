#include<stdio.h>
#include<math.h>
void solve (int a, int b, int c)
{
    float x0;
    float x1, x2;
    scanf("%d %d %d", &a, &b, &c);
    int delta = b*b - 4*a*c;
    if(delta < 0)
    {
        printf("NO SOLUTION");
    }
    else if(delta == 0)
    {
        x0 = -b/(2*a);
        printf("%.2f", x0);
    }
    else if(delta > 0)
    {
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        if(x1 < x2)
        {
            printf("%.2f %.2f", x1, x2);
        }
        else if(x1 > x2)
        {
            float temp = x1;
            x1 = x2;
            x2 = temp;
            printf("%.2f %.2f", x1, x2);
        }
    }
}
int main()
{
    int a, b, c ;
    float x0;
    float x1, x2;
    solve(a, b, c);
    return 0;
}
