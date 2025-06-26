#include <stdio.h>
#include <math.h>

float Whattodo(int operand, float numberA, float numberB);
float Addition(float numberA, float numberB);
float Subtraction(float numberA, float numberB);
float Multiplication(float numberA, float numberB);
float Division(float numberA, float numberB);
int Remainder(float numberA, float numberB);
float Pow(float numberA, float numberB);                                                                                //Si, esta calculadora tiene algunas funciones extras XD.
void Matrix();                                                                                                          //y demasiadas funciones en general. :(
void MatrixOp(int operand);
void Espacios();
void MatrixAdd();
void MatrixMult();
void MatrixTransposed();
void MatrixPrintr(float MatrixA[100][100], float MatrixB[100][100], float MatrixResult[100][100], int row1, int col1, int row2, int col2);                      //Por ahora le pongo un tamaño grande a las matrices hasta que veamos en clase como solucionar este problema de no saber el tamaño que quiere el user.
int Exit();

int main() {

    float numberA, numberB, result;                                                                                     //numberA y B son los numeros introducidos por pantalla en ese orden. result: resultado de la operacion.
    char operation;                                                                                                     //operation: es el signo de la operacion a realizar  en ascii.
    int operand, divbyzero=0, salida=0;                                                                                 //operand: lee el caracter de la operacion escrito por el user. divbyzero: comprueba si el usuario esta queriendo hacer una operacion indeterminada. salida: para preguntar si el usuario quiere otro intento o cerrar.

    printf("Bienvenido al intento de calculadora.\n");
    printf("Con  este  pequenio  programa  podras  hacer  las  siguientes  operaciones matematicas:\n");

    printf(" \n");
    printf("Suma: +                  Resta: -                   Division: /\n");
    printf("Multiplicacion: *        Obtencion del resto de una division: %\n");
    printf("Potencia:^               Operaciones con matrices/vectores: Escribe 1M1 para invocarlas.\n");
    printf(" \n");

    printf("Para ello solo escribe a continuacion la operacion matematica tal como lo harias a mano,\n");
    printf("sin espacios, todo junto.\n");
    printf("Te recuerdo  que para  calcular  el resto de una division y la division, los numeros que\n");
    printf("introduzcas deben ser enteros distintos de 0.\n");
    printf("Aqui te dejo algun ejemplo: 56*39, 100%2, 2^4.\n");

    while(salida==0){                                                                                                   //Condicion de salida para saber si el user quiere repetir otro calculo.

        printf("\n");
        printf("Dime lo que quieres que te calcule\n");

        scanf("%f %c %f",&numberA, &operation, &numberB);                                                        //Recogemos la expresion del usuario, siendo los primeros numeros hasta el operador el numberA, el operador queda guardado en 'operation', y el siguiente numero en numberB.
        printf(" \n");

        operand=(int)operation;                                                                                         //Para poder utilizar el signo del operador, lo transformamos a su valor ASCII y lo guardamos como entero para luego compararlo.

        result=Whattodo(operand, numberA, numberB);                                                                     //Llama a la funcion que indentifica la operacion a realizar y a su vez ejecuta la funcion correspondiente.

        if((operand=='/' && numberB==0) || (operand=='%' && numberB==0)){                                               //Para evitar que el usuario divida por 0, si el segundo numero introducido (numberB) es 0 y se encuentra en las operaciones division o resto, activa este switch.

            divbyzero=1;

        }

        if(operand!='M' && divbyzero==0){                                                                               //Si no hay ningun problema con la division por 0, y no se esta en el caso de las matrices devolvemos el resultado de la operacion.

            printf("El resultado de tu operacion es: %f\n", result);
            printf(" \n");

        }

        divbyzero=0;                                                                                                    //Reseteamos la variable para la repeticion del calculo.

        do{                                                                                                             //Bucle que pregunta al user si quiere hacer otro calculo hasta que introduzca un valor correcto.

                salida=Exit();                                                                                          //La funcion exit devuelve 0 si el user quiere repetir, 1 si quiere salir y 2 si la respuesta es incorrecta.

        }while(salida==2);

    }

}

