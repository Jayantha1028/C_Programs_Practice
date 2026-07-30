#include <stdio.h>

int main() {
    int num;
    printf("Enter the number of items : \n");
    scanf("%d",&num);
    int item[num],qty[num];
    printf("Enter the prices and quantity : \n");
    for(int i=0;i<num;i++){
    scanf("%d",&item[i]);
    scanf("%d",&qty[i]);
    }
    float sum=0;
    printf("\n Item\t  Price\t  Quantity  Total\n");
    for(int i=0;i<num;i++){
    printf("Item %d\t\t",i);
    printf("%d\t\t",item[i]);
    printf("%d\t\t", qty[i]);
    printf("%d\n",item[i]*qty[i]);
    sum+=item[i]*qty[i];
    }
    printf("------------------------------------\n");
    printf("Total %.2f \n",sum);
    float d;
    if (sum<1000){
        d=sum/20;
    }
    else if (sum>5000){
        d=sum*3/20;
    }
    else{
        d=sum/10;
    }
    printf("discount %.2f\n", d);
    printf("-------------------------------------\n");
    printf("Grand Total %.2f \n",sum-d);
    return 0;
}
