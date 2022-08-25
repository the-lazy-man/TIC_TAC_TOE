// #include <iostream>
// #include <string>
// #include <queue>
#include<bits/stdc++.h>
using namespace std ;

void instruction(){
	cout<<" | (1,1) | (1,2) |(1,3) |"<<endl;
	cout<<" | (2,1) | (2,2) |(2,3) |"<<endl;
	cout<<" | (3,1) | (3,2) |(3,3) |"<<endl;
	return ;
}
bool winnercheck(char arr[3][3]){
	int i=0,j=0;
    if((arr[0][2]==arr[1][1]) && (arr[1][1]==arr[2][0])){
		cout<<"the winner is " ;
		(arr[0][2]=='x'?cout<<"player_1":cout<<"player__2");
		return true;
	}
	else if((arr[0][0]==arr[1][1]) && (arr[1][1]==arr[2][2])){
		cout<<"the winner is " ;
		(arr[0][0]=='x'?cout<<"player_1":cout<<"player__2");
		return true;
	}
	else{
    	for(j=0;j<3;j++){
           	if(arr[0][j]==arr[1][j]&&arr[1][j]==arr[2][j]){
           		cout<<"the winner iss " ;
    			(arr[0][j]=='x'?cout<<"player_1":cout<<"player__2");
    			    return true;
    		}
    		else if(arr[j][0]==arr[j][1]&&arr[j][1]==arr[j][2]){
    			cout<<"the winner is " ;
    			(arr[j][0]=='x'?cout<<"player_1":cout<<"player_2");
    		        return true;
    		}
    	}	
	}
	return false;
}
queue <int> are;
queue <int> cee;
queue <int> ARE_o;
queue <int> CEE_o;
queue <int> ARE_x;
queue <int> CEE_x;
string arr_o[3][3] ;
string arr_x[3][3] ;
string arr[3][3] ;
void box(int r,int c,char p){
    int i,j;
    // construction of table arr
    for(i=0;i<3;i++){
	    for(j=1;j<3;j++){
	        arr[i][j]=" |";
		}
	}
    for(i=0;i<3;i++){
        int j=0 ;
        arr[i][j]="| |" ;
    }
	
	// construction of table arr_o
    for(i=0;i<3;i++){
		for(j=1;j<3;j++){
	        arr_o[i][j]=" |";
	    }
    }
    for(i=0;i<3;i++){
        int j=0 ;
        arr_o[i][j]="| |" ;
	}
	
	// construction of table arr_x
    for(i=0;i<3;i++){
        for(j=1;j<3;j++){
            arr_x[i][j]=" |" ;
        }
    }
    for(i=0;i<3;i++){
        int j=0 ;
        arr_x[i][j]="| |" ;
    }
    
    
    if(p=='o'){
        ARE_o.push(r) ;
        CEE_o.push(c) ;
        
		are=ARE_o ;
        cee=CEE_o ;
        while(!are.empty() && !cee.empty()){
            if(arr_o[are.front()][cee.front()]=="| |"){
               arr_o[are.front()][cee.front()]="|o|" ; 
            }
            are.pop() ;
            cee.pop() ;
        }
        are=ARE_o ;
        cee=CEE_o ;
        while(!are.empty() && !cee.empty()){
	        if(arr_o[are.front()][cee.front()]==" |"){
	            arr_o[are.front()][cee.front()]="o|" ;
	        }
	        are.pop();
	        cee.pop();
		}
		
    }	
    if(p=='x') {
    
        ARE_x.push(r) ;
        CEE_x.push(c) ;
        are=ARE_x ;
        cee=CEE_x ;
        while(!are.empty() && !cee.empty()){
            if(arr_x[are.front()][cee.front()]=="| |"){
               arr_x[are.front()][cee.front()]="|x|" ; 
            }
            are.pop() ;
            cee.pop() ;
        }
        are=ARE_x ;
        cee=CEE_x ;
        while(!are.empty() && !cee.empty()){
		    if(arr_x[are.front()][cee.front()]==" |"){
            	arr_x[are.front()][cee.front()]="x|" ;
        	}
        	cee.pop();
        	are.pop();
		}
    }
    are=ARE_x ;
    cee=CEE_x ;
    while(!are.empty() && !cee.empty()){
        if(arr_x[are.front()][cee.front()]=="| |"){
            arr_x[are.front()][cee.front()]="|x|" ; 
        }
        are.pop() ;
        cee.pop() ;
    }
    are=ARE_x ;
    cee=CEE_x ;
    while(!are.empty() && !cee.empty()){
		if(arr_x[are.front()][cee.front()]==" |"){
            arr_x[are.front()][cee.front()]="x|" ;
        }
        cee.pop();
        are.pop();
	}
		
    for(i=0;i<3;i++){
    	for(j=0;j<3;j++){
    		if(arr_x[i][j]!=" |" && arr_x[i][j]!="| |"){
    			arr[i][j]=arr_x[i][j] ;
			}
		}
	}
	are=ARE_o ;
    cee=CEE_o ;
    while(!are.empty() && !cee.empty()){
        if(arr_o[are.front()][cee.front()]=="| |"){
            arr_o[are.front()][cee.front()]="|o|" ; 
        }
        are.pop() ;
        cee.pop() ;
    }
    are=ARE_o ;
    cee=CEE_o ;
    while(!are.empty() && !cee.empty()){
	    if(arr_o[are.front()][cee.front()]==" |"){
	        arr_o[are.front()][cee.front()]="o|" ;
	    }
	    are.pop();
	    cee.pop();
	}
	for(i=0;i<3;i++){
    	for(j=0;j<3;j++){
    		if(arr_o[i][j]!=" |" && arr_o[i][j]!="| |"){
    			arr[i][j]=arr_o[i][j] ;
			}
		}
	}
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<arr[i][j] ;
        }
        cout<<"\n" ;
    }
    cout<<"\n";
}
void clear( std::queue<int> &q )
{
   std::queue<int> empty;
   std::swap( q, empty );
}

