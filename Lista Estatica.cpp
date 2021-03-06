#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Lista[MAX];


void Insertar_al_inicio();
void Insertar_al_final();
void Insertar_en_posicion_deseada();
void Eliminar_de_la_lista();
void Reportar_lista();
void Verificar_estado_de_la_lista();
void Vaciar_la_lista();
void Buscar_en_la_lista();
void Buscar_kesimo_la_lista();


int Verificar_si_lista_esta_llena(int lista[]);
int Verificar_si_lista_esta_vacia(int lista[]);

int main() {
	
	int op;
    int posicion;
    
	do{
    	
    printf("\n\n--------------BIENVENIDO AL PROGRAMA DE LISTAS DINAMICAS--------------");
	printf("\n Puedes realizar las siguientes tareas: \n   ");
	printf("\n  1. INSERTAR ELEMENTO AL INICIO.            ");
	printf("\n  2. INSERTAR ELEMENTO AL FINAL.             ");
	printf("\n  3. INSERTAR ELEMENTO EN POSICION DEFINIDA. ");
	printf("\n  4. ELIMINAR ELEMENTO.                      ");
	printf("\n  5. REPORTAR LISTA.                         ");
	printf("\n  6. VERIFICAR EL ESTADO DE LISTA.           ");
	printf("\n  7. VACIAR LA LISTA.                        "); 
	printf("\n  8. BUSCAR EN LA LISTA.                     ");
	printf("\n  9. BUSCAR K-ESIMO EN LA LISTA.             ");
	printf("\n  10. SALIR.                                 ");
    printf("\n\n   POR FAVOR INGRESE OPCION: ");
    
    scanf("%d",&op);
    
    printf("\n");
    	
        switch(op){
        	
            case 1:
            	Insertar_al_inicio();
            break;

            case 2:
            	Insertar_al_final();
            break;
    
			case 3:
				Insertar_en_posicion_deseada();	
            break;
 
            case 4:
            	Eliminar_de_la_lista();
            break;

            case 5:
            	Reportar_lista();
            break;
            
            
            case 6:
				Verificar_estado_de_la_lista();
            break;
            
            
            case 7:
				Vaciar_la_lista();    	
            break;
            
            
            case 8:
            	Buscar_en_la_lista();
            break;
            
            case 9:
				Buscar_kesimo_la_lista();  
            break;
            
            case 10:
            	printf("\n\n\n\t\tHasta la proxima :v \n\n\n");
            	return 0;
			break;
        }
 
        system("pause");
        system("cls");
 
    }while(op<10);
 
   return 0;

}



void Insertar_al_inicio(){
	
	int valor;
	
    if(!Verificar_si_lista_esta_llena(Lista)){
    	
		int x;
		int tam = 0;
		
		for (x = 1; x<=Lista[0]; x++) {
		    tam++;
		}
			
		if(tam == 0){
			
			Insertar_al_final();
			
		}else{
			
			printf("\n\tEscribe el valor del dato: ");
			scanf("%d", &valor);
			
			tam = tam + 1;
			
			int ListaAux[tam];
			int i;
			int aux = 0;
			
			for(i = 1; i < tam; i++){
				
				ListaAux[aux] = Lista[i];
				
				aux++;
			}
			
			Lista[1] = valor;	
       		
       		Lista[0]++;
			aux = 0;
			
			for(i = 2; i <= tam+1; i++){
				
				Lista[i] = ListaAux[aux];
				aux++;
				
			}
       		
    	}
		
    }else{
    	
    	printf("\n\tError al insertar, lista llena");
    	printf("\n\n");
    	
	}
}


	
void Insertar_al_final(){
	
	int valor;
	
	if(!Verificar_si_lista_esta_llena(Lista)){
		
		printf("\n\tEscribe el valor del dato: ");
    	scanf("%d", &valor);
		
        Lista[Lista[0]+1] = valor;
        Lista[0]++;
        
    }else{
    	
    	printf("\n\tError al insertar, la lista llena.");
    	printf("\n\n");
    	
	}
}


void Insertar_en_posicion_deseada(){
	
	int valor;
	int posicion;
	
    if(!Verificar_si_lista_esta_llena(Lista)){

    	printf("\n\tEscribe la posicion en la que desea agregar: ");
		scanf("%d", &posicion);
		    	
    	printf("\n\tEscribe el valor del dato: ");
		scanf("%d", &valor);

        if(posicion > 0 && posicion < Lista[0]){
        	
            int ListaAux[(Lista[0]-posicion)];
            int i, j = 0;
            
            for (i = posicion; i <= Lista[0]; i++) {
            	
                ListaAux[j] = Lista[i];
                j++;
            }
            Lista[posicion] = valor;
            
            j = 0;
            
            for (i = posicion+1; i <= Lista[0]+1; i++) {
            	
                Lista[i] = ListaAux[j];
                j++;
            }
            
            Lista[0]++;
            return;
        }
        
        if(posicion == Lista[0]){
            int aux = Lista[posicion];
            Lista[posicion] = valor;
            Lista[posicion+1] = aux;
            Lista[0]++;
            return;
        }
    }
    else{
    	
        printf("\n\tError al insertar, la lista esta llena");
        printf("\n\n");
    }
}


