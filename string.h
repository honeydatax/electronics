#include <stdarg.h>

int strslen(char *s);
int strcopy(char *s1,char *s2);
int strncopy(char *s1,char *s2,int size);
int strcat(char *s1,char *s2);
int ucase(char *s);
int lcase(char *s);
int findchar(char *s,char c);
int strnfill(char *s1,char c,int size);
int incmp(char *s,char *s2);
int strsfills(char *s,char c);
void strsint(char *s,int n);
void strslong(char *s,long n);
void strsfloat(char *s,float n);
void strsdouble(char *s,double n);
int ssprintf(char *stringss,char *format,int num, ... );


int strslen(char *s){
	int pos=0;
	while(s[pos]!=0){
		pos++;
	}
	return pos;
}

int strcopy(char *s1,char *s2){
	int pos=0;
	while(s2[pos]!=0){
		s1[pos]=s2[pos];
		pos++;
	}
	s1[pos]=s2[pos];
	return pos;
}

int strncopy(char *s1,char *s2,int size){
	int pos=0;
	while(pos<=size){
		s1[pos]=s2[pos];
		pos++;
	}
	return pos;
}

int strcat(char *s1,char *s2){
	int pos=0;
	char *s3;
	s3=s1+strslen(s1);
	while(s2[pos]!=0){
		s3[pos]=s2[pos];
		pos++;
	}
	s3[pos]=s2[pos];
	return pos;
}

int lcase(char *s){
	int pos=0;
	while(s[pos]!=0){
		if (s[pos]>='A' && s[pos]<='Z')s[pos]=(s[pos]-'A')+'a';
		pos++;
	}
	return pos;
}

int ucase(char *s){
	int pos=0;
	while(s[pos]!=0){
		if (s[pos]>='a' && s[pos]<='z')s[pos]=(s[pos]-'a')+'A';
		pos++;
	}
	return pos;
}


int findchar(char *s,char c){
	int pos=0;
	while(s[pos]!=0 && s[pos]!=c){
		pos++;
	}
	if(s[pos]!=c)pos=-1;
	return pos;
}



int strnfill(char *s1,char c,int size){
	int pos=0;
	while(pos<=size){
		s1[pos]=c;
		pos++;
	}
	return pos;
}

int incmp(char *s,char *s2){
	int pos=0;
	int exit=0;
	int cmp=0;
	while(exit!=1){
		if(s[pos]!=s2[pos]){
			if(s[pos]>s2[pos])cmp=1;
			if(s[pos]<s2[pos])cmp=-1;
			if(s2[pos]==0)cmp=0;
			exit=1;
		}
		pos++;
	}
	return cmp;
}


int strsfills(char *s,char c){
	int pos=0;
	while(s[pos]!=0){
		s[pos]=c;
		pos++;
	}
	return pos;
}

void strsint(char *s,int n){
	int nn=n;
	int pos=0;
	int signals=0x7fff;
	int divsb=10000;
	int divsa=0;
	nn=signals & nn;
	signals++;
	signals=signals & n;
	s[pos]='+';
	if(signals!=0)s[pos]='-';
	for(pos=0;pos<5;pos++){
		divsa=nn/divsb;
		divsa=divsa+'0';
		s[pos+1]=(char) divsa;
		nn=nn % divsb;
		divsb=divsb/10;
	}
	s[pos+1]=0;
}


void strslong(char *s,long n){
	long nn=n;
	long pos=0;
	long signals=0x7fffffff;
	long divsb=1000000000;
	long divsa=0;
	nn=signals & nn;
	signals++;
	signals=signals & n;
	s[pos]='+';
	if(signals!=0)s[pos]='-';
	for(pos=0;pos<10;pos++){
		divsa=nn/divsb;
		divsa=divsa+'0';
		s[pos+1]=(char) divsa;
		nn=nn % divsb;
		divsb=divsb/10;
	}
	s[pos+1]=0;
}

void strsfloat(char *s,float n){
	float nn=n;
	float nnn=n;
	char pp=0;
	int pos=0;
	int pos2=1;
	float signals=n;
	float divsb=100.00f;
	float divsa=0;
	s[pos]='+';
	if(signals<0){
		s[pos]='-';
		nn=0-nn;
	}
	for(pos=0;pos<5;pos++){
		nnn=nn;
		divsa=nn/divsb;
		if(pos==3){
			pos2++;
			s[pos+1]='.';
		}
		pp=(char) divsa;
		nn=nnn-(divsb*pp);
		pp=pp+'0';
		s[pos+pos2]=(char) pp;
		divsb=divsb/10.00f;
	}
	s[pos+pos2]=0;
}



void strsdouble(char *s,double n){
	double nn=n;
	double nnn=n;
	char pp=0;
	int pos=0;
	int pos2=1;
	double signals=n;
	double divsb=100.00f;
	double divsa=0;
	s[pos]='+';
	if(signals<0){
		s[pos]='-';
		nn=0-nn;
	}
	for(pos=0;pos<8;pos++){
		nnn=nn;
		divsa=nn/divsb;
		if(pos==3){
			pos2++;
			s[pos+1]='.';
		}
		pp=(char) divsa;
		nn=nnn-(divsb*pp);
		pp=pp+'0';
		s[pos+pos2]=(char) pp;
		divsb=divsb/10.00f;
	}
	s[pos+pos2]=0;
}


int ssprintf(char *stringss,char *format,int num, ... ){
	va_list arguments;
	char sssss[32];
	int ar0;
	long ar1;
	float ar2;
	double ar3;
	char *sss;
	char *ssss;
	int nums=0;
	int count=0;
	int pos=0;
	int pos2=0;
	int shift=0;
	int shift2=0;
	stringss[0]=0;
	ar0=0;
	ar1=0;
	ar2=0.00f;
	ar3=0.00f;

	va_start(arguments,num);
	while(format[pos]!=0){
		if(shift==0){
			if(format[pos]!='%'){
				stringss[pos2]=format[pos];
				pos2++;
				stringss[pos2]=0;
				shift=0;
			}else{
				shift=1;
			}
		}else{
			if(format[pos]=='s'){
				sss=va_arg(arguments,char *);
				strcat(stringss,sss);
				pos2=strslen(stringss);
			} 
			if(format[pos]=='d'){
				ar0=va_arg(arguments,int);
				strsint(sssss,ar0);
				strcat(stringss,sssss);
				pos2=strslen(stringss);
			} 
			if(format[pos]=='l'){
				ar1=va_arg(arguments,long);
				strslong(sssss,ar1);
				strcat(stringss,sssss);
				pos2=strslen(stringss);
			} 
			if(format[pos]=='f'){
				ar2=(float) va_arg(arguments,double);
				strsfloat(sssss,ar2);
				strcat(stringss,sssss);
				pos2=strslen(stringss);
			} 
			if(format[pos]=='F'){
				ar3=va_arg(arguments,double);
				strsdouble(sssss,ar3);
				strcat(stringss,sssss);
				pos2=strslen(stringss);
			} 
			shift=0;

		}
		pos++;
	}
	va_end(arguments);
	return pos;
}


