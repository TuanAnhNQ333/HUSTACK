
#include <stdio.h>
#include <string.h>
void maxSwap(char a[], char b[]){// Chuyen xau lon nhat thanh xau a
	char c[1001];
	if(strlen(b)>strlen(a)){
		strcpy(c, a);
		strcpy(a, b);
		strcpy(b, c);
	}
}
void reverseString(char x[]){// lat nguoc chuoi
	int l=0, r = strlen(x)-1;
	while(l<r){
		char tmp=x[l];
		x[l]=x[r];
		x[r]=tmp;
		l++, r--;
	}
}
void reverseInt(int sum[], int n){// lat nguoc mang Integer
	int l=0, r=n-1;
	while(l<r){
		int tmp=sum[l];
		sum[l]=sum[r];
		sum[r]=tmp;
		l++, r--;
	}
}
int main(){
	char a[1001], b[1001];
	scanf("%s%s", a, b);
	maxSwap(a, b);
	reverseString(a), reverseString(b);
	int aI[strlen(a)];
    int bI[strlen(a)];
    int sum[2002]={0}, carry=0, n=strlen(a);
	for(int i=0; i<strlen(a); i++){// Chuyen doi 2 xau thanh 2 mang Integer
		aI[i] = a[i]-48;
		if(i<strlen(b)) bI[i] = b[i]-48;;
	}
	for(int i=0; i<strlen(a); i++){// Cong 2 mang integer
		sum[i] = (aI[i]+bI[i]+carry)%10;
		carry = (aI[i]+bI[i]+carry)/10;
	}
	if(carry>0){// Truong hop phep tinh cuoi cung lon hon 10, vi du: 5555+5123=10678 thay vi 0678
        sum[strlen(a)]=carry;
        n = strlen(a)+1;
    }
    reverseInt(sum, n);
	for(int i=0; i<n; i++){
		printf("%d", sum[i]);
	}
	return 0;
}


