#include <iostream>
#include <string>
using namespace std;

bool checkForSandwich(string suspect){
	if (suspect.length() > 2){
		int identicPairs = 0;
		int right = suspect.length() - 1;
		char prevL;
		char prevR;
		for (int i = 0; i < suspect.length() / 2; i++){
			if (suspect[i] == suspect[right]){
				if (identicPairs){
					if (suspect[i] != suspect[i - 1]){
						break;
					}
				}
				identicPairs++;
				prevL = suspect[i];
				prevR = suspect[right--];
			}
			else{
				if(identicPairs > 0){
					if (suspect[i] == prevL || suspect[right] == prevR) {
						cout << "a";
						return false;
					}
					else{
						return true;
					}
				}
				else{
					return false;
				}
			}
		}
		if (suspect.length() % 2){
			if (suspect[suspect.length() / 2 + 1] == suspect[suspect.length() / 2] && suspect[suspect.length() / 2] == suspect[0] ){
				return false;
			}
		}
		else{
			if (suspect.length() / 2 == identicPairs){
				return false;
			}
		}
		return true;
	}
	return false;
}

int main(){
	string line;
	cout << "Enter line: "; cin >> line;
	if (checkForSandwich(line)){
		cout << "Line is sandwich" << endl;
	}
	else{
		cout << "Line is not sandwich" << endl;
	}
	system("pause");
}