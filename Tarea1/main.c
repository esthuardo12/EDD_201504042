#include <stdio.h>


struct nodo
 {
   int valor;
   struct nodo *siguiente;
   struct nodo *anterior;
 };
 struct nodo *primero, *ultimo;

/* Funciones con listas: */
void insertar();
void eliminar();
void mostrar();

int main(int argc, char *argv[])
{

          primero=NULL;

          ultimo=NULL;

    int opcion;

       do
       {
         system("cls");

         printf("\n******************************************");
         printf("\n1.  Insertar numero                      *");
         printf("\n2.  Eliminar numero                      *");
         printf("\n3.  Mostrar lista                        *");
         printf("\n4.  Salir                                *");
         printf("\n******************************************");
         printf("\n\n\n");

         printf("\n Elija opcion:    ");

         scanf("%d",&opcion);

         switch (opcion)
             {
                    case 1: insertar();
                              break;
                    case 2: eliminar();
                              break;
                    case 3: mostrar();
                              break;
                    case 4: printf("SALIENDO DEL SISTEMA");
                                break;
                    default:  system("cls");
                              break;
            }
         } while (opcion!=4);
}

void insertar(){
    char esnum[50];
    int dato=0;
     system("cls");
     printf("INGRESE EL DATO QUE DESEA INSERTAR EN LA LISTA: ");
     scanf("%s",esnum);
     dato=atoi(esnum);
     if(dato!=0 || esnum[0]=='0'){
         //correcto
         struct nodo *nuevo;
              nuevo=( struct nodo*)malloc(sizeof( struct nodo));
              if(nuevo==NULL)
                 printf("\n MEMORIA INSUFICIENTE\n");
              else
              {
                  nuevo->valor=dato;
                  nuevo->siguiente=NULL;
                  if(primero==NULL)
                    {
                     nuevo->anterior=NULL;
                     nuevo->siguiente=NULL;
                     primero=nuevo;
                     ultimo=nuevo;

                    }else{
                          nuevo->siguiente= NULL;

                          nuevo->anterior=ultimo;

                          ultimo->siguiente=nuevo;

                          ultimo=nuevo;
                       }
                  printf("DATO INGRESADO CON EXITO! ");
                  system("pause");
                }
     }else{
         //dato invalido
         printf("EL DATO INGRESADO ES INVALIDO ");
         system("pause");
     }


}
void eliminar(){
    system("cls");
    printf("\n ELIGIO ELIMINAR\n");
    printf("\n Ingrese el valor que desea eliminar: ");
    char esnum[50];
    int dato;
    scanf("%s",esnum);
    dato=atoi(esnum);
    if(dato!=0 || esnum[0]=='0'){
        struct nodo  *aux;
        struct nodo  *actual;
       actual = primero;
       while(actual!=NULL){
           if(actual->valor==dato){
               if(actual==primero && actual==ultimo){
                   primero=NULL;
                   ultimo=NULL;
                   printf("La lista queda completamente vacia... \n");
                   system("pause");
               }else if(actual==primero){
                   primero = primero->siguiente;
                   primero->anterior == NULL;
               }else if(actual==ultimo){
                   ultimo->anterior->siguiente = NULL;
                   ultimo = ultimo->anterior;
               }else{
                   aux = actual;
                   actual->anterior->siguiente = actual->siguiente;
                   actual->siguiente->anterior = actual->anterior;
               }
               break;
           }else{
               actual=actual->siguiente;
           }
       }
       free(aux);
    system("pause");
    }else{
        //dato invalido
        printf("EL DATO INGRESADO NO ES INVALIDO ");
        system("pause");
    }

}

void mostrar(){
    int pos;
    system("cls");
    printf("\n ELIGIO MOSTRAR \n");

         struct nodo *actual;

         pos=1;

         actual=primero;

         while(actual!=NULL)
           {
              printf(" %d.- ", pos);

              printf(" %d\n", actual->valor);

              actual= actual->siguiente;

              pos++;
           }
           if(pos==1)

               printf("\n LISTA VACIA");

           printf("\n\n\n\n\n\n\n");

    system("pause");

}