void Eliminar_de_la_lista(){
	
	int posicion;
	
    if(!Verificar_si_lista_esta_vacia(Lista)){
    	
    	printf("\n\tEscribe la posicion en la que desea eliminar: ");
		scanf("%d", &posicion);
    	
        if(posicion > 0 && posicion < Lista[0]){
        	
            int ListaAux[(Lista[0]-posicion)];
            int i, j=0;
            
            for (i = posicion+1; i <= Lista[0]; i++) {
            	
                ListaAux[j] = Lista[i];
                j++;
            }
            
            j=0;
            
            for (i = posicion; i <= Lista[0]-1; i++) {
            	
                Lista[i] = ListaAux[j];
                j++;
            }
            
            Lista[0]--;
            return;
        }
        
        if(posicion == Lista[0]){
            Lista[0]--;
            return;
        }
    }
    else{
    	
        printf("\n\tError al eliminar, la lista esta vacia");
        printf("\n\n");
    }
}



void Reportar_lista(){
	
	if(!Verificar_si_lista_esta_vacia(Lista)){
    	
		int i;
    	for (i = 1; i<=Lista[0]; i++){
    		
        	printf("\n\t  %i- %i", i, Lista[i]);
        
    	}
    	
    	printf("\n\n");

    }
    else{
    	
        printf("\n\tError al reportar, la lista esta vacia\n");
        
    }

}



void Verificar_estado_de_la_lista(){
	
	if(!Verificar_si_lista_esta_vacia(Lista)){
		
		if(!Verificar_si_lista_esta_llena(Lista)){
		
			printf("\n\tLa lista esta contiene elementos");
        	printf("\n\n");
        
    	}else{
    		
    		printf("\n\tLa lista esta llena");
        	printf("\n\n");
		}
    	
    }
    else{
    	
        printf("\n\tLa lista esta vacia\n");
        printf("\n\n");
        
    }

}


void Vaciar_la_lista(){
	
	if(!Verificar_si_lista_esta_vacia(Lista)){
		
		int i;
		
		for(i = 1; i <= 10; i++){
			
			Lista[0]--;
		}
		
        printf("\n\tLa lista se ha vaciado");
        printf("\n\n");
        
	}else{
    	
        printf("\n\tLa lista esta vacia");
        printf("\n\n");
        
    }
	
	
}


void Buscar_en_la_lista(){
	
	int valor;
	int valor_buscado = 1;
	int encontrado;
	int posicion = 1;
	
    if(Lista[0]>0){
    	
    	printf("\n\tEscribe el valor del dato: ");
		scanf("%d", &valor);
		
		do{
			
			if(valor == Lista[valor_buscado]){
            
            	encontrado = 1;
            	valor_buscado++;
            	break;
       		}
			valor_buscado++;
			
		}while(valor_buscado <= Lista[0]);
    	   	


        if(encontrado == 1){
        	
        	valor_buscado--;
			printf("\n\t El valor %d se encuentra en la posicion %d .",valor , valor_buscado);
        	printf("\n\n");
        	
        	
		}else{
			
			printf("\n\t El valor %d no se encuentra en la lista.", valor);
        	printf("\n\n");
			
		}
		   
    }else{
    	
    	printf("\n\t La lista esta vacia.", valor);
        printf("\n\n");
    	
	}
    
}

void Buscar_kesimo_la_lista(){
	
	int posicion;
	int valor_buscado;
	int encontrado;
	
    if(Lista[0]>0){
    	
    	printf("\n\tEscribe la posicion del dato: ");
		scanf("%d", &posicion);
    	
        for(valor_buscado = 0; valor_buscado <= posicion; valor_buscado++){
        	
            if(valor_buscado == posicion){
                
                encontrado = 1;
                
            }
            
        }
        
        if(encontrado == 1){
        	
        	valor_buscado--;
			printf("\n\t En la posicion %d se encuentra en el valor %d .",valor_buscado, Lista[valor_buscado]);
        	printf("\n\n");
        	
		}else{
			
			printf("\n\t En la lista no se encuentra algun valor en la posicion %d", valor_buscado);
        	printf("\n\n");
			
		}

        
    }else{
    	
    	printf("\n\t La lista esta vacia.");
        printf("\n\n");
    	
	}
    	
	
}




int Verificar_si_lista_esta_llena(int lista[]){
	
    return lista[0] >= MAX;
}


int Verificar_si_lista_esta_vacia(int lista[]){
	
    return lista[0] == 0;
}



