#include <QCoreApplication>
#include <Windows.h>
#include <iostream>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])

{

    QCoreApplication a(argc, argv);
    int i=1;
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


          cout<<"rouge : "<<endl; cout<<red<<endl;
          cout<<"vert : "<<endl; cout<<green<<endl;
          cout<<"bleu : "<<endl;cout<<blue<<endl;





         if(red != 255 && green != 255 && blue != 255)
         {
             printf("VOUS AVEZ PERDU APPUYER SUR UNE TOUCHE POUR REJOUER");
             scanf("%c",&z);
         }
          ReleaseDC(NULL, dc);

      i=i;
    }



    return a.exec();
}
