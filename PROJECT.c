#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main_portal();
void candidate_list();
void error();
void error1();
void admin_pass();
void voter_names();
void voting_results();
void admin_portal();
void live_voting();
void votes_after_results();

char a_[] = " 1" , b_[] = " 2" , c_[] = " 3" , d_[] = " 4" , e_[] = " 5" ;
char f_[] = " 6" , g_[] = " 7" , h_[] = " 8" , i_[] = " 9" , j_[] = " 10" ;

char voter_check[20] = {"$"};

int CANDIDATE1_recieved=0 , CANDIDATE2_recieved=0 , NOTA_recieved=0;
#define CANDIDATE1 "PREETHAM"
#define CANDIDATE2 "PREM"
#define NOTA "NOTA"

// live voting
void live_voting(){
    printf("\n### live votes ###\n");
    printf("\n%s WITH %d VOTES" , CANDIDATE1, CANDIDATE1_recieved);
    printf("\n%s WITH %d VOTES" , CANDIDATE2, CANDIDATE2_recieved);
    printf("\nNO. OF VOTES SPOILED %d \n\n" , NOTA_recieved );
    admin_portal();
}

// VOTES RECIEVED BY ANOTHER CANDIDATES
void votes_after_results(){
    printf("\n### votes ###\n");
    printf("\n%s WITH %d VOTES" , CANDIDATE1, CANDIDATE1_recieved);
    printf("\n%s WITH %d VOTES" , CANDIDATE2, CANDIDATE2_recieved);
    printf("\nNO. OF VOTES SPOILED : %d\n\n" , NOTA_recieved );
}

//ADMIN PORTAL
void admin_portal(){
    int option;
    printf("\n1.VOTING RESULTS\n");
    printf("2.LIVE RESULTS\n");
    printf("3.BACK");
    printf("ENTER YOUR RESPONSE : ");
    scanf("%d" , &option);
    switch(option){
        case 1 : voting_results(); break;
        case 2 : live_voting(); break;
        case 3 : main_portal(); break;
        default : printf("PLEASE ENTER A VALID NUMBER");
    }

}

//VOTING RESULTS
void voting_results(){
    printf ("\n### VOTING RESULTS ###\n\n");
    if(CANDIDATE1_recieved > CANDIDATE2_recieved && CANDIDATE1_recieved > NOTA_recieved){
        printf("\033[92m");
        printf("%s HAS WON THE ELECTIONS WITH %d VOTES\n\n", CANDIDATE1,CANDIDATE1_recieved);
        printf("\033[0m");
    }
    else if( NOTA_recieved == CANDIDATE2_recieved && CANDIDATE1_recieved == NOTA_recieved){
        printf("\033[91m");
        printf("NO. OF VOTES RECIEVED BY BOTH THE COMPETITORS AND NO. OF VOTES SPOILED ARE EQUAL \n");
        printf("IT'S TIME FOR THE RE-ELECTION\n\n");
        printf("\033[0m");
    }
    else if(NOTA_recieved > CANDIDATE2_recieved && CANDIDATE1_recieved < NOTA_recieved){
        printf("\033[91m");
        printf("MOST OF THE VOTES WERE SPOILED\n");
        printf("IT'S TIME FOR THE RE-ELECTION\n\n");
        printf("\033[0m");
    }
    else if(CANDIDATE1_recieved > NOTA_recieved && CANDIDATE2_recieved > NOTA_recieved && CANDIDATE1_recieved == CANDIDATE2_recieved ){
        printf("\033[91m");
        printf("BOTH THE COMPETITORS HAS RECIEVED SAME NUMBER OF VOTES\n");
        printf("IT'S TIME FOR THE RE-ELECTION\n\n");
        printf("\033[0m");
    }
    else if(CANDIDATE1_recieved < CANDIDATE2_recieved && CANDIDATE2_recieved > NOTA_recieved){
        printf("\033[92m");
        printf("%s HAS WON THE ELECTIONS WITH %d VOTES\n\n", CANDIDATE2,CANDIDATE2_recieved);
        printf("\033[0m");
    }

    votes_after_results();
}

