#include <iostream>
#include <string> 

using namespace std; 

void Search (class obra, string str1){
	string str; //a string onde será buscada
	size_t achou =str.find(str1);// "size_t achou" armazenará o índice do resultado da busca por str1 dentro de str. 

	if (achou != string::npos) // npos= no position, ou seja, se o resultado não for "no position" é pq achou
		cout << "Primeira ocorrência de "<< str1<<" é: " << found << endl; 






int main() 
{ 
	string str = "geeksforgeeks a computer science"; 
	string str1 = "geeks"; 

	// Find first occurrence of "geeks" 
	size_t found = str.find(str1); 


	// Find next occurrence of "geeks". Note here we pass 
	// "geeks" as C style string. 
	char arr[] = "geeks"; 
	found = str.find(arr, found+1); 
	if (found != string::npos) 
		cout << "Next occurrence is " << found << endl; 


	return 0; 




	string str = "geeksforgeeks a computer science"; 
	string str1 = "geeks"; 

	// Find first occurrence of "geeks" 
	size_t found = str.find(str1); 
	if (found != string::npos) 
		cout << "First occurrence is " << found << endl; 

	// Find next occurrence of "geeks". Note here we pass 
	// "geeks" as C style string. 
	char arr[] = "geeks"; 
	found = str.find(arr, found+1); 
	if (found != string::npos) 
		cout << "Next occurrence is " << found << endl; 





} 


