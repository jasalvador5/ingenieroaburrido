//                 Creado por Rubén García Segovia
// Se permite la parcial o total modificación y la apropiación del código
// Código creado en el año 2013 y es de libre uso
//          http://ingenieroaburrido.com http://rubenelportero.net
#include<stdlib.h>
#include<stdio.h>
//creamos las variables
float A[4];
float B[4];
float C[4];
float D[4];
float x,y,z;
int signo, dificultad = 3, solucion = 1, seleccion;
void main (void){
//Seleccionamos como semilla para la función rand() el tiempo actual
        srand(time(NULL));
//E iniciamos el bucle que dará vida al menú de la aplicación
        do{
                printf("*********************************\n");
                printf("1.Generar sistemas\n");
                printf("2.Resolver sistemas\n");
                printf("3.SALIR DEL PROGRAMA\n");
                printf("     http://ingenieroaburrido.com\n");
                printf("*********************************\n");
                scanf("%d", &seleccion);
                if (seleccion < 1 || seleccion>3) printf("OPCION INCORRECTA. VUELVE A ELEGIR \n");
                //Con switch mandamos a la aplicación a que haga la acción que haya introducido el user
                switch (seleccion){
                        case 1:
                        //Se pide la dificultad
                        printf("Seleccione la dificultad del sistema\n");
                        printf("1. Soluciones sencillas entre [0,10]\n");
                        printf("2. Soluciones con decimales entre [0,10]\n");
                        printf("3. Soluciones con decimales entre [-10,10]\n");
                        scanf("%d",&dificultad);
                        if (dificultad == 1) {
                                //X es el resto de rand() entre 11, lo que da un número entre 0 y 10
                                //rand() de por sí puede tomar valores muy altos, y eso no nos conviene
                                x = rand() % 11;
                                y = rand() % 11;
                                z = rand() % 11;
                        }
                        if (dificultad == 2){
                                x = rand() % 11;
                                y = rand() % 11;
                                z = rand() % 11;
                                //Al resultado del número aleatorio le sumamos 2 para que nunca sea 0 o 1
                                x = x/((rand()%11)+2);
                                y = y/((rand()%5)+2);
                                z = z/((rand()%8)+2);
                        }
                        if (dificultad == 3){
                                x = rand() % 21;
                                y = rand() % 21;
                                z = rand() % 21;
                                x = x/((rand()%11)+2);
                                y = y/((rand()%6)+2);
                                z = z/((rand()%8)+2);
                                //Aquí simplemente jugamos a las cartas para ver si el número es o no positivo
                                if ((rand()%4)>1) x = -x;
                                if ((rand()%4)>1) y = -y;
                                if ((rand()%4)>1) z = -z;
                        }
                        //Aquí la generación aleatoria de coeficientes de la matriz
                        //También se juega con sus signos, todo aleatorio
                        A[0] = rand() % 6;
                        if ((rand()%4)>1) A[0] = -A[0];
                        B[0] = rand() % 6;
                        if ((rand()%3)>1) B[0] = -B[0];
                        C[0] = rand() % 6;
                        if ((rand()%2)>1) C[0] = -C[0];
                        A[1] = rand() % 7;
                        if ((rand()%2)>1) A[1] = -A[1];
                        B[1] = rand() % 9;
                        if ((rand()%4)>1) B[1] = -B[1];
                        C[1] = rand() % 11;
                        if ((rand()%3)>1) C[1] = -C[1];
                        A[2] = rand() % 4;
                        if ((rand()%3)>1) A[2] = -A[2];
                        B[2] = rand() % 9;
                        if ((rand()%2)>1) B[2] = -B[2];
                        C[2] = rand() % 11;
                        if ((rand()%3)>1) C[2] = -C[2];
                        D[0] = A[0]*x+B[0]*y+C[0]*z;
                        D[1] = A[1]*x+B[1]*y+C[1]*z;
                        D[2] = A[2]*x+B[2]*y+C[2]*z;
                        //imprimimos por pantalla el sistema
                        printf("\nSistema:\n");
                        printf("%gx + %gy + %gz= %g",A[0],B[0],C[0],D[0]);
                        printf("\n%gx + %gy + %gz= %g\n",A[1],B[1],C[1],D[1]);
                        printf("%gx + %gy + %gz= %g\n",A[2],B[2],C[2],D[2]);
                        //imprimimos por pantalla las soluciones
                        printf("\nSoluciones:\nX:%g\nY:%g\nZ:%g\n\n\n",x,y,z);
                        break;
                       
                        case 2:
                        //Aquí se enseña al user la forma del sistema
                        printf("A[0]x + B[0]y + C[0]z= D[0]");
                        printf("\nA[1]x + B[1]y + C[1]z= D[1]\n");
                        printf("A[2]x + B[2]y + C[2]z= D[2]\n");
                        //Y aquí se piden valores
                        printf("A[0]:");
                        scanf("%f",&A[0]);
                        printf("B[0]:");
                        scanf("%f",&B[0]);
                        printf("C[0]:");
                        scanf("%f",&C[0]);
                        printf("D[0]:");
                        scanf("%f",&D[0]);
                        printf("A[1]:");
                        scanf("%f",&A[1]);
                        printf("B[1]:");
                        scanf("%f",&B[1]);
                        printf("C[1]:");
                        scanf("%f",&C[1]);
                        printf("D[1]:");
                        scanf("%f",&D[1]);
                        printf("A[2]:");
                        scanf("%f",&A[2]);
                        printf("B[2]:");
                        scanf("%f",&B[2]);
                        printf("C[2]:");
                        scanf("%f",&C[2]);
                        printf("D[2]:");
                        scanf("%f",&D[2]);
                        //Si A[0] es 0 rota la fila 1 por la fila 3
                        if(A[0]==0) {
                                A[3] = A[0];
                                B[3] = B[0];
                                C[3] = C[0];
                                D[3] = D[0];
                                A[0] = A[2];
                                B[0] = B[2];
                                C[0] = C[2];
                                D[0] = D[2];
                                A[2] = A[3];
                                B[2] = B[3];
                                C[2] = C[3];
                                D[2] = D[3];
                        }
                        //Si tras rotar A[0] sigue siento 0, rota la fila 1 por la fila 2
                        if(A[0]==0) {
                                A[3] = A[0];
                                B[3] = B[0];
                                C[3] = C[0];
                                D[3] = D[0];
                                A[0] = A[1];
                                B[0] = B[1];
                                C[0] = C[1];
                                D[0] = D[1];
                                A[1] = A[3];
                                B[1] = B[3];
                                C[1] = C[3];
                                D[1] = D[3];
                        }
                        //imprime el sistema ya ordenado
                        printf("\nSistema:\n");
                        printf("%gx + %gy + %gz= %g",A[0],B[0],C[0],D[0]);
                        printf("\n%gx + %gy + %gz= %g\n",A[1],B[1],C[1],D[1]);
                        printf("%gx + %gy + %gz= %g\n",A[2],B[2],C[2],D[2]);
                        //Hace Gauss (0 por debajo de la diagonal principal)
                        D[1] = (D[1]*A[0]-D[0]*A[1]);
                        C[1] = (C[1]*A[0]-C[0]*A[1]);
                        B[1] = (B[1]*A[0]-B[0]*A[1]);
                        A[1] = (A[1]*A[0]-A[0]*A[1]);
                        D[2] = (D[2]*A[0]-D[0]*A[2]);
                        C[2] = (C[2]*A[0]-C[0]*A[2]);
                        B[2] = (B[2]*A[0]-B[0]*A[2]);
                        A[2] = (A[2]*A[0]-A[0]*A[2]);
                        /*Una vez que está la matriz |A[0] + B[0] + C[0] = D[0]|
                                                     | 0   + B[1] + C[1] = D[1]|
                                                     | 0   + B[2] + C[2] = D[2]|
                        Si B[1] es 0, se rota la fila 2 por la fila 3.
                        */
                        if(B[1]==0) {
                                A[3] = A[1];
                                B[3] = B[1];
                                C[3] = C[1];
                                D[3] = D[1];
                                A[1] = A[2];
                                B[1] = B[2];
                                C[1] = C[2];
                                D[1] = D[2];
                                A[2] = A[3];
                                B[2] = B[3];
                                C[2] = C[3];
                                D[2] = D[3];
                        }
                        //se termina de hacer ceros (a B[2])
                        D[2] = (D[2]*B[1]-D[1]*B[2]);
                        C[2] = (C[2]*B[1]-C[1]*B[2]);
                        B[2] = (B[2]*B[1]-B[1]*B[2]);
                        //Si C[2] se hace cero, el sistema será S.C.I.
                        if (C[2]==0){
                                printf("\n El sistema no tiene solucion, son ecuaciones linealmente dependientes\n\n\n");
                                solucion = 0;
                        }
                        z = D[2]/C[2];
                        C[1] = C[1] * z;
                        y = (D[1]-C[1])/B[1];
                        B[0] = y * B[0];
                        C[0] = C[0] * z;
                        x = (D[0]-B[0]-C[0])/A[0];
                        if (solucion == 1) printf("\nSoluciones:\nX:%g\nY:%g\nZ:%g\n\n\n",x,y,z);
                };
        } while (seleccion!=3);
}