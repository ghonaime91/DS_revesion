#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void)
{
    
    int arr[SIZE] = {10,20,30,40,50};
    int pos, i, n = 5;

    printf("Enter a postion to delete from: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
        return 1;

    // o(n)
    for(i=pos-1; i<n-1;i++)
        arr[i] = arr[i+1];

    // if array not sorted and o(1)
    // arr[pos-1] = arr[n-1];
    n--;
    for(i=0; i<n;i++)
        printf("%d\n", arr[i]);
    return 0;   


}