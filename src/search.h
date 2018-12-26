#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

typedef struct element{
	char foodType[64];	//食物種類 
	char storeName[64];	//商家名稱 
	char address[64];	//地址 
	int price;	//價格 
	char weight[64];	//份量(網址)  
	float calorie;	//卡洛里 
	float evaluation;	//評價 
}Element;

typedef struct data{
	Element* num[200]; 
	int size;
	void import();	//從資料庫讀檔 
	void show();	//顯示資料庫全部內容 
	void SearchStoreName();	//輸入商家名稱並顯示相關資訊在console上 
	void SearchFoodType();	//輸入食物種類並將相關內容輸出為"SearchFoodType.txt" 
}Data;

void D0611117();
void D0642339();
void D0641533();
void D0642075();
