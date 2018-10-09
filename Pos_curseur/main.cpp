#include <QCoreApplication>
#include <Windows.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int i=1;
    while(i==1)
    {
   POINT position_curseur;
  int posa, posb;

    GetCursorPos(&position_curseur);
     posa = position_curseur.y;
     posb = position_curseur.x;
    printf("X : %ld - Y : %ld\n", posa,posb);


          if((posa > 300 || posa <600)  && (posb == 300 || posb < 600))
          {

          std::cout<<"Vous avez perdu"<<std::endl;
          i= i+1;
          std::cout<<"Entrer 1 pour rejouer"<<std::endl;
          std::cin>>i;

        }

      i=i;
    }



    return a.exec();
}
