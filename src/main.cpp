#include <stdio.h>
#include <stdlib.h>
#include "search.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int command;
	do{
		printf("請輸入代碼:\n");
		printf("1: 食物需求 2: 排序 3: 輪盤 4: 搜尋 0: 結束\n");
		scanf("%d",&command);
		switch(command){
			case 1:
				D0642339();
				break;
			case 2:
				D0641533();
				break;
			case 3:
				D0611117();
				break;
			case 4:
				D0642075();
				break;
			case 0:
				break;
			default:
				printf("wrong command\n");
				break;
		}
	}while(command!=0);
	return 0;
}
