#include <stdio.h>

int main() {
   
    int arr[100] = {10, 20, 30, 40, 50}; 
    int size = 5;        
    int position = 2;  
    int newValue = 99;   

   
    if (position < 0 || position > size || size >= 100) {
        printf("Invalid position or array is full!\n");
        return 1;
    }

  
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
 
    arr[position] = newValue;

    
    size++;

    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}