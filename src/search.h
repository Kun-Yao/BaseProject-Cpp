#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

typedef struct element{
	char foodType[64];	//�������� 
	char storeName[64];	//�Ӯa�W�� 
	char address[64];	//�a�} 
	int price;	//���� 
	char weight[64];	//���q(���})  
	float calorie;	//�d���� 
	float evaluation;	//���� 
}Element;

typedef struct data{
	Element* num[200]; 
	int size;
	void import();	//�q��ƮwŪ�� 
	void show();	//��ܸ�Ʈw�������e 
	void SearchStoreName();	//��J�Ӯa�W�٨���ܬ�����T�bconsole�W 
	void SearchFoodType();	//��J���������ñN�������e��X��"SearchFoodType.txt" 
}Data;

void D0611117();
void D0642339();
void D0641533();
void D0642075();
