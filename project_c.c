#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "project.h"


int main() 
{
	char Enter_card_num[100],Enter_pin[100];
	int Aadhar_check,Pan_check,Pin_check,Account_fully_verified,Prev_verified_account=0;
	int total_accounts = tot_registers(); 
	int selected_bankno;
	int limit=5;
	file_to_struct(total_accounts);
	
	while(1){
		printf("Please Enter your card number: ");
		gets(Enter_card_num);
		if(!card_validity(Enter_card_num)){printf("Card invalid\n");}
		else{printf("Card Valid\n");break;}
	}
	for(int i=0;i<total_accounts;i++){
		if(!(strcmp(A[i].bank_num,Enter_card_num))){
			selected_bankno=i;
			Prev_verified_account=1;
			break;
		}
	}
	if(!Prev_verified_account){
			selected_bankno=total_accounts;
			total_accounts++;
			strcpy(A[selected_bankno].bank_num,Enter_card_num);
			printf("Welcome to BPS bank\nPlease enter credentials here:\n");
			while(1){
				printf("Aadhar:");
				gets(A[selected_bankno].aadhar);
				if(!aadhar_validity(A[selected_bankno].aadhar)){printf("Aadhar card invalid\n");}
				else{printf("Card Identified\n");break;}
			}
			while(1){
				printf("PAN Card:");
				gets(A[selected_bankno].pan);
				if(!pan_validity(A[selected_bankno].pan)){printf("PAN card invalid\n");}
				else{printf("Card Identified\n");break;}
			}
			while(1){
				printf("Desired PIN(4 digits):");
				gets(A[selected_bankno].pin_code);
				if(!new_pin_validity(A[selected_bankno].pin_code)){printf("PIN Number is invalid\n");}
				else{printf("Card Identified\n");break;}
			}
			strcpy(A[selected_bankno].bal,"5000");
			A[selected_bankno].act_disabled='0';
	}
	if(Prev_verified_account){
		while(limit!=0){
			printf("Enter Your ATM Pincode:");
			gets(Enter_pin);
			if(!(pin_validity(Enter_pin,A[selected_bankno].pin_code))){
					printf("Bank access Accepted\n");
					Account_fully_verified=1;
					break;
				}
			else{printf("False PIN: Try Again.\n");limit--;}
			
		}
		if(limit==0){
			A[selected_bankno].act_disabled='1';
		}
	}
	
	if((Account_fully_verified&&A[selected_bankno].act_disabled=='0')||!Prev_verified_account){
		int sel_option;
		int choose;
		int aorp_option;
		int c=1;
		char aorp_check[13];
		float temp_bal=atof(A[selected_bankno].bal);
		while(c)
		{
					system("CLS");
					main_Menu();
		
					printf("------------------------------------------------------\n");
					printf("Your Selection:\t");
					scanf("%d", &sel_option);
					switch (sel_option){
							case 1:
								system("CLS");
								check_Balance(temp_bal);
								break;
							case 2:
								system("CLS");
								temp_bal = money_Deposit(temp_bal);
								break;
							case 3:
								system("CLS");
								temp_bal = money_Withdraw(temp_bal);
								break;
							case 4:
								system("CLS");
								if(A[selected_bankno].act_disabled=='0'){printf("The account is active\n");}
								printf("Enter 1> Aadhar Verification\nEnter 2>PAN verification\n==>");
								scanf("%d",&aorp_option);
								if(aorp_option==1){
									while(1){
										fflush(stdin);
										printf("Enter Aadhar number:");
										gets(aorp_check);
										if(!strcmp(aorp_check,A[selected_bankno].aadhar)){printf("Aadhar Verified");break;}
										else{printf("Aadhar not verified, Try again.\n");}
									}
								}
								else if(aorp_option==2){
									while(1){
										fflush(stdin);

										printf("Enter PAN card number:");
										gets(aorp_check);
										if(!strcmp(aorp_check,A[selected_bankno].pan)){printf("PAN Card Verified");break;}
										else{printf("PAN card not verified, Try again.\n");}
									}
								}
								else{printf("Invalid Option");}
								break;
							case 5:
								system("CLS");
								menu_Exit();
								break;
		
							default:
								error_Message();
								break;
					}
					printf("------------------------------------------------------\n");
					printf("Would you like to do another transaction:\n");
					printf("1 > Yes\n");
					printf("2 > No\n");
					scanf("%d", &choose);
					if (choose == 2){c = 0;menu_Exit();}
			
		}
		ftoa(temp_bal,A[selected_bankno].bal,2);
		struct_to_file(total_accounts);
	}
	else{
		printf("Your account was Deactivated, Please contact your bank for further details.");
		struct_to_file(total_accounts);
	}
	return 0;
}