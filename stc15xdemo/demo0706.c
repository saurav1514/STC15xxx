code u8 Buffer[4]={0xfe,0xfd,0xfb,0xf7};

u8 num[3]={0,0,0},num0;

void scan();//ɨ��
void process();//����
void display();//��ʾ
void delay();//��ʱ

void main(){
	u8 i;

	//P0M0=1;����P0ģʽ ������ʹ�ã���
	//P0M1=1;
	
	while(1){
			i=0;
			scan();
			display();
			num[i]=num0;//һ�������еڶ����漰�˱���������num���顣(�˱���֮��Ҫ���б�Ĳ���)
			i++;
		}
		process();
		diplay();		
	}
}

void scan(){//ɨ�������̣�P0�ڣ�
	static xdata u16 count=0;
	u8 i,j,value;
	if(count>1000){
		count=0;
		for(i=0;i<4;i++){
			P0=Buffer[i];
			value=0x80;//1000 0000
			for(j=0;j<4;j++){
				if((value&P0)==0){
					num0=(j*4+i)+1;//һ�������е�һ���漰�˱��������ڴ��������
				}
				value>>=1;
			}
		}
	}
	count++;
}

void process(){ //1+2=3��1Ϊnum[0],+Ϊnum[1],2Ϊnum[2]
	if(num[1]==???){ //???��ӺŶ�Ӧ����
		num0=num[0]+num[2];//������������num0��һ�������е������漰�˱�����
	}
	if(num[1]==???){//???����Ŷ�Ӧ����
		num0=num[0]-num[2];
	}
	if(num[1]==???){//???��˺Ŷ�Ӧ����
		num0=num[0]*num[2];
	}
	if(num[1]==???){//???����Ŷ�Ӧ����
		num0=num[0]/num[2];
	}
}

void display(){//���������������������ʾ
	//num_2=num0/100;//�����λ
	num_1=num0/10;	 
	num_0=num0%10;
	//P???=0x?? //��ʾ��λ��
	P???=0x??;  //��ʾʮλ��
	P???=0x??;  //��ʾ��λ��
}

void delay(){//��ʱ����������Ҫ�ɵ��á�
	u8 i;
	for(i=100000;i>0;i--);
}

