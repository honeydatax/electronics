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

