#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct 
{
  int account_number;
  char name[100];
  float balance;
}account;
account load_acc(int num);

void account_creation();
void saveAccount(account x);
void deposite_money();
void withdraw_money();
void check_balance();
int main(){
    int d;
    do
    {
       
    printf("donner un numéro entr 1 et 5 pour fonctionner dans le systéme du bank \n 1:pour account creation \n 2:pour depiste money \n 3:pour withdrow money \n 4: pour check balance \n 5:pour saving ur data and exist ");
    scanf("%d",&d);
    switch (d)
    {
    case 1:
        account_creation();
        break;
    case 2:
        despite_money();
        break;
    case 3:
        withdrow_money();
        break;
    case 4:
        check_balance();
        break;
    case 5:
        printf("your data are saved, exiting the system right now \n");
        break;
    case 6:
        printf("your input are indefind please try again \n");
        break;
    default:
        break;
    }
    } while (d>5);
    

    return 0;
}

account load_acc(int num)
{
    FILE *file=fopen("account.dat","rb");
    if (file==NULL){
        printf("erreur opening account\n");
        exit(1);
    }
    account acc;
    while (fread(&acc,sizeof(account),1,file))
    {
     if (acc.account_number==num)
     {
        fclose(file);
        return acc;
     }
     
    }
    fclose(file);
    printf("erreur finding your account \n");
    
    
}

void account_creation()
{ account new_one;
    char reponse[100];
    printf("donner le nom d'utilésateur de ce compte ");
    scanf("%s", new_one.name);
    new_one.account_number=rand() % 789456132224797 + 1;
    printf("votre numéro du compte égale %d",new_one.account_number);
    do
    {
        printf("tu veux intialer votre a zero ou dépôter d'argent");
        scanf("%s",&reponse);
    } while (strcmp(reponse,"zero")!=0 && strcmp(reponse,"dépoter")!=0);
    if (strcmp(reponse,"zero")==0)
    {
       new_one. balance=0.0;
    }
    else
    {
        deposit_money();
    }
    
    saveAccount(new_one);
    printf("félicitations,Compte créé avec succès!\n");
    
  

}
void saveAccount(account x){
 FILE *file=fopen("x.dat","ab");
 if (file==NULL)
 {
 printf("erreur opening file try again \n");
 exit(1);
 }
    fwrite(&x,sizeof(account),1,file);
    fclose(file);
 
}

void deposit_money() {
    int num_acc;
    float amount_money;
    printf("Enter your account number:\n");
    scanf("%d", &num_acc);
    account acco = load_acc(num_acc);
    printf("Enter the amount to deposit:\n");
    scanf("%f", &amount_money);
    acco.balance += amount_money;
    saveAccount(acco);
    printf("Money deposited successfully!\n");
}

void withdraw_money()
{
    int num_acc;
    float amount_money;
    printf("Enter your account number:\n");
    scanf("%d", &num_acc);
    account acco = load_acc(num_acc);
    printf("Enter the amount to withdraw:\n");
    scanf("%f", &amount_money);
    if (acco.balance>=amount_money)
    {
        acco.balance -= amount_money;
        saveAccount(acco);
        printf("Money withdrawed successfully!\n");
    }
    else{
        printf("insuficient balamce \n");
    }
}

void check_balance()
{
    int num_acc;
    printf("Enter your account number:\n");
    scanf("%d", &num_acc);
    account acco = load_acc(num_acc);
    printf("your bqnk balance is %f ",acco.balance);
}
