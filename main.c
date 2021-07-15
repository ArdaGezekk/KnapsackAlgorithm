#include<stdlib.h>
#include<stdio.h>
#define MAX 100
int max(int a, int b) {
if(a < b)
return b;
else
return a;
}
 int knapsit(int capacity, int n, int list[], int kg[])
 {
 int K[n+1][capacity+1];

 for (int i=0; i<=n; i++) {
 for (int j=0; j<=capacity; j++) {
 if (i == 0 || j == 0) {
 K[i][j] = 0;
 } else if (kg[i-1] > j) {
 K[i][j] = K[i-1][j];
 } else {
 K[i][j] = max(list[i-1] + K[i-1][j - kg[i-1]], K[i-1][j]);
 }
 }
 }
 printf("########################## KNAPSACK TABLE: ########################## \n\n");
 printf("i \t CAPACITY1\t CAPACITY2\t CAPACITY3\t CAPACITY4\n");
 printf("_ \t _________\t _________\t _________\t _________\n\n");
 for (int i = 0; i <= n; ++i)
 {
 for (int j = 0; j <= capacity; ++j)
 {
 // display of the elements of the generated matrix
 printf("%d\t", K[i][j]);
 }
 printf("\n");
 }
 // table which allows to have the elements taken
 int x[n];
 int c = n, w = capacity;
 while(c>0 && w>0)
 {
 if (K[c][w]== K[c-1][w]){
 // same weight so element not taken
 x[c-1]= 0;
 }else{
 // weight has changed so element taken
 x[c-1] = 1;
 w = w - kg[c-1];
 }
 c--;
 }
 printf("\n======================================================================== \n");
 for(int j=0;j<n;j++)
 {
 if(x[j]==1)
 {
 // if the value in the table of elements == 1 then the element is taken
 printf("item %d is selected with value %d: weigth :%d \n",j+1, kg[j], list[j]);
 }
 }
 return K[n][capacity];
 }
 int main()
 {
 //values
 int list[MAX] = {3,2,1,7};
 //weight
 int kg[MAX] = {1,2,5,3};
 // maximum capacity
 int capacity = 8;
 // number of elements in the array
 int n=4;
 // call of the knapsack function
 printf("Max value : %d\n", knapsit(capacity, n, list, kg));
 return 0;
 }
