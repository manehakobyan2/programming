#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
//adding header files
#include "auth.h"
#include "slot_manage.h"

#define MAX_INPUT 100

//function for scanf to avoid infinte loops
void clear_input_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


int main() 
{
   //first pointng to data base
    sqlite3* db;
    //return code 
    int rc = sqlite3_open("bitcart.db", &db);
    //checking for failur when opening the database
    if (rc != SQLITE_OK) {
        //print the error message
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    //After opening the database was succesful
    // Create tables if the tables  dont already exist(defined in init.sql file)
    create_users_table(db);
    create_slots_table(db);
    

   //storing users choice
    int choice;
    // log in status 
    int logged_in = 0;
    // storing user id (-1) to inccate no one is logged in
    int user_id = -1;
    // arrays to store username and password
    char username[MAX_INPUT];
    char password[MAX_INPUT];
 
   //loop till the user is still logged in 
    while (!logged_in) 
    {
       //header
        printf("\n--- Bitcart ---\n");
        //options
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
         
        if (scanf("%d", &choice) != 1) 
        {
            clear_input_buffer();
            printf("Invalid input. Try again.\n");
            continue;
        }
        clear_input_buffer();
        
        //using switch for every choice
        switch (choice) {
           //if register is chosen  
            case 1:
                //asking for input
                printf("Enter username: ");
                //reading input
                fgets(username, sizeof(username), stdin);
                // remove newline trailing and copy that to username
                username[strcspn(username, "\n")] = 0;
                 
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0;

               //function returns 1 when succesful if 1 then printing this
                if (register_user(db, username, password)) 
                 {
                    printf("Registration successful! Please login.\n");
                } 
               else 
                 {
                    
                    printf("Registration failed. Username may already exist.\n");
                }
                break;

            case 2:

                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;

                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0;
                
               //using the function login user to check if the login was succesful
                if (login_user(db, username, password, &user_id)) {
                    printf("Login successful! Welcome, %s.\n", username);
                    logged_in = 1;
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;

                
            case 3:
               //close the data base finish with program
                printf("Goodbye!\n");
                sqlite3_close(db);
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    // menu after login 
    while (1) 
    {
        //Header
        printf("\n--- Bitcart Menu ---\n");
        //Options
        printf("1. View total balance\n");
        printf("2. View slots\n");
        printf("3. Create a slot\n");
        printf("4. Delete a slot\n");
        printf("5. Transfer money to slot\n");
        printf("6. Withdraw money from slot\n");
        printf("7. Logout\n");
        printf("Enter choice: ");
 
        //check user input 
        if (scanf("%d", &choice) != 1) 
        { 
            clear_input_buffer();
            printf("Invalid input. Try again.\n");
            continue;
        }
        clear_input_buffer();

       //if user chose to log out
        if (choice == 7) 
        {
            
            printf("You're loged out.\n");
            //change variable for cheking login to 0               
            logged_in = 0;
            //intialize user id to -1 to remove users
            user_id = -1;
            break;
        }
      
        switch (choice) 
        {
            case 1: 
            {   
                //define variable balance and set it to balance from database
                double balance = get_total_balance(db, user_id);
                printf("Your total balance: %.2f\n", balance);
                break;
            }
             
            case 2:
                //use function view slots which displays the slots user has
                view_slots(db, user_id);
                break;

            case 3: 
            {
                //creating slot
                //creating string array for slot name
                char slot_name[MAX_INPUT];
                //prompt
                printf("Enter new slot name: ");
                //scan and remove \n 
                fgets(slot_name, sizeof(slot_name), stdin);
                slot_name[strcspn(slot_name, "\n")] = 0;
                //check if creating slot was succesful
                if (create_slot(db, user_id, slot_name)) 
                {
                    printf("Slot '%s' created successfully.\n", slot_name);
                } 
                else 
                {
                    printf("Failed to create slot. It may already exist.\n");
                }
                break;
            }

            case 4: 
            {
                char slot_name[MAX_INPUT];
                printf("Enter slot name to delete: ");
                fgets(slot_name, sizeof(slot_name), stdin);
                slot_name[strcspn(slot_name, "\n")] = 0;
                //using the function check if deltetion was succesful

                if (delete_slot(db, user_id, slot_name)) 
                {
                    printf("Slot '%s' deleted successfully.\n", slot_name);
                } 
                else 
                {
                    printf("Failed to delete slot. Check if it exists.\n");
                }
                break;
            }

            //transfering money to slot
            case 5: 
            {
                char slot_name[MAX_INPUT];
                double amount;
                printf("Enter slot name to transfer money to: ");
                fgets(slot_name, sizeof(slot_name), stdin);
                slot_name[strcspn(slot_name, "\n")] = 0;

                printf("Enter amount to transfer: ");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    clear_input_buffer();
                    printf("Invalid amount.\n");
                    break;
                }
                clear_input_buffer();

                if (transfer_to_slot(db, user_id, slot_name, amount)) 
                {
                    printf("Transferred %.2f to slot '%s'.\n", amount, slot_name);
                } 
                else 

                {
                    printf("Transfer failed. Check balance or slot name.\n");
                }
                break;
            }

            case 6: 
            {
                char slot_name[MAX_INPUT];
                double amount;
                printf("Enter slot name to withdraw money from: ");
                
                fgets(slot_name, sizeof(slot_name), stdin);
                slot_name[strcspn(slot_name, "\n")] = 0;

                printf("Enter amount to withdraw: ");
                
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    clear_input_buffer();
                    printf("Invalid amount.\n");
                    break;
                }
                clear_input_buffer();

                if (transfer_from_slot(db, user_id, slot_name, amount)) 
                {
                    printf("Withdrew %.2f from slot '%s'.\n", amount, slot_name);
                } 
                else 
                {
                    printf("Withdrawal failed. Check slot balance or name.\n");
                }
                break;
            }

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    //close and finish function
    sqlite3_close(db);
    return 0;
}

