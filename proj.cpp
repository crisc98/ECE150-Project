#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXLINE=256;

bool isComment(char arr[]){
	bool check=false;
	for (int i=0; i<MAXLINE;i++){
		if (arr[i]=='#'){
			check= true;
		}
		
	}
	return check;
}

void stripCmt(char arr[]){
	for (int i=0; i<MAXLINE;i++){
		if (arr[i]=='#'){
			arr[i]=0;
		}
		
	}
}


int firstRealChar(char arr[]){
	for (int i=0;i<MAXLINE;i++){
		if(arr[i]!=' '&&arr[i]!='\n'&&arr[i]!='\t'){
			return i;
		}
	}
	return -1;
}
int getOPCode(char arr[]){
	int code=-1;
	int x=0;
	char *codeList [19] = {
	"SUBi ","ADDi ","MULi ","DIVi ","JMP ","JZ ","JGEZ ","JLEZ ","JNZ ","JLZ ","JGZ ","LDi ","SDi ","ADD ","SUB ","MUL ","DIV ","LD ","SD "};

	char opCode[5];
	
	x=firstRealChar(arr);
	for (int i=0;i<5;i++){
		opCode[i]=arr[x+i];
	

	char *output = NULL;

	for (int c=0;c<19;c++){
			output = strstr (opCode, codeList[c]);
		
		if (output){
			code=c;
			for(int b=0;b<strlen(codeList[c]);b++){
				for(int z=0;z<MAXLINE;z++){
					arr[z]=arr[z+1];
				}
			}
			//cout <<arr<<endl;
			return code;
		}
	}
	}
	return code;
		
	
	
}	
void exeCommand(int opCode){
	
}


bool hasValidOperands(char arr[]){
/*switch (getOPCode(arr)){
		int x=firstRealChar(arr);
		int y=firstRealChar(arr);
		int L=0;
		while(arr[y]!=' '&&arr[y]!='\n'&&arr[y]!='\t'){
			L++;
			y++
		}
		char firstOperand[L];
		for(int i=0;i<L;i++){
				firstOperand[i]==arr[x+i];
		}
		case 0:
		//if(firstOperand=="R )
		break;
		case 1:
		//getOperands(opCode,2)=getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 2:
		//getOperands(opCode,2)=getOperands(opCode,0)-getOperands(opCode,1);
		break;
		case 3:
		//getOperands(opCode,2)=getOperands(opCode,0)-getOperands(opCode,1);
		break;
		case 4:
		//getOperands(opCode,2)=getOperands(opCode,0)*getOperands(opCode,1);
		break;
		case 5:
		//getOperands(opCode,2)=getOperands(opCode,0)*getOperands(opCode,1);
		break;
		case 6:
		//getOperands(opCode,2)=getOperands(opCode,0)/getOperands(opCode,1);
		break;
		case 7:
		//getOperands(opCode,2)=getOperands(opCode,0)/getOperands(opCode,1);
		break;
		case 8:
		//getOperands(opCode,0)=getOperands(opCode,1);
		break;
		case 9:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 10:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 11:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 12:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 13:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 14:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 15:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
		case 16:
		//getOperands(opCode,0)+getOperands(opCode,1);
		break;
	}
	*/


}




int main (int argc,char*argv[]){
	int lC=0;
	int numALU=0, numJC=0, numLS=0;
	if (argc !=2){
		cerr << "Error: Invalid number of arguments!";
		return 0;
	}
	
	ifstream file (argv[1]);
	char oneline[MAXLINE]="DEFAULT";

	if(!file.is_open()){
		cerr << "Error: File is invalid!";
		return 1;
	}

	while(file){
	file.getline(oneline, MAXLINE);
	lC++;

	if (isComment(oneline)){
		stripCmt(oneline);
		
	}
		
		
		//if (!hasValidOperands(oneline))
		//	cerr << "Error on line " << lC <<": Invalid Operands!";
		//	return 1;
		//}
	//exeCommand(oPC);0-3,13-16
		cout <<oneline<<endl;
		int oPC=getOPCode(oneline);
		cout << oPC <<endl;
		if(oPC==11||oPC==12||oPC==17||oPC==18){
			numLS++;
		}else if (oPC==0||oPC==1||oPC==2||oPC==3||oPC==13||oPC==14||oPC==15||oPC==16){
			numALU++;
		}else if(oPC!=-1){
			numJC++;
		}
		
		
		
		
	}
	cout << "Total Number of Assembly Instructions: " << numALU+numJC+numLS<<endl;
	cout << "Number of Load/Store Instructions: "<< numLS<<endl;
	cout << "Number of ALU Instructions: "<< numALU<<endl;
	cout << "Number of Jump/Compare Instructions: "<< numJC<<endl;
	file.close();
	return 0;

}
