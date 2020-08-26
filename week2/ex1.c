#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int int_var;
    float float_var;
    double double_var;
    
    int_var = INT_MAX; 
    float_var = FLT_MAX;
    double_var = DBL_MAX;
    
    
    printf("Values:\n %d\n %f\n %f\n", int_var, float_var, double_var);
    printf("Sizes:\n %lu\n %lu\n %lu\n", sizeof(int_var), sizeof(float_var), sizeof(double_var));

    return 0;
}
