#include <stdio.h>



/*  orientador
*
*	 0 || 4
*
*3 || 7   1 || 5
*
*	 2 || 6
*/

int labirinto [10] [10] = 
{
{8,8,8,8,8,8,8,8,8,8},
{8,1,0,0,8,0,0,0,0,8},
{8,8,8,0,8,0,8,0,8,8},
{8,0,0,0,0,0,8,8,0,8},
{8,0,8,8,8,0,0,0,0,8},
{8,0,0,0,8,8,8,8,8,8},
{8,8,8,0,8,8,8,8,8,8},
{8,0,0,0,0,0,0,0,8,8},
{8,8,8,0,8,8,8,0,0,8},
{8,8,8,8,8,8,8,8,8,8}		
};

int pos[2]={1,1};

int Backtracking (int origem){
	int i, j, k; 
	int retorno = 1;
	int destino [2] = { pos[0], pos[1] };
	for ( i = (origem + 1) % 4; i != origem % 4; i++ ){
		if ( retorno == 0 || ( pos [0] == 8 && pos [1] == 8 )) return 0;
		else {
			switch (i % 4) {
				case 0: destino [0] = pos[0] - 1;destino [1] = pos[1];break;
				case 1: destino [1] = pos[1] + 1;destino [0] = pos[0];break;
				case 2: destino [0] = pos[0] + 1;destino [1] = pos[1];break;
				case 3: destino [1] = pos[1] - 1;destino [0] = pos[0];break; 				
			}
			if (labirinto [destino [0]] [destino [1]] == 0) {
				labirinto [pos [0]] [pos [1]] = 0;
				pos [0] = destino [0];
				pos [1] = destino [1];
				labirinto [pos [0]] [pos [1]] = 1;
				for (j=0;j<10;j++){
					for (k=0;k<10;k++){
						printf("%d ",labirinto[j][k]);
					}
					printf("\n");
				}
				getchar();
				retorno = Backtracking ( ( i + 2 ) % 4 );
			}
		}
	}
}

int main () {
	Backtracking (3);
	return 0;
}

