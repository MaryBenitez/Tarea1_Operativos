#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Variables globales para las operaciones
int suma, resta, producto;

void hilo(int* n1, int* n2){
    //Se les otorga un valor a cada operacion
    suma = *n1 + *n2;
    resta = *n1 - *n2;
    producto = *n1 * *n2;

    //Se crea el archivo y se escribe sobre el 
    FILE * archivo = fopen("tarea1.txt","w");
    
    //Condicion para saber se crea o no el archivo
    if(archivo==NULL){
        perror("Error al crear el archivo.txt");
    } else {
        //fprintf escribe en el archivo el tipo de dato que se le designe
        fprintf(archivo,"%s", "*** Numeros ingresados ***\n\n");
        fprintf(archivo,"%s", "Primer numero: ");
        fprintf(archivo,"%d",*n1);
        fputc('\n',archivo);
        fprintf(archivo,"%s", "Segundo numero: ");
        fprintf(archivo,"%d",*n2);
        fprintf(archivo,"%s", "\n\n*** Resultados de Operaciones ***\n\n");

        //For menos a 3 ya que son 3 operaciones a realizarse
        for(int i=0; i<3; i++){
            //Condiciones dependiendo de la operacón
            if(i==0){
                fprintf(archivo,"%s", "Suma:");
                fprintf(archivo,"%d",suma);
            } else if(i==1){
                fprintf(archivo,"%s", "Resta:");
                fprintf(archivo,"%d",resta);
            } else if(i==2){
                fprintf(archivo,"%s", "Multiplicación:");
                fprintf(archivo,"%d",producto);
            }
            fputc('\n',archivo);
        }
        fflush(archivo);
        fclose(archivo);
        printf("ARCHIVO CREADO EXITOSAMENTE !!!\n");
    }
    return;
}

int main(void){
    int numero1;
    int numero2;
    printf("Ingrese primer numero: ");
    scanf("%d",&numero1);
    printf("Ingrese segundo numero: ");
    scanf("%d",&numero2);
    hilo(&numero1,&numero2); 
}