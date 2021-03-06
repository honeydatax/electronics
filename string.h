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
void strshex(char *s,long n);
void strsoct(char *s,long n);
int ssprintf(char *stringss,char *format,int num, ... );
void strsbin(char *s,long n);
void paraleleadd(char *c0,char *c1,char *c2);
void paraleleclear(char *c0);
void paralelecopy(char *c0,char *c1);
void paralelemul(char *c0,char *c1,char *c2);
char cmpint64(char *c0,char *c1);
void div256(char *c0);
void mul256(char *c0);

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

void strshex(char *s,long n){
	long nn=n;
	long pos=8;
	long divsa=0;
	long signals=0x10;
	long signals2=0xf;
	char *digits="0123456789ABCDEF0123456789ABCDEF";
	s[pos]=0;
	for(pos=7;pos>-1;pos--){
		divsa=nn & signals2;
		s[pos]=(char) digits[(int)divsa];
		nn=nn/signals;
	}
}

void strs4(char *s,long n){
	long nn=n;
	long pos=32;
	long divsa=0;
	long signals=4;
	long signals2=3;
	char *digits="0123456789ABCDEF0123456789ABCDEF";
	s[pos]=0;
	for(pos=pos-1;pos>-1;pos--){
		divsa=nn & signals2;
		if(divsa<0)divsa=0-divsa;
		s[pos]=(char) digits[(int)divsa];
		nn=nn/signals;
	}
}


void strsoct(char *s,long n){
	long nn=n;
	long pos=11;
	long divsa=0;
	long signals=8;
	long signals2=7;
	char *digits="0123456789ABCDEF0123456789ABCDEF";
	s[pos]=0;
	for(pos=pos-1;pos>-1;pos--){
		divsa=nn & signals2;
		if(divsa<0)divsa=0-divsa;
		s[pos]=(char) digits[(int)divsa];
		nn=nn/signals;
	}
}

void strsbin(char *s,long n){
	long nn=n;
	long pos=32;
	long divsa=0;
	long signals=2;
	long signals2=1;
	char *digits="0123456789ABCDEF0123456789ABCDEF";
	s[pos]=0;
	for(pos=pos-1;pos>-1;pos--){
		divsa=nn & signals2;
		if(divsa<0)divsa=0-divsa;
		s[pos]=(char) digits[(int)divsa];
		nn=nn/signals;
	}
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
			if(format[pos]=='x' || format[pos]=='X'){
				ar3=va_arg(arguments,long);
				strshex(sssss,ar3);
				strcat(stringss,sssss);
				pos2=strslen(stringss);
			} 
			if(format[pos]=='o' || format[pos]=='O'){
				ar3=va_arg(arguments,long);
				strsoct(sssss,ar3);
				strcat(stringss,sssss);
				pos2=strslen(stringss);
			} 

		if(format[pos]=='4'){
				ar3=va_arg(arguments,long);
				strs4(sssss,ar3);
				strcat(stringss,sssss);
				pos2=strslen(stringss);
		} 

		if(format[pos]=='b'){
				ar3=va_arg(arguments,long);
				strsbin(sssss,ar3);
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

void paraleleadd(char *c0,char *c1,char *c2){
	int i=0;
	int ii=0;
	int iii=0;
	int carry=0;
	for(i=0;i<8;i++){
		ii=c1[i];
		iii=c2[i];
		ii=ii+iii+carry;
		carry=0;
		if(ii>255)carry++;
		c0[i]=(char)ii;
	}
}


void paralelesub(char *c0,char *c1,char *c2){
	int i=0;
	int ii=0;
	int iii=0;
	int carry=0;
	for(i=0;i<8;i++){
		ii=c1[i];
		iii=c2[i];
		ii=ii-carry-iii;
		carry=0;
		if(ii<0)carry++;
		c0[i]=(char)ii;
	}
}


void paraleleclear(char *c0){
	int i=0;
	for(i=0;i<32;i++)c0[i]=0;
}

void paralelecopy(char *c0,char *c1){
	int i=0;
	for(i=0;i<32;i++){
		c0[i]=c1[i];
	}
}

void paralelemul(char *c0,char *c1,char *c2){
	int i=0;
	int i1=0;
	int i2=0;
	int i3=0;
	int ii3=0;
	int ii=0;
	int iii=0;
	int carry=0;
	char c3[35];
	char c4[35];
	char c5[35];
	paraleleclear(c3);
	paraleleclear(c4);
	paraleleclear(c5);

	for(i=0;i<8;i++){
		paraleleclear(c4);
		paralelecopy(c4,c3);
		paraleleclear(c3);
		paraleleclear(c5);
		ii3=c2[i];
		for(i1=0;i1<8;i1++){
			iii=c1[i1];
			ii=ii3*iii+carry;
			carry=0;
			if(ii>255)carry=ii;
			carry=carry/256;
			c5[i1+i]=(char)ii;
		}
		paraleleadd(c3,c4,c5);
	}
	paraleleclear(c0);
	paralelecopy(c0,c3);	
}

char cmpint64(char *c0,char *c1){
	int i=0;
	char r=0;
	for(i=7;i>-1;i--){
		if(c0[i]>c1[i]){
			r=1;
			i=-2;
		}
		if(c0[i]<c1[i]){
			r=255;
			i=-2;
		}
	}
	return r;
}

void mul256(char *c0){
	int i=0;
	for(i=30;i>-1;i--){
		c0[i+1]=c0[i];
	}
	c0[0]=0;
}

void div256(char *c0){
	int i=0;
	for(i=0;i<31;i++){
		c0[i]=c0[i+1];
	}
	c0[32]=0;
}


char paraleleentry(char *c0,char *c1){
	long long int l0=0;
	int i=0;
	int pos=0;
	char r=0;
	char rr=0;
	char c3[35];
	paraleleclear(c3);
	
	for(i=0;i<8;i++){
		r=(char) i;
		if(c0[7-i]!=0){
			c3[0]=c0[7-i];
			i=10;

		}
		
	}
	rr=r;
	if(rr!=7){
		for(i=(int)rr;i<8;i++){
			if(cmpint64(c3,c1)==255){
				mul256(c3);
				c3[0]=c0[7-i];
				r=i;
			}else{
				
				i=10;
			}
		}
	}
	
	paraleleclear(c0);
	paralelecopy(c0,c3);
	return r;
}


