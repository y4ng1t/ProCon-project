#include<iostream>
#include<cstring>
using namespace std;
int main()
{	
	string choose;
	bool startbool = true;
	bool value1 = false;
	bool value2 = true;
	int n1,n2,res;
	string op;

	//choosing what between aritmatics and matriks
	cout << "Choose\n"  << "(1) to do Aritmatics\n" << "(2) to do Matriks\n";
	do{	
		cin >> choose;
		if(choose == "1" || choose == "2")
		{
			startbool = false;
		}
		else
		{
			cout <<"That's not a choise \nPlease choose one of two calculation that you wanna use\n";
			startbool = true;
		}
	}while(startbool == true);
	
	
		char repeat;
	
		//case 1 for aritmatics
		if(choose == "1"){
			do {
				//inputing number
				cout << "input Number" << endl;
				cin >> n1;
				cout << "enter the operator" << endl;
				cin >> op;
				cout << "input Number" << endl;
				cin >> n2;
				
				//operator
				if(op == "+")
					res = n1 + n2;
				else if(op == "-")
					res = n1 - n2;
				else if (op == "*")
					res = n1 * n2;
				else if (op == "/")
					res = n1 / n2;
				else if (op == "%")
					res = n1 % n2;
				else 
					cout <<"Your Operator is not Found please try again" << endl;
			
				//calculating
				cout << n1 << op << n2 << "=" << res << endl;
				//looping
				do 
				{
					cout << "do you want to calculate again? answer y/n" <<endl;
					cin>>repeat;
					
					switch(repeat)
					{
						case 'y':
							value1 = false;
							value2 = true;
						break;
						case 'n' :
							value1 = true;
							value2 = true;
						break;
						default :
							value2 = false; 
					}
				} while(value2 == false);
			
			} while(value1 == false);
				cout <<"thank you for using aritmatics\n";
		}
		
		
			 //case 2 matrix
		else if(choose == "2"){
			int var1;
			int var2;
			int var3 = 0, var4 = 0;
			string matrixoperator;
			int arr[100][100];
			int arr2[100][100];
			int arrsum[100][100];
			
			//input the matrix
			do
			{	
				cout << "Please Enter First Matrix Ordo [Max 100x100]" << endl;
				cin >> var1;
				cin >> var2;
			
				cout << "Input Element Number in Matrix" << endl;
				for (int row = 0; row < var1; row++) 
				{
					  for (int column = 0; column < var2; column++) 
					  {
					    int temp1;
						cout << "Input Element of " << row + 1 << " " << column + 1 << endl;
						cin >> temp1;
						arr[row][column] = temp1;
					  }
					  cout << endl;
				} 
					
				cout << "Please Enter Second Matrix Ordo" << endl;
				cin >> var3 >> var4;
				for (int rows = 0; rows < var3; ++rows) 
				{
					  for (int columns = 0; columns < var4; ++columns) 
					  {
					    int temp2;
						cout << "Input Element of " << rows + 1 << " " << columns + 1<< endl;
						cin >> temp2;
						arr2[rows][columns] = temp2;
					  }
					  cout << endl;
				} 
				
				//operator
				cout << "What Operation Do You Want? (Add,Subs,Multi)" << endl;
				cin >> matrixoperator;
				char tempop[matrixoperator.length() + 1];
				char lowermatrix[matrixoperator.length() + 1];
				strcpy(tempop, matrixoperator.c_str());
				for(int b = 0; b < matrixoperator.length(); b++)
				{
					lowermatrix[b] = tolower(tempop[b]);
				}
				matrixoperator = lowermatrix;
					
				if(matrixoperator == "add")
				{
					if(var1 == var3 && var2 == var4)
					{
						for(int count = 0; count < var1; ++count)
						{
							for(int counts = 0; counts < var2; ++counts)
							{
								arrsum[count][counts] = arr[count][counts] + arr2[count][counts];
								cout << arrsum[count][counts] << " "; 
							}
							cout << endl;
						}
					}
					else
					{
						cout << "This operation cannot be done\n";
					}
				}
				
				else if(matrixoperator == "subs")
				{
					if(var1 == var3 && var2 == var4)
					{
						for(int count = 0; count < var1; ++count)
						{
							for(int counts = 0; counts < var2; ++counts)
							{
								arrsum[count][counts] = arr[count][counts] - arr2[count][counts];
								cout << arrsum[count][counts] << " "; 
							}
							cout << endl;
						}
					}
					else 
					{
						cout << "This operation cannot be done\n";
					}
				}
				
				else if(matrixoperator == "multi")
				{
					if(var1 == var4 && var2 == var3)
					{
						for(int i = 0; i < var1; ++i)
	        			{
							for(int j = 0; j < var4; ++j)
	        				{
	            				arrsum[i][j]=0;
	        				}
						}	
						for(int count = 0; count < var1; ++count)
						{
							for(int counts = 0; counts < var2; ++counts)
							{
								for(int countr = 0; countr < var4; ++countr)
								{
									arrsum[count][counts] += arr[count][countr] * arr2[countr][counts];
								}
							}
							cout << endl;
						}			
						for(int i = 0; i < var1; ++i)
						    for(int j = 0; j < var4; ++j)
						    {
						        cout << " " << arrsum[i][j];
						        if(j == var4-1)
						            cout << endl;
						    }
	
					}
					else
					{
						cout << "This Operation Cannot Be Done" << endl;
					}
				}
				
				//looping
				do 
				{
					cout << "do you want to calculate again? answer y/n" <<endl;
					cin>>repeat;
					
					switch(repeat)
					{
						case 'y':
							value1 = false;
							value2 = true;
						break;
						case 'n' :
							value1 = true;
							value2 = true;
						break;
						default :
							value2 = false; 
					}
				} while(value2 == false);
			}	while (value1 == false);
				cout <<"\nThank you for using Matrix calculator\n";
		} 
		
		
	return 0;

}
