#include"reg51.h"
unsigned char code dis[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
sbit p30=P3^0;sbit p31=P3^1;
sbit p20=P2^0;sbit p21=P2^1;sbit p22=P2^2;sbit p23=P2^3;sbit p24=P2^4;sbit p25=P2^5;sbit p07=P0^7;
char a=0;char b=0;char c=0;char d=0;char e=0;char f=0;
char aa=0;char bb=0;char cc=0;char dd=0;char ee=0;char ff=0;
int count1=0;int count2=0;int count3=0;char i=0;
int count11;int count22;int count33;
int x=0;int y=0;char xuan=0;int shan=0;
void delay(int a);
char choice=-1;char se=-1;
main()
{
	TMOD=0x21;
	TH0=0xf4;TL0=48;
	TL1=TH1=0x38;
	PT1=1;PT0=0;IT0=1;
	EA=1;ET1=1;ET0=1;EX0=1;
	TR0=1;TR1=1;
	while(1){
	if(choice==-1){
	if(p30==0){
	delay(10);
		if(p30==0){xuan++;
		if(xuan==4)xuan=0;
				  }
	   		  }while(p30==0);
	if(p31==0){
		delay(10);
		if(p31==0){
			switch(xuan){
			case 1:count1=0;break;
			case 2:count2++;break;
			case 3:count3++;break;
			}
		}while(p31==0);
	}
	}
	
	if(choice==1){
		if(p30==0){
		delay(10);
			if(p30==0){
				se=-se;	
			}while(p30==0);
		}
		if(p31==0){
		delay(10);
			if(p31==0){
			if(se==-1){count11=0;count22=0;count33=0;}
			}while(p31==0);
		}
	}
			}	 
}

void int_verxianshi() interrupt 1 using 0
{
if(choice==-1){
	P0=0xff;
	TH0=0xf4;
	TL0=48;
	i++;if(i==6)i=0;P2=0;shan++;
	if(shan==300)shan=0;
	switch(i){
		case 0:
		if(xuan==3&shan<=150){P0=0xff;}
		else
		P0=~dis[f];p20=1;break;
		case 1:
		if(xuan==3&shan<=150){P0=0xff;}
		else
		P0=~dis[e];p07=0;p21=1;break;
		case 2:
		if(xuan==2&shan<=150){P0=0xff;}
		else
		P0=~dis[d];p22=1;break;
		case 3:
		if(xuan==2&shan<=150){P0=0xff;}
		else
		P0=~dis[c];p07=0;p23=1;break;
		case 4:
		if(xuan==1&shan<=150){P0=0xff;}
		else
		P0=~dis[b];p24=1;break;
		case 5:
		if(xuan==1&shan<=150){P0=0xff;}
		else
		P0=~dis[a];p07=0;p25=1;break;
		}
	}
if(choice==1){
	P0=0xff;
	TH0=0xf4;
	TL0=48;
	i++;if(i==6)i=0;P2=0;
	aa=count11%10;
	bb=count11/10;
	cc=count22%10;
	dd=count22/10;
	ee=count33%10;
	ff=count33/10;
	switch(i){
		case 0:
		P0=~dis[ff];p20=1;break;
		case 1:
		P0=~dis[ee];p07=0;p21=1;break;
		case 2:
		P0=~dis[dd];p22=1;break;
		case 3:
		P0=~dis[cc];p07=0;p23=1;break;
		case 4:
		P0=~dis[bb];p24=1;break;
		case 5:
		P0=~dis[aa];p07=0;p25=1;break;
		}
	}
}

void int_jishu() interrupt 3 using 1
{
	x++;
	if(x==4000){
	x=0;count1++;
	if(count1>59){
		count1=0;count2++;
	}
	if(count2>59){
		count2=0;count3++;
	}
	if(count3>23)count3=0;
	a=count1%10;
	b=count1/10;
	c=count2%10;
	d=count2/10;
	e=count3%10;
	f=count3/10;
	}
	if(se==1){
		y++;if(y==40){
		y=0;count11++;
		if(count11>99){
			count11=0;count22++;
		}
		if(count22>59){
			count22=0;count33++;
		}
		if(count33>59){
			count33=0;
		}
		}
	}
}

void int_zhuanhuan()interrupt 0 using 2
{
	choice=-choice;
}

void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)for(j=0;j<127;j++);
}
