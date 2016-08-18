#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int sv, bool* visited, map< int , list<int> > adj , int * count , int n);
map< int , list<int> > createnewgraph(map< int , list<int> > adj,int n);

int main(){
	ifstream f1;
	ofstream f2;
	string line;
	int n=0;
	int c=0;
	char a;
	map< int , list<int> > adj;
	int startvertex = -1;
	int myint;
	f1.open("input.txt" , ios::in);
	
	if(f1.is_open()){
		while(getline(f1,line)){
			
			//cout<<line<<endl;
			if(c == 0){
				stringstream ss;
				ss << line;
				ss >> n;
				//cout<<"n= "<<n<<endl;
			}
			else if(c<=n){
				int len = line.length();
				string temp="";
				int num=0;
				int check=0;
				int mainvertex=0;
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
							
							if(check==0){
								mainvertex = num;
								check=1;
							}else{
								adj[mainvertex].push_back(num);
							}
							
						}
					}
					if( i == len-1){
						if(temp != ""){
							stringstream ss;
							ss << temp;
							ss >> num;
							temp = "";
							
							if(check==0){
								mainvertex = num;
								check=1;
								list< int > empty;
								adj[mainvertex] = empty;
							}else{
								adj[mainvertex].push_back(num);
							}
							
						}	
					}	
				}
			}
			else{
				int len = line.length();
				string temp="";
				for(int i=1;i<len;i++){
					temp+=line[i];
				}
				stringstream ss;
				ss << temp;
				ss >> startvertex;
			}
			c++;
		}
		f1.close(); 
	}          
	else{     
	cout<<"Couldn't open file.";
    }
    
    /*cout<<"The Adjacency list is"<<endl;
    for(map< int , list< int > >::iterator i= adj.begin() ; i!= adj.end(); i++){
    	cout<<(*i).first<<" -> ";
    	for(list< int >::iterator j = (*i).second.begin(); j!= (*i).second.end(); j++){
    		cout<<(*j)<<" ";
		}
		cout<<endl;
	}
	cout<<"The start vertex is "<<startvertex; */
	
	if(startvertex != -1){
		map< int , list<int> > newg = createnewgraph(adj,n);
		int newn = 2*n;
		
		bool* visited;
		visited = new bool[newn+1];
		for(int i=0;i<=newn;i++){
			visited[i] = false;
		}
	   
	   	//cout<<"Visited vertices from vertex "<<startvertex<<endl;
		int * count;
		int total =0;
		count = &total;
		dfs(startvertex ,visited, newg,count,n);
		
		f2.open("output.txt",ios::out);
		bool first=true;
		if(f2.is_open()){
			f2 << (*count) <<endl;
			for(int i=1;i<=newn;i++){
				if(visited[i] == true && i<=n ){
					if(first){
						f2<<"v"<<i;
						first = false;
					}
					else{
						f2<<",v"<<i;
				    }
				}
		    }	
		}else{
			cout<<"Can't open output file"<<endl;
		}
		
		/*cout<<"count= "<<*count<<endl;
		for(int i=1;i<=newn;i++){
			if(visited[i] == true && i<=n ){
				cout<<i<<" ";
			}
		}*/
		
	}else{
		cout<<"Start vertex can't be initialized!";
	}
	
    
	return 0;
}

void dfs(int sv, bool* visited, map< int , list<int> > adj, int* count, int n){
	visited[sv] = true;
	if(sv<=n)(*count)++;
	for(list<int>::iterator i= adj[sv].begin(); i != adj[sv].end(); i++){
		if(!visited[(*i)]){
			dfs((*i) , visited , adj , count , n);
	    }
	}
}

map< int , list<int> > createnewgraph(map< int , list<int> > adj,int n){
	map< int , list<int> > newg;
	for(map< int , list< int > >::iterator i= adj.begin() ; i!= adj.end(); i++){
    	int m = (*i).first;
    	list<int> temp = (*i).second;
    	for(list< int >::iterator j = temp.begin(); j!= temp.end(); j++){
    		newg[(m)].push_back(n+(*j));
    		newg[n+(m)].push_back((*j));
		}
	}
	return newg;
}
