#include <iostream>
#include<stdlib.h>
using namespace std;

#define ALMACEN 100
#define PERSONAL 100
#define PERSONAL2 20

class Vehiculo {       
  public:             
    int cauchos;       
    string modelo;  
    string motor;
    string carroceria;
    string pintura;
    Vehiculo();
    Vehiculo(int,string,string,string,string); //Constructor de vehiculo con pase de parametros
};

//Constructor
Vehiculo::Vehiculo(int _caucho,string _modelo,string _motor,string _carroceria,string _pintura){
       cauchos = _caucho;
       modelo = _modelo;
       motor = _motor;
       carroceria = _carroceria;
       pintura = _pintura;

}

Vehiculo::Vehiculo(){
       cauchos = this->cauchos;
       modelo = this->modelo;
       motor = this->motor;
       carroceria = this->carroceria;
       pintura = this->pintura;

}


class Persona {       
  public:             
    int edad;       
    string nombre;  
    string cedula;
    string especializacion;
    
    Persona(int,string,string,string); //Constructor con pase de parametros;
    
};

//Constructor 
Persona::Persona(int _edad,string _nombre,string _cedula,string _especializacion){
       edad = _edad;
       nombre = _nombre;
       cedula = _cedula;
       especializacion = _especializacion;

} 


Persona::Persona(){
       edad = this->edad;
       nombre = this->nombre;
       cedula = this->cedula;
       especializacion = this->especializacion;

}


class Robot {       
  public:                    
    string modelo;
    
   Robot(string);//Constructor
};
//Constructor de robot
Robot::Robot(string _modelo){
  modelo = _modelo;
}

Robot::Robot(string _modelo){
  modelo = this->modelo;
}


class Estacion {       
  public:                    
    string nombre;
    Vehiculo vehiculo;
    string modulo;
    Robot robots;
    Persona personas[PERSONAL2];
    
    Estacion(string,Vehiculo,string,Robot,Persona); //Constructor
};


class Empresa {       
  public:                    
    string nombre;
    Vehiculo vehiculos[ALMACEN];
    Persona trabajadores[PERSONAL];
    Estacion estaciones[ALMACEN];
    Empresa(string,Vehiculo*,Persona*,Estacion*); //Constructor
   
};


Empresa::Empresa(string _nombre,Vehiculo *vehiculos,Persona *trabajadores,Estacion *estaciones){
    nombre = _nombre;
    vehiculo = _vehiculos new Vehiculo[];
    trabajadores = _trabajadores new Persona[];
    estaciones = _estaciones new Estacion [];
    
}

int main() {
  //Persona persona;  // Create an object of MyClass

  // Access attributes and set values
  //persona.edad = 15;

  // Print attribute values
  //cout << persona.edad << "\n";
  return 0;
}