//error program
void error(){
    int else9;
    printf ("\nSESSION TERMINATED\n\n");
    printf ("ENTER 1 TO RETURN TO MAIN PORTAL\n");
    printf ("ENTER 2 TO RETURN TO VOTER PORTAL\n");
    // printf ("ENTER 0 TO STOP\n");
    printf ("ENTER YOUR RESPONSE HERE : ");
    scanf("%d", &else9);
    switch(else9){
        case 1 : main_portal();break;
        case 2 : voter_names();break;
        // case 3 : printf("THANKYOU\n");break;
        return ; printf("PLEASE ENTER A VALIED NUMBER\n"); void error();
    }
}

void error1(){
    int else9;
    printf ("\nSESSION TERMINATED\n\n");
    printf ("ENTER 1 TO RETRY\n");
    printf ("ENTER 2 TO RETURN TO MAIN PORTAL\n");
    // printf ("ENTER 0 TO STOP\n");
    printf ("ENTER YOUR RESPONSE HERE : ");
    scanf("%d", &else9);
    switch(else9){
        case 1 : admin_pass();break;
        case 2 : main_portal();break;
        // case 3 : printf("THANKYOU\n");break;
        return ; printf("PLEASE ENTER A VALIED NUMBER\n"); void error1();
    }
}


//MAIN PORTAL

void admin_pass(){
    char username[30] = {'L','A','K','S','H','M','A','N'};
    char user_check[30];
    printf("\nUSERNAME : ");
    scanf ("%s" , &user_check);
    if(strcmp(username,user_check)==0){
        char password[30] = {'L','A','K','S','H','M','A','N','1','2','3'};
        char pass_check[30];
        printf ("ENTER THE PASSWORD : ");
        scanf ("%s" , &pass_check);
        if (strcmp(password,pass_check) == 0){
            admin_portal();
        }
        else {
            error1();
        }
    }

    else{
        error1();
    }

}

//candidate list
void candidate_list() {
    int a;
    printf("\n\n ### Please choose your Candidate ####\n\n");
    printf("1. %s\n", CANDIDATE1);
    printf("2. %s\n", CANDIDATE2);
    printf("3. %s\n", NOTA);
    printf("ENTER THE NUMBER BASED ON YOUR CHOICE (1-3) :");
    scanf("%d" , &a);
    switch(a){
        case 1 : CANDIDATE1_recieved++ , printf("\n### THANKYOU FOR VOTING ###\n\n"); main_portal(); break;
        case 2 : CANDIDATE2_recieved++ , printf("\n### THANKYOU FOR VOTING ###\n\n"); main_portal(); break;
        case 3 : NOTA_recieved++ ,  printf("\n### THANKYOU FOR VOTING ###\n\n"); main_portal(); break;
        default : printf("PLEASE ENTER A VALID NUMBER\n\n"); candidate_list();

    }

}


