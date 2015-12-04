/*Funzionante: sì. Svolto: sì. Approfondimenti: N/D.
##################PROGRAMMA LAB08 - 12BHDLZ - Esercizio 3####################
#                                                                           #
#Copyright © 2015 Corrado Mulas.                                            #
#                                                                           #
#Rilasciato dietro licenza GNU GENERAL PUBLIC LICENSE VERSION 3             #
#                                                                           #
#    This program is free software: you can redistribute it and/or modify   #
#    it under the terms of the GNU General Public License as published by   #
#    the Free Software Foundation, either version 3 of the License, or      #
#    (at your option) any later version.                                    #
#                                                                           #
#    This program is distributed in the hope that it will be useful,        #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of         #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          #
#    GNU General Public License for more details.                           #
#                                                                           #
#    You should have received a copy of the GNU General Public License      #
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.  #
#                                                                           #
#############################################################################
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define N 6

int stime(hh, mm)
{
	//converte gli orari in secondi.
	//1448754863
	int s1, s2;
	
	s1 = hh*3600;
	s2 = mm*60;
	
	return (s1+s2);
	
}

int main(int argc, char **argv)
{
	//sscanf (stdinconfgets,"%d:%d",&hh,&mm); //RESTITUISCE EOF SE VA A PUTTANE
	char std1[N];
	int hh;
	int mm;
	int diff = 0;
	int hh1;
	int mm1;
	
	int e = 0;
	
	printf("\nInserire un orario nel formato [hh:mm]: ");
	while(fgets(std1, N, stdin) != NULL && e == 0)
	{
		//Leggo orario
		if(!sscanf(std1, "%d:%d", &hh, &mm))
		{
			printf("\nFormato non valido.\n");
			e++;
		}
		else
		{
			if(hh > 23 || mm > 60 || hh < 0 || mm < 0)
			{
				printf("\nFormato non valido.");
				e++;
			}
			else
			{
				printf("\nOrario inserito: %d : %d", hh, mm);
			}
		}
	
		e = 0;
		

		e++;
		
	}
	
	e = 0;
	
	printf("\nInserire un altro orario nel formato [hh:mm]: ");	
	while(fgets(std1, N, stdin) != NULL && e == 0)
	{
		//Leggo orario
		if(!sscanf(std1, "%d:%d", &hh1, &mm1))
		{
			printf("\nFormato non valido.\n");
			e++;
		}
		else
		{
			if(hh1 > 23 || mm1 > 60 || hh1 < 0 || mm1 < 0)
			{
				printf("\nFormato non valido.");
				e++;
			}
			else
			{
				printf("\nOrario inserito: %d : %d", hh1, mm1);
			}
		}
	
		e = 0;
		

		e++;
		}
		
		if(stime(hh, mm) < stime(hh1,mm1))
		{
			printf("\nIl secondo orario inserito, è cronologicamente conseguente al primo.");
			
			diff = stime(hh1,mm1) - stime(hh, mm);
			
			diff /= 60;
			printf("\nMinuti di differenza: %d", diff);
		}
		else
		{
			if(stime(hh, mm) == stime(hh1,mm1))
			{
				printf("\nIl secondo orario inserito, è identico al primo.");
			}
			else
			{
				printf("\nIl secondo orario inserito, è cronologicamente antecedente al primo.");
				diff = stime(hh, mm) - stime(hh1, mm1);
			
				diff /= 60;
				printf("\nMinuti di differenza: %d", diff);
			}
		}
		//printf("\n%d", stime(hh, mm));
		//printf("\n%d", stime(hh1,mm1));
		
		//
		
		printf("\n%d_minuti\n", diff);
	return 0;
}
