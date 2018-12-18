#include "monthread.h"
#include <iostream>

#include <QRgb>

#include <Windows.h>
#include <iostream>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <stdio.h>
#include <chrono>
#include <Qlabel>


#include "mainwindow.h"


void monThread::run()
{

    int i=1;
    int score = 500;
    // int temps = 0;
    int tem = 0;

    int sc = 0;

    while(i==1)
    {
        POINT position_curseur;
        int posa, posb;
        char z;


        GetCursorPos(&position_curseur);
        posa = position_curseur.y;
        posb = position_curseur.x;

        printf("Y : %ld - X : %ld\n", posa,posb);
        printf("SCORE : ");
        std::cout<<score<<std::endl;
        m_app->Timers(QString(score));
        HDC dc = GetDC(NULL) ;


        DWORD pix = GetPixel(dc, posb, posa);

        unsigned int red = GetRValue(pix);
        unsigned int green = GetGValue(pix);
        unsigned int blue = GetBValue(pix);

        //  cout<<"Temps : "<<temps<<endl;

        if( red != 255 && green != 0 && blue != 0)
        {
             m_app->afficher_message( QString("---" )  );
            printf("POSITIONNER LE CURSEUR SUR DU ROUGE");
            //scanf("%c",&z);
            score = 500;

        }
        else if(red == 255 && green == 0 && blue == 0)
        {
            m_app->afficher_message( QString("DEMARRER" )  );

            sc = 1;
        }

        QThread::msleep(75);
        printf("Y : %ld - X : %ld\n", posa,posb);
        tem ++;
        if(tem == 5)
        {
            //temps++;
            if (sc==1){ score --;}
            std::cout<<"rouge : "; std::cout<<red<<std::endl;
            std::cout<<"vert : "; std::cout<<green<<std::endl;
            std::cout<<"bleu : ";std::cout<<blue<<std::endl;
            //printf("Il vous reste :");cout<<temps<<endl;
            tem = 0;


        }


        //system("cls");

        if(red == 255 && green == 255 && blue == 255)
        {
               m_app->afficher_message( QString("ATTENTION AU BORDURES NOIRES" )  );



        }

        if(red == 0 && green == 0 && blue == 0)
        {
               m_app->afficher_message( QString("PERDU - RETOURNER SUR LE ROUGE" )  );

            printf("VOUS AVEZ PERDU METTER LE CURSEUR SUR DU ROUGE POUR REJOUER \n");



            printf("Votre score est de : ");std::cout<<score<<std::endl;
            //printf("Vous avez mis : ");cout<<temps;printf(" secondes");
            //scanf("%c",&z);
            sc = 0;

            score = 500;

        }

        if(red == 0 && green == 0 && blue == 255)
        {
             m_app->afficher_message( QString("GAGNE" )  );
            printf("VOUS AVEZ GAGNER APPUYER SUR UNE TOUCHE POUR REJOUER \n");
            printf("Votre score est de : ");std::cout<<score<<std::endl;
            //printf("Vous avez mis : ");cout<<temps;printf(" secondes");
            //scanf("%c",&z);
            score = 500;
            sc = 0;


        }

        ReleaseDC(NULL, dc);

    }

}

void monThread::set_app(MainWindow *app)
{
    m_app = app;
}

