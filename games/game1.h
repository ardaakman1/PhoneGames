#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void mineField(int*ptr){
    
    srand(time(NULL));
    int diflvl;      
    int minenum;
    int bombnumber;
    int area1;
    int area2;
    int found=0;
    int i=0,j,k;
    int field1[30][30];
    int fieldsecret[30][30];
    int user_row,user_column;
    int flag=1;   
    int life=3;

    printf("welcome to the minefield game!\n");
    printf("(this is not the same game as minesweeper)\n\n");
    printf("1-EASY    9x9 area  10 bombs\n");
    printf("2-MEDIUM    16x16 area  40 bombs\n");
    printf("3-HARD    30x16 area  99 bombs\n");
    while(i==0){
    printf("please enter difficulty:");
    scanf("%d",&diflvl);
    switch(diflvl){
        case 1:
        printf("EASY MODE\n\n");
        bombnumber=10;
        minenum=10;
        area1=9;
        area2=9;
        i=1;
        break;

        case 2:
        printf("MEDIUM MODE\n\n");
        bombnumber=40;
        minenum=40;
        area1=16;
        area2=16;
        i=1;
        break;

        case 3:
        printf("HARD MODE\n\n");
        bombnumber=99;
        minenum=99;
        area1=30;
        area2=16;
        i=1;
        break;

        default:
        printf("please enter a valid number!\n\n");
        break;
    }
}

    printf("there will be %d mines\n\n",minenum);
    printf("0=space\t\t1=free\t\t8=mine\n\n");
    printf("you can enter numbers between 1-%d for rows.\n",area1);
    printf("you can enter numbers between 1-%d for columns.\n\n\n",area2);

    
      
    for(i=0;i<area1;i++){
        for(j=0;j<area2;j++){
            field1[i][j]=0;
        }
    }

    
    while(flag!=0){
        int count_mine=0;
        for(i=0;i<area1;i++){
            for(j=0;j<area2;j++){
                fieldsecret[i][j]=1;
            }
    }

        for(i=0;i<minenum;i++){
            
            int row=rand()%area1;
            int column=rand()%area2;
            fieldsecret[row][column]=8;
            
        }

        for(i=0;i<area1;i++){
            for(j=0;j<area2;j++){
                if(fieldsecret[i][j]==8){
                    count_mine++;
                }
            }
        }

        if(count_mine==minenum){
            flag=0;
        }

    }
        

    printf("the game begins!\n");

    printf("this is your area:\n\n");

     for(i=0;i<area1;i++){
        for(j=0;j<area2;j++){
            printf("%d ",field1[i][j]);
            
        }
        printf("\n");
    }
    printf("\n");

    while(life!=0 && found!=minenum){//game

        printf("life:%d\n",life);
        printf("mines found:%d\n",found);
        printf("mines remain:%d\n\n\n",bombnumber);

        flag=0;
        while(flag==0){
        printf("please enter row and column:"); 
        scanf("%d %d",&user_row,&user_column);
        
        if(user_row>area1 || user_row<1){
            printf("enter a number between 1 and %d for row! (1 and %d are included)\n",area1,area1);
        }

        else{
            flag=1;
            
        }

        if(user_column>area2 || user_column<1){
            flag=0;
            printf("enter a number between 1 and %d for column! (1 and %d are included)\n",area2,area2);
        }

    }
    system("cls");

    user_row--;
    user_column--;

    printf("\n\n");

    field1[user_row][user_column]=fieldsecret[user_row][user_column];

    if(fieldsecret[user_row][user_column]==8){
        Beep(200,300);
        life--;
    }

    
        if(user_row==0){
        if(user_column==0){
            
            field1[user_row+1][user_column]=fieldsecret[user_row+1][user_column]; 
            field1[user_row][user_column+1]=fieldsecret[user_row][user_column+1];
            field1[user_row+1][user_column+1]=fieldsecret[user_row+1][user_column+1];

        }

        else if(user_column==area2-1){
            field1[user_row+1][user_column]=fieldsecret[user_row+1][user_column];
            field1[user_row][user_column-1]=fieldsecret[user_row][user_column-1];
            field1[user_row+1][user_column-1]=fieldsecret[user_row+1][user_column-1];

        }
        else{
            field1[user_row+1][user_column]=fieldsecret[user_row+1][user_column]; 
            field1[user_row][user_column-1]=fieldsecret[user_row][user_column-1];
            field1[user_row][user_column+1]=fieldsecret[user_row][user_column+1];
            field1[user_row+1][user_column-1]=fieldsecret[user_row+1][user_column-1];
            field1[user_row+1][user_column+1]=fieldsecret[user_row+1][user_column+1];

        }

    }

//
    else if(user_row==area1-1){
        if(user_column==0){
             
            field1[user_row-1][user_column]=fieldsecret[user_row-1][user_column];
            field1[user_row][user_column+1]=fieldsecret[user_row][user_column+1];
            field1[user_row-1][user_column+1]=fieldsecret[user_row-1][user_column+1];


        }

        else if(user_column==area2-1){ 
            field1[user_row-1][user_column]=fieldsecret[user_row-1][user_column];
            field1[user_row][user_column-1]=fieldsecret[user_row][user_column-1];
            field1[user_row-1][user_column-1]=fieldsecret[user_row-1][user_column-1];

        } 
        else{
            field1[user_row-1][user_column]=fieldsecret[user_row-1][user_column];
            field1[user_row][user_column-1]=fieldsecret[user_row][user_column-1];
            field1[user_row][user_column+1]=fieldsecret[user_row][user_column+1];
            field1[user_row-1][user_column-1]=fieldsecret[user_row-1][user_column-1];
            field1[user_row-1][user_column+1]=fieldsecret[user_row-1][user_column+1];


        }

    }
//

    else{
        if(user_column==0){ 

            field1[user_row+1][user_column]=fieldsecret[user_row+1][user_column];
            field1[user_row-1][user_column]=fieldsecret[user_row-1][user_column];
            field1[user_row][user_column+1]=fieldsecret[user_row][user_column+1];
            field1[user_row+1][user_column+1]=fieldsecret[user_row+1][user_column+1];
            field1[user_row-1][user_column+1]=fieldsecret[user_row-1][user_column+1];


        }

        else if(user_column==area2-1){ 

            field1[user_row+1][user_column]=fieldsecret[user_row+1][user_column];
            field1[user_row-1][user_column]=fieldsecret[user_row-1][user_column];
            field1[user_row][user_column-1]=fieldsecret[user_row][user_column-1];
            field1[user_row+1][user_column-1]=fieldsecret[user_row+1][user_column-1];
            field1[user_row-1][user_column-1]=fieldsecret[user_row-1][user_column-1];



        }
        else{

            field1[user_row+1][user_column]=fieldsecret[user_row+1][user_column];
            field1[user_row-1][user_column]=fieldsecret[user_row-1][user_column];
            field1[user_row][user_column-1]=fieldsecret[user_row][user_column-1];
            field1[user_row][user_column+1]=fieldsecret[user_row][user_column+1];
            field1[user_row+1][user_column-1]=fieldsecret[user_row+1][user_column-1];
            field1[user_row+1][user_column+1]=fieldsecret[user_row+1][user_column+1];
            field1[user_row-1][user_column-1]=fieldsecret[user_row-1][user_column-1];
            field1[user_row-1][user_column+1]=fieldsecret[user_row-1][user_column+1];


        }
        
    }
//
    found=0;
    bombnumber=minenum;

    for(i=0;i<area1;i++){
        for(j=0;j<area2;j++){
            if(field1[i][j]==8){
                found++; 
                bombnumber--;
            }
        }

    }

      for(i=0;i<area1;i++){
        for(j=0;j<area2;j++){
            printf("%d ",field1[i][j]);
            
        }
        printf("\n");
    }
    printf("\n\n");

    }//while end

    if(bombnumber==0){
        if(life>0){
        printf("You find all of the mines!\n\n");
        switch (diflvl)
        {
        case 1:
        printf("YOU BEAT THE GAME IN EASY MODE CONGRUTULATIONS!\n\n");
        break;
        
        case 2:
        printf("YOU BEAT THE GAME IN MEDIUM MODE CONGRUTULATIONS!\n\n");
        break;

        case 3:
        printf("YOU BEAT THE GAME IN HARD MODE CONGRUTULATIONS!\n\n");
        break;
        }
        }
        else{
            printf("You find all of the mines!\n\nCONGRUTULATIONS!\n\n");
            printf("(you died but that is not important)\n\n");
        }
    }
    
    else if(life==0 && bombnumber>0){
        printf("GAME OVER\n\n");
        printf("you died!\n\n");
    } 
    *ptr += (life*30) + (found*10); 
    printf("you earned %d points!\n\n",(life*30) + (found*10));

}