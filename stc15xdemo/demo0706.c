code u8 Buffer[4]={0xfe,0xfd,0xfb,0xf7};

u8 num[3]={0,0,0},num0;

void scan();//扫描
void process();//运算
void display();//显示
void delay();//延时

void main(){
	u8 i;

	//P0M0=1;设置P0模式 （按需使用）。
	//P0M1=1;
	
	while(1){
			i=0;
			scan();
			display();
			num[i]=num0;//一次运算中第二次涉及此变量，传入num数组。(此变量之后要进行别的操作)
			i++;
		}
		process();
		diplay();		
	}
}

void scan(){//扫描矩阵键盘（P0口）
	static xdata u16 count=0;
	u8 i,j,value;
	if(count>1000){
		count=0;
		for(i=0;i<4;i++){
			P0=Buffer[i];
			value=0x80;//1000 0000
			for(j=0;j<4;j++){
				if((value&P0)==0){
					num0=(j*4+i)+1;//一次运算中第一次涉及此变量，用于存键盘输入
				}
				value>>=1;
			}
		}
	}
	count++;
}

void process(){ //1+2=3中1为num[0],+为num[1],2为num[2]
	if(num[1]==???){ //???填加号对应键码
		num0=num[0]+num[2];//将计算结果存入num0（一次运算中第三次涉及此变量）
	}
	if(num[1]==???){//???填减号对应键码
		num0=num[0]-num[2];
	}
	if(num[1]==???){//???填乘号对应键码
		num0=num[0]*num[2];
	}
	if(num[1]==???){//???填除号对应键码
		num0=num[0]/num[2];
	}
}

void display(){//将结果分离后在数码管上显示
	//num_2=num0/100;//如需百位
	num_1=num0/10;	 
	num_0=num0%10;
	//P???=0x?? //显示百位数
	P???=0x??;  //显示十位数
	P???=0x??;  //显示个位数
}

void delay(){//延时函数，如需要可调用。
	u8 i;
	for(i=100000;i>0;i--);
}