float Whattodo(int operand, float numberA, float numberB){                                                              //operand: recibe el valor ascii correspondiente al caracter de la operacion a realizar. numberA y B: son los datos con los que hacer las operaciones.


    switch(operand){

        case '+':                                                                                                       //Caso de la suma, llama a la funcion Addition y le pasa los dos numeros a sumar.

            return Addition(numberA, numberB);


        case '-':                                                                                                       //Caso de la resta, llama a la funcion Subtraction y le pasa los numeros a restar.

            return Subtraction(numberA, numberB);


        case '*':                                                                                                       //Caso de la multiplicacion, llama a la funcion Multiplication y le pasa los numeros.

            return Multiplication(numberA, numberB);


        case '/':                                                                                                       //Caso de la division, primero comprueba que el divisor es distinto de 0 y luego llama a la funcion Division si es distinto.

            if(numberB==0){                                                                                             //Si el divisor es 0 se lo decimos al usuario y pedimos que repita la operacion. No devuelve ningun valor al main ni imprime resultado.

                printf("Lo  siento pero mi programador aun no me ha enseniado a dividir por 0.\n");
                printf("(;_;)\n");
                printf("P.d. A usar la enie tampoco.  (ToT)\n");
                printf(" \n");

                printf("Vuelve a  escribirlo  con  un  denominador distinto de 0 y prometo por\n");
                printf("las leyes de Boole, que te dare el resultado correcto de la operacion.\n");
                printf("(O por lo menos uno parecido, dame un margencito de error)\n");
                printf(" \n");

                break;

            }else{                                                                                                      //Si el divisor es distinto de 0, entonces calculamos la division llamando a la funcion.

                return Division(numberA, numberB);

            }

        case '%':                                                                                                       //Caso del calculo del resto de la division de dos numeros. Debemos comprobar de nuevo que no se divida por 0.

            if(numberB==0){                                                                                             //Si el divisor es 0 no hacemos calculo ni devolvemos valor al main.

                printf("Lo siento pero mi programador aun no me ha enseniado a dividir por 0.\n");
                printf("(;_;)\n");
                printf("P.d. A usar la enie tampoco.  (ToT)\n");
                printf(" \n");

                printf("Vuelve a  escribirlo  con  un  denominador distinto de 0 y prometo por\n");
                printf("las leyes de Boole, que te dare el resultado correcto de la operacion.\n");
                printf("(O por lo menos uno parecido, dame un margencito de error)\n");
                printf(" \n");

                break;

            }else{                                                                                                      //Si no se esta dividiendo por 0 llama a la funcion Remainder y devuelve el valor del resto.

                return Remainder(numberA, numberB);

            }

        case '^':                                                                                                       //Caso de la potencia, llama a la funcion Pow y devuelve el resultado de elevar numberA a numberB.

            return Pow(numberA, numberB);


        case 'M':                                                                                                       //Caso del modulo de calculos con matrices, llama la funcion (modulo) donde ofrece los posibles calculos con matrices.

            Matrix();
            break;

        default:                                                                                                        //Si el valor no corresponde con ninguno de los posibles devuelve un mensaje de error y pide de nuevo los datos al usuario.

            printf("Vaya, mi IA dice que algo no esta bien en lo que me has escrito,\n");
            printf("por que no lo intentas de nuevo?\n");
            printf("Asi le das un repaso a las opciones y como se escriben, porque\n");
            printf("si no, te voy a dar un resultado invalido.\n");
            printf("como el que sigue.\n");
            break;

    }
}                                                          //Clasifica las operaciones y llama a la funcion correspondiente pasando los datos.

float Addition(float numberA, float numberB){

    return (numberA+numberB);                                                                                           //Devuelve la suma de numberA y numberB.

}                                                                       //Operacion de suma de los datos introducidos.

float Subtraction(float numberA, float numberB){

    return (numberA-numberB);                                                                                           //Devuelve la diferencia entre numberA y numberB.

}                                                                    //Operacion de resta.

float Multiplication(float numberA, float numberB){

    return (numberA*numberB);                                                                                           //Devuleve la multiplicacion de numberA por numberB.

}                                                                 //Operacion de multiplicacion.

