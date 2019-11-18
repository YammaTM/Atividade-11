#include<stdlib.h>
#include<stdio.h>

/*
    O RadixSort � um algoritmo de ordena��o que ordena
    do d�gito menos significativo para o mais significativo
    usando CountingSort como subrotina
*/

/*
	O coutingSort � respons�vel pela veriifica��o do d�gito respons�vel
	da ordena��o, ou seja, fazer a ordena��o em etapas baseado pelos d�gitos
	em quest�o: Unidade por Unidade, Dezena por Dezena, Centena por Centena...
*/
void CountingSort(int *v,int n, int exp){
    int output[n], count[10]={0};
    int i;

    for (i=0;i<n;i++){
        count[(v[i]/exp)%10]++;
    }
    for(i=1;i<n;i++){
        count[i]+=count[i-1];
    }

    for(i=n-1;i>=0;i--){
        output[count[(v[i]/exp)%10]-1]=v[i];
        count[(v[i]/exp)%10]--;
    }

    for(i=0;i<n;i++){
        v[i]=output[i];
        printf("%d ",v[i]);
    }
    printf("\n");
}

/*
	A fun��o de achar o maior, como o pr�prio nome diz � a respons�vel por achar o maior
	n�mero do vetor, usando isso � capaz de fazer as compara��es do m�todo de radix.
*/
int acharMaior(int *v,int n){
    int maior=v[0];
    for(int i=1;i<n;i++){
        if(v[i]>maior){
            maior=v[i];
        }
    }
    return maior;
}
/*
	E finalmente a fun��o radix propriamente dita, respons�vel pela ordena��o final,
	acahndo primeiramente o maior n�mero para ser usado como condi��o de parada no la�o
	for, em cada itera��o do for � chamada a fun��o countingSort
*/
void Radix(int *v,int n){
    int maior = acharMaior(v,n);
    int exp;
    for(exp=1;exp<=maior;exp*=10){
        CountingSort(v,n,exp);
    }
}
int main (){
    int v[6]={65055372,65919190,65147145,65892478,65055214,65452870};
    Radix(v,6);
    for(int i=0;i<6;i++){
        printf("%d ",v[i]);
    }
    return 0;
}
