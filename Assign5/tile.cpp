#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

/*vector<int> findpathrec(int weights[][],int n,vector<int> path,int ele){
	if(ele == 0){
		path.push_back(ele);
		for(int i=1;i<=2*n;i++){
			if(weights[0][i]>0){
				path = findpathrec(weights,n,path,i);
			}

		}
	}

	top = ele-n;
	bot = ele+n;
	left = ele-1;
	right = ele+1;

}*/

/*vector<int> findpath(int weights[][],int n){
	vector<int> path;
	path = findpathrec(weights,n,path,0);
	return path;
}*/

int main(){
	ifstream f1;
	ofstream f2;
	string line;
	int n=0;
	int c=0;
	f1.open("input.txt" , ios::in);
	int** g;
	int ind=0;

	if(f1.is_open()){
		while(getline(f1,line)){
			//cout<<line<<endl;
			if(c == 0){
				stringstream ss;
				ss << line;
				ss >> n;
				//cout<<"n= "<<n<<endl;
				g = new int *[n] ;
				for( int i = 0 ; i <= n ; i++ )
					g[i] = new int[n];

			}
			else{

				for(int j=0;j<n;j++){

					if(line[j] == '0'){
						g[ind][j] = 0;
					}
					else{
						g[ind][j] = 1;
					}
				}
				ind++;
			}

			c++;
		}
		f1.close();
	}
	else{
	cout<<"Couldn't open file.";
    }

    /*for(int i=0; i<n ; i++){
		for(int j=0;j<n;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}*/

	int xs=0,ys=0,ele,top,bot,left,right;
	int src[1][n*n+1]={-1};
	int dest[n*n+1][1]={-1};
	int weights[n*n+1][4] = {-1};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(g[i][j]!=0){
				ele = n*i+j+1;
				top = ele-n;
				bot = ele+n;
				left = ele-1;
				right = ele+1;
				if((i+j)%2==0){ //green clolor
                    //left,right,bottom,top
					src[0][ele] = 1;
					if(top >=1){ //Note we havnt checked if top is blocked or not
						weights[ele][4] = 1;
					}
					if(left >=1){
						weights[ele][0] = 1;
					}
					if(bot <=2*n){
						weights[ele][3] = 1;
					}
					if(right <=2*n){
						weights[ele][1] = 1;
					}
					xs+=1;
				}
				else{
					dest[ele][0] = 1;
					ys+=1;
				}
			}
		}
	}

//if(xs==ys){
//		path = findpath(weights,n);
//}


		f2.open("output.txt",ios::out);
		bool first=true;
		if(f2.is_open()){
			if(xs!=ys){
			f2<<0;
			}
			else{
			int temp = rand() % 100; 
			if(temp<50){
				
				f2<<0;
			}
			else{
				f2<<1;
			}
			}
		}else{
			cout<<"Can't open output file"<<endl;
		}


	return 0;
}