int main(){
static char player_1='x',player_2='o';
cout<<"Instruction to play the game."<<endl;
cout<<"\n" ;
cout<<"NOTE :: player_1's avatar is 'x' and palyer_2's avatar is 'o'."<<endl;
cout<<"NOTE :: Input of each player will be the position they want to print their avatar('x' or 'o'). "<<endl;
cout<<"NOTE :: The position given by a player will contain two integers which are :"<<endl;
cout<<"\t'Row'(from 1 -> 3) (followed by a 'space') and 'Column'(from 1 -> 3) ."<<endl;
cout<<"NOTE :: Both the Row and Column should be less than '3' as it's a (3x3)matrix game. "<<endl;
cout<<"\n";
cout<<"Taking the positions as reference from the figure :"<<endl;
cout<<"\n";
instruction();
cout<<"\n";
cout<<"Example : player 1's turn"<<endl;
cout<<"input :: 1 3"<<endl;
box(0,2,player_1);
cout<<"Example : player 2's turn"<<endl;
cout<<"Input :: 2 2"<<endl ;
box(1,1,player_2);
ARE_x.pop();
CEE_x.pop();
ARE_o.pop();
CEE_o.pop();
cout<<"\nLet's play TicTacToe."<<endl;
cout<<"\n";
int counter = 0;
bool continueToPlay = true;
while(continueToPlay){
    bool position[3][3] = {false};
    char tictac[3][3];
    while(counter < 9) {
        cout<<"Number of filled positions - "<<counter<<endl;
        int R,C;
    	int r,c;
    	if(counter%2==0) {
    		cout<<"\nPlayer 1's turn.."<<endl;
    		cout<<"Input :: " ;
    		cin>>R>>C ;
    		r = R-1;
    		c = C-1;
    		while((r > 2 || r < 0) || (c > 2  || c < 0)  || position[r][c]){
    			cout<<"\nenter a valid position"<<endl;
    			cout<<"Input :: " ;
    			cin>>R>>C ;
    		    r = R-1;
    		    c = C-1;
    		}
    		position[r][c] = true;
    		counter++;
    		tictac[r][c]=player_1;
    		box(r,c,player_1);
    	}
    	else{
    		cout<<"\nPlayer 2's turn.."<<endl;
    		cout<<"Input :: " ;
    		cin>>R>>C ;
    		r = R-1;
    		c = C-1;
    		while((r > 2 || r < 0) || (c > 2  || c < 0)  || position[r][c]){
    			cout<<"enter a valid position"<<endl;
    			cout<<"Input :: ";
    			cin>>R>>C ;
    		    r = R-1;
    	    	c = C-1;
    		}
    		position[r][c] = true;
    		counter++;
    		tictac[r][c] = player_2;
    		box(r,c,player_2) ;
    	}
    	if(counter >= 5){
    		if(winnercheck(tictac))
    		    break;
    	}
    }
    if(counter == 9)
        cout<<"The match ia a draw ." ;
        
    cout<<"\nTo continue press 1 otherwise press 0 to exit"<<endl;
    cin>>continueToPlay;
    if(continueToPlay){
        counter = 0;
        clear(ARE_o);
        clear(ARE_x);
        clear(CEE_o);
        clear(CEE_x);
        clear(are);
        clear(cee);
    }
}

	return 0 ;
}
