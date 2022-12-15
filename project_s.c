#include<stdio.h>
#include<string.h>
#include"project.h"
#include<stdlib.h>
#include<math.h>


void main_Menu() 
{
    	printf("Welcome to ATM Banking\n\n");
    	printf("Please choose one of the options below\n\n");
    	printf("1 >  Check Balance\n");
    	printf("2 >  Deposit\n");
    	printf("3 >  Withdraw\n");
		printf("4 >  Check Account Status and Verify Aadhar or Pancard\n");
    	printf("5 >  Exit\n\n");
}

void check_Balance(float balance) 
{
	printf("You Choose to See your Balance\n");
   	printf("\n\nYour Available Balance is:   Rs%.2f\n\n", balance);
}

float money_Deposit(float balance) 
{
	float deposit;
    printf("You choose to Deposit a money\n");
    printf("Your Balance is: Rs%.2f\n\n", balance);
    printf("Enter your amount to Deposit\n");
    scanf("%f", &deposit);
    balance += deposit;
    printf("\nYour New Balance is:   Rs%.2f\n\n", balance);
    return balance;
}

float money_Withdraw(float balance) 
{
	float withdraw;
    	int c = 1;
    	printf("You choose to Withdraw a money\n");
    	printf("Your Balance is: Rs%.2f\n\n", balance);
 
    	while (c) 
	{
    		printf("Enter your amount to withdraw:\n");
    		scanf("%f", &withdraw);
    		if (withdraw < balance) 
		{
        		c = 0;
        		balance -= withdraw;
        		printf("\nYour withdrawing money is:  Rs%.2f\n", withdraw);
        		printf("Your New Balance is:   Rs%.2f\n\n", balance);
   		}
        	else  
		{
        		printf("You don't have enough money\n");
        		printf("Please contact to your Bank Customer Services\n");
        		printf("Your Balance is:   Rs%.2f\n\n", balance);
    		}
    	 }
   	 return balance;
}
void check_BankStatus(int n){
	if(n){printf("The account is activate");}
	else{printf("Your account has been deactivated, Please contact the bank for further notice");}
}
void menu_Exit() 
{
	printf("Take your receipt.\n");
    printf("Thank you for using ATM Banking Machine.\n");
}

void error_Message() 
{
	printf("You selected invalid number.\n");
}
int pin_validity(char n[],char placeholder[]){
    return(strcmp(n,placeholder));
}
int new_pin_validity(char n[]){
	return(strlen(n)==4);
}
int card_validity(char n[]){
	return(strlen(n)==15);
}
int aadhar_validity(char n[]){
	return(strlen(n)==10);
}
int pan_validity(char n[]){
	return(strlen(n)==12);
}

void struct_to_file(int total_registers){
    FILE *fp=fopen("register.txt","w");
    for(int i=0;i<total_registers;i++){
        fprintf(fp,"%-12s",A[i].pan);
        fprintf(fp,"%-10s",A[i].aadhar);
        fprintf(fp,"%-15s",A[i].bank_num);
        fprintf(fp,"%-4s",A[i].pin_code);
        fprintf(fp,"%-100s",A[i].bal);
        fprintf(fp,"%c",A[i].act_disabled);
    }
    fclose(fp);
}
void reader(char* data, int dataspace,FILE *fp){
    while(dataspace--){
        *data=fgetc(fp);
        data++;
    }
    *data='\0';
}
void file_to_struct(int total_registers){
    FILE *fp=fopen("register.txt","r");
    for(int i=0;i<total_registers;i++){
        reader(A[i].pan, 12,fp);
        reader(A[i].aadhar, 10,fp);
        reader(A[i].bank_num, 15,fp);
        reader(A[i].pin_code, 4,fp);
        reader(A[i].bal, 100,fp);
        A[i].act_disabled=fgetc(fp);
    }
    fclose(fp);
};

int tot_registers(){
	FILE *fp=fopen("register.txt","r");
	fseek(fp,0,SEEK_END);
	return ((int)ftell(fp)/142);
}
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while(x){
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
    while(i < d)
        str[i++] = '0';
  
    reverse(str, i);
    str[i] = '\0';
    return i;
}

void ftoa(float n, char* res, int afterpoint)
{
    int ipart = (int)n;
  	float fpart = n - (float)ipart;
  	int i = intToStr(ipart, res, 0);
  	if (afterpoint != 0) {
        res[i] = '.'; 
        fpart = fpart * pow(10, afterpoint);
  		intToStr((int)fpart, res + i + 1, afterpoint);
    }
}