#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)==(y)?0:((x)>(y)?1:-1))
#define MAX 100

typedef struct{
	int expo;
	int coef;

}po;

po poly[MAX];
int avail = 0;

void attach(int expo, int coef){
	if(avail>=MAX){
		printf("array index out of range");
		exit(0);
	}
	else{
		poly[avail].expo = expo;
		poly[avail].coef = coef;
		avail++;
	}	
}


void add(int starta, int enda, int startb, int endb, int startc, int endc){
	int i, j;
	while(starta<=enda && startb<=endb){
		switch(COMPARE(poly[starta].expo,poly[startb].expo)){
			case 1:	poly[avail].expo = poly[starta].expo;
				poly[avail].coef = poly[starta].coef;
				avail++, starta++;
				break;

		        case -1:  poly[avail].expo = poly[startb].expo;
				  poly[avail].coef = poly[startb].coef;
				  avail++, startb++;
				  break;

			case 0:	  poly[avail].expo = poly[startb].expo;
				  poly[avail].coef = poly[starta].coef + poly[startb].coef;
				  avail++, starta++, startb++;


		}

	}

	for(i=starta; i<=enda; i++){
		poly[avail].expo = poly[i].expo;
		poly[avail].coef = poly[i].coef;
	}

	for(i=startb; i<=endb; i++){
		poly[avail].expo = poly[i].expo;
		poly[avail].coef = poly[i].coef;
	}
}


void main(){
	
	int n1, n2;
	printf("enter the no of tearm in poly A and poly B\t");
	scanf("%d%d", &n1, &n2);

	
	int i, j, j2;
	int starta, startb, startc, enda, endb, endc;
	starta = 0;
	for(i=0; i<n1; i++){
		printf("enter the %d expo and coef of poly A\t",i+1);
		scanf("%d%d",&j,&j2);
		attach(j,j2);

	}
	enda = avail-1;
	startb = avail;
	for(i=0; i<n2; i++){
		printf("enter the %d expo and coef of poly B\t",i+1);
		scanf("%d%d",&j,&j2);
		attach(j,j2);

	}
	endb = avail-1;
	startc=avail;
	add(starta,enda,startb,endb,startc,endc);
	endc = avail-1;

	for(i=startc; i<=endc; i++){
		printf("expo is %d   and coef %d \n", poly[i].expo, poly[i].coef);
	}
}
