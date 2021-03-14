#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int menu(){
	int x;
	system("cls");
	cout<<"--------------------Base de datos empleados--------------------"<<endl<<endl;
	cout<<"Bienvenido a la base de datos de empleados, por favor elija lo"<<endl;
	cout<<"que desea realizar: \n"<<endl;
	cout<<"1. Agregar registro"<<endl;
	cout<<"2. Mostrar registro"<<endl;
	cout<<"3. Buscar registro"<<endl;
	cout<<"4. Editar registro"<<endl;
	cout<<"5. Eliminar registro"<<endl;
	cout<<"6. Salir \n"<<endl;
	cout<<"Opcion: ";
	cin>>x;
	return x;
	
}
bool verifica(string Id){
 ifstream leer ("Archivo.dat", ios::in);
 string id,nom,Ap,pu;
 int su,bo,suma;
 leer>>id;
 while(!leer.eof()){
  leer>>Ap;
  leer>>nom;
  leer>>pu;
  leer>>su;
  leer>>bo;
  leer>>suma;
  if(id == Id){
   cout<<"\n\n\tError: Registro ya existe.\n\n";
   system("pause");
   leer.close();
   return false;
  }
  leer>>id;
 }
   leer.close();
   return true; 
}
void agregar_empleado(ofstream &es) {
	system("cls");
	string id,Ap,nom,pu;
	int su,bo,suma;
	es.open("Archivo.dat", ios::out| ios::app);
	cout<<"Ingrese codigo de empleado:  ";
	cin>>id;
	cout<<"Ingrese Apellido.....:";
	cin>>Ap;
	cout<<"Ingrese Nombre.......:";
	cin>>nom;
	cout<<"Ingrese Puesto.......:";
	cin>>pu;
	cout<<"Ingrese Sueldo.......:";
	cin>>su;
	cout<<"Ingrese Bonificacion:";
	cin>>bo;
	suma=su+bo;
	cout<<"\nEl salario total a pagar es: Q."<<suma<<".00"<<endl;
	system("pause");
	if(verifica(id))
		es<<id<<" "<<Ap<<" "<<nom<<" "<<pu<<" "<<su<<" "<<bo<<" "<<suma<<"\n";
	es.close();
	}

void mostrar_empleado(ifstream &Lec){
	system("cls");
	string id,nom,Ap,pu;
 	int su,bo,suma;
 	Lec.open("Archivo.dat", ios::in);
 	if(Lec.is_open()){
	 	cout<<"-------Empleados-------"<<endl<<endl;
	 	Lec>>id;
	 	while(!Lec.eof()){
			Lec>>Ap;
			Lec>>nom;
			Lec>>pu;
			Lec>>su;
			Lec>>bo;
			Lec>>suma;
			cout<<"Cod. Empleado   : "<<id<<endl;
			cout<<"Nombre          : "<<nom<<endl;
			cout<<"Apellido        : "<<Ap<<endl;
			cout<<"Puesto          : "<<pu<<endl;
			cout<<"Sueldo          : "<<su<<endl;
			cout<<"Bonificacion    : "<<bo<<endl;
			cout<<"\nEl salario total a pagar es: Q."<<suma<<".00"<<endl;
			cout<<"---------------------------------------------"<<endl<<endl;
			Lec>>id;
		 }
		 Lec.close();
	}else
		cout<<"No se encontraron registros"<<endl;
	 system("pause");
}

void buscar_empleado(ifstream &Lec){
	system("cls");
	Lec.open("Archivo.dat", ios::in);
	string id, Ap, nom, pu, idaux;
	int su, bo, suma;
	bool encontrado = false;
	cout<<"Ingrese el codigo de empleado a buscar: ";
	cin>>idaux;
	Lec>>id;
	while(! Lec.eof() && !encontrado){	
		Lec>>id;
		Lec>>Ap;
		Lec>>nom;
		Lec>>pu;
		Lec>>su;
		Lec>>bo;
		Lec>>suma;
		if(id == idaux){
			cout<<"Codigo      : "<<id<<endl;
			cout<<"Nombre      : "<<nom<<endl;
			cout<<"Apellido    : "<<Ap<<endl;
			cout<<"Puesto      : "<<pu<<endl;
			cout<<"Sueldo      : "<<su<<endl;
			cout<<"Bonificacion: "<<bo<<endl;
			cout<<"Sueldo Total: "<<suma<<endl;
			encontrado = true;
		}	
		Lec>>id;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"No se encontro ningun registro"<<endl<<endl;
	system("pause");
}

void editar_empleado(ifstream &Lec){
	system("cls");
 	string Ap,id,nom,pu;
	int su,bo,suma;
	string idaux,Apaux,nomaux,puaux;
	int suaux,boaux,sumaaux;
	Lec.open("Archivo.dat", ios::in);
	ofstream aux("temp.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Editar registros--------------------"<<endl;
		cout<<"Ingrese codigo de empleado:  ";
		cin>>idaux;
		Lec>>id;
		while(!Lec.eof()){
		  	Lec>>Ap;
			Lec>>nom;
			Lec>>pu;
			Lec>>su;
			Lec>>bo;
			if(id == idaux){
				cout<<"\nIngrese Apellido    :";
				cin>>Apaux;
				cout<<"\nIngrese Nombre       :";
				cin>>nomaux;
				cout<<"\nIngrese Puesto       :";
				cin>>puaux;
				cout<<"\nIngrese Sueldo       :";
				cin>>suaux;
				cout<<"\nIngrese Bonificacion       :";
				cin>>boaux;
				sumaaux=suaux+boaux;
				aux<<id<<" "<<Apaux<<" "<<nomaux<<" "<<puaux<<" "<<suaux<<" "<<boaux<<" "<<sumaaux<<"\n";
			}else{
				suma=su+bo;
				aux<<id<<" "<<Ap<<" "<<nom<<" "<<pu<<" "<<su<<" "<<bo<<" "<<suma<<"\n";
			}
				
			Lec>>id;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"No se encontraron registros para modificar"<<endl;
	remove ("Archivo.dat");
	rename("temp.dat", "Archivo.dat");
}

void eliminar_empleado(ifstream &Lec){
	system("cls");
 	string Ap,id,nom,pu;
	int su,bo,suma;
	string idaux,Apaux,nomaux,puaux;
	int suaux,boaux,sumaaux;
	Lec.open("Archivo.dat", ios::in);
	ofstream aux("temp.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Registro a eliminar--------------------"<<endl;
		cout<<"Ingrese codigo de empleado:  ";
		cin>>idaux;
		Lec>>id;
		while(!Lec.eof()){
		  	Lec>>Ap;
			Lec>>nom;
			Lec>>pu;
			Lec>>su;
			Lec>>bo;
			if(id == idaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"------Registro eliminado-----"<<endl;
				Sleep(1500);
				cout<<"--------------------------------------"<<endl;
			}else{
				aux<<id<<" "<<Ap<<" "<<nom<<" "<<pu<<" "<<su<<" "<<bo<<" "<<suma<<"\n";
				
			}
			
			Lec>>id;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"Registro no se pudo eliminar"<<endl;
	remove ("Archivo.dat");
	rename("temp.dat", "Archivo.dat");	
	
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{	
		system("cls");
		op = menu();
		switch(op){
			case 1:
				agregar_empleado(Esc);
				break;
			case 2:
				mostrar_empleado(Lec);
				break;
			case 3:
				buscar_empleado(Lec);
				break;
			case 4:
				editar_empleado(Lec);
				break;
			case 5:
				eliminar_empleado(Lec);
				break;	
		}	
	}while(op != 6);
	return 0;
}
