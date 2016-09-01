#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int* findkMaxDifferencesIndex(int differences[],int k,int n){
	int* indices;
	int temp[n];
	for(int i=0;i<n;i++){
		temp[i] = differences[i];
	} 
	indices = new int[k];
	for(int i=0;i<k;i++){
		int maxindex = -1;
		int max =-1;
		for(int j=0;j<n;j++){
			if(temp[j]>max){
				max = temp[j];
				maxindex = j;
			}
		}
		indices[i] = maxindex;
		differences[maxindex]--;
		temp[maxindex] = -1;
	}
	return indices;
}


int main(){
	ifstream f1;
	ofstream f2;
	string line;
	int n=0;
	int c=0;
	f1.open("input.txt" , ios::in);
	map<int,int> Rmap;
	map<int,int> Cmap;
	bool solexist = true;
	
	if(f1.is_open()){
		while(getline(f1,line) && solexist){
			
			//cout<<line<<endl;
			if(c == 0){
				stringstream ss;
				ss << line;
				ss >> n;
				//cout<<"n= "<<n<<endl;
				//R = new int[n];
				//C = new int[n];
			}
			else if(c==1){
				int k = 0;
				int len = line.length();
				string temp="";
				int num=0;
				for(int i=0; i<len ; i++){
					if(line[i] == '0' || line[i] == '1' ||  line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9'){
						temp += line[i];
					}
					else{
						if(temp != ""){
							stringstream ss;
							ss << temp;
							ss >> num;
							temp = "";
							Rmap[k++] = num;
							if(num>n){
								solexist = false;
								break;
							}
						}
					}
					if( i == len-1){
						if(temp != ""){
							stringstream ss;
							ss << temp;
							ss >> num;
							temp = "";
						    Rmap[k++] = num;
							if(num>n){
								solexist = false;
								break;
							}	
						}	
					}	
				}
			}
			else{
				int k = 0;
				int len = line.length();
				string temp="";
				int num=0;
				for(int i=0; i<len ; i++){
					if(line[i] == '0' || line[i] == '1' ||  line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9'){
						temp += line[i];
					}
					else{
						if(temp != ""){
							stringstream ss;
							ss << temp;
							ss >> num;
							temp = "";
							Cmap[k++] = num;
							if(num>n){
								solexist = false;
								break;
							}
						}
					}
					if( i == len-1){
						if(temp != ""){
							stringstream ss;
							ss << temp;
							ss >> num;
							temp = "";
						    Cmap[k++] = num;
							if(num>n){
								solexist = false;
								break;
							}	
						}	
					}	
				}
			}
			c++;
		}
		f1.close(); 
	}          
	else{     
	cout<<"Couldn't open file.";
    }
    
    //for(int i=0;i<n;i++){
    //	cout<<"R["<<i<<"]= "<<Rmap[i]<<endl;
    //	cout<<"C["<<i<<"]= "<<Cmap[i]<<endl;
	//}
	
	int A[n][n];
	if(solexist){
		
		int differences[n];
		for(int i=0;i<n;i++){
			differences[i] = Cmap[i];
			for(int j=0;j<n;j++){
				A[i][j] = 0;
			}
		}
		
		
		for(int i=0;i<n;i++){
			int k = Rmap[i];
			int* indices = findkMaxDifferencesIndex(differences,k,n);
			if(differences[indices[k-1]] < 0 ){
				solexist = false;
				break;
			}
			for(int l=0;l<k;l++){
				A[i][indices[l]] = 1;
			}
		}
	}
	
	f2.open("output.txt",ios::out);
	if(f2.is_open()){
		
		if(solexist){
		    f2<<1<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					f2<<A[i][j];
					if(j!=n-1)f2<<",";
				}
				if(i!=n-1)f2<<endl;
			}
		}
		else{
			f2<<0;
		}
	
	}else{
		cout<<"Can't open output file"<<endl;
	}
	return 0;
}