//VOTERS
//VOTER 1
void PREETHAM_V1(){
    char VOTER1_USERNAME[30] = {'2','2','1','8','0','1','3','5','0','0','0','7'};
    char VOTER1_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER1_USERNAME_TALLY);
    if (strcmp(VOTER1_USERNAME,VOTER1_USERNAME_TALLY)==0){
        char VOTER1_PASSWORD[20] = {'P','R','E','E','T','H','A','M','@'};
        char VOTER1_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER1_PASSWORD_TALLY);
        if (strcmp(VOTER1_PASSWORD,VOTER1_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','1'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,a_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }

    else{
        error();
    }
}


//VOTER 2
void PREM_V2(){
    char VOTER2_USERNAME[30] = {'2','2','1','8','0','1','3','9','0','0','0','8'};
    char VOTER2_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER2_USERNAME_TALLY);
    if (strcmp(VOTER2_USERNAME,VOTER2_USERNAME_TALLY)==0){
        char VOTER2_PASSWORD[20] = {'P','R','E','M','@'};
        char VOTER2_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER2_PASSWORD_TALLY);
        if (strcmp(VOTER2_PASSWORD,VOTER2_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','2'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,b_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }
    else{
        error();
    }
}


//VOTER 3
void BHASKAR_V3(){
    char VOTER3_USERNAME[30] = {'2','2','1','8','0','1','3','5','0','0','1','9'};
    char VOTER3_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER3_USERNAME_TALLY);
    if (strcmp(VOTER3_USERNAME,VOTER3_USERNAME_TALLY)==0){
        char VOTER3_PASSWORD[20] = {'B','H','A','S','K','A','R','@'};
        char VOTER3_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER3_PASSWORD_TALLY);
        if (strcmp(VOTER3_PASSWORD,VOTER3_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','3'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,c_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }
    else{
        error();
    }
}


//VOTER 4
void ROHITH_V4(){
    char VOTER4_USERNAME[30] = {'2','2','1','8','0','1','3','5','0','0','1','7'};
    char VOTER4_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER4_USERNAME_TALLY);
    if (strcmp(VOTER4_USERNAME,VOTER4_USERNAME_TALLY)==0){
        char VOTER4_PASSWORD[20] = {'R','O','H','I','T','H','@'};
        char VOTER4_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER4_PASSWORD_TALLY);
        if (strcmp(VOTER4_PASSWORD,VOTER4_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','4'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,d_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }

    else{
        error();
    }
}


//VOTER 5
void SAI_KIRAN_V5(){
    char VOTER5_USERNAME[30] = {'2','2','1','8','0','1','3','5','0','0','0','2'};
    char VOTER5_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER5_USERNAME_TALLY);
    if (strcmp(VOTER5_USERNAME,VOTER5_USERNAME_TALLY)==0){
        char VOTER5_PASSWORD[20] = {'S','A','I','K','I','R','A','N','@'};
        char VOTER5_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER5_PASSWORD_TALLY);
        if (strcmp(VOTER5_PASSWORD,VOTER5_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','5'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,e_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }

    else{
        error();
    }
}


//VOTER 6
void SANDESH_V6(){
    char VOTER6_USERNAME[30] = {'2','2','1','8','0','1','3','9','0','0','0','3'};
    char VOTER6_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER6_USERNAME_TALLY);
    if (strcmp(VOTER6_USERNAME,VOTER6_USERNAME_TALLY)==0){
        char VOTER6_PASSWORD[20] = {'S','A','N','D','E','S','H','@'};
        char VOTER6_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER6_PASSWORD_TALLY);
        if (strcmp(VOTER6_PASSWORD,VOTER6_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','6'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,f_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }

    else{
        error();
    }
}


//VOTER 7
void CHARAN_V7(){
    char VOTER7_USERNAME[30] = {'2','2','1','8','0','1','3','5','0','0','1','1'};
    char VOTER7_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER7_USERNAME_TALLY);
    if (strcmp(VOTER7_USERNAME,VOTER7_USERNAME_TALLY)==0){
        char VOTER7_PASSWORD[20] = {'C','H','A','R','A','N','@'};
        char VOTER7_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER7_PASSWORD_TALLY);
        if (strcmp(VOTER7_PASSWORD,VOTER7_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','7'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,g_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }

    else{
        error();
    }
}


//VOTER 8
void SRIYA_V8(){
    char VOTER8_USERNAME[30] = {'2','2','1','8','0','1','3','6','0','0','1','3'};
    char VOTER8_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER8_USERNAME_TALLY);
    if (strcmp(VOTER8_USERNAME,VOTER8_USERNAME_TALLY)==0){
        char VOTER8_PASSWORD[20] = {'S','R','I','Y','A','@'};
        char VOTER8_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER8_PASSWORD_TALLY);
        if (strcmp(VOTER8_PASSWORD,VOTER8_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','8'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,h_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }

    else{
        error();
    }
}


//VOTER 9
void MADHURI_V9(){
    char VOTER9_USERNAME[30] = {'2','2','1','8','0','1','3','5','0','0','1','0'};
    char VOTER9_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER9_USERNAME_TALLY);
    if (strcmp(VOTER9_USERNAME,VOTER9_USERNAME_TALLY)==0){
        char VOTER9_PASSWORD[20] = {'M','A','D','U','R','I','@'};
        char VOTER9_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER9_PASSWORD_TALLY);
        if (strcmp(VOTER9_PASSWORD,VOTER9_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','9'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,i_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }
    else{
        error();
    }
}


//VOTER 10
void NIHARIKA_V10(){
    char VOTER10_USERNAME[30] = {'2','2','1','8','0','1','3','5','0','0','0','8'};
    char VOTER10_USERNAME_TALLY[30];
    printf("\nUSERNAME : ");
    scanf("%s" , &VOTER10_USERNAME_TALLY);
    if (strcmp(VOTER10_USERNAME,VOTER10_USERNAME_TALLY)==0){
        char VOTER10_PASSWORD[20] = {'N','I','H','A','R','I','K','A','@'};
        char VOTER10_PASSWORD_TALLY[20];
        printf ("ENTER THE PASSWORD : ");
        scanf("%s" , &VOTER10_PASSWORD_TALLY);
        if (strcmp(VOTER10_PASSWORD,VOTER10_PASSWORD_TALLY) == 0){
            char VOTER1_FP[5] = {'@','1','0'};
            char VOTER1_FP_TALLY[5];
            printf("\nPLACE YOUR FINGRER ON THE CENSOR : ");
            scanf("%s" , &VOTER1_FP_TALLY);
            if(strcmp (VOTER1_FP,VOTER1_FP_TALLY)==0){
                printf("ACCESS GRANTED\n");
                strcat(voter_check,j_);printf("%s" ,voter_check);
                candidate_list();
            }
            else {
                error();
            }
        }
        else{
            error();
        }
    }

    else{
        error();
    }
}


//voter names
void voter_names(){
    #define voter_1 "PREETHAM"
    #define voter_2 "PREM"
    #define voter_3 "BHASKAR"
    #define voter_4 "ROHITH"
    #define voter_5 "SAI KIRAN"
    #define voter_6 "SANDESH"
    #define voter_7 "CHARAN"
    #define voter_8 "SRIYA"
    #define voter_9 "MADHURI"
    #define voter_10 "NIHARIKA"
    
    int vote_num;
    char ch[3];
    printf("\n\n ### SELECT YOUR NAME ###\n");
    printf("1. %s\n" , voter_1);
    printf("2. %s\n" , voter_2);
    printf("3. %s\n" , voter_3);
    printf("4. %s\n" , voter_4);
    printf("5. %s\n" , voter_5);
    printf("6. %s\n" , voter_6);
    printf("7. %s\n" , voter_7);
    printf("8. %s\n" , voter_8);
    printf("9. %s\n" , voter_9);
    printf("10. %s\n" , voter_10);
    printf("ENTER YOUR RESPONSE : ");
    scanf("%s" , &ch);

    
    char *ptr ;
    ptr = strstr(voter_check,ch);
    vote_num = atoi(ch);
    
    if (ptr != NULL){
        printf("\nU HAVE ALREADY VOTED\n\n");main_portal();
    }
    else{
        strcat(voter_check,ch);
        switch(vote_num){ 
            case 1 : PREETHAM_V1(); break;
            case 2 : PREM_V2(); break;
            case 3 : BHASKAR_V3(); break;
            case 4 : ROHITH_V4(); break;
            case 5 : SAI_KIRAN_V5(); break;
            case 6 : SANDESH_V6(); break;
            case 7 : CHARAN_V7(); break;
            case 8 : SRIYA_V8(); break;
            case 9 : MADHURI_V9(); break;
            case 10 : NIHARIKA_V10(); break;
            default : printf("\nPLEASE GIVE THE CORRECT RESPONCE");voter_names();
        }
    }
}

//MAIN PORTAL
void main_portal() {
    int select;
    printf ("###  WHICH PORTAL YOU WANT TO OPEN  ###\n");
    printf ("1.ADMIN PORTAL...\n");
    printf ("2.VOTING PORTAL...\n");
    printf ("3.OVER...\n");
    printf ("ENTER YOUR RESPONSE : ");
    scanf ("%d" , &select);

    switch (select){
        case 1 : admin_pass();
        break;
        case 2 : voter_names();
        break;
        case 3 : printf ("### THANKYOU ###");
        break;
        default : printf("ENTER THE CORRECT OPTION");
    }
    
}

int main(){
    main_portal();
}
