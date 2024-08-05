#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define st struct

//kelar
struct malaysia {
  char location1[50];
  char location2[30];
  char price[21];
  int rooms;
  int bathrooms;
  int carparks;
  char type[30];
  char furnish[30];
};

//kelar
void menu() { //nampilin file pas diawal"
  puts("1. Display data");
  puts("2. Search Data");
  puts("3. Sort Data");
  puts("4. Export Data");
  puts("5. Exit");
}

void swap(st malaysia *a,st malaysia*b){
	malaysia temp = *a;
	*a = *b;
	*b = temp;
}

int readfile(char fname[], st malaysia mys[]){
	int n=0;
	FILE *fptr = fopen(fname,"r");
	
	char buffer[1000];
    if (fgets(buffer, sizeof(buffer), fptr) == NULL) {
    perror("Error reading file");
	}
	else {
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
    	sscanf(buffer, "%30[^;];%30[^;];%21[^;];%13d;%13d;%13d;%30[^;];%30s",
          mys[n].location1, mys[n].location2, mys[n].price,
          &mys[n].rooms, &mys[n].bathrooms, &mys[n].carparks,
          mys[n].type, mys[n].furnish);

      n++;
    }
    
  
	}
    fclose(fptr);
    return n;
}



void bubblesortAscloc(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-i-1;j++){
			if (strcmp(arr[j].location1,arr[j+1].location1)>0){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void bubblesortDscloc(st malaysia arr[],int size){
	for (int i=0;i<size;i++){
		for (int j=0;j<size-1;j++){
			if (strcmp(arr[j+1].location1,arr[j].location1)>0){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void bubblesortAscloc2(st malaysia arr[],int size){
	for (int i=0;i<size;i++){
		for (int j=0;j<size-1;j++){
			if (strcmp(arr[j].location2,arr[j+1].location2)>0){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void bubblesortDscloc2(st malaysia arr[],int size){
	for (int i=0;i<size;i++){
		for (int j=0;j<size-1;j++){
			if (strcmp(arr[j+1].location2,arr[j].location2)>0){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void bubblesortAscprc(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-i-1;j++){
			if (strcmp(arr[j].price,arr[j+1].price)>0){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void bubblesortDscprc(st malaysia arr[],int size){
	for (int i=0;i<size;i++){
		for (int j=0;j<size-1;j++){
			if (strcmp(arr[j+1].price,arr[j].price)==0){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void bubblesortAscroom(st malaysia arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].rooms > arr[j + 1].rooms) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubblesortDscroom(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-i-1;j++){
			if (arr[j+1].rooms>arr[j].rooms){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void bubblesortAscbrm(st malaysia arr[],int size){
	for (int i=0;i<size;i++){
		for (int j=0;j<size-1;j++){
			if (arr[j].bathrooms>arr[j+1].bathrooms){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void bubblesortDscbrm(st malaysia arr[],int size){
	for (int i=0;i<size;i++){
		for (int j=0;j<size-1;j++){
			if (arr[j+1].bathrooms>arr[j].bathrooms){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void bubblesortAsccp(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-1-1;j++){
			if (arr[j].carparks>arr[j+1].carparks){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void bubblesortDsccp(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-i-1;j++){
			if (arr[j+1].carparks>arr[j].carparks){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void selectionsortasctp(st malaysia arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(arr[j].type, arr[minIndex].type) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void bubblesortDsctp(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-1-i;j++){
			if (strcmp(arr[j+1].type,arr[j].type)>0){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void bubblesortAscfsh(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-i-1;j++){
			if (strcmp(arr[j].furnish,arr[j+1].furnish) > 0){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void bubblesortDscfsh(st malaysia arr[],int size){
	for (int i=0;i<size-1;i++){
		for (int j=0;j<size-i-1;j++){
			if (strcmp(arr[j+1].furnish,arr[j].furnish)>0){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void printall(st malaysia mys[], int panjang) {
  printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
      "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");

  for (int i = 0; i < panjang; i++) {
  	if (i==0){
    printf("%-20s %-20s %-13s %-13d %-13d %-13d %-13s %s\n",
        mys[i].location1, mys[i].location2, mys[i].price,
        mys[i].rooms, mys[i].bathrooms, mys[i].carparks,
        mys[i].type, mys[i].furnish);
		}
    else if (i>0){
    printf("%-20s %-20s %-13s %-13d %-13d %-13d %-13s %s\n",
        mys[i].location1, mys[i].location2, mys[i].price,
        mys[i].rooms, mys[i].bathrooms, mys[i].carparks,
        mys[i].type, mys[i].furnish);
		}
  }
}

void printall2(st malaysia mys[], int panjang) {
  for (int i = 0; i < panjang; i++) {
//  	if (i==0){
    printf("%-20s %-20s %-13s %-13d %-13d %-13d %-13s %s\n",
        mys[i].location1, mys[i].location2, mys[i].price,
        mys[i].rooms, mys[i].bathrooms, mys[i].carparks,
        mys[i].type, mys[i].furnish);
//		}

  }
}
//void fprintall(st malaysia mys[], int panjang,) {
//  for (int i = 0; i < panjang; i++) {
//    fprintf(fp,"%-20s %-20s %-13s %-13d %-13d %-13d %-13s %s\n",
//        mys[i].location1, mys[i].location2, mys[i].price,
//        mys[i].rooms, mys[i].bathrooms, mys[i].carparks,
//        mys[i].type, mys[i].furnish);
//  }
//}



//display
void menu1(st malaysia mys[],int n) {

//  FILE *fptr = fopen("file2.csv", "r");
//  readfile("file2.csv",mys);
  

//  if (fptr == NULL) {
//    perror("Read Error:");
//    exit(1);
//  }
//
//  char buffer[4001];
//  if (fgets(buffer, sizeof(buffer), fptr) == NULL) {
//    perror("Error reading file");
//    fclose(fptr);
//    exit(1);
//  }

  printf("Number of rows: ");
  int rows;
  scanf("%d", &rows);
  if (rows<=0){
  	printf ("Data yang dimasukan harus lebih sama dengan dari 1");
  }
//  unsigned long long int n = 0;

//  while (n != rows) {
//    fscanf(fptr, "%20[^;];%20[^;];%13[^;];%13d;%13d;%13d;%13[^;];%13s", &mys[n].location1, &mys[n].location2,
//      &mys[n].price, &mys[n].rooms, &mys[n].bathrooms, &mys[n].carparks, &mys[n].type, &mys[n].furnish);
//    n++;
//  }

//  fclose(fptr);

	else printall(mys, rows);
  getchar();
}

//selectrow
void menu2(st malaysia mys[],int n) {

  char tujuan[30];
  char tujuan2[101];

  printf("Choose column: ");
  scanf("%s", tujuan);
  getchar();

  puts("What data do you want to find?");
  scanf("%s", tujuan2);
  getchar();
if (strcmpi(tujuan,"Location")==0){
  
int jwb=0;
int i=0;
  for(int i=0;i<n;i++) {
      if (strcmpi(tujuan2,mys[i].location1) == 0) {
        if (jwb == 0) {
          printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
              "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not2 Found!\n"); 
		  }
		 
	}
	
	else if (strcmpi(tujuan,"City")==0){
	int jwb=0;
	int i=0;
	  for(int i=0;i<n;i++) {
	      if (strcmpi(tujuan2,mys[i].location2) == 0) {
	        if (jwb == 0) {
          	printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
              	"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not2 Found!\n"); 
		  }
		 
	}
	
	else if (strcmpi(tujuan,"Price")==0){
int jwb=0;
int i=0;
  for(int i=0;i<n;i++) {
      if (strcmpi(tujuan2,mys[i].location1) == 0) {
        if (jwb == 0) {
          printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
              "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not2 Found!\n"); 
		  }
		 
	}
	else if (strcmpi(tujuan,"Rooms")==0){

	int jwb=0;
	int i=0;
	  for(int i=0;i<n;i++) {
	      if (atoi(tujuan2)==mys[i].rooms) {
	        if (jwb == 0) {
	          printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
	              "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
	          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not Found!\n"); 
		  }
		 
	}
	
	else if (strcmpi(tujuan,"Bathroom")==0){

	int jwb=0;
	int i=0;
	  for(int i=0;i<n;i++) {
	      if (atoi(tujuan2)==mys[i].bathrooms) {
	        if (jwb == 0) {
	          printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
	              "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
	          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not Found!\n"); 
		  }
		 
	}
	
	else if (strcmpi(tujuan,"CarPark")==0){

	int jwb=0;
	int i=0;
	  for(int i=0;i<n;i++) {
	      if (atoi(tujuan2)==mys[i].carparks) {
	        if (jwb == 0) {
	          printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
	              "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
	          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not Found!\n"); 
		  }
		 
	}
	
	else if (strcmpi(tujuan,"Type")==0){
	int jwb=0;
int i=0;
  for(int i=0;i<n;i++) {
      if (strcmpi(tujuan2,mys[i].type) == 0) {
        if (jwb == 0) {
          printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
              "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not2 Found!\n"); 
		  }
		 
	}
	else if(strcmpi(tujuan,"Furnish")==0){
	int jwb=0;
	int i=0;
	  for(int i=0;i<n;i++) {
	      if (strcmpi(tujuan2,mys[i].furnish) == 0) {
	        if (jwb == 0) {
	          printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
              	"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
          jwb = 1;
        }
        printall2(&mys[i],1);
         
      }
      
	}
			if(!jwb) {
			printf("Data not Found!\n"); 
		  }
		 
	}
	
  else printf ("Data not Found!\n");
}


//sorting
void menu3(st malaysia mys[],int n) {


  printf("Choose Column: ");
  char tujuan[400];
  scanf("%s", tujuan);

  printf("Sort ascending or descending? ");
  char tujuan2[400];
  scanf("%s", tujuan2);
	getchar();
	

  int jwb = 0;
	if (strcmpi(tujuan, "location") == 0|| strcmpi(tujuan,"City")==0) {
		
        if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
          bubblesortAscloc(mys, n);
        } 
		else if (strcmpi(tujuan2, "descending")==0 || strcmpi(tujuan2,"dsc")== 0) {
          bubblesortDscloc(mys, n);
		}
		jwb=1;
  }
  
//  else if (strcmpi(tujuan, "City") == 0) {
////    if (jwb == 0) {
////    	printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
////      "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
//////      jwb = 1;
////      }
//
//    if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
////      bubblesortAscloc2(mys, n);
//        } 
//	else if (strcmpi(tujuan2, "descending")==0 || strcmpi(tujuan2,"dsc")== 0) {
////      bubblesortDscloc2(mys, n);
//        }
//        
//	jwb=1;
//  }
  else if (strcmpi(tujuan, "price") == 0) {

	    if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
	      bubblesortAscprc(mys, n);
       	 } 
		else if (strcmpi(tujuan2, "descending")==0 || strcmpi(tujuan2,"dsc")== 0) {
      bubblesortDscprc(mys, n);
        }
        jwb=1;
  }
  else if (strcmpi(tujuan, "rooms") == 0) {


    if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
      bubblesortAscroom(mys,n);
        } 
		else if (strcmpi(tujuan2, "descending") || strcmpi(tujuan2,"dsc")== 0) {
      bubblesortDscroom(mys, n);
        }
        
jwb=1;
  }
  else if (strcmpi(tujuan, "bathroom") == 0) {

    if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
      bubblesortAscbrm(mys, n);
        } 
		else if (strcmpi(tujuan2, "descending") || strcmpi(tujuan2,"dsc")== 0) {
      bubblesortDscbrm(mys, n);
        }
        jwb=1;
  }
  else if (strcmpi(tujuan, "carpark") == 0) {

    if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
      bubblesortAsccp(mys, n);
        } 
		else if (strcmpi(tujuan2, "descending") || strcmpi(tujuan2,"dsc")== 0) {
      bubblesortDsccp(mys, n);
        }
	jwb=1;
  }
	else if (strcmpi(tujuan, "Type") == 0) {

        if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
          selectionsortasctp(mys, n);
        } else if (strcmpi(tujuan2, "descending")==0 || strcmpi(tujuan2,"dsc")== 0) {
          bubblesortDsctp(mys, n);
        }
	jwb=1;
  }
  else if (strcmpi(tujuan, "Furnish") == 0) {

    if (strcmpi(tujuan2, "ascending") == 0 || strcmpi(tujuan2,"asc")==0) {
      bubblesortAscfsh(mys, n);
        } 
		else if (strcmpi(tujuan2, "descending")==0 || strcmpi(tujuan2,"dsc")== 0) {
      bubblesortDscfsh(mys, n);
        }
	jwb=1;
  }	
      
  if (jwb){
  printf("%-20s %-20s %-13s %-13s %-13s %-13s %-13s %s\n",
      "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
  	for (int i=0;i<10;i++){
     printall2(&mys[i], 1);
	}
  }
  else if (!jwb) {
    printf("Data not Found!\n");
  }

}

void menu4(st malaysia mys[],int n){
		
    char tujuan[50];
    printf ("File Name: ");
    scanf ("%s",tujuan);
    FILE *fp = fopen(tujuan,"w");
    getchar();
    
    for (int i = 0; i < n; i++) {
    fprintf(fp,"%-20s %-20s %-13s %-13d %-13d %-13d %-13s %s\n",
        mys[i].location1, mys[i].location2, mys[i].price,
        mys[i].rooms, mys[i].bathrooms, mys[i].carparks,
        mys[i].type, mys[i].furnish);
  }
    
    printf ("Data successfully written to file sorted %s !",tujuan);

    fclose(fp);
	}


int main() {

//  FILE *fptr = fopen("file2.csv", "r");
//
//  if (fptr == NULL) {
//    perror("Read Error:");
//    exit(1);
//  }
//   
//  char buffer[1000];
//    if (fgets(buffer, sizeof(buffer), fptr) == NULL) {
//    perror("Error reading file");
//    fclose(fptr);
//    exit(1);
//  }
	
//	st malaysia mys[]
	

  int n=0;
  malaysia arr[4001] = {};
  
  n = readfile("file2.csv",arr);
  int choice;

  do {
    system("cls");
    menu();	
    printf("Your choice:");
    scanf("%d", &choice);

    switch (choice) {
    case 1: //display data
      menu1(arr,n);
      getchar();
      break;
	case 2: //search data
		menu2(arr,n);
		getchar();
		break;
    case 3: //sort data
      menu3(arr,n);
      getchar();
      break;
	case 4: //export
		menu4(arr,n);
		getchar();
		break;
    }
  } while (choice != 5);
  printf("Good Bye and See You Next Time (^_^)/");
//  fclose(fptr);
  return 0;
}
