#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define MAX 5


int get_int(char *prompt)
{
    int num = 0, ch, count = 0;

    printf("%s", prompt);
    while (1)
    {
        ch = getch();
        if (ch == 13 && count)
        {
            break;
        }
        if (ch >= 48 && ch <= 57 && ch != 13)
        {
            num = num * 10 + (ch - 48);
            printf("%c", ch);
            count++;
        }
        else if ((ch == 8 && num) || (num == 0 && count))
        {
            num /= 10;
            printf("\b \b");
            count--;
        }
    }
    return num;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void panah(int posisiMenu, int posisiPanah)
{
    if (posisiPanah == posisiMenu)
        printf("==> ");
    else
        printf("   ");
}
void delay()
{
    for (int di = 1; di <= 15000; di++)
    {
        for (int dj = 1; dj <= 8000; dj++)
        {
        }
    }
}

int getPilihan()
{
    int posisi = 1;
    int keyPressed = 0;
    while (keyPressed != 27)
    {
        system("cls");
        gotoxy(40, 1);
        printf("==============================\n");
        gotoxy(45, 3);
        printf("TUGAS STACK AND QUEUE");
        gotoxy(40, 5);
        printf("==============================\n");
        gotoxy(47, 7);
        panah(1, posisi);
        printf("1. Stack");
        gotoxy(47, 8);
        panah(2, posisi);
        printf("2. Queue");
        gotoxy(47, 9);
        panah(3, posisi);
        printf("3. Keluar");
        gotoxy(40, 10);
        printf("==============================\n");

        if (kbhit())
        {
            keyPressed = getch();
        }
        if (keyPressed == 72)
        {
            posisi--;
        }
        else if (keyPressed == 80)
        {
            posisi++;
        }
        else if (keyPressed == 13)
        {
            return posisi;
        }
        if (posisi < 1)
        {
            posisi = 3;
        }
        else if (posisi > 3)
        {
            posisi = 1;
        }
        keyPressed = 'a';
        delay();
    }
}


   void menu()
   {
       int pilihan;
       system("cls");
       printf("----------------------\n");
       printf("TUGAS STACK DAN QUEUE\n");
       printf("----------------------\n");
       printf("1. Stack\n");
       printf("2. Queue\n");
       printf("3. exit\n");
       printf("pilihan: ");
       scanf("%d",&pilihan);
       switch(pilihan)
       {
            case 1:
                stack();
                break;

            case 2:
                queue();
                break;

            case 3:
                exit(0);

            default:

                printf("tidak ada dalam pilihan\n");
                break;

       }
   }
   struct Tumpukan
        {
            char data[5][50];
            int top;

        }tumpuk;

        int isEmpty()
        {
            if(tumpuk.top == -1)
            {
                return 1;
            }else{
                return 0;
            }
        }


        int isFull()
        {
            if(tumpuk.top == MAX-1)
            {
                return 1;
            }
            else{
                return 0;
            }
        }

        void inisialisasi()
        {
            tumpuk.top = -1;
        }

        void push()
        {
            char temp[30];
            if(isFull() != 1)
            {
                tumpuk.top++;
                gotoxy(41,15);
                printf("Masukkan data:");
                scanf("%s",&temp);
                strcpy(tumpuk.data[tumpuk.top],temp);
                gotoxy(41,16);
                printf("Data %s berhasil di input\n",tumpuk.data[tumpuk.top]);
            }else{
                gotoxy(41,15);
                printf("Data sudah penuh");
            }
        }

        void pop()
        {
            if(isEmpty() != 1)
            {
                gotoxy(41,15);
                printf("Data %s telah dibuang\n",tumpuk.data[tumpuk.top]);
                tumpuk.top--;

            }else{
                gotoxy(41,15);
                printf("Data masih kosong\n");
            }
        }

        void printData()
        {
            if(isEmpty() !=1)
            {
                for(int i=tumpuk.top;i>=0;i--)
                {
                    gotoxy(41,15+i);
                    printf("data ke %d = %s\n",i,tumpuk.data[i]);
                }
            }else{
                gotoxy(41,15);
                printf("Data masih kosong\n");
            }
        }

    void stack()
    {
        inisialisasi();
        int pil;
        do{
            system("cls");
            gotoxy(40, 1);
            printf("==============================\n");
            gotoxy(45, 3);
            printf("TUGAS STACK AND QUEUE");
            gotoxy(40, 5);
            printf("==============================\n");
            gotoxy(48, 7);
            printf("1.Push Stack\n");
            gotoxy(48, 8);
            printf("2.Pop Stack\n");
            gotoxy(48, 9);
            printf("3.Print Stack\n");
            gotoxy(48, 10);
            printf("4.Clear Stack\n");
            gotoxy(48, 11);
            printf("5.Exit\n");
            gotoxy(40,13);
            printf("==============================\n");
            gotoxy(41, 14);
            pil=get_int("Input pilihan: ");
                switch(pil)
                {
                case 1:
                    push();
                    getch();
                    break;
                case 2:
                    pop();
                    getch();
                    break;
                case 3:
                    printData();
                    getch();
                    break;
                case 4:
                    if(isEmpty())
                    {
                        gotoxy(41,15);
                        printf("Data masih kosong!,tidak bisa reset\n");
                        getch();
                    }
                    else
                    {
                        inisialisasi();
                        gotoxy(41,15);
                        printf("Data telah di reset!\n");
                        getch();
                    }
                    break;
                case 5:
                    main();
                    break;
                default:
                    fflush(stdin);
                    gotoxy(41,15);
                    printf("tidak ada dalam pilihan\n");
                    break;
                }

        }while(pil >0 && pil < 6);
    }

     struct Antrian{
        int head;
        int tail;
        int data[MAX];
    }antrian;

    int isempty()
    {
        if(antrian.tail == -1)
        {
            return 1;
        }else{
            return 0;
        }
    }

    int isfull()
    {
        if(antrian.tail == MAX -1)
        {
            return 1;
        }else{
            return 0;
        }
    }

    void inisial()
    {
        antrian.head=antrian.tail = -1;
    }

    void enqueue(int data)
    {
        if(isempty()==1)
        {
            antrian.head=antrian.tail = 0;
            antrian.data[antrian.tail] = data;
            gotoxy(41,16);
            printf("Data %d berhasil di input\n",antrian.data[antrian.tail]);
        }

        else{

        if(isfull() == 0)
        {
            antrian.tail++;
            antrian.data[antrian.tail] = data;
            gotoxy(41,16);
            printf("Data %d berhasil di input\n",antrian.data[antrian.tail]);
        }
      }
    }

    int dequeue()
    {
        if(isempty() == 1)
        {
            gotoxy(41,15);
            printf("Data masih kosong!\n");
        }
        else{
            int i;
            int e = antrian.data[antrian.head];
            gotoxy(41,15);
            printf("Data %d telah dikeluarkan dari antiran\n",antrian.data[antrian.head]);
            for(i=antrian.head;i<=antrian.tail-1;i++)
            {
                antrian.data[i] = antrian.data[i+1];
            }
            antrian.tail--;
                 return e;

        }

    }

    void clear()
    {
        antrian.head = antrian.tail = -1;
        gotoxy(41,15);
        printf("Data telah di reset!\n");
    }

    void print()
    {
        if(isempty() == 0)
        {
            for(int i=antrian.head;i<=antrian.tail;i++)
            {
                gotoxy(41,15+i);
                printf("Data ke %d = %d\n",i,antrian.data[i]);

            }
        }else{
            gotoxy(41,15);
            printf("Data masih kosong!\n");
        }
    }


    void queue()
    {

        int dt;
        inisial();
        int pil;
        do{
            system("cls");
            gotoxy(40, 1);
            printf("==============================\n");
            gotoxy(45, 3);
            printf("TUGAS STACK AND QUEUE");
            gotoxy(40, 5);
            printf("==============================\n");
            gotoxy(48, 7);
            printf("1.Enqueue\n");
            gotoxy(48, 8);
            printf("2.Dequeue\n");
            gotoxy(48, 9);
            printf("3.Print Queue\n");
            gotoxy(48, 10);
            printf("4.Clear Queue\n");
            gotoxy(48, 11);
            printf("5.Exit\n");
            gotoxy(40,13);
            printf("==============================\n");
            gotoxy(41, 14);
            pil=get_int("Input pilihan: ");
                switch(pil)
                {
                case 1:
                    if(isfull() !=1)
                    {
                        gotoxy(41, 15);
                        dt=get_int("Masukkan data: ");
                        enqueue(dt);
                        getch();
                    }
                    else
                    {
                        gotoxy(41, 15);
                        printf("Data sudah penuh!\n");
                        getch();
                    }

                    break;
                case 2:
                    dequeue();
                    getch();
                    break;
                case 3:
                    print();
                    printf("\n");
                    getch();
                    break;
                case 4:
                    clear();
                    getch();
                    break;
                case 5:
                    main();
                    break;
                default:
                    gotoxy(41,15);
                    printf("Tidak ada dalam pilihan!\n");
                    getch();
                    break;
                }

        }while(pil>0 && pil <6);
    }

    int main()
    {
    system("color 70");
    int pilihan = getPilihan();

    do
    {
        switch (pilihan)
        {
        case 1:
            stack();

            break;
        case 2:
            queue();

            break;
        case 3:
            exit(0);

            break;
        }
    }while (pilihan != 3);
}

