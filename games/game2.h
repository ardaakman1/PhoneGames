#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//sınır=1 boşluk=9 yılan başı=0 yılan devamı=5 yemek=8
void snakeGame(int *ptr){
    srand(time(NULL));
    int area1[40][40];
    int row,column;
    int rand_row,rand_column;
    int head_row,head_column;
    int i,j;
    int flag=0;
    int food_control=0;
    int food_count=0;
    int body_row[500];
    int body_column[500];
    int control_row;
    int control_column;

    char user_button;
    char current_direction=' ';

    
    while(flag==0){
        printf("please enter the area's row and column that you want play in\n");
        printf("you can enter between (8-40):");
        scanf("%d %d",&row,&column);
        if(row>40 || row<8 || column>40 || column<8){
            printf("please enter numbers between 8 and 40 (8 and 40 are included)\n");
        }

        else{
            flag=1;
            area1[row][column];
           
        }

    }

    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(i==0 || i==row-1 || j==0 || j==column-1){
                area1[i][j]=1;
            }
            else{
            area1[i][j]=9;
            }

        }

    }

    printf("\n\n");
  
    i/=2;
    j/=2;

    head_row=i;
    head_column=j;
    area1[head_row][head_column]=0;
    

    printf("this is your area\n\n"); 

    printf("1-wall    0-head    5-body    8-food\n\n");

    printf("press p to start the game!\n\n"); 


    for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               if(area1[i][j]==9){
                    printf("  ");
                }

            }
            printf("\n");
        }
    

      
        while(flag==1){
            if(_kbhit()==1){
                user_button=_getch();
                if(user_button=='p'){
                    flag=0;
                }
               
            }
        }

        
    while(flag==0){//game
        system("cls");

     

        while(food_control==0){
            rand_row=rand()%(row-2)+1;
            rand_column=rand()%(row-2)+1;

            if(area1[rand_row][rand_column]==9){
                area1[rand_row][rand_column]=8;
                food_control=1;
            }
            else{
                continue;
            }
        }

//
        if(food_count>0){
            area1[body_row[food_count-1]][body_column[food_count-1]]=9;

        }

        else{
            area1[head_row][head_column]=9;
        }

        for(i=food_count-1;i>0;i--){
            body_row[i]=body_row[i-1];
            body_column[i]=body_column[i-1];
        }

        if(food_count>0){
            body_row[0]=head_row;
            body_column[0]=head_column;
            }
        


        if(_kbhit()==1){
            current_direction=_getch();
        }


        switch(current_direction)
        {
        case 'w':
        
            area1[--head_row][head_column]=0;
           
        break;

        case 'a':
        if(area1[head_row][head_column-1]!=5){
            area1[head_row][--head_column]=0;
        }

        break;
    
        case 'd':
        if(area1[head_row][head_column+1]!=5){
            area1[head_row][++head_column]=0;
        }

        break;

        case 's':
        if(area1[head_row+1][head_column]!=5){
            area1[++head_row][head_column]=0;

        }
        break;

        default:
        break;
        }
        
            
        for(i=0; i<food_count; i++){
            area1[ body_row[i] ][ body_column[i] ] = 5; 
        }
//
        
        for(i=0;i<food_count;i++){
            if(head_row==body_row[i] && head_column==body_column[i]){
                Beep(200,300);
                flag=1;
            }
        }

        if(head_row==rand_row && head_column==rand_column){
            body_row[food_count] = head_row; 
            body_column[food_count] = head_column;

            food_count++; 
            food_control=0;
            Beep(600,200);
        }

        else if(head_row==0 || head_row==row-1 || head_column==0 || head_column==column-1){
            Beep(200,300);
            flag=1;
        }
        
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               if(area1[i][j]==9){
                    printf("  ");
                }

                else{
                    printf("%d ",area1[i][j]);
                }

            }
            printf("\n");
        }

        printf("\ncollected food:%d\n",food_count);
        Sleep(750);
        
   
        }

        printf("\n\nGAME OVER\n\n");
        printf("you collected %d foods!\n\n",food_count);
        *ptr += food_count*20;
        printf("you earned %d points\n\n",food_count*20);

    }  