float Division(float numberA, float numberB){

     return (numberA/numberB);                                                                                          //Devuelve el resultado de dividir numberA entre numberB.

}                                                                       //Operacion division.

int Remainder(float numberA, float numberB){

    int numA=(int)numberA, numB=(int)numberB;                                                                           //Para calcular el resto, los numeros introducidos deben ser enteros, por ello, si el usuario introduce numero decimales los convertimos a enteros, aunque puede afectar al resultado.

    return (numA%numB);                                                                                                 //Devuelve el resto de dividir numberA entre numberB.

}                                                                        //Operacion que calcula el resto.

float Pow(float numberA, float numberB){

    double result, numA=(double)numberA, numB=(double)numberB;                                                          //Para utilizar la funcion de c (pow) los datos introducidos deben ser double, asi que los convertimos y volvemos a pasar el resultado a float, aunque puede dar errores en el resultado.

    result=pow(numA, numB);                                                                                       //Calcula el resultado de elevar numberA a numberB.
    result=(float)result;

    return result;

}                                                                            //Operacion para el calculo de potencias.

void Matrix(){

    int operand;                                                                                                        //Recibe el valor ascii del caracter op, para luego clasificarlo.
    char op;                                                                                                            //Simbolo de la operacion, introducido por el usuario.

    Espacios();                                                                                                         //Mete espacios para separar este modulo del principal. (Nada importante).

    printf("Vaya, vaya, vaya. Parece que estamos tratando temas serios aqui.\n");
    printf("Si matrices es lo que quieres calcular entonces solo sigue los pasos a continuacion.\n");
    printf("Tambien  sirve  para  trabajar  con vectores, en ese caso solo dime que el numero de \n");
    printf("filas es 1.\n");
    printf(" \n");

    printf("Estas son las cosas que he aprendido a hacer:\n");
    printf(" \n");

    printf("Suma de dos matrices: s                            Multiplicacion de dos matrices: x\n");
    printf("Traspuesta de una matriz: t     (Solo para matrices aunque te devuelva una solucion)\n");
    printf(" \n");
    printf("Dime cual de ellas quieres que te calcule:  (ej. T, +)\n");
    scanf(" %c", &op);                                                                                           //Problema aqui, pues la intencion inicial era poner las letras que designan cada operacion en mayuscula, pero el scanf rompe si uso mayusculas. Mirando por ahi se habla de algo relacionado con el buffer, pero las soluciones propuestas no lo solucionan.

    operand=(int)op;

    MatrixOp(operand);                                                                                                  //Llama a la funcion que clasifica la operacion requerida y le pasa el valor ascii.

}                                                                                                      //Submodulo del programa principal (Subcalculadora).

void Espacios(){

    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");

}                                                                                                    //Exquisiteses del programador para separar el modulo de matrices del modulo de cardinales en la pantalla introduciendo espacios entre ambos.

void MatrixOp(int operand){

    switch(operand){

        case 's':                                                                                                       //Caso para la suma de matrices, llama a la funcion MatrixAdd.

            MatrixAdd();
            break;

        case 'x':                                                                                                       //Caso para la multiplicacion de matrices, llama a la funcion MatrixMult.

            MatrixMult();
            break;


        case 't':                                                                                                       //Caso del calculo de la matriz traspuesta, llama a la funcion MatrixTrasposed.

            MatrixTransposed();
            break;

        default:                                                                                                        //Si el valor introducido no esta entre las opciones entonces repite.

            printf("Vaya, creo que has escrito algo mal, comprueba tu entrada y vuelvelo a intentar.\n");
            printf("\n");

    }

}                                                                                         //Tiene una utilidad similar a la funcion Whattodo, clasificando operaciones con matrices y llamando sus funciones.

