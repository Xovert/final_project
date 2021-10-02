#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "mergefin.h" //mergesort file
#include "binarysearch.h"//binarysearch file
#include "deposit-withdraw.h"//deposit-withdraw file

//structure Customer
typedef struct Customer{
	short int list;
	char user[54];
	char password[34];
	char name [255];
	double tabungan;
	int hari,tgl,tahun;
	int age;
	long long int NIK;
	bool registered;
}account;
//Global Variable
Customer customer [100];
int TOTAL_CUSTOMERS = 0;
int autonumber = 0;
char adminPass[] = {"admin"};

//Prototype Function
void addCustomer(Customer s);
void showChoices();
void mainMenu();
void Menu1(int n);
void Admin();
void create();
void withdraw();
void deposit(unsigned int dep);
int search();

//fungsi main
int main (){
	mainMenu();
	return 0;
}
void mainMenu();

void showChoices() { //Menunjukkan Menu
	puts("WELCOME TO MockUp BANK");
	puts ("1. Add Account");
	puts ("2. Withdraw");
	puts ("3. Deposit");
	puts ("4. Close Account");
	puts ("5. Admin");
	puts ("0. Exit");
}


void create(){//Menambahkan account
	account s;
	FILE *fp;
	fp = fopen ("list.txt", "a");
	printf ("Nama : ");
	scanf("%[^\n]", s.name); getchar();
	printf("Tanggal Lahir (dd/mm/yyyy) : ");
	scanf("%d/%d/%d", &s.hari, &s.tgl, &s.tahun); getchar();
	printf("NIK : ");
	scanf("%lld", &s.NIK); getchar();
	fwrite(&s, sizeof(account), 1, fp);
	fclose (fp);
	
}

void mainMenu (){//Fungsi Menu
	
	bool onBank = true;
	
	while (onBank) {
		
			showChoices();
			int choice;
			do {
				printf("Select : ");
				scanf("%d", &choice); getchar();
			} while (choice < 0 || choice > 5);
			
			switch (choice) {
				case 1 :{ //Add Acount
					autonumber++;
					account s;
					FILE *fp;
					fp = fopen ("list.txt", "a");
					printf ("Account name (no spaces): ");
					scanf("%s", s.user); getchar();
					printf ("Password: ");
					char ch;
					int i = 0;
					while ((ch=(char)_getch()) != '\r'){
						s.password[i] = ch;
						printf ("%c", ch);
						i++;
					}puts ("");
					printf ("Nama : ");
					scanf("%[^\n]", s.name); getchar();
					printf("Tanggal Lahir (dd/mm/yyyy) : ");
					scanf("%d/%d/%d", &s.hari, &s.tgl, &s.tahun); getchar();
					printf("NIK : ");
					scanf("%lld", &s.NIK); getchar();
					s.list = autonumber;
					s.age = 2021-s.tahun;
					s.registered= true;
					fwrite(&s, sizeof(account), 1, fp);
					fclose (fp);
					break;
				}
				case 2: { //Belum (Withdraw)
					
					break;
				}
				case 3: { //Belum (Deposit)
					char user[34];
					puts ("Please login");
					printf ("Username: ");
					scanf("%s", user);
					printf("%d", search());
//					unsigned int dep;
//					printf ("Select Amount you want to Deposit: ");
//					scanf("%lu", &dep);
					//void deposit(dep);
					break;
				}
				case 4: { //Belum (Remove Account)
					break;
				}
				case 5: { //Admin (Show Account)
					char passT[30];
					do {
						printf ("Please enter admin password: ");
						char ch;
						int i = 0;
						while ((ch=(char)_getch()) != '\r'){
						passT[i] = ch;
						i++;
						}
						fflush(stdin);
						if (strcmp(passT, adminPass)!=0){
							printf ("\nWrong Password\n");
						}
					}while (strcmp(passT, adminPass)!=0);
						printf ("Password Match");
					Admin();
					puts ("\nMenu");
					puts ("1. Sort by Age");
					puts ("2. Default List");
//					account s;
//					FILE *fp;
//					fp = fopen("list.txt", "r");
//					fseek(fp,0,SEEK_END);
//					int n = ftell(fp)/sizeof(account);
//					mergeSort(s.age, 0, n);
					break;
				}
				case 0: { //Exit Program
						printf ("Thank You and Goodbye!!! ");
						onBank = false;
					break;
				}
			}
	}
}


void Admin(){ //Main menu option 5.Admin (Show Account List)
	account s;
	FILE *fp;
	fp = fopen("list.txt", "r");
//  printf ("\nNo-5-15")
	while (fread(&s, sizeof(account),1,fp)){
		printf("\n%-5d%-15s", s.list, s.name);
		printf ("%5d%7.2f\n", s.age, s.tabungan);
	}
	fclose(fp);
}
	
void deposit(unsigned int dep){//fungsi Deposit, belum selesai.
	
}

/*int search(){   //Fungsi Search untuk mencari username, belum selesai.
	account s;
	char user[34];
	int found;
	FILE *fp;
	fp = fopen("list.txt", "r");
	printf ("Username : ");
	printf ("%s", user);
	while (fread(&s, sizeof(account),1,fp)){
		if (strcmp(s.user, user)==0) {
			found = 1;
			return s.list;
		}	
	}
	if (!found)
		return 1;
	fclose(fp);
}	*/
	
	
	
	

