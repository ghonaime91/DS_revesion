#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void)
{
    
    int arr[SIZE] = {10,20,30,40,50};
    int num, pos, i, n = 5;
    printf("Enter a number to insert: ");
    scanf("%d", &num);

    printf("Enter a postion to insert: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n+1)
        return 1;

    //o(n)
    // for(i = n; i >= pos-1; i--)
    // {
    //     arr[i] = arr[i-1];
    // }
    // arr[pos-1] = num;

    // o(1)
    arr[n-1] = arr[pos-1];
    arr[pos-1] = num;
    
    for(i = 0; i<n; i++)
        printf("%d\t", arr[i]);

    
    return 0;   


}