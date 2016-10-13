/*
 *this is a simple multiple-line comment
 * this is a simple multiple-line comment
 *///one-line comment

///*
 /* this is a nested multiple-line comment
 /*
// oneline comment nested in multiple-line comment
 ////* ////*
 ////*/

//a simple one-line comment/**/
//same as the above

int oct1 = .3;
int hex1 = 0x4512ad;
int hex2 = 0x45hasjkd;//invalid hex number
int hex3 = 0xa4a5s6d45;//invalid hex number
int oct1 = 04512;
int oct2 = 012348979;//invalid oct number
int oct3 = 0123asd;//invalid oct number
float f1 = .3;
float f2 = 0.;
float f3 = 0.1;
float f4 = 0.3e4;
float f5 = +0.1;
float f6 = 0.3e;//invalid float
string1 = "Hello\" World!";
string2 = "prefix""suffix";//valid string
string2 = "prefix"  "suffix";//valid string
string2 = "prefix"			 "suffix";//valid string
string2 = "prefix"
"suffix";//valid string
if(1){}
else{}

do{/*expression*/}while(1);
for(/*st*/;/*cond*/;/*step*/){};

struct Complex {
	int real;
	float img;
};

int main(){return 0;}