void MatrixAdd(){

    int row1, col1, row2, col2, i, j;                                                                                   //row1 y 2: Numero de filas de las matrices.      col1 y 2: Numero de columnas de las matrices. i, j: operadores auxiliares para los bucles.
    float MatrixA[100][100], MatrixB[100][100], MatrixResult[100][100];                                                 //MatrixA y B: Matrices a sumar.                  MAtrixResult: Resultado de la suma de las matrices.

    printf(" \n");
    printf("Dime el numero de filas de tus matrices:\n");
    scanf("%d", &row1);                                                                                          //Pedimos el valor del numero de filas de las matrices, que deben ser iguales en ambas.

    printf(" \n");
    printf("Ahora dime el numero de columnas:\n");
    scanf("%d", &col1);                                                                                          //Pedimos el valor del numero de columnas de las matrices, que tambien debe ser igual en ambas.

    printf(" \n");
    printf("Perfecto.\n");
    printf("Entonces ahora empecemos a rellenarlas, vamos con la primera.\n");
    printf("\n");

    for(i=0;i<=row1-1;i++){

        for(j=0;j<=col1-1;j++){

            printf("Escribe el valor de la fila %d y columna %d:\n",i+1 ,j+1);
            scanf(" %f", &MatrixA[i][j]);                                                                        //Pedimos los valores de las posiciones de la matriz 1.

        }

    }

    printf(" \n");
    printf("Y lo siguiente es la segunda:\n");
    printf(" \n");

    for(i=0;i<=row1-1;i++){

        for(j=0;j<=col1-1;j++){

            printf("Escribe el valor de la fila %d y columna %d:\n",i+1 ,j+1);
            scanf("%f", &MatrixB[i][j]);                                                                         //Pedimos los valores de las posiciones de la matriz 2.

        }

    }

    printf("\n");

    for(i=0;i<=row1-1;i++){

        for(j=0;j<=col1-1;j++){

            MatrixResult[i][j]=MatrixA[i][j]+MatrixB[i][j];                                                             //Calcula la suma de los valores de las matrices y lo almacena en la matriz resultado en la coordenada correspondiente.

        }

    }

    row2=row1;                                                                                                          //Para imprimir las matrices usando la funcion MatrixPrintr, debemos pasar valores de filas y columnas para cada una, pero en este caso las matrices sabemos que deben tener el mismo tamaño y por eso lo igualamos.
    col2=col1;

    MatrixPrintr(MatrixA, MatrixB, MatrixResult, row1, col1, row2, col2);                                               //Llamamos a la funcion que imprime las matrices introducidas y el resultado de su suma.

}                                                                                                   //Operacion suma de matrices.

void MatrixPrintr(float MatrixA[100][100], float MatrixB[100][100], float MatrixResult[100][100], int row1, int col1, int row2, int col2){

    int i, j;                                                                                                           //Operadores para los bucles de impresion.

    printf(" \n");
    printf("Estas son tus matrices:\n");
    printf("Matriz 1.\n");
    printf("\n");

    for(i=0;i<=row1-1;i++){

        for(j=0;j<=col1-1;j++){

            printf("%f ", MatrixA[i][j]);                                                                        //Imprime la matriz A introducida por el user.

        }

        printf(" \n");

    }

    printf("\n");
    printf("Matriz 2:\n");
    printf("\n");

    for(i=0;i<=row2-1;i++){

        for(j=0;j<=col2-1;j++){

            printf("%f ", MatrixB[i][j]);                                                                        //Imprime la matriz 2.

        }

        printf(" \n");

    }

    printf("\n");
    printf("Y el resultado:\n");
    printf("\n");

    for(i=0;i<=row1-1;i++){

        for(j=0;j<=col2-1;j++){

            printf("%f ", MatrixResult[i][j]);                                                                   //Imprime la matriz con el resultado de la operacion. Esta preparada para imprimir la suma y la multiplicacion de matrices.

        }

        printf(" \n");

    }

    printf("\n");

}    //Imprime las matrices y el resultado para las funciones suma y multiplicacion.

