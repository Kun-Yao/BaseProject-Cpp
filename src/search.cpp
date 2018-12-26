#include "search.h"

void Data::import(){
	
		memset(num,NULL,sizeof(num));
		FILE* inptr = fopen("data.txt","r");
		if(inptr==NULL){
			printf("開檔失敗!");
			exit(0);
		}
		
		int i;
		for(i=0;;i++){
			num[i] = (Element*)malloc(sizeof(Element));
			if(fscanf(inptr,"%s %s %s %d %s %f %f",num[i]->foodType,num[i]->storeName,num[i]->address,&num[i]->price,num[i]->weight,&num[i]->calorie,&num[i]->evaluation)==EOF)
				break;
			
		}
		free(num[i]);
		num[i] = NULL;
		size = i;
		return;
	}
	
void Data::show(){
	int i;
	for(i=0;i<size;i++){
		printf("%s %s %s %d %s %.2f %.1f\n",num[i]->foodType,num[i]->storeName,num[i]->address,num[i]->price,num[i]->weight,num[i]->calorie,num[i]->evaluation);
	}
	return;
}

void Data::SearchStoreName(){
	int i;
	char name[64];
	printf("請輸入商家名稱:");
	scanf(" %s",name);
	for(i=0;i<size;i++){
		if(strcmp(name,num[i]->storeName)==0){
			printf("%s %s %s %d %s %.2f %.1f\n",num[i]->foodType,num[i]->storeName,num[i]->address,num[i]->price,num[i]->weight,num[i]->calorie,num[i]->evaluation);
			break;
		}
	}
	if(i==size){
		printf("查無此資料");
	}
	return;
}

void Data::SearchFoodType(){ 
	int i,j,k;
	char name[64];
	FILE* outptr = fopen("SearchFoodType.txt","w");
	while(1){
		printf("請輸入食物種類:");
		scanf(" %s",name);
		for(j=0;j<strlen(name);j+=2){
			if(name[j]>0 ){
				i=1;
				break;
			}
		}
		if(i==1){
			printf("請輸入中文\n");
			continue;
		}
		k=0;
		for(i=0;i<size;i++){
			if(strcmp(name,num[i]->foodType)==0){
				printf("%s %s %s %d %s %.2f %.1f\n",num[i]->foodType,num[i]->storeName,num[i]->address,num[i]->price,num[i]->weight,num[i]->calorie,num[i]->evaluation);
				fprintf(outptr,"%s %s %s %d %s %.2f %.1f\n",num[i]->foodType,num[i]->storeName,num[i]->address,num[i]->price,num[i]->weight,num[i]->calorie,num[i]->evaluation);
				k=1;
			}
		}
		if(k==0){
			printf("查無此資料");
		}
		else{
			break;
		}
	}
	fclose(outptr);
} 

void SortFoodAndPrint(){ //堂 
	element obj[10],tmp;
	int i,j,k,select;
	FILE* sort = fopen("SearchFoodType.txt","r");
	if(sort == NULL){
		printf("請先設定食物需求!\n");
		return;
	}
	else{
		printf("請選擇:\n1.依評價排序\n2.依價格排序\n");
		scanf("%d",&select);
	}
	
	//讀檔案 
	while(fscanf(sort,"%s %s %s %d %s %f %f",&obj[i].foodType,&obj[i].storeName,&obj[i].address,&obj[i].price,&obj[i].weight,&obj[i].calorie,&obj[i].evaluation)!=EOF) i++;
	
	if(select==1){
		for(j=0;j<i-1;j++){
			for(k=j+1;k<i;k++){
				if(obj[j].evaluation<obj[k].evaluation){
					tmp=obj[j];
					obj[j]=obj[k];
					obj[k]=tmp;
				}
			}
		}
		printf("排序後的資料:\n\n");
		for(j=0;j<i;j++) printf("%s \t%-10s \t%-40s \t%d \t%s \t%.2f \t%.1f\n",obj[j].foodType,obj[j].storeName,obj[j].address,obj[j].price,obj[j].weight,obj[j].calorie,obj[j].evaluation);
		system("pause");
	}
	else if(select==2){
		for(j=0;j<i-1;j++){
			for(k=j+1;k<i;k++){
				if(obj[j].price>obj[k].price){
					tmp=obj[j];
					obj[j]=obj[k];
					obj[k]=tmp;
				}
			}
		}
		printf("排序後的資料:\n\n");
		for(j=0;j<i;j++) printf("%s \t%-10s \t%-40s\n \t%d \t%s \t%.2f \t%.1f\n\n",obj[j].foodType,obj[j].storeName,obj[j].address,obj[j].price,obj[j].weight,obj[j].calorie,obj[j].evaluation);
		system("pause");
	}
	else{
		printf("Error!\n");
		return;
	}
}

