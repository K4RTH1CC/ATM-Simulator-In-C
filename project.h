void main_Menu();
void check_Balance(float balance);
float money_Deposit(float balance);
float money_Withdraw(float balance);
void menu_Exit();
void error_Message();
int pin_validity(char n[],char placeholder[]);
int card_validity(char n[]);
int aadhar_validity(char n[]);
int pan_validity(char n[]);
int new_pin_validity(char n[]);
void reader(char* data, int dataspace,FILE *fp);
void struct_to_file(int total_registers);
void file_to_struct(int total_registers);
int tot_registers();
void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char* res, int afterpoint);
struct Account{
    char pan[13];
    char aadhar[11];
    char bank_num[16];
    char pin_code[5];
    char bal[101];
    char act_disabled;
}A[100];