void MatrixMult(){

    int row1, col1, row2, col2, i, j, correct=0, k;                                                                     //row1 y 2: Numero de filas de las matrices A y B respectivamente.      col1 y 2: numero de columnas de las matrices A y B repectivamente.         i, j, k: Variables auxiliares para los bucles.                                   correct: Comprueba si los valores de las dimensiones de las matrices son correcotos para poder multiplicar.
    float MatrixA[100][100], MatrixB[100][100], MatrixResult[100][100], sum, multiplication;                            //MatrixA y B: Son las matrices a multiplicar.                          MatrixResult: Matriz que almacena el resultado de la multiplicacion.       sum: Auxiliar que almacena la suma de los productos de filas por columnas.       multiplication: Almacena el resultado de la multiplicacion de los valores de las coordenadas de las matrices.

    while(correct==0){                                                                                                  //Mientras correct=0 pedimos de nuevo los valores de las dimensiones de las matrices al usuario hasta que sean compatibles.

        printf("Te recuerdo que para la multiplicacion, tu matriz 1 debe tener el mismo numero de columnas\n");
        printf("que de filas tiene la segunda. Sabiendo eso:\n");

        printf(" \n");
        printf("Dime el numero de filas de tu matriz 1:\n");
        scanf("%d", &row1);

        printf(" \n");
        printf("Ahora dime el numero de columnas:\n");
        scanf("%d", &col1);

        printf(" \n");
        printf("Y ahora:\n");
        printf("Dime el numero de filas de tu matriz 1:\n");
        scanf("%d", &row2);

        printf(" \n");
        printf("Ahora dime el numero de columnas:\n");
        scanf("%d", &col2);

        if(col1==row2){                                                                                                 //Si cumple la condicion para la multiplicacion de matrices: numero de columnas de la matriz A igual al numero de filas de la matriz B, cambia correct=1 y pasa a pedir los valores de las matrices.

            correct=1;

        }

    }

    printf(" \n");
    printf("Perfecto.\n");
    printf("Entonces ahora empecemos a rellenarlas, vamos con la primera.\n");
    printf("\n");

    for(i=0;i<=row1-1;i++){

        for(j=0;j<=col1-1;j++){

            printf("Escribe el valor de la fila %d y columna %d:\n",i+1 ,j+1);
            scanf(" %f", &MatrixA[i][j]);                                                                        //Lee la matriz A.

        }

    }

    printf(" \n");
    printf("Y lo siguiente es la segunda:\n");
    printf(" \n");

    for(i=0;i<=row2-1;i++){

        for(j=0;j<=col2-1;j++){

            printf("Escribe el valor de la fila %d y columna %d:\n",i+1 ,j+1);
            scanf("%f", &MatrixB[i][j]);                                                                         //Lee la matriz B.

        }

    }

    printf("\n");

    for(k=0;k<=row1-1;k++){                                                                                             //Bucle para la multiplicacion. k recorre las filas de la primera matriz y de la del resultado.

        sum=0;

        for(i=0;i<=col2-1;i++){                                                                                         //Bucle que recorre las columnas de la segunda matriz.

            for(j=0;j<=row2-1;j++){                                                                                     //Bucle que recorre las columnas de la matriz1 y las filas de la matriz2.

                multiplication=MatrixA[k][j]*MatrixB[j][i];                                                             //Multiplicamos los valores de las filas de la primera matriz por los valores de las columnas de la segunda y guardamos si resultado uno a uno en multiplicacion para luego irlos sumando.
                sum+=multiplication;                                                                                    //Vamos recogiendo los resultados de la multiplicacion y los sumamos con los anteriores.

            }

            MatrixResult[k][i]=sum;                                                                                     //Guardamos el resultado de la suma en la matriz resultado a medida que multiplicamos toda la fila por toda la columna.
            sum=0;                                                                                                      //OJO!!! Importante reiniciar la variable suma para que al repetir no se nos vayan sumando los calculos anteriores.

        }

    }


    MatrixPrintr(MatrixA, MatrixB, MatrixResult, row1, col1, row2, col2);                                               //Llamamos a la funcion que imprime las matrices y le pasamos los datos necesarios.

}                                                                                                  //Operacion multiplicacion de matrices.

