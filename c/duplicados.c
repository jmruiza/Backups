#include <stdio.h>

void muestraUso(char* programa){
	printf("    Uso: %s <directorio>\n", programa);
	printf(" -> Este programa busca los archivos duplicados en el <directorio> especificado \n");
	printf(" -> ejem: \"%s /home/usuario/\"\n", programa);
	printf("          Busca los archivos duplicados en \"/home/usuario/\"\n");
}

void get_files(char* directorio){
	// FILE *cmd=popen(" find . -type -f -print","r");
	// char* cad = "find ../origen -type \"f\" -print";
	
	char *cad = "find ";
	strcpy(&cad[ strlen(cad) ], directorio);
	strcpy(&cad[ strlen(cad) ], " -type \"f\"");
	
	FILE *cmd = popen(cad, "r");
	char tmp[256]={0x0};
	
	while(fgets(tmp,sizeof(tmp),cmd) != NULL){
    		printf("%s", tmp);
	}
	
	pclose(cmd);
}


int main(int argc, char** argv){
//int main(){
	
	if( argc < 2 || argc > 2){
		printf(" -> Error: Solo se adminte un parametro: \"%s <directorio>\"\n", argv[0]);
		muestraUso(argv[0]);
		return 0;
	}
	
	printf("Archivos duplicados en \"%s\":\n", argv[1] );
		
	get_files(argv[1]);
	
/*
	FILE *cmd = popen("find ../origen -type \"f\" -print", "r");
	// FILE *cmd=popen(" find . -type -f -print","r");
	char tmp[256]={0x0};
	
	while(fgets(tmp,sizeof(tmp),cmd) != NULL){
    		printf("%s", tmp);
	}
	
	pclose(cmd);
*/
	return 0;
}
