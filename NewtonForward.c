#include<stdio.h>
int main()
{
    int i,j,c,n,h,k=1;
    float x,z,xo,p,yp;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    float a[n][n+1];
    //Inputing the x and y values
    printf("Enter the data:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
            scanf("%f",&a[i][j]);
    }
    //Displaying the x and y values
    printf("The data values are:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
            printf("%.2f\t",a[i][j]);
        printf("\n");
    }
    //Calculating the forward difference table
    for(i=2;i<n+1;i++)
    {
        for(j=0;j<n-1;j++)
            a[j][i]=a[j+1][i-1]-a[j][i-1];
    }
    //Displaying the forward difference table
    c=n;
    printf("Newton's Forward Interpolation Table is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<c+1;j++)
            printf("%.2f  ",a[i][j]);
        c--;
        printf("\n");
    }
    xo=a[0][0];
    printf("Enter the value of x: ");
    scanf("%f",&x);
    h=a[1][0]-a[0][0];
    printf("The height is %d\n",h);
    p=(x-xo)/h; //Calculating p
    printf("The value of p is %.2f\n",p);
    //calculating yp
    yp=a[0][1];
    k=1;
    for(i=2;i<n+1;i++) //i=2 to 7
    {
        z=1;
        for(j=0;j<k;j++)
        z=z*(p-j)/(j+1); //pth term/fact
        yp=yp+z*a[0][i]; //Sum
        k++;
    }
    printf("The value of y when x = %.2f is: %.4f",x,yp);
    return 0;
}