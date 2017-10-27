#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void makeequal(string &s1,string &s2){
	
	if(s1.size() == s2.size()) return;
	else if(s1.size() > s2.size()){
		int m = (s1.size()-s2.size());
		for(int i=0;i<m;i++){
			s2 = "0" + s2;
		}
	}
	else{
		int m = (s2.size()-s1.size());
		for(int i=0;i<m;i++){
			s1 = "0" + s1;
		}
	}
}

string sum(string s1,string s2){
	if(s1=="")return s2;
	if(s2=="")return s1;
	makeequal(s1,s2);
	int l = s1.size();
	int c = 0;
	string ans="";
	for(int i=(l-1);i>=0;i--){
		char a = s1[i];
		char b = s2[i];
		if(a=='0' && b=='0' && c==0){
			ans = '0' + ans;  c=0;
		}
		else if(a=='0' && b=='0' && c==1){
			ans = '1' + ans;  c=0;
		}
		else if(a=='0' && b=='1' && c==0){
			ans = '1' + ans;  c=0;
		}
		else if(a=='0' && b=='1' && c==1){
			ans = '0' + ans;  c=1;
		}
		else if(a=='1' && b=='0' && c==0){
			ans = '1' + ans;  c=0;
		}
		else if(a=='1' && b=='0' && c==1){
			ans = '0' + ans;  c=1;
		}
		else if(a=='1' && b=='1' && c==0){
			ans = '0' + ans;  c=1;
		}
		else if(a=='1' && b=='1' && c==1){
			ans = '1' + ans;  c=1;
		}
	}
	if(c==0) return(ans);
    else return('1'+ans);
}

string subtract(string s1,string s2){
	string temp = "";
	if(s1 == s2) return("0");
	makeequal(s1,s2);
	int l = s1.size();
	for(int i=0;i<l;i++){
		if(s2[i]=='0'){
			temp = temp + '1';
		}
		else{
			temp = temp + '0';
		}
	}
	string k1 = sum(s1,temp);
	string k2 = sum(k1,"1");
	k2= k2.substr(k2.size()-l,l);
	return(k2);
}

char multiplysingle(string s1,string s2){
	if(s1[0]=='1' && s2[0]=='1') return('1');
	else return('0');	
}

string shift(string s , int n){
	string ans = s;
	for(int i=0;i<n;i++){
		ans = ans + '0';
	}
	return(ans);
}


string multiplyiter(string s1,string s2){
	string ans="";
	makeequal(s1,s2);
	int len = s1.size();
	if(len==0) return("");
	else if(len==1){
		ans = multiplysingle(s1,s2) + ans;
		return(ans);
	}
	for(int i=0;i<len;i++){
		if(s2[len-i-1]=='1'){
			ans = sum(ans,shift(s1,i));
		}
	}
	return(ans);
}

string multiply(string s1,string s2){
	string ans="";
	makeequal(s1,s2);
	int len = s1.size();
	if(len==0) return("");
	else if(len==1){
		ans = multiplysingle(s1,s2) + ans;
		return(ans);
	}
	//if(len<45) return(multiplyiter(s1,s2));
	//cout<<s1<<" s1"<<endl;
	//cout<<s2<<" s2"<<endl;
	int left = len/2;  
	int right = len - left; 
    string xl = s1.substr(0,left);
    string xr = s1.substr(left,right);
    string yl = s2.substr(0,left);
    string yr = s2.substr(left,right);
    //XY = 2n XlYl + 2n/2 * [(Xl + Xr)(Yl + Yr) - XlYl - XrYr] + XrYr
    string xlyl = multiply(xl,yl);
    //cout<<xlyl<<"left"<<endl;
    string xryr = multiply(xr,yr);
    //cout<<xryr<<"right"<<endl;
	string t1 = multiply(sum(xl,xr),sum(yl,yr)); 
	string t2 = subtract(subtract(t1,xlyl),xryr);
    //cout<<t2<<"mid"<<endl;
	string t3 = shift(xlyl,(2*right));
    string t4 = shift(t2,right);
    ans = sum(sum(t3,t4),xryr);
    return(ans);
}


int main(){
	//ifstream f1;
	//ofstream f2;
	string line;
	int n=0;
	int c=0;
	//f1.open("input.txt" , ios::in);
	string num1="";
	string num2="";
	
	/*if(f1.is_open()){
		while(getline(f1,line)){
			
			//cout<<line<<endl;
			if(c == 0){
				stringstream ss;
				ss << line;
				ss >> n;
			}
			else if(c==1){
				int len = line.length();
				for(int i=0;i<len;i++){
					if(line[i] != ' '){
						num1 =  num1 + line[i] ;
					}
					else{
						break;
					}
				}
			}
			else if(c==2){
				int len = line.length();
				for(int i=0;i<len;i++){
					if(line[i] != ' '){
						num2 = num2 + line[i];
					}
					else{
						break;
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
    */
	num1="";
	for(int m=0;m<pow(2,0);m++){
    	num1 = '1'+num1;
	}
	num2=num1;

	string ans = multiplyiter(num1,num2);
	int numzero = 0;
	for(int i=0;i<ans.size();i++){
		if(ans[i]=='0') numzero++;
		else break;
	}

	ans = ans.substr(numzero,(ans.size()-numzero));
	
	//cout<<ans<<endl;
	
	/*f2.open("output.txt",ios::out);
	if(f2.is_open()){
		
		    f2<<ans<<endl;
		    
	}else{
		cout<<"Can't open output file"<<endl;
	}*/


	
	return 0;
}