void MatrixTransposed(){

    float Matrix[100][100], MatrixResult[100][100];                                                                     //Matrix: Matriz a trasponer.                    MatrixResult: Matriz traspuesta.
    int i, j, size;                                                                                                     //i,j: Variables auxiliares para los bulces.     size: Recoge el valor del tamaño de la matriz.

    printf("Si quieres obtener la traspuesta de una matriz solo dime sus valores.\n");
    printf(" \n");
    printf("Primero dime el tamanio de tu matriz:\n");
    scanf("%d", &size);                                                                                          //Recoge el tamaño de la matriz que debe ser cuadrada.

    printf("\n");
    printf("De acuerdo, ahora su contenido.\n");

    for(i=0;i<=size-1;i++){

        for(j=0;j<=size-1;j++){

            printf("El valor en la coordenada (%d,%d) es:\n",i+1,j+1);
            scanf("%f",&Matrix[i][j]);                                                                           //Construye la matriz con los valores dados por el usuario.

        }

    }

    printf("\n");
    printf("La matriz introducida es:\n");
    printf("\n");

    for(i=0;i<=size-1;i++){

        for(j=0;j<=size-1;j++){

            printf(" %f ",Matrix[i][j]);                                                                         //Imprime la matriz introducida.

        }

        printf("\n");

    }

    printf(" \n");

    for(i=0;i<=size-1;i++){

        for(j=0;j<=size-1;j++){

            MatrixResult[i][j]=Matrix[j][i];                                                                            //Obtiene la matriz traspuesta en la MatrixResult.

        }

    }

    printf("\n");
    printf("Y su traspuesta es:\n");
    printf("\n");

    for(i=0;i<=size-1;i++){

        for(j=0;j<=size-1;j++){

            printf(" %f ",MatrixResult[i][j]);                                                                   //Imprime la matriz traspuesta.

        }

        printf("\n");

    }

    printf("\n");

}                                                                                            //Obtiene la matriz traspuesta de una dada.

int Exit(){

    char ans;                                                                                                           //Recibe la respuesta del usuario a la pregunta de hacer otro calculo.
    int exit;                                                                                                           //Traduce el valor del caracter ans a ascii.

    printf("Quieres hacer otro calculo?(s/n)\n");
    scanf(" %c",&ans);

    exit=(int)ans;

    switch(exit){

        case 's':                                                                                                       //El usuario quiere repetir. Devuelve 0 a la funcion main y repite el bucle del programa.

            printf("\n");
            printf("Me alegra mucho oir eso.  :)     Vamos alla.\n");
            printf("\n");
            return 0;

        case 'S':                                                                                                       //El usuario quiere repetir. Devuelve 0 a la funcion main y repite el bucle del programa.

            printf("\n");
            printf("Me alegra mucho oir eso.  :)     Vamos alla.\n");
            printf("\n");
            return 0;
            break;

        case 'n':                                                                                                       //El usuario no quiere repetir. Devuelve 1 a la funcion main y sale del bucle del programa.

            printf("\n");
            printf("Jo, con lo bien que me lo estaba pasando  (;_;)\n");
            printf("Pero entiendo  que  eres  humano  y necesitas un  descanso.\n");
            printf("Asi que, muchas gracias por haber jugado un ratito conmigo.  (^_^)\n");
            printf("Adioooosssss, espero verte pronto.\n");
            printf("\n");
            return 1;

        case 'N':                                                                                                       //El usuario no quiere repetir. Devuelve 1 a la funcion main y sale del bucle del programa.

            printf("\n");
            printf("Jo, con lo bien que me lo estaba pasando  (;_;)\n");
            printf("Pero entiendo  que  eres  humano  y necesitas un descanso.\n");
            printf("Asi que, muchas gracias por haber jugado un ratito conmigo  (^_^)\n");
            printf("\n");
            return 1;

        default:                                                                                                        //Si lo intriducido no coincide con ninguno de los casos devuelve un 2 y repite la pregunta sin repetir entero el programa.

        printf(" \n");
        printf("Lo siento pero no encuentro respuesta a eso en mi base de datos.\n");
        printf("Vamos a probar de nuevo.\n");
        return 2;

    }

}                                                                                                         //Pregunta al usuario si quiere salir del programa y clasifica la respuesta para devolver un valor que puede cerrar o no el programa.



