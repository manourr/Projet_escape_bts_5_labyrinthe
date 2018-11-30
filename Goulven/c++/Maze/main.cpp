#include <QCoreApplication>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <chrono>


using namespace std;
int main(int argc, char *argv[])

{

    QCoreApplication a(argc, argv);
    int i=1;
    int score = 500;
    int temps = 500;
    while(i==1)


    {
        POINT position_curseur;
        int posa, posb;
        char z;

        GetCursorPos(&position_curseur);
        posa = position_curseur.y;
        posb = position_curseur.x;

        printf("Y : %ld - X : %ld\n", posa,posb);
        HDC dc = GetDC(NULL) ;

        DWORD pix = GetPixel(dc, posb, posa);



        unsigned int red = GetRValue(pix);
        unsigned int green = GetGValue(pix);
        unsigned int blue = GetBValue(pix);


        cout<<"rouge : "; cout<<red<<endl;
        cout<<"vert : "; cout<<green<<endl;
        cout<<"bleu : ";cout<<blue<<endl;

        score=score-1;
        printf("Il vous reste :");cout<<temps<<endl;
        //this_thread::sleep_for (chrono::milliseconds(10));
        temps--;


        system("cls");

        if (red == 0 && green == 0 && blue == 255)
        {
            printf("VOUS AVEZ Gagner \n");
        }

        else if(red == 0 && green == 0 && blue == 0)
        {
            printf("VOUS AVEZ PERDU APPUYER SUR UNE TOUCHE POUR REJOUER \n");
            printf("Votre score est de : ");cout<<score<<endl;
            printf("Vous avez mis : ");cout<<500-temps;printf(" secondes");
            scanf("%c",&z);
        }


            ReleaseDC(NULL, dc);


        printf("VOUS AVEZ gagner \n");

        i=i;
    }

    return a.exec();
}
