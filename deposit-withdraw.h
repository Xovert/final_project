void deposit() {
	int d;
	printf("How much do you want to deposit : ");
	scanf("%d", &d);
}

void withdraw()
	int w;
	printf("How much do you want to withdraw : ");
	scanf("%d", &w);
	if ( w > saldo ){
		printf("The amount of withdrawal you input have execeeded the amount you have. \n");
		
			int choice1;
				printf("\n1. Back to main menu\n");
				printf("2. Go back to withdraw menu\n");
					scanf("%d", &choice1);
					if ( choice1 == 1 ){
						void MainMenu();
					}
					else if ( choice1 == 2){
						void withdraw();
					}
	}
	else if ( w == saldo ){
		printf("The amount of withdrawal you input is equal to all the fund you have in this account. ");
		
			int choice2;
				printf("\n1. Cancel and Go Back to main menu\n");
				printf("2. Cancel and Go Back to withdraw menu\n");
					scanf("%d", &choice2);
					if ( choice2 == 1 ){
						void MainMenu();
					}
					else if ( choice2 == 2 ){
						void withdraw();
					}
	}
	else if ( w < saldo ){
		printf("The amount of withdrawal is %d \n", w);
		printf("1. Yes and Continue\n");
		printf("2. Cancel and Go Back to withdraw menu\n");
		puts(" ");
		printf("Enter your choice : ");
			int choice3;
				scanf("%d", &choice3);
					if ( choice3 == 1 ){
						
						saldo = saldo - w;
						
						puts("\nWithdrawal has been done!");
						puts("Thank You for choosing our service!");
						puts(" ");
						puts("1. Continue to withdraw menu");
						puts("2. Countinue to main menu");
							
							int choice3_1;
								if ( choice3_1 == 1 ){
									void withdraw();
								}
								else if ( choice3_1 == 2 ){
									void MainMenu();
								}
					}
					else if ( choice3 == 2 ){
						void withdraw();
					}
	}
}









	
	
	

