#include  <stdio.h>
#include  <conio.h>//提供实时读取键盘按键
#include  <windows.h>//提供清屏，延时等效果
#include   <stdlib.h>//rand()随机函数
#include   <time.h>//随机数
//#include "D:\raylib-6.2_win64_mingw-w64\raylib-6.2_win64_mingw-w64\include\raylib.h"
#define  MAP_M 30
#define  MAP_H 15
int main(){
     int snakeX[100];//蛇的每节身体坐标x
     int snakeY[100];//y坐标
     int snakeLen = 2;//蛇的初始长度
     int dir =0;//初始位置为向右
     int foodX ,foodY;//食物的坐标
     //初始蛇的坐标
     snakeX[0]=10;snakeY[0]=7;//蛇头坐标左右方向x数字越大越靠右，上下方向y数字越大越靠下
     snakeX[1]=9;snakeY[1]=7;//蛇身坐标
     srand((unsigned int)time(NULL));//随机数种子即食物
     foodX = rand()%(MAP_M - 2) + 1;//随机生成食物坐标，随机数
        foodY = rand()%(MAP_H - 1) + 1;//同理
    while(1){//死循环，让表达式一直为真
        system("cls");//清屏,吃一个食物闪烁
        for(int c=snakeLen-1;c>=1;c--){
            snakeX[c]=snakeX[c-1];//蛇一共2节从1开始循环，身体拿到上一节的旧目标
            snakeY[c]=snakeY[c-1];//同理
        }
        switch(dir){
            case 0: snakeX[0]++; break;//向右行走
            case 1: snakeY[0]--; break;//向上行走
            case 2: snakeX[0]--; break;//向左行走
            case 3: snakeY[0]++; break;//向下行走
        }
        if(snakeX[0] == foodX &&  snakeY[0] == foodY){//蛇头坐标与吃食物的坐标
            snakeLen++;
            foodX = rand() % (MAP_M - 2) + 1;//随机生成食物坐标，随机数
            foodY = rand() % (MAP_H - 1) + 1;//同理
        }
        if(_kbhit()){//检测有无按键按下，有则为真，无则为假，与#include <conio.h>配合使用
            char key =_getch();//读取键盘按键，存进key中
            if(key == 'd'&& dir != 2)dir =0;//向右行走且不能掉头
            if(key == 'w'&& dir != 3)dir =1;//向上行走且不能掉头
            if(key == 'a'&& dir != 0)dir =2;//向左行走且不能掉头
            if(key == 's'&& dir != 1)dir =3;//向下行走且不能掉头
        }
        for(int i=0;i<MAP_M;i++){
            printf("#");
        }
        printf("\n");//打印顶部边框
        for(int a=0;a<MAP_H;a++){
            printf("#");//左边框
            for(int b=0;b<MAP_M-2;b++){
                int printsnake = 0;//这个位置不是蛇
                for(int d=0;d< snakeLen;d++){
                    if(b == snakeX[d] && a == snakeY[d]){
                        printf("O");//坐标正确则打印蛇
                        printsnake=1;//若标记为1，则表示以打印蛇
                        break;//终止循环
                    }
                }
                if(printsnake == 0){
                    if(b == foodX && a == foodY){
                        printf("*");//打印出食物
                    }
                    else{
                        printf(" ");//中间空格
                    }
                }
            }
            printf("#");//右边框
            printf("\n");
        }
        for(int i=0;i<MAP_M;i++){
            printf("#");//底部边框
        }
        printf("\n");
        if(snakeX[0]<0 || snakeX[0]>MAP_M-3 || snakeY[0]<0 || snakeY[0]>MAP_H-1){//蛇头撞墙，游戏结束
            printf("game overs!\n");
            break;
        }
        Sleep(150);//闪烁速度
    }
    return 0;
  
}