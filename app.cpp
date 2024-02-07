#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<Windows.h>
#include<conio.h>

int W = 119;
int S = 115;
int sp = 32;

#define cw 5 //선택할수 있는 경우의 수

int sw = 0; //선택 기능 순서
int swb = 0; //선택 기능(학생
int opw = 0; //선택 기능(설정
int gd; //키보드 입력

int ko = 0; //반복문 나가는 bool
int ko1 = 0; //반복문 나가는 bool
int ko11 = 0; //반복문 나가는 bool

void cote(int x, int y) //선택 했는지 확인 시켜주는 미디어
{
    if (x != y)
        printf("○ ");
    else if (x == y)
        printf("● ");
}

char st[101][21] = {}; //학생 이름
int rw[101][21] = {}; //교과 점수
int sc = 0; //학생 수
int rat = 5; //교과 수

char na[21] = {}; //이름 입력 받기
int tn;

int kromoto; //교과 입력 받기
int scor; //교과 점수 입력 받기

double br = 0; //평균값 출력

char str[71] = {};

char ry[101][21] = {
   "국어", "수학", "영어", "사회", "동아리"
}; //교과 이름

int TTT; //쓰레기값

int main(void)
{


    Sleep(1000);
    system("cls");
    while (1) //전체 시스템 반복
    {
        while (1) //선택하는거 반복
        {
            system("cls");

            if (ko == 1)
                break;

            ko = 0;
            ko1 = 0;
            ko11 = 0;

            cote(0, sw);
            printf("학생부 출력\n");
            cote(1, sw);
            printf("성적 교체 / 입력\n");
            cote(2, sw);
            printf("학생 추가\n");
            cote(3, sw);
            printf("설정\n");
            cote(4, sw);
            printf("종료\n");


            gd = _getch();
            if (gd == W) {
                sw--;
                if (sw == -1)
                    sw = cw - 1;
            }
            else if (gd == S) {
                sw++;
                if (cw == sw)
                    sw = 0;
            }
            else if (gd == sp) {
                ko = 1;
            }
        }


        switch (sw) //선택한 거 실행
        {

        case 0:
            printf("학생의 수가 %d명 입니다.\n", sc);
            if (sc == 0)
            {
                printf("먼저 학생을 추가해 주세요\n");
                break;
            }

            for (int j = 0; j < rat; j++)
            {
                printf("    %s", ry[j]);
            }
            printf("    평균\n");

            for (int i = 0; i < sc; i++)
            {
                br = 0;
                printf("%s  ", st[i]);
                for (int j = 0; j < rat; j++)
                {
                    printf("%d  ", rw[i][j]);
                    br += rw[i][j];
                }
                printf("%f", br / rat);
                printf("\n");
            }
            break;

        case 1:
            if (sc == 0)
            {
                printf("학생의 수가 0명 입니다 먼저 학생을 추가해 주세요\n");
                break;
            }
            ko1 = 0;
            while (1)
            {
                system("cls");

                if (ko1 == 1)
                {
                    for (int j = 0; j < rat; j++)
                    {
                        printf("%s  ", ry[j]);
                    }
                    printf("\n");
                    for (int j = 0; j < rat; j++)
                    {
                        printf("%d  ", rw[swb][j]);
                    }
                    printf("\n");
                    printf("변환하고 싶은 교과 점수의 번호를 입력해주세요\n");
                    scanf("%d", &kromoto);
                    kromoto--;
                    printf("해당 과목의 학생 점수를 입력해주세요\n");
                    scanf("%d", &scor);
                    rw[swb][kromoto] = scor;
                    break;
                }

                ko1 = 0;

                printf("학생의 수가 %d명 입니다.\n", sc);
                for (int j = 0; j < rat; j++)
                {
                    printf("    %s", ry[j]);
                }
                printf("\n");
                for (int i = 0; i < sc; i++)
                {
                    cote(i, swb);
                    printf("%s  ", st[i]);
                    for (int j = 0; j < rat; j++)
                    {
                        printf("%d  ", rw[i][j]);
                    }
                    printf("\n");
                }

                gd = _getch();
                if (gd == W) {
                    swb--;
                    if (swb == -1)
                        swb = sc - 1;
                }
                else if (gd == S) {
                    swb++;
                    if (sc == swb)
                        swb = 0;
                }
                else if (gd == sp) {
                    ko1 = 1;
                }
            }

            break;

        case 2:
            printf("학생 이름 입력 : ");
            scanf("%s", st[sc]);
            printf("%d개 교과의 해당 학생 성적 입력\n", rat);
            for (int i = 0; i < rat; i++)
            {
                printf("%s 교과 : ", ry[i]);
                scanf("%d", &rw[sc][i]);
            }
            sc++;
            break;

        case cw - 2:
            swb = 0;
            while (1)
            {
                system("cls");
                if (ko1 == 1)
                    break;
                cote(0, swb);
                printf("조작키 설정\n");
                cote(1, swb);
                printf("세이브 파일 복원\n");
                cote(2, swb);
                printf("뒤로가기\n");

                gd = _getch();
                if (gd == W) {
                    swb--;
                    if (swb == -1)
                        swb = 3 - 1;
                }
                else if (gd == S) {
                    swb++;
                    if (3 == swb)
                        swb = 0;
                }
                else if (gd == sp) {
                    ko1 = 1;
                }
            }
            switch (swb)
            {
                case 0:
                    while (1)
                    {
                        system("cls");
                        if (ko11 == 1) break;

                        cote(0, opw);
                        printf("위로가기 %c\n", W);
                        cote(1, opw);
                        printf("아래로 가기 %c\n", S);
                        cote(2, opw);
                        if (sp != 32)
                            printf("선택하기 %c\n", sp);
                        else
                            printf("선택하기 space\n");
                        cote(3, opw);
                        printf("뒤로가기\n");

                        gd = _getch();
                        if (gd == W) {
                            opw--;
                            if (opw == -1)
                                opw = 4 - 1;
                        }
                        else if (gd == S) {
                            opw++;
                            if (4 == opw)
                                opw = 0;
                        }
                        else if (gd == sp) {
                            ko11 = 1;
                        }
                    }
                    printf("원하시는 변경 키를 입력해주세요\n");
                    scanf("%c", &TTT);
                    switch (opw)
                    {
                        case 0:
                            W = TTT;
                            break;
                        case 1:
                            S = TTT;
                            break;
                        case 2:
                            sp = TTT;
                            break;
                        case 3:
                            printf("뒤로가기");
                            break;
                    }

                     break;
                case 1:
                    printf("구현중\n");
                    break;
            }

            break;


        case cw - 1:
            printf("프로그램이 종료 됩니다\n");
            return 0;
            break;

        }

        ko = 0;
        printf("계속 하시려면 아무키나 입력해주세요\n");
        getchar();
    }
}
