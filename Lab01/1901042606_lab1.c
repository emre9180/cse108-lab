/* EMRE YILMAZ - 1901042606 - Gebze Technical University 2021 */

/* 

The variable names that used in this file have no relation with the ones in the pdf file. 

<?> in the functions means something other than void, you should find the correct type for these functions.

*/

#include <stdio.h>

void trigonometry(float a, float b, float c)
{
    printf("sinx = %f\ncosx = %f\ntanx = %f",a,b,c);
    return;
}

void trigonometry_calculation(int a, int b, int c)
{
    float a_float = a;
    float b_float = b;
    float c_float = c;

    float tan;
    float sin;
    float cos;

    tan = a_float/b_float;
    sin = a_float/c_float;
    cos = b_float/c_float;

    trigonometry(tan,sin,cos);
}
    

void age(int x)
{
    printf("You are %d seconds.\n",x);
    return;
}


int age_calculation(int x)
{
    int result;
    result = x*365*24*60*60;

    return result;
}


int main()
{

    int ages = -1;
    while (ages<0 || ages>100)
    {
        printf("Your age: ");
        scanf("%d",&ages);
        if ((ages<0 || ages>100)) printf("Please enter your age between 0-100 age\n");
    }

    int sec_age = age_calculation(ages);
    age(sec_age);
    
    /* */

    int a,b,c;
    printf("a side: ");
    scanf("%d",&a);
    printf("b side: ");
    scanf("%d",&b);
    printf("c side: ");
    scanf("%d",&c);

    trigonometry_calculation(a,b,c); 
    return 0;
}
