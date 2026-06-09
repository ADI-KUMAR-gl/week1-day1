#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(2 * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    *returnSize = 0;
    free(result);
    return NULL;
}

int main(void) {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;

    int* indices = twoSum(nums, 4, target, &returnSize);
    if (returnSize == 2 && indices != NULL) {
        printf("Found indices: %d %d\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No pair found.\n");
    }

    return 0;
}   