#include <stdio.h>
#include <stdlib.h>
/**
    Sorting an array using bubble sort
*/
void display(int arr[], int n);
void swap( int *first, int *second);
void bubbleSort(int arr[], int size);
/**
    Function main
*/
int main()
{
    printf("Hello world!\n Sorting an array.\n");
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    printf("Introduceti elementele tabloului: ");
    int i;
    int arr[n];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    fprintf(stdout, "Tabloul initial: ");
    display(arr, n);

    bubbleSort(arr, n);

    fprintf(stdout, "Tabloul sortat: ");
    display(arr, n);

    return 0;

}
/**
    display() function
*/
void display(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
/**
    Functia swap
*/
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
/**
*/
void bubbleSort(int arr[], int size)
{
    int i, j;
    for(i = 0; i < size -1; i++){
        for ( j = 0; j < size -1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
