
/*
 * Codebeispiel zum Abspeichern von Bildern aus RGB-Daten als BMP-/PPM-Datei.
 *
 * Ein Bild besteht aus Pixeln, die in Zeilen und Spalten angeordnet sind.
 * Jedes Pixel hat einen Rot-, Grün- und Blau-Wert zwischen 0 und 255. Der Ursprung
 * des Bildes befindet sich links oben:
 *  (0,0) ---------- (0, breite-1)
 *    |                  |
 *    |       (z,s)      |
 *    |                  |
 *   (hoehe-1,0) --- (hoehe-1, breite-1)
 * Diese Pixel werden in einem eindimensionalen Feld zeilenweise abgelegt und zwar in
 * der Reihenfolge
 * R[0,0] G[0,0] B[0,0] R[0,1] G[0,1] B[0,1] R[0,2] G[0,2] B[0,2]...
 * R[1,0] G[1,0] B[1,0] R[1,1] G[1,1] B[1,1] R[1,2] G[1,2] B[1,2]...
 * ...
 * R[hoehe-1,0] G[hoehe-1,0] B[hoehe-1,0] R[hoehe-1,1] G[hoehe-1,1] B[hoehe-1,1] R[hoehe-1,2] G[hoehe-1,2] B[hoehe-1,2]...
 * ... R[hoehe-1,breite-2] G[hoehe-1,breite-2] B[hoehe-1,breite-2] R[hoehe-1,breite-1] G[hoehe-1,breite-1] B[hoehe-1,breite-1]
 *
 * Die benoetigte Feldgroesse betraegt daher breite*hoehe*3 Bytes, da pro R,G,B-Wert 1 Byte benoetigt wird.
 * Der Zugriff auf die Farbwerte eines Pixels in Zeile z und Spalte s kann wie folgt erfolgen:
 * R-Wert: feld[(z*breite + s)*3 + 0]
 * G-Wert: feld[(z*breite + s)*3 + 1]
 * B-Wert: feld[(z*breite + s)*3 + 2]
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>

#include "background.h"

//int a = 10;
//int bc= 10;

//char password[] = "Hallo";

using namespace std;

void savePicture(Background &picture)
{
    picture.save();

}

//int main()
//{

//    cout << &a << endl;
//    cout << &bc << endl;

//    int *p  = &a;

//    *(p+1) = 99;

//    cout << bc << endl;
//#if 0
//    long long wo =0;
//    cin >> wo;
//    *((int *)wo) = 10;
//    cout << bc << endl;
//#endif

//    for( int i = 0; i <100; i++){
//        printf("%c ", *((char *) &bc +i));



//    }
//    cout << endl;

//    cout << &a << endl;
//    cout << &bc << endl;


//    int *p  = &a;

//    *(p+1) = 99;

//    cout << bc << endl;
//#if 0
//    long long wo =0;
//    cin >> wo;
//    *((int *)wo) = 10;
//    cout << bc << endl;
//#endif

//    for( int i = 0; i <100; i++){
//        printf("%c ", *((char *) &bc +i));



//    }
//    cout << endl;

//int main()
//{
//    int laenge = 40;
//    double winkel = M_PI/2;
//            int startx = 50, starty = 90;


//    Brush b(3,3);
//    Color gelb("yellow");
//    Color rot("red");
//    Color weiss("weiß");
//    Color schwarz("schwarz");
//    Color grau(100,100,100);
//    Background pictureOne(&gelb, 100, 100);
//    pictureOne.setPinsel(&b);
//    b.malemitFarbe(&rot);
//    pictureOne.drawline(10,10,20,80);
//    b.setFarbe(&weiss);
//    pictureOne.drawline(10,50,50,60);
//    savePicture(pictureOne);

//    return 0;
//}

////GROESSE von Pinsel implementieren

void histogramberechnen(int *output);


//void zeichneLinie(int x, int y, int laenge, int winkel)
//{
//    if(laenge < 5)
//    {
//        return;
//    }
//    else
//    {
//        zeichneLinie(x-laenge*cos(winkel),y + laenge*sin(winkel), laenge *0.7, winkel + M_PI/8);
//                zeichneLinie(x-laenge*cos(winkel),y + laenge*sin(winkel), laenge *0.7, winkel - M_PI/8);
//                        zeichneLinie(x-laenge*cos(winkel),y + laenge*sin(winkel), laenge *0.7, winkel);
//    }
//}

        while(!myReadFile.eof())
        {
            getline(myReadFile, output);

            if(!(isdigit(output[0]))
                    return 0;

                    histogramberechnen(greyval);
        }
        }
        }


                    else
            {
                    cerr <<"Konnte die Werte nicht auslesen" <<endl;
        }



                    return 0;
        }



//int main()
//{
//    int laenge = 40;
//    double winkel = M_PI/2;
//            int startx = 50, starty = 90;

//    Brush b(3,3);
//    Color gelb("yellow");
//    Color rot("red");
//    Color weiss("weiß");
//    Color schwarz("schwarz");
//    Color grau(100,100,100);
//    Background pictureOne(&gelb, 100, 100);
//    pictureOne.setPinsel(&b);
//    b.malemitFarbe(&rot);

//         pictureOne.zeichneLinie(startx, starty, laenge, winkel);
////        pictureOne.drawlineWinkel(  );

//        savePicture(pictureOne);
//}


int main()
{
    ifstream myReadFile;
    ofstream myWriteFile;
    ofstream greyFile;
    string temp;
    myReadFile.open("magnolie.ppm");
    myWriteFile.open("magnolieKopie.ppm");
    greyFile.open("magnolieGreyscale.ppm");
    string output;
    if (myReadFile.is_open() && myWriteFile.is_open() && greyFile.is_open()) {
        greyFile << "#Das ist das GreyFile" << endl;
        for(int i = 0; i < 3 ; ++i)
        {
            getline(myReadFile, output);
                    greyFile << output << endl;
        }
        while (!myReadFile.eof()) {
            {
                for(int i = 0; i < 3 ; ++i)
                {
                    getline(myReadFile, output);
                            greyFile << output << endl;
                }

            getline(myReadFile, output);

            cout<<output << endl;

            if(*output.data() < 256 && isdigit(output[0]))
            {
            myWriteFile << output << endl;
            temp.append(output); temp += '\n';
            }
            }



//          int grauwert = static_cast<double> (0.299 * r + 0.587 *(g+1) + 0.144 * (b+2))
//           }



}
        int greyval[256] = {0};
        if (*output.data() < 256 && isdigit(output[0]))
        {
//                int grauwert = static_cast<double> (0.299 * i + 0.587 *(i+1) + 0.144 * (i+2))
            greyval[*output.data()] =  greyval[*output.data()] +1;
        }
//            for(int i = 0; i< 256; ++i)
//            {
//                if(greyval[i] == 0)
//                    cout << "Null mal gab es den Grauwert " << i << endl;
            }


        myReadFile.close();
        myWriteFile.close();
        greyFile.close();

    } else {
        cerr << "Could not open file..." << endl;
    }
    return 0;
}


                    void   histogramberechnen(int *output)
               {
                       if(stoi(output) < 256)
               {
                       greyval[stoi(output)] =  greyval[stoi(output)] +1;
                   }
                       else break;


                       for(int i = 0; i< 256; ++i)
               {
                       if(greyval[i] == 0)
                       cout << "Null mal gab es den Grauwert " << i << endl;
           }

           }



