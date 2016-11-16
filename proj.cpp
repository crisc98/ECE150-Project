#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>

using namespace std;

const int MAXLINE=256;
char oneline[MAXLINE]="DEFAULT";
int opLen=0;
bool doneLine=false;
int oPC=0;

int strToInt(char* str){
	// Define variables to store the number to be converted, the current digit position, and the char value of the current digit  
	unsigned int number = 0;
	unsigned int maxValue = INT_MAX;
	unsigned int currDigit = 0;
	char currDigitStr = str[0];

	// 1. Check if there is a minus sign at the front
	//    If yes, move to the next digit position
	bool minusSign = (currDigitStr == '-');
	if (minusSign){
		currDigit = 1;
		currDigitStr = str[1];
		maxValue = maxValue+1;
	}
	
	// 2. Calculate the number on a digit-by-digit basis using base-10 arithmetic
	//	  Repeat the process until end of text string is reached
	while (currDigitStr != '\0'){
		
		// A. If the current digit string is not between 0 to 9, something is wrong
		//    In this case, simply return INT_MIN as the return value
		if (currDigitStr < '0' || currDigitStr > '9'){
			cerr << "Error in integer string conversion" << endl;
			return -1;
		}
		
		// B. Update the number via: 
		//		(1) multiplying current value by 10
		//		(2) Add the value of the current digit 
		//				(found by subtracting the ASCII value of 0 from the current digit's ASCII value)

		// Note: Premature function end if the number is going to be larger than the limits of int variables
		if ( number > maxValue/10 ){
			return -1;
		}
		else
			number *= 10;

		unsigned int currDigitIntValue = currDigitStr - '0';
		if ( currDigitIntValue > maxValue-number ){
			return -1;
		}
		else
			number += currDigitIntValue;
		
		// C. Move to the next digit and update the digit's char value accordingly 
		currDigit++;
		currDigitStr = str[currDigit];
	}
	
	// 3. If there is a minus sign, return the negated value of the number; 
	//	  otherwise, just return the number value
	return minusSign? (-number) : number;
}

void shortArray(char arr[], int length){
	for(int b=0;b<length;b++){
				for(int z=0;z<MAXLINE;z++){
					arr[z]=arr[z+1];
				}
			}
}


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
		if(arr[i]!=' '&&arr[i]!='\n'&&arr[i]!='\t'&&arr[i]!=0){
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
			opLen=strlen(codeList[c]);
			
			//cout <<arr<<endl;
			return code;
		}
	}
	}
	return code;
		
	
	
}	


void exeCommand(int opCode){
	
}
char* getOperand(char* arr){
		int x=firstRealChar(arr);
		int y=x;
		int L=0;
		while(arr[y]!='\n'&&arr[y]!=','&&arr[y]!=0){
			L++;
			y++;
		}
		char oper[L];
		for(int i=0;i<L;i++){
				oper[i]=arr[x+i];
		}
		cout<<arr<<endl;
		
		cout<<L<<endl;
		cout<<oper<<endl;
		//char* temp=new char[sizeof(arr)];
		//shortArray(arr,L+1);
		if(arr[x+L]!=','&&arr[x+L]!=0){
			cout<<"FAIL"<<endl;
			return "f";
		}
		if(arr[x+L]==0){
			cout<<"PASS Final"<<endl;
			shortArray(arr,L+1);
			doneLine=true;
		}else{
		cout <<"PASS"<<endl;
		shortArray(arr,L+2);
		}
		return oper;
}
bool isRegister(char arr[]){
	if(arr[0]=='R'&&arr[1]>= 48&&arr[1]<=57){
		return true;
	}else{
	
	return false;
	}
	
}
bool isNumber(char arr[]){
	if(strToInt(arr)!=-1){
		return true;
	}
	return false;
	
}
bool isMemLoc(char arr[]){
	if(strToInt(arr)<10000&&strToInt(arr)>999){
		return true;
	}
	return false;
}
/*int getNumOperands(char arr[]){
	int numOperands=0;
	char *temp=arr;
	while (firstRealChar(temp)!=-1){
		char* tempOper=getOperand(temp);
		if(tempOper=="f"){
			return -1;
		}
		
		numOperands++;
		
	}
	return numOperands;
}*/


