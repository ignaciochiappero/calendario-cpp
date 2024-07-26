#include <iostream>
#include <iomanip>
#include <conio.h> 
#include <time.h> 

using namespace std;

void pintarCalendario(int year)
{
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	int mDias[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	string mesLista[] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", 
		"Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" }; 
	
	
	cout<<"  --------------------------------"<<endl;
	cout<<"     Calendario Nacho Dev- "<<year<<endl;
	cout<<"  --------------------------------"<<endl<<endl;
	int dias; 
	int actual; 
	
	int y = year - 1;
	actual = ( y + y/4 - y/100 + y/400 + t[0] + 1) % 7;
	
	for (int i = 0; i < 12; i++) 
	{ 
		if( i==1 )
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) 
				dias = 29;
			else	
				dias = mDias[i];
		else
			dias = mDias[i];
		
		cout<<endl<<"  ------------"<<mesLista[i]<<"-------------"<<endl;   
		
		cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat"<<endl; 
		
		int k; 
		for (k = 0; k < actual; k++) 
			cout<<"     "; 
		
		for (int j = 1; j <= dias; j++) 
		{
			k++;
			cout<<setw(5)<<j;
			if (k > 6) 
			{ 
				k = 0; 
				cout<<endl; 
			} 
		} 
		
		if (k)
			cout<<endl; 
		
		actual = k; 
	}
	
	return; 
}

int main() {
	system("cls");
	
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	
	int year = 1900 + local_time->tm_year; 
	char option;
	
	do{
		system("cls");
		pintarCalendario(year);
		
		cout<<endl<<endl;
		cout<<"Presione "<<endl;
		cout<<"- s para siguiente año"<<endl;
		cout<<"- a para año anterior"<<endl;
		cout<<"- x para cerrar"<<endl;
		option = getche();
		switch(option){
		case 's':
			year++;
			break;
		case 'a':
			year--;
			break;
		}
		
	}while(option!='x' && option!='X');	 	
	
	return 0;
}
