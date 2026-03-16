#include<iostream>
using namespace std;

class Train{
	
	private:
		
		int trainnum;
		string trainname;
		string source;
		string destination;
		int traintime;
		
		static int traincount;
		
		public:
			
			Train(){
				
				trainnum = 0;
				trainname = "";
				source = "";
				destination = "";
				traintime = 0;
				traincount++;	
			}
	
			Train(int number, string name, string src,string des, int time){
				
				trainnum = number;
				trainname = name;
				source = src;
				destination = des;
				traintime = time;
				traincount++;
				
			}
			
			~Train(){
				traincount--;
			}
			
			void settraindeatils(int number,string name,string src,string des,int time){
				
				trainnum = number;
				trainname = name;
				source = src;
				destination = des;
				traintime = time;
				traincount++;
			}
			
			int gettrainnumber(){
				return trainnum;
			}
			string gettrainname(){
				return trainname;
			}
			string gettrainsorce(){
				return source;
			}
			string gettraindest(){
				return destination;
			}
			int gettraintime(){
				return traintime;
			}
	
	
			void display(){
				
				cout<< " Train Number :- " << trainnum <<endl;
				cout<< " Train Name   :- " << trainname <<endl;
				cout<< " Train From   :- " << source <<endl;
				cout<< " Train To     :- " << destination <<endl;
				cout<< " Train Time   :- " << traintime <<endl;
			}
			
			static int gettraincount(){
				
				return traincount;
			}
			
};

int Train::traincount = 0;

class Railwaysystem {
		
	
		private:
		
		Train t1[100];
		int totaltrain;
		
		
		public:
		
		int number, time;
       	string name, src, des;
       	 
       	 
		Railwaysystem(){
			totaltrain =0; 
		}	
		
		void addtrain(){
			
			if (totaltrain>100){
				
				cout<< "train data is full" << endl;
				return;
			}
			
		cout << "Enter Train Number: ";
        cin >> number;
        cout << "Enter Train Name: ";
        cin >> name;
        cout << "Enter Source: ";
        cin >> src;
        cout << "Enter Destination: ";
        cin >> des;
        cout << "Enter Time: ";
        cin >> time;

        t1[totaltrain].settraindeatils(number, name, src, des, time);
        totaltrain++;
			}
			
		void displayalltrain(){
			
			for (int i = 0; i < totaltrain; i++) {
            cout << "-----------" << endl;
            t1[i].display();
        	}
		
		}
		void searchtrain(int number) {
    			for (int i = 0; i < totaltrain; i++) {
        			if (t1[i].gettrainnumber() == number) {
		            cout << "Train Found:"<< endl;
		            t1[i].display();

		            return;
		        }
   			 }
   				 
        	cout << "Train with number " << number << " not found."<< endl;
    		
		}
	
			
			
};


int main(){

	Railwaysystem rs;
    int choice;

    do {
        cout << "\n--Railway System Menu--\n";
        cout << "1. Add Train\n";
        cout << "2. Display All Trains\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rs.addtrain();
                
                cout<< "Train added sucessfully " << endl;
                break;
            case 2:
                cout<< "Display all Trains-----  " << endl;
                rs.displayalltrain();
                
                break;
            case 3: {
                int searchnum;
                cout << "Enter Train Number to Search: ";
                cin >> searchnum;
                rs.searchtrain(searchnum);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice.\n";
        }
    } while (choice != 4);

	
	
	return 0;
}