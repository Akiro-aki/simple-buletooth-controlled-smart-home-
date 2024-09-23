/*
 * main.c
 *
 *  Created on: Aug 12, 2024
 *      Author: walid
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Config.h"

#include "HAL/BUZZER/BUZ_Interface.h"
#include "HAL/BUZZER/BUZ_Config.h"

#include "HAL/LED/LED_Interface.h"
#include "HAL/LED/LED_Config.h"

#include "HAL/SEL/SEL_Interface.h"
#include "HAL/SEL/SEL_Config.h"

#include "HAL/BLUETOOTH/BLTH_Interface.h"
#include "HAL/BLUETOOTH/BLTH_Config.h"
#include <util/delay.h>

#include "string.h"
#define F_CPU   8000000UL

typedef struct {
    char username[50];
    char password[50];
} User;

	User users[10] = {
		        {"user1", "pass1"},
		        {"user2", "pass2"},
		        {"user3", "pass3"},
		        {"user4", "pass4"},
		        {"user5", "pass5"},
		        {"user6", "pass6"},
		        {"user7", "pass7"},
		        {"user8", "pass8"},
		        {"user9", "pass9"},
		        {"user10", "pass10"}
		};

int authenticate(User users[], int num_users, char* username, char* password);




int main(){

//	LED_Init();
//	SEL_Init();
//	Buzzer_Init();
//    _delay_ms(2000);



//====================================================================================

	/*BUZZER*/
		Buzzer_Init();
	/*LED*/
		LED_Init();
	/*SELNOID*/
		SEL_Init();

    /*UART*/
		BLTH_Init();


		u8 welcome_message[]="Hello Enter User";
		u8 Enter_Pass[]="Enter Password";
		u8 error[]="User Not Found";

		u8 user_Enter[7];
		u8 pas_Enter[5];


		u8 receive;
		u8 choice = 0;

		u16 login_flag=3;
		u16 logout_flag=0;



         while(login_flag>0){

       // enter username
        	 	 BLTH_SendString(welcome_message);

				  for(int i = 0 ; i < 7 ; i++)
				  {
					  //to store string from uart in user_enter
					  receive = BLTH_ReceiveData();
					  user_Enter[i]=receive;
				  }
        //=========================================

		// enter password
				  BLTH_SendString(Enter_Pass);

				 for(int i = 0 ; i<5 ; i++)
				 {
				 		// to store password in pasenter
				 		receive = BLTH_ReceiveData();
				 		pas_Enter[i]=receive;
				 }
				 if(authenticate(users, 10, user_Enter, pas_Enter)){
        //=========================================

        // available options
				BLTH_SendString("This Is Your choices \n"
							  	  "D-> To open Door \n"
							  	  "L-> To close Door \n"
							  	  "F-> To on Led \n"
							  	  "K-> To off Led \n"
							  	  "E-> Log Out");

//					  BLTH_SendString("D-> To open Door");
//					  BLTH_SendString("L-> To close Door");
//					  BLTH_SendString("F-> To on Led");
//					  BLTH_SendString("K-> To off Led");
//					  BLTH_SendString("E-> Log Out");
        // take input from user
                      choice = BLTH_ReceiveData();
        // switch case for options
					  switch(choice)
					  			  {
					  			  case 'D' :

					  				  SEL_On();
					  				  break;

					  			  case 'L' :

					  				  SEL_Off();
					  				  break;

					  			  case 'F' :

					  				  LED_On();
					  				  break;

					  			  case 'K' :

					  				  LED_Off();
					  				  break;

					  			  case 'E' :      // to exit program

					  				 logout_flag=1;
					  				  break;

					  			  default:      // else

					  				BLTH_SendString("Enter right choice");
					  				  break;
					  			  }

				 }else{  // wrong login
					 BLTH_SendString(error);
					 login_flag--;
				 }
				 // check logout == 1
				 if(logout_flag){
					 // exit
					 return 0;
				 }

}
         // out of while loop

         // if login happened 3 times
         if(login_flag==0){

        	 Buzzer_On();
        	 _delay_ms(10000);
        	 Buzzer_Off();
         }

     	return 0;

}

int authenticate(User users[], int num_users, char* username, char* password) {


		for (int i = 0; i < num_users; i++) {
					if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
					          return 1;
					}else{
						return 0;
					}
		}

return 0;
}
