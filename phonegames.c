#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "games/menu.h"
#include "games/game1.h"
#include "games/game2.h"


typedef struct{
    char name[60];
    int point;
    int level;
    
}character;


int main()
{

    int choice=0;
    character hero;
    hero.point=0;
    hero.level=0;
    int gamepoint=0;
    FILE*fptr;
    
    printf("welcome to the game program!\n");
    printf("please enter your characters name:");
    fgets(hero.name,100,stdin);
    hero.name[strcspn(hero.name,"\n")]=0;

    menu();
    while(choice!=6){
    printf("please enter your choice:");
    scanf("%d",&choice);
    switch(choice){

        case 1:
        menu();
        break;

        case 2:
        printf("you selected to play minefild!\ngood luck!\n\n");
        mineField(&gamepoint);
        break;


        case 3:
        printf("you selected to play snake game!\ngood luck!\n\n");
        snakeGame(&gamepoint);
        break;

        case 4:
        printf("showing stats...\n\n");
        
        fptr=fopen("stats.txt","r");
        if(fptr==NULL){
            printf("there is nothing to see yet...\n");
        }
        else{
            while(fscanf(fptr,"%s %d %d",hero.name,&hero.point,&hero.level)!=EOF){
                printf("your hero's name: %s\n",hero.name);
                printf("your point:%d\n",hero.point);
                printf("your level:%d\n",hero.level);
                printf("your game point:%d\n\n",gamepoint);
            }

        }
        fclose(fptr);
        break;

        case 5:
            printf("saving the game...\n\n");
            if(hero.point>=100){
                hero.level += hero.point/100;
                hero.point%=100;
            }
            fptr=fopen("stats.txt","w");
            fprintf(fptr,"%s\n%d\n%d",hero.name,hero.point+=gamepoint,hero.level);
            gamepoint=0;
            fclose(fptr);
        break;

        case 6:
            printf("thank you for playing!\n\n");
            printf("exitting program...\n");
        return 0;

        case 7:
            printf("points are increasing...\n\n");
            gamepoint+=10;
        break;

        case 8:
            printf("reseting the game...\n\n");
            fptr=fopen("stats.txt","w");
            fprintf(fptr,"%s\n%d\n%d",hero.name,hero.point=0,hero.level);
            gamepoint=0;
            fclose(fptr);
        break;

        default:
        printf("please enter a valid number!\n\n");

        break;

    }
}


    return 0;
}