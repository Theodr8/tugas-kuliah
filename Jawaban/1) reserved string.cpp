#include <stdio.h>
#include <string.h>

void Reserve(char *kata,int size){
	for (int i=0;i<size/2;i++){
		char temp;
		temp = kata[i];
		kata[i] = kata[size-i-1];
		kata[size-i-1] = temp;
	}
}

void Pengubah(char *kata,int panjang){
	for (int i=0;i<panjang;i++){
	if (kata[i] >= 'A' && kata[i] <= 'Z'){
		kata[i] = kata[i] +32;	
	}
	else if (kata[i] >= 'a' && kata[i] <= 'z'){
		kata[i] = kata[i] -32;	
	}
	}
}

int main(){
	char kata[101];
	scanf ("%[^\n]", kata);
	int panjang = strlen(kata);
	Reserve(kata,panjang);
	Pengubah(kata,panjang);
	printf ("%s\n",kata);
	return 0;
}
