#include<iostream>
using namespace std;
	
	class Bank{
		
		protected:
	    int balance = 0;
	    int account;
	    string name;
	
	    static int accountCounter;
	
	public:
		
	    void createAccount(string n) {
	        name = n;
	        account = 100000 + accountCounter * 13 + n[0];
	        accountCounter++;
	        cout << "Account created successfully!" << endl;
	        cout << "Generated Account Number: " << account << endl;
	    }
	
	    int getAccount() const {
	        return account;
	    }
		
	    string getName() const {
	        return name;
	    }
	
	    int getBalance() const {
	        return balance;
	    }
	
	    void deposit(int amount) {
	        if (amount > 0) {
	            balance += amount;
	            cout << "Deposit successful!" << endl;
	        } else {
	            cout << "Invalid deposit amount." << endl;
	        }
	    }
	
	    void withdraw(int amount) {
	        if (amount > 0 && amount <= balance) {
	            balance -= amount;
	            cout << "Withdrawal successful!" << endl;
	        } else {
	            cout << "Invalid or insufficient balance." << endl;
	        }
	    }
	
	    bool transfer(Bank &receiver, int amount) {
	        if (amount > 0 && amount <= balance) {
	            balance -= amount;
	            receiver.balance += amount;
	            return true;
	        } else {
	            return false;
	        }
	    }
	    
		virtual void applyInterest() {
	          
	      }
       
	    virtual void calculateFixedInterest() {
            
        }
	       	
		
	};
	

	
	int Bank::accountCounter = 1;
	
	class Savingaccount : public Bank{
		
			public:
				
				int interestrate = 5;
				
				void setinterst(){
				
				if (balance > 0) {
		            int interest = (balance * interestrate) / 100;
		            balance += interest;
		            cout << "Interest of " << interest << " added. New balance: " << balance << endl;
		        		} else {
		            cout << "No balance to apply interest." << endl;
		       	}
						
			}
					
		
	};
	
	class Checkingaccount : public Bank{
		
			public:
				
				int overdraftLimit = -1000;
	
	    void withdraw(int amount) {
	        if (balance - amount >= overdraftLimit) {
	            balance -= amount;
	            cout << "Withdrawal with overdraft successful!" << endl;
	        } else {
	            cout << "Overdraft limit exceeded!" << endl;
	        }
	    }
	};
	
	class Fixeddeposite : public Bank{
		
			public:
				
			int term = 2;
	
		    void calculateinterest() {
		        int interestRate = 5;
		        int interest = (balance * interestRate * term) / 100;
		        cout << "Interest on fixed deposit after " << term << " years: " << interest << endl;
		    }
				
	};
	
	int findAccount(Bank* users[], int total, int accNum) {
		    for (int i = 0; i < total; ++i) {
		        if (users[i]->getAccount() == accNum) {
		            return i;
		        }
		    }
		    return -1;
			}
	
	int main() {
	    const int MAX = 100;
	    Bank* users[MAX];
	    Savingaccount S;
	    int totalAccounts = 0;
	    int choice;
	
	    do {
	        cout << "\n--- Welcome to BANK---" << endl;
	        cout << "1. Create New SavingAccount" << endl;
	        cout << "2. Show Account Details" << endl;
	        cout << "3. Deposite Money Account " << endl;
	        cout << "4. Withraw Money Account " << endl;
	        cout << "5. Interest rate Money from Account " << endl;
	        cout << "6. overdraft Money Account " << endl;
	        cout << "7. Fixed Deposite Account " << endl;
	        cout << "8. Exit" << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;
	
	        switch(choice) {
	        	
	            case 1: {
	                if (totalAccounts >= MAX) {
	                    cout << "Account limit reached!" << endl;
	                    break;
	                }
	             string name;
                cout << "Enter your name: ";
                cin>> name;
                users[totalAccounts] = new Savingaccount();
                users[totalAccounts]->createAccount(name);
                totalAccounts++;
                break;
	            }
	
	            case 2: {
	               int acc;
                cout << "Enter your account number: ";
                cin >> acc;
                int idx = findAccount(users, totalAccounts, acc);
                if (idx != -1) {
                    cout << "Name: " << users[idx]->getName() << endl;
                    cout << "Account Number: " << users[idx]->getAccount() << endl;
                    cout << "Balance: " << users[idx]->getBalance() << endl;
                } else {
                    cout << "Account not found." << endl;
                }
                break;
	            }
	
	            case 3: 
				
				{
	               int acc, amt;
                cout << "Enter your account number: ";
                cin >> acc;
                int idx = findAccount(users, totalAccounts, acc);
                if (idx != -1) {
                    cout << "Enter deposit amount: ";
                    cin >> amt;
                    users[idx]->deposit(amt);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
	            }
	
	            case 4: {
	                 int acc, amt;
                cout << "Enter your account number: ";
                cin >> acc;
                int idx = findAccount(users, totalAccounts, acc);
                if (idx != -1) {
                    cout << "Enter withdrawal amount: ";
                    cin >> amt;
                    users[idx]->withdraw(amt);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
	            }
	
	            case 5: {
	            	int acc;
                cout << "Enter your account number: ";
                cin >> acc;
                int idx = findAccount(users, totalAccounts, acc);
                if (idx != -1) {
                    S.setinterst();
               } else {
                    cout << "Account not found or not a Saving Account!" << endl;
                }
                break;
	            }
	            case 6: {
	               
				    int acc;
	                cout << "Enter account number: ";
	                cin >> acc;
	                int idx = findAccount(users, totalAccounts, acc);
	                Fixeddeposite* fd = dynamic_cast<Fixeddeposite*>(users[idx]);
	                
					if (fd) {
	                    fd->calculateinterest();
	                } else {
	                	
	                    cout << "Not a Fixed Deposit Account!" << endl;
	                
					}
	                break;
	            }
	            case 7: {
	               if (totalAccounts >= MAX) {
                    cout << "Account limit reached!" << endl;
                    break;
                }
                string name;
                cout << "Enter your name: ";
                cin >> name;
                users[totalAccounts] = new Fixeddeposite();
                users[totalAccounts]->createAccount(name);
                totalAccounts++;
                break;
	            }
	            
	            case 8: {
	                cout << "Exiting the system.... Thank you!" << endl;
	                break;
	            }
	
	            default:
	                cout << "Invalid choice. Try again!" << endl;
	        }
	
	    } while (choice != 8);
	
	    return 0;
	}
