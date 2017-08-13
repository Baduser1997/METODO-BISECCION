// MÃ©todo de la BisecciÃ³n
// Autor: Canal de Youtube: Algoritmos y Algo mÃ¡s
// 16/03/2016

#include <iostream>
#include <iomanip> // setprecision
#include <cmath>
 
#define PRECISION 6
 
using namespace std;
 
void tabula(double a, double b); //utilizamos la funcion tabula para crear una tabla con los intervalos disponibles
double f(double x);  //la funcion doble es para cuadrados
 
int main()
{
   cout << setprecision(PRECISION); //definimos la precision en 6
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion\n";
   cout << "\nIngrese el intervalo inicial [a,b]:" << endl;
   //pedimos el intervalo inicial de la variable a,b
 
   double a, b, tolerancia;  // estas son las variables que almacenaran la variable a,b, tolerancia
   
 
   cout << "\na = ";
   cin >> a; //le introduce un valor el usuario a la variable a
 
   cout << "b = ";
   cin >> b; //le introduce un valor el usuario a la variable b
   tabula(a, b); //almacenamos el resultado introducido por el usuario y arrojamos una serie de numeros intermedios con la funcion tabula
   //
   cout << "\nEscoja el intervalo adecuado" << endl;//le pedimos al usuario que seleccione el intervalo adecuado
   cout << "\na = ";
   cin >> a; //selecciona el intervalo adecuado para a
 
   cout << "b = ";
   cin >> b; //selecciona el intervalo adecuado para b
 
 
   double xr;   
   // si los numeros tienen el mismo signo no se puede aplicar el metodo de biseccion
   if (f(a) * f(b) > 0) {   //si a * b es mayor a 0 entonces no se puede aplicar el metodo de biseccion 
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl; //no se puede aplicar el metodo de biseccion por que los dos intervalos tiene el mismo signo
 
   } else {  //en caso contrario si se puede aplicar el metodo de biseccion
      cout << "Tolerancia = ";   //ahora le pedimos al usuario que defina la tolerancia del metodo
      cin >> tolerancia;
 
      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;
      do {  //iniciamos un bucle pára calcular un punto medio
 
         xr = (a + b) / 2.0;  //variable a + b 
         cout << a << "\t" << b << "\t" << xr << "\t" << f(a) << "\t" << f(b) << "\t" << f(xr) << endl;
 
         if (fabs(f(xr)) <= tolerancia) { //si el valor absoluto de la imagen es menor o igual a 0 imprimimos
            cout << "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es: " << xr << endl;
            break;
            //si la condicion de arriba no se cumple volvemos  a repetir el ciclo
 
         } else {
            if (f(xr) * f(a) > 0) {  //aqui si no se cumple el bucle reemplazamos la imagen de xr remplaza a la variable (a)
               a = xr;
            } else if (f(xr) * f(b) > 0) { //aqui si no se cumple el bucle reemplazamos la imagen de b remplaza a la variable (xr)
               b = xr;
            }
         }
 
      } while (1);
   }
 
   cin.get();//cerramos ciclos
   cin.get();//cerramos ciclos y evitamos que la ventana se cierre
   return 0;//devolvemos resultados 
}
 
#define INTERVALOS 10  //definimos los intervalos en 10
void tabula(double a, double b)
{
   int puntos = INTERVALOS + 1; //si tenemos 10 intervalos el numero de puntos va a ser el numero de intervalos aumentado en 1
 
   double ancho = (b - a) / INTERVALOS; //diferencia de los puntos extremos (a,b) entre los intervalos
 
   cout << "\n\tx\tf(x) " << endl; //aqui se imprimen las cabeceras de las tablas
   for (int i = 0; i < puntos; i++) {  //aqui tomamos los valores de i y lo inicializamos en 0, y vamos a ir aumentando en la variable ancho
      cout << "\t" << a << "\t" << f(a) << endl; // imprimimos un tabulador con el valor de la imagen de a.
      a = a + ancho; //ahora se aumenta su valor actual + el ancho
   }
}
 
double f(double x)
{
   return exp(-1 * x) - cos(3 * x) - 0.5; //**********esta es la funcion que vamos  a revisar los intervalos ******
}