int hasValidOperands(char arr[]){
	//cout<< "GOOD";
	int numOperands=0;
	
	
	oPC=getOPCode(arr);
	cout<<"ARRAY: "<<arr<<endl;
	shortArray(arr, opLen);
	cout<<"TEMP: "<<arr<<endl;
	//int numOperands=getNumOperands(temp);
	char* init[3];
	int i=0;
	
	
	while (doneLine==false){
		char* tempOper=getOperand(arr);
		//cout<<getOperand(arr)<<endl;
		//cout<<tempOper;
		if(tempOper=="f"){
			return -1;
		}
		init[i]=tempOper;
		numOperands++;
		i++;
	}
	char* operands[numOperands];
	for(int x=0;x<numOperands;x++){
		operands[x]=init[x];
	}
	cout<< "Num Operands: " <<numOperands<<endl;
	cout<<operands[0]<<endl;
	
/*switch (oPC){
	
	
		
		case 0:
			if(isRegister(operands[0])&&isNumber(operands[1])&&isRegister(operands[2])&&numOperands==3){
				return 1;
			}
		break;
		
		case 1:
		if(isRegister(operands[0])&&isNumber(operands[1])&&isRegister(operands[2])&&numOperands==3){
				return 1;
			}
		break;
		
		case 2:
		if(isRegister(operands[0])&&isNumber(operands[1])&&isRegister(operands[2])&&numOperands==3){
				return 1;
			}
		break;
		
		case 3:
		if(isRegister(operands[0])&&isNumber(operands[1])&&isRegister(operands[2])&&numOperands==3){
				return 1;
			}
		break;
		
		case 4:
		if(isMemLoc(operands[0])&&numOperands==1){
				return 1;
			}
		break;
		
		case 5:
		if(isRegister(operands[0])&&isMemLoc(operands[1])&&numOperands==2){
				return 1;
			}
		break;
		
		case 6:
		if(isRegister(operands[0])&&isMemLoc(operands[1])&&numOperands==2){
				return 1;
			}
		break;
		
		case 7:
		if(isRegister(operands[0])&&isMemLoc(operands[1])&&numOperands==2){
				return 1;
			}
		break;
		
		case 8:
		if(isRegister(operands[0])&&isMemLoc(operands[1])&&numOperands==2){
				return 1;
			}
		break;
		
		case 9:
		if(isRegister(operands[0])&&isMemLoc(operands[1])&&numOperands==2){
				return 1;
			}
		break;
		
		case 10:
		if(isRegister(operands[0])&&isMemLoc(operands[1])&&numOperands==2){
				return 1;
			}
		break;
		
		case 11:
		if(isNumber(operands[0])&&isRegister(operands[1])&&numOperands==2){
				return 1;
			}
		break;
		
		case 12:
		if(numOperands==2&&isNumber(operands[0])&&(isRegister(operands[1])||isMemLoc(operands[1]))){
				return 1;
			}
		
		case 13:
		cout<<"Test"<<isRegister(operands[0])<<endl;//isRegister(operands[1])<<isRegister(operands[2])<<endl;
		if(isRegister(operands[0])&&isRegister(operands[1])&&isRegister(operands[2])&&numOperands==3){
			
				return 1;
			}
		break;
		
		case 14:
		if(isRegister(operands[0])&&isRegister(operands[1])&&isRegister(operands[2])&&numOperands==3){
				return 1;
			}
		break;
		
		case 15:
		if(isRegister(operands[0])&&isRegister(operands[1])&&isRegister(operands[2])&&numOperands==3){
				return 1;
			}
		break;
		
		case 16:
		if(isRegister(operands[0])&&isRegister(operands[1])&&isRegister(operands[2])&&numOperands==3){
				return 1;
			}
		break;
		
		case 17:
		if(numOperands==2&&(isMemLoc(operands[0])||isRegister(operands[0]))&&isRegister(operands[1])){
				return 1;
			}
		break;
		
		case 18:
		if(numOperands==2&&isRegister(operands[0])&&(isRegister(operands[1])||isMemLoc(operands[1]))){
				return 1;
			}
		break;
	}
	return 0;
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
	if(oneline!=" "&&oneline!="\n"&&oneline!="\t"&&"\0"){
	int validity=hasValidOperands(oneline);
	
		
		
		if (validity==1){
		cout <<oneline<<endl;
		//int oPC=getOPCode(oneline);
		cout << oPC <<endl;
		if(oPC==11||oPC==12||oPC==17||oPC==18){
			numLS++;
		}else if (oPC==0||oPC==1||oPC==2||oPC==3||oPC==13||oPC==14||oPC==15||oPC==16){
			numALU++;
		}else if(oPC!=-1){
			numJC++;
		}
		}
		else{
			if (validity==-1){
				cerr<<"Error on line "<<lC<<": Invalid operand! Expected ','";
				return -1;
			}
		}
		
		
		
	}
	}
	cout << "Total Number of Assembly Instructions: " << numALU+numJC+numLS<<endl;
	cout << "Number of Load/Store Instructions: "<< numLS<<endl;
	cout << "Number of ALU Instructions: "<< numALU<<endl;
	cout << "Number of Jump/Compare Instructions: "<< numJC<<endl;
	file.close();
	return 0;

}
