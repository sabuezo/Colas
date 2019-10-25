#include <iostream>
#include<stdlib.h>
using namespace std;

struct nodo
{
    int nro;
    struct nodo *sgte;
};

struct cola
{
    nodo *delante;
    nodo *atras  ;
};

void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);

     aux->nro = valor;
     aux->sgte = NULL;

     if( q.delante == NULL)
         q.delante = aux;
     else
         (q.atras)->sgte = aux;

     q.atras = aux;
}

	int desencolar( struct cola &q )

{
     int num ;
     struct nodo *aux ;

     aux = q.delante;
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);

     return num;
}

void muestraCola( struct cola q )
{
     struct nodo *aux;

     aux = q.delante;

     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }
}

void vaciaCola( struct cola &q)
{
     struct nodo *aux;

     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;

}

void menu()
{
    cout<<"\n\t ...::COLAS::.. \n\n";
    cout<<" 1. Encolar                               "<<endl;
    cout<<" 2. Desencolar                            "<<endl;
    cout<<" 3. Mostrar cola                          "<<endl;
    cout<<" 4. Vaciar cola                           "<<endl;
    cout<<" 5. Salir                                 "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

int main()
{
    struct cola q;

    q.delante = NULL;
    q.atras   = NULL;


    int dato;
    int op;
    int x ;



    do
    {
        menu();  cin>> op;

        switch(op)
        {
            case 1:

                 cout<< "\n Ingrese Numero a encolar: "; cin>> dato;
                 encolar( q, dato );
                 cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
            break;


            case 2:

                 x = desencolar( q );
                 cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
            break;


            case 3:

                 cout << "\n\n Mostrar cola\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
            break;


            case 4:

                 vaciaCola( q );
                 cout<<"\n\n\t\tRealizado...\n\n";
            break;

         }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=5);


    return 0;
}
