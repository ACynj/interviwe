#include<stdio.h>
#include<string.h>
int maxProfit(int F[100][100], int f[100][100],int x, int n) {
	int a[100][100];
	memset(a, 0, sizeof(int) * 100);
	for (int i = 1; i <= n; i++) {
		//Ͷ�����Ŀ��
		for (int j = 0; j <= x; j++) {
			//Ͷ��Ľ��
			F[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				//��k����ĿͶ��xԪ
				if (F[i][j] < F[i - 1][j - k] + f[i][k]) {
					F[i][j] = F[i - 1][j - k] + f[i][k];
					a[i][j] = k;
				}
			}
		}	  
	}
	//ÿ����ĿͶ��Ľ��
	int money = x;
	int item = n;
	int sum = 0;
	while (1) {
		if (item == 0)break;
		printf("��%d����ĿͶ��Ľ��Ϊ%d\n",item,a[item][money]);
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
	//nΪ��Ŀ������xΪͶ����Ǯ����f�����ʾͶ��ĳ����Ŀ������F�����ʾͶ��xԪ��ǰk��3��Ŀ����õ�����
	printf("������һ��Ͷ����Ŀ�ĸ�����\n");
	scanf_s("%d", &n);
	printf("������Ͷ�ʵ��ܽ�\n");
	scanf_s("%d", &x);
	printf("������Ͷ�ʽ��������Ĺ�ϵ��\n");
	for (int i = 0; i <=n; i++) {
		for (int j = 0; j <= x; j++) {
			scanf_s("%d", &f[i][j]);
		}
	}
	
	printf("��õ��������Ϊ:%d\n", maxProfit(F, f, x, n));
	

}