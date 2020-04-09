#include<stdio.h>
#include<string.h>
int maxProfit(int F[100][100], int f[100][100],int x, int n) {
	int a[100][100];
	memset(a, 0, sizeof(int) * 100);
	for (int i = 1; i <= n; i++) {
		//投入的项目数
		for (int j = 0; j <= x; j++) {
			//投入的金额
			F[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				//第k个项目投入x元
				if (F[i][j] < F[i - 1][j - k] + f[i][k]) {
					F[i][j] = F[i - 1][j - k] + f[i][k];
					a[i][j] = k;
				}
			}
		}	  
	}
	//每个项目投入的金额
	int money = x;
	int item = n;
	int sum = 0;
	while (1) {
		if (item == 0)break;
		printf("第%d个项目投入的金额为%d\n",item,a[item][money]);
		sum += a[item][money];
		money = x- sum;
		item--;
		
	}
	return F[n][x];
}
int main() {
	int n, x, f[100][100], F[100][100];
	F[100][100] = { 0 };
	memset(F, 0, sizeof(int) * 30);
	//n为项目个数，x为投资总钱数，f数组表示投入某个项目的利润，F数组表示投入x元给前k个3项目所获得的利润
	printf("请输入一共投资项目的个数：\n");
	scanf_s("%d", &n);
	printf("请输入投资的总金额：\n");
	scanf_s("%d", &x);
	printf("请输入投资金额与利润的关系：\n");
	for (int i = 0; i <=n; i++) {
		for (int j = 0; j <= x; j++) {
			scanf_s("%d", &f[i][j]);
		}
	}
	
	printf("获得的最大利润为:%d\n", maxProfit(F, f, x, n));
	

}