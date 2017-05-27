#include <stdlib.h>
#include <stdio.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

struct Nodo{
	int dato;
	Nodo *derecho;
	Nodo *izquierdo;
};

void menu();
int pedirDatos();
void insertar_nodo(Nodo *&, int);
void imprimirArbol(Nodo *Arbol, int cont);
bool busqueda(Nodo *, int);
void modificar_nodo(Nodo *&, int);
void post_orden(Nodo *);
void pre_orden(Nodo *);
void in_orden(Nodo *);

int main(){
    Nodo *Arbol=NULL;
	menu();
	return 0;
}

void menu(){
	Nodo *Arbol = NULL;
	int opcion, n, numDatos, cont = 0, x, a, y;
	do{
		printf("\n*****MENU ARBOL BINARIO*****\n");
		printf("\n1. Insertar Elementos en el Arbol");
		printf("\n2. Mostrar Elementos del Arbol");
		printf("\n3. Buscar Elementos del Arbol");
		printf("\n4. Modificar Elementos del Arbol");
		printf("\n0. Salir\n");
		printf("\nIngrese el valor de la opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 0:
				exit(0);
				break;

			case 1:{
			    do{
               printf("Ingrese dato: ");
               scanf("%d",&a);
               insertar_nodo(Arbol,a);
               printf("Ingresar mas datos 1.SI  2.NO: ");
               scanf("%d",&y);
            }while(y==1);
            }break;

			case 2:{
            system("cls");
            printf("1. Mostrar arbol en preorden\n");
            printf("2. Mostrar arbol en inorden\n");
            printf("3. Mostrar arbol en posorden\n");
            printf("Digite opcion: ");
            scanf("%d",&x);
            switch(x){
                case 1:{
                    pre_orden(Arbol);
                    printf("\n");
                }break;

                case 2:{
                    in_orden(Arbol);
                    printf("\n");
                }break;

                case 3:{
                    post_orden(Arbol);
                    printf("\n");
                }break;
                default: printf("Opcion incorrecta\n");
            }
            }break;

            case 3:{
            printf("Ingrese dato que desea buscar: ");
            scanf("%d",&a);
            if(busqueda(Arbol,a)==true){
                printf("dato encontrado\n");
            }else{
                printf("dato no encontrado\n");
            }
            }break;

            case 4:{
            printf("Ingrese dato que desea modificar: ");
            scanf("%d",&a);
            modificar_nodo(Arbol,a);
            }break;

			default:
				printf("\nNo es una opcion valida");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

Nodo *crear_nodo(int a){
    Nodo *nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->dato=a;
    nuevo_nodo->izquierdo=NULL;
    nuevo_nodo->derecho=NULL;

    return nuevo_nodo;
}


int pedirDatos(){
	int n;
	printf("\nIngrese un valor a insertar: ");
	scanf("%d", &n);
	return n;
}


void insertar_nodo(Nodo *&Arbol, int a){
    int x;
    if(Arbol==NULL){
        Nodo *nuevo=crear_nodo(a);
        Arbol=nuevo;
    }else{
        printf("Insertar 1.Izquierda  2.Derecha: ");
        scanf("%d",&x);
        if(x==1){
            insertar_nodo(Arbol->izquierdo,a);
        }else{
            insertar_nodo(Arbol->derecho,a);
        }
    }
}


void imprimirArbol(Nodo *Arbol, int cont){
	int i;
	if(Arbol == NULL){
		return;
	}else{
		imprimirArbol(Arbol -> derecho, cont += 1);
		for(i = 0; i < cont; i++){
			printf("   ");
		}
		printf("%d\n", Arbol -> dato);
		imprimirArbol(Arbol -> izquierdo, cont += 1);
	}
}

bool busqueda(Nodo *Arbol, int n){
    if(Arbol == NULL){
        return false;
    }
    else if(Arbol->dato == n){
        return true;
    }
    else if (n,Arbol ->dato){
        return busqueda(Arbol->izquierdo,n);
    }
    else{
        return busqueda(Arbol->derecho,n);
    }

}

void post_orden(Nodo *Arbol){
    if(Arbol == NULL){
        return;
    }
    else{
        post_orden(Arbol->izquierdo);
        post_orden(Arbol->derecho);
        printf("%d ",Arbol->dato);
    }
}


void pre_orden(Nodo *Arbol){
    if(Arbol == NULL){
        return;
    }
    else{
        printf("%d ",Arbol->dato);
        pre_orden(Arbol->izquierdo);
        pre_orden(Arbol->derecho);

    }
}


void in_orden(Nodo *Arbol){
    if(Arbol == NULL){
        return;
    }
    else{
        in_orden(Arbol->izquierdo);
        printf("%d ",Arbol->dato);
        in_orden(Arbol->derecho);

    }
}


void modificar_nodo(Nodo *&Arbol, int a){
    int x, y;
    if(Arbol==NULL){
        return;
    }else{
        if(Arbol->dato==a){
            printf("Ingrese nuevo dato: ");
            scanf("%d",&x);
            Arbol->dato=x;
        }else{
            printf("Buscar 1.Izquierda  2.Derecha: ");
            scanf("%d",&y);
            if(y==1){
                busqueda(Arbol->izquierdo,a);
            }else{
                busqueda(Arbol->derecho,a);
            }
        }
    }
}
