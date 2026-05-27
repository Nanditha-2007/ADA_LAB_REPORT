#include <stdio.h>
#define LEFT 0
#define RIGHT 1
// Function to print permutation
void printPermutation(int p[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}
// Function to find position of mobile element
int getMobile(int p[], int dir[], int n) {
    int mobile = 0;
    int mobile_pos = -1;
    for(int i = 0; i < n; i++) {
        // Moving left
        if(dir[i] == LEFT && i != 0) {
            if(p[i] > p[i - 1] && p[i] > mobile) {
                mobile = p[i];
                mobile_pos = i;
            }
        }
        // Moving right
        if(dir[i] == RIGHT && i != n - 1) {
            if(p[i] > p[i + 1] && p[i] > mobile) {
                mobile = p[i];
                mobile_pos = i;
            }
        }
    }
    return mobile_pos;
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int p[n], dir[n];
    // Initialize permutation and directions
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i] = LEFT;
    }
    printPermutation(p, n);
    while(1) {
        int mobile_pos = getMobile(p, dir, n);
        // No mobile element
        if(mobile_pos == -1)
            break;
        int swap_pos;
        // Determine swap position
        if(dir[mobile_pos] == LEFT)
            swap_pos = mobile_pos - 1;
        else
            swap_pos = mobile_pos + 1;
        // Swap elements
        int temp = p[mobile_pos];
        p[mobile_pos] = p[swap_pos];
        p[swap_pos] = temp;
        // Swap directions
        temp = dir[mobile_pos];
        dir[mobile_pos] = dir[swap_pos];
        dir[swap_pos] = temp;
        mobile_pos = swap_pos;
        // Reverse directions of elements greater than mobile
        for(int i = 0; i < n; i++) {
            if(p[i] > p[mobile_pos]) {
                dir[i] = !dir[i];
            }
        }
        printPermutation(p, n);
    }
    return 0;
}