void D0611117()
{
	char name[6][12];
	char tmp[60][12];
	int i=0,j,num,a = 0,data = 0,com,food_num,food_size = 0;
	FILE *input = fopen("SearchFoodType.txt","r");
	for(i=0;i<6;i++)
		memset(name[i],'\0',sizeof(name[i]));
	for(i=0;i<60;i++)
		memset(tmp[i],'\0',sizeof(tmp[i]));
	i = 0;
	while(fscanf(input,"%*s %s %*s %*s %*s %*s %*s\n",tmp[food_size]) != EOF)
	{
		food_size++;
	}

	
	do
	{
		system("cls");
		for(i = 0 ; i < food_size ; i++)
		{
			if(tmp[i][0] != '\0')
				printf("%d.%s\n",i+1,tmp[i]);
		}
		printf("======以上為可選取的店家======\n");
		
		printf("\n======已選取的店家======\n");
		for(i = 0 ; i < data ; i++)
		{
			printf("%s\n",name[i]);
		}
		
		printf("\n請確認你要執行的步驟\n0.停止輸入\n1.選取店家(最多6個)\n");
		scanf("%d",&com);
		if(com == 1)
		{
			printf("請輸入店家編號:");
			scanf("%d",&food_num);
			if(tmp[food_num-1][0] == '\0' || food_num < 1)
			{
				printf("\n無此資料\n");
			}
			else
			{
				printf("\n加入完成!\n");
				strcpy(name[data],tmp[food_num-1]);
				memset(tmp[food_num-1],'\0',sizeof(tmp[food_num-1]));
				data++;
			}
		}
		else if(com == 0)
			break;
		if(data == 6)
		{
			system("cls");
			printf("資料已滿!即將開始轉盤\n");
			printf("\n======將進入轉盤的店家======\n");
			for(i = 0 ; i < data ; i++)
			{
				printf("%s\n",name[i]);
			}
			Sleep(3000);
			break; 
		}
	}while(com != 0);
	
	if(data > 0) 
	{
		while(a != 1) 
		{	
			i = 0; 
			while(i<3)
			{ 
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****                   *****                          \n"
					   "                      ****                             ****                      \n"
					   "                   ****                                   ****                   \n"
					   "                ***                                           ***                \n"
					   "             ***  ＼                                          ／ ***             \n"
					   "           ***      ＼                                      ／     ***           \n"
					   "         ***          ＼                                  ／         ***         \n"
					   "       **               ＼                              ／              **       \n"
					   "      **                  ＼                          ／                 **      \n"
					   "     **                     ＼       %-10s     ／                    **     \n"
					   "    **    %-10s          ＼                  ／         %-10s    **    \n"
					   "   **                           ＼              ／                          **   \n"
					   "  **                              ＼          ／                             **  \n"
					   " **                                 ＼      ／                                ** \n"
					   " **                                   ＼  ／                                  ** \n"                             
					   " **←←←←←←←←←←←←←←←←←←← ←←←←←←←←←←←←←←←←←←** \n"
					   " **                                   ／  ＼                                  ** \n"
					   " **                                 ／      ＼                                ** \n"
					   "  **                              ／          ＼                             **  \n"
					   "   **                           ／              ＼                          **   \n"
			           "    **    %-10s          ／                  ＼         %-10s    **    \n"
					   "     **                     ／       %-10s     ＼                    **     \n"
					   "      **                  ／                          ＼                 **      \n"
					   "       **               ／                              ＼              **       \n"
					   "         ***          ／                                  ＼         ***         \n"
					   "           ***      ／                                      ＼     ***           \n"
					   "             ***  ／                                          ＼ ***             \n"
					   "                ***                                           ***                \n"
					   "                   ****                                   ****                   \n"
					   "                      ****                             ****                      \n"
					   "                          *****                   *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[1],name[0],name[2],name[5],name[3],name[4]);
				Sleep(200); 
				system("cls");
				  
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****         ｜        *****                          \n"
					   "                      ****              ｜             ****                      \n"
					   "                   ****                 ｜                ****                   \n"
					   "                ***                     ｜                    ***                \n"
					   "             ***  ↖                    ｜                       ***             \n"
					   "           ***      ↖      %-10s  ｜                         ***           \n"
					   "         ***          ↖                ｜                           ***         \n"
					   "       **               ↖              ｜                              **       \n"
					   "      **                  ↖            ｜           %-10s          **      \n"
					   "     **                     ↖          ｜                                **     \n"
					   "    **       %-10s       ↖        ｜                                 **    \n"
					   "   **                           ↖      ｜                                  **   \n"
					   "  **                              ↖    ｜                                   **  \n"
					   " **                                 ↖  ｜                                    ** \n"
					   " **                                   ↖｜                                    ** \n"                             
					   " **---------------------------------------------------------------------------** \n"
					   " **                                     ｜↖                                  ** \n"
					   " **                                     ｜  ↖                                ** \n"
					   "  **                                    ｜    ↖                             **  \n"
					   "   **                                   ｜      ↖                          **   \n"
			           "    **                                  ｜        ↖       %-10s      **    \n"
					   "     **                                 ｜          ↖                    **     \n"
					   "      **                                ｜            ↖                 **      \n"
					   "       **        %-10s             ｜              ↖              **       \n"
					   "         ***                            ｜    %-10s  ↖         ***         \n"
					   "           ***                          ｜                  ↖     ***           \n"
					   "             ***                        ｜                    ↖ ***             \n"
					   "                ***                     ｜                    ***                \n"
					   "                   ****                 ｜                ****                   \n"
					   "                      ****              ｜             ****                      \n"
					   "                          *****         ｜        *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[0],name[1],name[5],name[2],name[4],name[3]);
				Sleep(200); 
				system("cls");
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****         ↑        *****                          \n"
					   "                      ****              ↑             ****                      \n"
					   "                   ****                 ↑                ****                   \n"
					   "                ***      %-10s     ↑       %-10s   ***                \n"
					   "             ***  ＼                    ↑                    ／ ***             \n"
					   "           ***      ＼                  ↑                  ／     ***           \n"
					   "         ***          ＼                ↑                ／         ***         \n"
					   "       **               ＼              ↑              ／              **       \n"
					   "      **                  ＼            ↑            ／                 **      \n"
					   "     **                     ＼          ↑          ／                    **     \n"
					   "    **                        ＼        ↑        ／                       **    \n"
					   "   **                           ＼      ↑      ／                          **   \n"
					   "  **                              ＼    ↑    ／                             **  \n"
					   " **                                 ＼  ↑  ／                                ** \n"
					   " **                                   ＼↑／                                  ** \n"                             
					   " **            %-10s               ↑                %-10s          ** \n"
					   " **                                   ／↑＼                                  ** \n"
					   " **                                 ／  ↑  ＼                                ** \n"
					   "  **                              ／    ↑    ＼                             **  \n"
					   "   **                           ／      ↑      ＼                          **   \n"
			           "    **                        ／        ↑        ＼                       **    \n"
					   "     **                     ／          ↑          ＼                    **     \n"
					   "      **                  ／            ↑            ＼                 **      \n"
					   "       **               ／              ↑              ＼              **       \n"
					   "         ***          ／    %-10s  ↑    %-10s  ＼         ***         \n"
					   "           ***      ／                  ↑                  ＼     ***           \n"
					   "             ***  ／                    ↑                    ＼ ***             \n"
					   "                ***                     ↑                    ***                \n"
					   "                   ****                 ↑                ****                   \n"
					   "                      ****              ↑             ****                      \n"
					   "                          *****         ↑        *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[5],name[0],name[4],name[1],name[3],name[2]);
				Sleep(200); 
				system("cls");
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****         ｜        *****                          \n"
					   "                      ****              ｜             ****                      \n"
					   "                   ****                 ｜                ****                   \n"
					   "                ***                     ｜                    ***                \n"
					   "             ***                        ｜  %-10s        ↗ ***             \n"
					   "           ***                          ｜                  ↗     ***           \n"
					   "         ***                            ｜                ↗         ***         \n"
					   "       **                               ｜              ↗              **       \n"
					   "      **                                ｜            ↗     %-10s  **      \n"
					   "     **           %-10s            ｜          ↗                    **     \n"
					   "    **                                  ｜        ↗                       **    \n"
					   "   **                                   ｜      ↗                          **   \n"
					   "  **                                    ｜    ↗                             **  \n"
					   " **                                     ｜  ↗                                ** \n"
					   " **                                     ｜↗                                  ** \n"                             
					   " **---------------------------------------------------------------------------** \n"
					   " **                                   ↗｜                                    ** \n"
					   " **                                 ↗  ｜                                    ** \n"
					   "  **                              ↗    ｜                                   **  \n"
					   "   **                           ↗      ｜                                  **   \n"
			           "    **      %-10s        ↗        ｜                                 **    \n"
					   "     **                     ↗          ｜                                **     \n"
					   "      **                  ↗            ｜         %-10s            **      \n"
					   "       **               ↗              ｜                              **       \n"
					   "         ***          ↗     %-10s ｜                           ***         \n"
					   "           ***      ↗                  ｜                         ***           \n"
					   "             ***  ↗                    ｜                       ***             \n"
					   "                ***                     ｜                    ***                \n"
					   "                   ****                 ｜                ****                   \n"
					   "                      ****              ｜             ****                      \n"
					   "                          *****         ｜        *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[5],name[0],name[4],name[3],name[1],name[2]);
				Sleep(200); 
				system("cls");
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****                   *****                          \n"
					   "                      ****                             ****                      \n"
					   "                   ****                                   ****                   \n"
					   "                ***                                           ***                \n"
					   "             ***  ＼                                          ／ ***             \n"
					   "           ***      ＼                                      ／     ***           \n"
					   "         ***          ＼                                  ／         ***         \n"
					   "       **               ＼                              ／              **       \n"
					   "      **                  ＼                          ／                 **      \n"
					   "     **                     ＼      %-10s      ／                    **     \n"
					   "    **                        ＼                  ／                       **    \n"
					   "   **         %-10s        ＼              ／          %-10s      **   \n"
					   "  **                              ＼          ／                             **  \n"
					   " **                                 ＼      ／                                ** \n"
					   " **                                   ＼  ／                                  ** \n"                             
					   " **→→→→→→→→→→→→→→→→→→→ →→→→→→→→→→→→→→→→→→** \n"
					   " **                                   ／  ＼                                  ** \n"
					   " **                                 ／      ＼                                ** \n"
					   "  **                              ／          ＼                             **  \n"
					   "   **         %-10s        ／              ＼          %-10s      **   \n"
			           "    **                        ／                  ＼                       **    \n"
					   "     **                     ／      %-10s      ＼                    **     \n"
					   "      **                  ／                          ＼                 **      \n"
					   "       **               ／                              ＼              **       \n"
					   "         ***          ／                                  ＼         ***         \n"
					   "           ***      ／                                      ＼     ***           \n"
					   "             ***  ／                                          ＼ ***             \n"
					   "                ***                                           ***                \n"
					   "                   ****                                   ****                   \n"
					   "                      ****                             ****                      \n"
					   "                          *****                   *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[4],name[3],name[5],name[2],name[0],name[1]);
				Sleep(200); 
				system("cls"); 
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****         ｜        *****                          \n"
					   "                      ****              ｜             ****                      \n"
					   "                   ****                 ｜                ****                   \n"
					   "                ***                     ｜                    ***                \n"
					   "             ***  ↘                    ｜                       ***             \n"
					   "           ***      ↘                  ｜                         ***           \n"
					   "         ***          ↘      %-10s｜                           ***         \n"
					   "       **               ↘              ｜                              **       \n"
					   "      **                  ↘            ｜                               **      \n"
					   "     **                     ↘          ｜         %-10s             **     \n"
					   "    **                        ↘        ｜                                 **    \n"
					   "   **      %-10s           ↘      ｜                                  **   \n"
					   "  **                              ↘    ｜                                   **  \n"
					   " **                                 ↘  ｜                                    ** \n"
					   " **                                   ↘｜                                    ** \n"                             
					   " **---------------------------------------------------------------------------** \n"
					   " **                                     ｜↘                                  ** \n"
					   " **                                     ｜  ↘                                ** \n"
					   "  **                                    ｜    ↘                             **  \n"
					   "   **      %-10s                   ｜      ↘       %-10s         **   \n"
			           "    **                                  ｜        ↘                       **    \n"
					   "     **                                 ｜          ↘                    **     \n"
					   "      **                                ｜            ↘                 **      \n"
					   "       **                               ｜              ↘              **       \n"
					   "         ***                            ｜                ↘         ***         \n"
					   "           ***                          ｜    %-10s    ↘     ***           \n"
					   "             ***                        ｜                    ↘ ***             \n"
					   "                ***                     ｜                    ***                \n"
					   "                   ****                 ｜                ****                   \n"
					   "                      ****              ｜             ****                      \n"
					   "                          *****         ｜        *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[3],name[4],name[2],name[1],name[5],name[0]); 
				Sleep(200); 
				system("cls");
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****         ↓        *****                          \n"
					   "                      ****              ↓             ****                      \n"
					   "                   ****                 ↓                ****                   \n"
					   "                ***                     ↓                    ***                \n"
					   "             ***  ＼                    ↓                    ／ ***             \n"
					   "           ***      ＼      %-10s  ↓  %-10s      ／     ***           \n"
					   "         ***          ＼                ↓                ／         ***         \n"
					   "       **               ＼              ↓              ／              **       \n"
					   "      **                  ＼            ↓            ／                 **      \n"
					   "     **                     ＼          ↓          ／                    **     \n"
					   "    **                        ＼        ↓        ／                       **    \n"
					   "   **                           ＼      ↓      ／                          **   \n"
					   "  **                              ＼    ↓    ／                             **  \n"
					   " **                                 ＼  ↓  ／                                ** \n"
					   " **                                   ＼↓／                                  ** \n"                             
					   " **            %-10s               ↓              %-10s            ** \n"
					   " **                                   ／↓＼                                  ** \n"
					   " **                                 ／  ↓  ＼                                ** \n"
					   "  **                              ／    ↓    ＼                             **  \n"
					   "   **                           ／      ↓      ＼                          **   \n"
			           "    **                        ／        ↓        ＼                       **    \n"
					   "     **                     ／          ↓          ＼                    **     \n"
					   "      **                  ／            ↓            ＼                 **      \n"
					   "       **               ／              ↓              ＼              **       \n"
					   "         ***          ／                ↓                ＼         ***         \n"
					   "           ***      ／       %-10s ↓       %-10s ＼     ***           \n"
					   "             ***  ／                    ↓                    ＼ ***             \n"
					   "                ***                     ↓                    ***                \n"
					   "                   ****                 ↓                ****                   \n"
					   "                      ****              ↓             ****                      \n"
					   "                          *****         ↓        *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[2],name[3],name[1],name[4],name[0],name[5]);
				Sleep(200); 
				system("cls");
				printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****         ｜        *****                          \n"
					   "                      ****              ｜             ****                      \n"
					   "                   ****                 ｜                ****                   \n"
					   "                ***                     ｜                    ***                \n"
					   "             ***                        ｜     %-10s     ↙ ***             \n"
					   "           ***                          ｜                  ↙     ***           \n"
					   "         ***                            ｜                ↙         ***         \n"
					   "       **                               ｜              ↙              **       \n"
					   "      **                                ｜            ↙                 **      \n"
					   "     **           %-10s            ｜          ↙                    **     \n"
					   "    **                                  ｜        ↙                       **    \n"
					   "   **                                   ｜      ↙       %-10s         **   \n"
					   "  **                                    ｜    ↙                             **  \n"
					   " **                                     ｜  ↙                                ** \n"
					   " **                                     ｜↙                                  ** \n"                             
					   " **---------------------------------------------------------------------------** \n"
					   " **                                   ↙｜                                    ** \n"
					   " **                                 ↙  ｜                                    ** \n"
					   "  **                              ↙    ｜                                   **  \n"
					   "   **             %-10s    ↙      ｜                                  **   \n"
			           "    **                        ↙        ｜                                 **    \n"
					   "     **                     ↙          ｜                                **     \n"
					   "      **                  ↙            ｜               %-10s      **      \n"
					   "       **               ↙              ｜                              **       \n"
					   "         ***          ↙                ｜                           ***         \n"
					   "           ***      ↙                  ｜                         ***           \n"
					   "             ***  ↙      %-10s    ｜                       ***             \n"
					   "                ***                     ｜                    ***                \n"
					   "                   ****                 ｜                ****                   \n"
					   "                      ****              ｜             ****                      \n"
					   "                          *****         ｜        *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[2],name[1],name[3],name[0],name[4],name[5]);
				Sleep(200); 
				system("cls");
				i++; 
			} 
			i=5;
			printf("===============================《  食 物 轉 盤  》===============================\n"
					   "                               *******************                               \n"
					   "                          *****         ｜        *****                          \n"
					   "                      ****              ｜             ****                      \n"
					   "                   ****                 ｜                ****                   \n"
					   "                ***                     ｜                    ***                \n"
					   "             ***                        ｜     %-10s     ↙ ***             \n"
					   "           ***                          ｜                  ↙     ***           \n"
					   "         ***                            ｜                ↙         ***         \n"
					   "       **                               ｜              ↙              **       \n"
					   "      **                                ｜            ↙                 **      \n"
					   "     **           %-10s            ｜          ↙                    **     \n"
					   "    **                                  ｜        ↙                       **    \n"
					   "   **                                   ｜      ↙       %-10s         **   \n"
					   "  **                                    ｜    ↙                             **  \n"
					   " **                                     ｜  ↙                                ** \n"
					   " **                                     ｜↙                                  ** \n"                             
					   " **---------------------------------------------------------------------------** \n"
					   " **                                   ↙｜                                    ** \n"
					   " **                                 ↙  ｜                                    ** \n"
					   "  **                              ↙    ｜                                   **  \n"
					   "   **             %-10s    ↙      ｜                                  **   \n"
			           "    **                        ↙        ｜                                 **    \n"
					   "     **                     ↙          ｜                                **     \n"
					   "      **                  ↙            ｜               %-10s      **      \n"
					   "       **               ↙              ｜                              **       \n"
					   "         ***          ↙                ｜                           ***         \n"
					   "           ***      ↙                  ｜                         ***           \n"
					   "             ***  ↙      %-10s    ｜                       ***             \n"
					   "                ***                     ｜                    ***                \n"
					   "                   ****                 ｜                ****                   \n"
					   "                      ****              ｜             ****                      \n"
					   "                          *****         ｜        *****                          \n"
					   "                               *******************                               \n"
					   "                                                                                 \n",name[2],name[1],name[3],name[0],name[4],name[5]);
			if(data > 0) 
			{
				printf("抽籤中");
				while(1) 
				{
					srand(time(NULL)); 
					num = rand()%6;
					if(name[num][0] != '\0')
						break; 
				}
				
			}
	
			printf("===============================《  結果： %s  》===============================\n",name[num]);
			while(1)
			{
				if(kbhit())
				{
					i = 5; 
					do 
					{
						if(data > 1)
							printf("請確認\n1.確認結果\n2.重選\n"); 
						scanf("%d%*c",&a); 	
					}while(a != 1 && a != 2);
					if(a == 1)  
						break;
					else if(a == 2)
						break;
				} 
				printf("在%d秒內按下1.確認結果2.重選(5秒無選擇自動默認為確認)\n",i);
				i--;
				if(i < 0)
				{	
					a = 1; 
					break;
				} 
				Sleep(1000);
			}
			if(a == 2)
			{	
				if(data == 1)
				{	
					printf("已無資料\n");
					break;
				} 
				else 
				{
					strcpy(name[num],"\0");
					data--; 
				} 
			}
		}
	}
	else
	{
		printf("請先選取資料在開始轉盤\n");
	}
}

void D0642075(){	//收尋功能合集(讓坤堯直接COPY用) 
	Data data;
	data.import();
	data.SearchStoreName();
}

void D0641533(){
	SortFoodAndPrint();
}

void D0642339(){
	Data data;
	data.import();
	data.SearchFoodType();
}
