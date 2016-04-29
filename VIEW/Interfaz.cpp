#include <VIEW/Interfaz.h>

Interfaz::Interfaz() 
{
    cap = VideoCapture(1);
    cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 210);
    brithness = 255;
    contrast = 300;
    gamma = 100;
}

Interfaz::~Interfaz() {}

void Interfaz::vistaPrincipal() 
{
    system("clear");
    cout << "+------------+ " << endl;
    cout << "| BIENVENIDO | " << endl;
    cout << "+------------+ " << endl;

    do
    {
        do
        {
            system("clear");
            cout << "Seleccione la opción que desee realizar" << endl;
            cout << "1 ==> Interpretar Seña" << endl;
            cout << "2 ==> Agregar Seña" << endl;
            cout << "3 ==> Cerrar la Aplicación" <<endl;
            cout << "Esperando Tecla..." <<endl;
            cin >> selection;
        }
        while (selection != "1" && 
               selection != "2" && 
               selection != "3");

        if (selection == "1")
        {
            vistaInterpretar();
        }
        else if (selection == "2")
        {
            vistaAgregar();
        }
        else if (selection == "3")
        {
            break;
        }
    } while(true);
}
void Interfaz::vistaInterpretar() 
{
    cout << "+------------------+ " << endl;
    cout << "| INTERPRETAR SEÑA | " << endl;
    cout << "+------------------+ \n" << endl;
    cout << "Presione Enter para interpretar la seña y" << endl;
    cout << "Presione Espaciadora si desea agregar un espacio " << endl;
    cout << "Presione Borrar (BackSpace) si desea borrar lo \n deletreado hasta el momento" << endl; 
    cout << "Para volver al menu principal precione Escape (ESC)" << endl;
    cout << "Esperando Tecla..." <<endl;

    namedWindow("Control", CV_WINDOW_AUTOSIZE);
    cvCreateTrackbar("brithness", "Control", &brithness, 510);
    cvCreateTrackbar("contrast", "Control", &contrast, 1000);
    cvCreateTrackbar("gamma", "Control", &gamma, 1000);

    bool t = true;
    Mat img;
    string tmp = "";

    interpret.updatePattern();

    while (t)
    {
        cap >> img;
        patron.setImg(img, brithness, contrast, gamma);

        switch(waitKey(10))
        {
            case 10:
            {
                tmp += interpret.interpretSing(img, brithness, 
                                                    contrast, 
                                                    gamma);
                cout << tmp << endl;
                break;
            }
            case 32:
            {
                tmp += " ";
                break;
            }
            case 65288:
            {
                tmp = "";
                break;
            }
            case 27:
            {
                t = false;
                break;
            }
        }
    }
}
void Interfaz::vistaAgregar() 
{
    cout << "+--------------+ " << endl;
    cout << "| AGREGAR SEÑA | " << endl;
    cout << "+--------------+ \n" << endl;
    cout << "1 ==> Capturar Seña" << endl;
    cout << "2 ==> Escribir el nombre de la seña" << endl;
    cout << "3 ==> Guardar como Modelo"<< endl;
    cout << "Presiones Esc para volver atrás"<< endl;
    cout << "Esperando Tecla..." <<endl;

    namedWindow("Control", CV_WINDOW_AUTOSIZE);
    cvCreateTrackbar("brithness", "Control", &brithness, 510);
    cvCreateTrackbar("contrast", "Control", &contrast, 1000);
    cvCreateTrackbar("gamma", "Control", &gamma, 1000);

    bool t = true;
    Mat img;
    string charater = "";

    while (t)
    {
        cap >> img;
        patron.setImg(img, brithness, contrast, gamma);

        switch(waitKey(10))
        {
            case 49:
            {
                patron.addPattern();
                break;
            }
            case 50:
            {
                cout << "Esperando letra" << endl;
                cin >> charater;
                patron.setCharacter(charater);
                break;
            }
            case 51:
            {
                patron.create();
                cout << "Agregado al Modelo" << endl;
                break;
            }
            case 27:
            {
                t = false;
                break;
            }
        }
    }
}
