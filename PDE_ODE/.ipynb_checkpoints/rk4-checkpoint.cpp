//Este codigo fue proporcionado por el profesor del lab en clase, dice que es un template qu enos puede ser util en el futuro.

// RK4

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


// variable constantes globales
const float v_0 = 10/cos(M_PI/4);
const float angle = 45.0;
const float grav = 9.8;
const float k_f = 0.7;
const float N = 10.0;
const float v_0x = v_0*cos(angle*M_PI/180);
const float v_0y = v_0*sin(angle*M_PI/180);
const float T = 2.0*v_0y/grav;
const float H = v_0y*v_0y/(2.0*grav);
const float R = 2.0*v_0x*v_0y/grav;
const double DeltaT = 0.01;
const float magv = sqrt(pow(v_0x,2)+pow(v_0y,2));

// declaracion de funciones

double fx0(double t, double x0, double x1); // derivada de x0
double fx1(double t, double x0, double x1); // derivada de x1
double fy0(double t, double y0, double y1); // derivada de y0
double fy1(double t, double y0, double y1); // derivada de y1
void rk4(double t, double h, double & x0, double & x1, double & y0, double & y1); 


// metodo de runge kutta 4 orden

double fx0(double t, double x0, double x1)
{
  return x1;
}

double fx1(double t, double x0, double x1)
{
  return -k_f*v_0x*(v_0x/magv);
}

double fy0(double t, double y0, double y1)
{
  return y1;
}

double fy1(double t, double y0, double y1)
{
  return -grav-k_f * v_0y * (v_0y/magv);
}


//sacado del metodo del lab: https://raw.githubusercontent.com/JoseMontanaC/Laboratorio-Metodos-Computacionales/master/c_tests??///Rungekutta_Nvars.cpp
void rk4(double t, double h, double & x0, double & x1,double & y0, double & y1) // metodo de runge kutta 4 orden
{
  double kx10, kx11, kx20, kx21, kx30, kx31, kx40, kx41, ky10, ky11, ky20, ky21, ky30, ky31, ky40, ky41;
	
  kx10 = h*fx0(t, x0, x1);
  kx11 = h*fx1(t, x0, x1);
  kx20 = h*fx0(t+h/2, x0 + kx10/2, x1 + kx11/2);
  kx21 = h*fx1(t+h/2, x0 + kx10/2, x1 + kx11/2);
  kx30 = h*fx0(t+h/2, x0 + kx20/2, x1 + kx21/2);
  kx31 = h*fx1(t+h/2, x0 + kx20/2, x1 + kx21/2);
  kx40 = h*fx0(t + h, x0 + kx30, x1 + kx31);
  kx41 = h*fx1(t + h, x0 + kx30, x1 + kx31);
	
  ky10 = h*fy0(t, y0, y1);
  ky11 = h*fy1(t, y0, y1);
  ky20 = h*fy0(t+h/2, y0 + ky10/2, y1 + ky11/2);
  ky21 = h*fy1(t+h/2, y0 + ky10/2, y1 + ky11/2);
  ky30 = h*fy0(t+h/2, y0 + ky20/2, y1 + ky21/2);
  ky31 = h*fy1(t+h/2, y0 + ky20/2, y1 + ky21/2);
  ky40 = h*fy0(t + h, y0 + ky30, y1 + ky31);
  ky41 = h*fy1(t + h, y0 + ky30, y1 + ky31);

  x0 = x0 + (1.0/6.0)*(kx10 + 2*kx20 + 2*kx30 + kx40);
  x1 = x1 + (1.0/6.0)*(kx11 + 2*kx21 + 2*kx31 + kx41);
	
  y0 = y0 + (1.0/6.0)*(ky10 + 2*ky20 + 2*ky30 + ky40);
  y1 = y1 + (1.0/6.0)*(ky11 + 2*ky21 + 2*ky31 + ky41);
}

int main(void)
{
  ofstream fout("Clase_28.dat");
  double d_x = 0, vx = v_0x , d_y = 0, vy = v_0y;
  double time;
  for(time = 0; time <= T; time += DeltaT) {
    fout << time << "      " << d_x << "      " << vx << "      " << d_y << "      " << vy << "      " << time*10 << "      " << 10*time+((-grav*time*time)/2) << endl;
      
    rk4(time, DeltaT, d_x, vx, d_y, vy);
  }
    cout<<"Rango R=  "<<R<<"\n";
    cout<<"Pico T=  "<<T<<"\n";
  fout.close();

  return 0;
}