/*
 * app.c
 *
 *  Created on: Sep 16, 2019
 *      Author: Newname
 */

#include "MCAL/DIO.h"
#include "HAL/LCD.h"
#include "HAL/EKEY_PAD.h"
#include "macros.h"
#include "types.h"
#include "EBOOKS.h"
#include "EMEMBERS.h"
#include <util/delay.h>


void DISPLAY_OnDemand(char *str1, char *str2);


int main(void)
{
	LCD_vidInitialize();
	BOOKS_vidInitialize();
	LinkedList_vidInitialize();

	LinkedList_vidInsertion("1", "Mohamed");
	LinkedList_vidInsertion("2", "John");
	LinkedList_vidInsertion("11", "Mark");
	LinkedList_vidInsertion("13", "Rose");
	LinkedList_vidInsertion("15", "Sarah");
	LinkedList_vidInsertion("18", "Aya");
	LinkedList_vidInsertion("20", "Mona");
	LinkedList_vidInsertion("4", "Newname");
	LinkedList_vidInsertion("12", "Joey");


	BOOKS_vidInsertion("019", "Charles Dickens", 5);	//281785
	BOOKS_vidInsertion("025", "Paulo Coelho", 5);		//486198
	BOOKS_vidInsertion("033", "Emily Bronte", 5);		//010690
	BOOKS_vidInsertion("058", "Jane Eyre", 5);			//207719
	BOOKS_vidInsertion("075", "Eileen Power", 5);		//149253
	BOOKS_vidInsertion("111", "The Zahir", 5);	//281785
	BOOKS_vidInsertion("222", "The Alchemist", 5);		//486198
	BOOKS_vidInsertion("333", "For one more Day", 5);		//010690
	BOOKS_vidInsertion("444", "Hard times", 5);			//207719
	BOOKS_vidInsertion("555", "Stands alone", 5);		//149253

	//BOOKS_show();
	//LinkedList_show();

	while(1)
	{
		LCD_vidClearOnDemand(1, 32);

		DISPLAY_OnDemand("1-INSER BOOK", "2-INSER MEMBER");

		DISPLAY_OnDemand("3-BORROW BOOK", "4-RETURN BOOK");

		DISPLAY_OnDemand("5-Show all books", "6-Show all members");

		DISPLAY_OnDemand("7-Member's INFO.", "                 ");

		LCD_String("OPERATION NO. :");
		LCD_vidGoTo(1, 2);


		KeyPad_vidInitialize();

		if(DEAD_SIGNAL_TERMINATE)
		{
			DEAD_SIGNAL_TERMINATE = 0;

			// Reset pointers to the head ot its linked list
			restart_vip();
			BOOKS_restart_vip();

			// Delete the whole data base
			LinkedList_u8DeleteEntire();
			BOOKS_u8DeleteEntire();
			break;
		}
	}
}

void DISPLAY_OnDemand(char *str1, char *str2)
{
	LCD_vidClearOnDemand(1, 32);
	// Display 1st string
	LCD_vidGoTo(1, 1);
	LCD_String(str1);
	// Display 2nd string
	LCD_vidGoTo(1, 2);
	LCD_String(str2);

	_delay_ms(1300);
	// Clear whole display
	LCD_vidClearOnDemand(1, 32);
}

