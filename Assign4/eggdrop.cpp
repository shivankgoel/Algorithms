#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;




int main(){
	ifstream f1;
	ofstream f2;
	string line;
	int n=0;
	int k=0;
	int c=0;
	f1.open("input.txt" , ios::in);

	
	if(f1.is_open()){
		while(getline(f1,line)){
			
			//cout<<line<<endl;
			if(c == 0){
				stringstream ss;
				string num1="";
				int len = line.length();
				int i;
				for(i=0;i<len;i++){
					if(line[i] != ','){
						num1 =  num1 + line[i] ;
					}
					else{
						break;
					}
				}
				//cout<<i<<endl;
				i++;
				ss << num1;
				ss >> n;
				num1="";
				while(i<len){
					if(line[i] != ' '){
						num1 =  num1 + line[i] ;
					}
					else{
						break;
					}
					i++;
				}
				//cout<<num1<<endl;
				stringstream ss2;
				ss2 << num1;
				ss2 >> k;
			}
			c++;
		}
		f1.close(); 
	}          
	else{     
		cout<<"Couldn't open file.";
    }
    
    //cout<<n<<" "<<k<<endl;
    
    //n=10000;
    //k=100;
    
    int mint[n+1][k+1];
    // if floors is >2 and we have 1 egg than n trials in worst case
    // if we have 0 egg than we can't do any trial
	for(int i=2;i<=n;i++){
    	mint[i][1] = i;
    	mint[i][0] = 0;
	}
	//if only 1 floor than 1 trial
	//if 0 floors than 0 trials
	for(int i=0;i<=k;i++){
		mint[0][i] = 0;
		mint[1][i] = 1;
	}
	mint[1][0]=0;
	
	//loop for number of eggs
	for(int i=2;i<=k;i++){ 
		//loop for number of floors
		for(int j=2;j<=n;j++){
			//loop for floor from where egg is dropped
			int temp = INT_MAX;
			for(int f=1;f<=j;f++){
				int trialf = 1+max(mint[f-1][i-1],mint[j-f][i]);
				if(trialf<temp) temp=trialf;
			}
			mint[j][i] = temp;
			//cout<<j<<" "<<i<<" "<<temp<<endl;
		}
	}
	//cout<<mint[n][k]<<endl;
	
	f2.open("output.txt",ios::out);
	if(f2.is_open()){
		
		    f2<<mint[n][k]<<endl;
		    
	}else{
		cout<<"Can't open output file"<<endl;
	}


	
	return 0;
}


