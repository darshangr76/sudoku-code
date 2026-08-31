#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5; // Current number of elements
    int delete_index = 2; // Index of the element to delete (30)

    // Check if index is valid
    if (delete_index < 0 || delete_index >= size) {
        printf("Invalid index! Deletion not possible.\n");
    } else {
        // Shift elements to the left
        for (int i = delete_index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
        // Reduce the logical size
        size--; 

        // Print the updated array
        printf("Array after deletion: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}