#include <iostream>

using namespace std;

struct administrador{              // Lista Simple
        string nombre;
        int id;
        administrador * sig;

        administrador(string n, int i){
            nombre = n;
            id = i;
            sig = NULL;
        }
};


struct profesor{                   //Lista Doble
        string nombre;
        int cedula;
        profesor * sig;
        profesor * ant;
        struct AgregarCurso* subListaAC;

        profesor(string n, int c){
            nombre = n;
            cedula = c;
            sig = NULL;
            ant = NULL;
            subListaAC = NULL;
        }
};


struct estudiante{                 //Lista Simple
    string nombre;
    int carnet;
    estudiante * sig;
    struct AgregarCurso* sublistaAC;

    estudiante (string n, int c){

        nombre = n;
        carnet = c;
        sig = NULL;
        sublistaAC = NULL;
    }
};


struct curso{                     //Lista Circular
    string nombre;
    string codigo;
    int creditos;
    curso* sig;

    curso (string n, string cod, int cred){

        nombre = n;
        codigo = cod;
        creditos = cred;
        sig = NULL;
    }
};

struct AgregarCurso{

    AgregarCurso* sig;
    struct curso *enlace;

    AgregarCurso(struct curso *c){
        sig= NULL;
        enlace = c;

    }
};

//prototipo
void insertarAgregarCurso(int, string);
//Primeros de las listas principales
struct profesor* primeroP;
struct estudiante* primeroE;
struct curso* primeroC;


void insertarInicioLD(string n, int c){          //Lista Profesores

        struct profesor *nn = new profesor(n,c);

        nn->sig = primeroP;

        if(primeroP != NULL)
            primeroP->ant = nn;

        primeroP = nn;

}

void insetarInicioLS(string n, int c){            //Lista Simple Ordenada

        struct estudiante * nn = new estudiante(n, c);
        struct estudiante * temp = primeroE;

        if(primeroE > temp){

            primeroE = nn;
            primeroE->sig = primeroE;                    //Este método está en proceso
        }

            temp->sig = nn;
            temp = temp->sig;
}


void insetarFinalLC(string n, string cod, int cred){

        struct curso * nn = new curso(n, cod, cred);

        if(primeroC == NULL){

            primeroC = nn;
            primeroC->sig = primeroC;

        }
        else{
            struct curso * temp = primeroC;
            while(temp->sig != primeroC){
                temp = temp->sig;
            }

            primeroC = nn;
            nn->sig = primeroC;
            temp->sig = nn;

        }

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
