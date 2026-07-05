/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compare(const void *a ,const void *b)
 {
    return (*(int *)a-*(int *)b);
 }
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
   qsort(nums,numsSize,sizeof(int),compare);
   int *ans=(int*)malloc(numsSize *sizeof(int));
   *returnSize=0;
   int expected=1;
   for(int i=0;i<numsSize;i++){
    if(nums[i]==expected){
        expected++;
    }
    else if(nums[i]<expected){
        continue;//do same na aaye 
    }
    else{
        while(expected<nums[i]){
            ans[*returnSize]=expected;
            (*returnSize)++;
            expected++;
        }
        expected++;
    }
   }
   while(expected<=numsSize){
    ans[*returnSize]=expected;
    (*returnSize)++;
    expected++;
   }
   return ans;
}