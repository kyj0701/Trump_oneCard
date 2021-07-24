#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HRT 0
#define SPDE 1
#define CLVR 2
#define DMD 3
#define JKR 4

typedef struct plyr *pl_ptr;

struct plyr{
    int hand[47];
    int indx;
};

int card[54]={0};
int draw_stack[54];             //뽑는 스택
int ind=-1;              //뽑는 스텍 인덱스
int put_stack[54];      //카드 내는 스택
int p_ind=-1;            //카드 내는 스택 인덱스
int LOOSE=1;
int attack_ind;

struct plyr computer;
struct plyr Me;



void init_card(void);
void init_hand(pl_ptr);
void print_board(void);
void print_card(int);
void print_shpe(int);
void print_num(int);
void put_card(int num);
int set_attack(int *index);


int main(){
    init_card();
    init_hand(&computer);
    init_hand(&Me);
    
    //while(LOOSE){
    print_board();
   printf("\nput index of card to attack:");
    scanf("%d", &attack_ind);
    if(set_attack(&attack_ind));
       // attack(attack_ind);
   
    

    
}

void init_card(){
    int random;
    
    srand(time(NULL));
    
    for(;ind<54;)
        if(!card[random=rand()%55]){
            draw_stack[++ind]=random;
            card[random]=1;
        }
    
    put_stack[++p_ind]=draw_stack[ind--];
}

void init_hand(pl_ptr p){
    
    for(int i=0;i<7;i++)
        p->hand[i]=draw_stack[ind--];
    p->indx=7;
}

void print_board(){
    int i=ind-1;
    
    print_card(put_stack[p_ind]);
    printf("  █ █ █ █ █\n\n");
    
    printf("======your card======\n");
    printf("index:\t");
    for(i=0;i<Me.indx;i++)
        printf("%d\t", i+1);
    printf("\ncard:\t");
    for(i=0;i<Me.indx;i++){
        print_card(Me.hand[i]);
        printf("\t");
    }
    printf("\n");
}

void print_card(int num){
    print_shpe(num);
    print_num(num);
}

void print_shpe(int num){
    int shape=num/13;
    switch (shape) {
        case 0:
            printf("♥");
            break;
        case 1:
            printf("♣");
            break;
        case 2:
            printf("♠");
            break;
        case 3:
            printf("♦");
            break;
        default:
            printf("JKR");
            break;
    }
}

void print_num(int num){
    int number=num%13;
    if(num/13==4)
        return;
    
    switch (number) {
        case 0:
            printf("A");
            break;
        case 10:
            printf("J");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d", number+1);
            break;
    }
    
}


int set_attack(int * index){
    (*index)--;
    while((Me.hand[*index])==-1)(*index)++;
   // (*index)--;
    
    int card=Me.hand[*index];
    int test_card=put_stack[p_ind];

    if(!(card>=52||card%13==test_card%13||card/13==test_card/13)){
        printf("your card is not right");
        return -1;
        }
    
    
        put_stack[++p_ind]=card;
        Me.hand[*index]=-1;
       if(card==52||card==53||card%13==0||card%13==1)
           return 1;
        return 0;
    
}
