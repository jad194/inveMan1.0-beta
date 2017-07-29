#include<iostream>
#include"Item.h"
using namespace std;
string input, item;
int q = 0, change;

int main(){
  cout << "\n\n\n\n InveMan beta v1.0 \n\nFor a list of commands type '-help' or '-h' without quotes.\n\n ";
Item obj;

while(q==0){

cin >> input;

if(input=="-help"||input=="-HELP"||input=="-h"||input=="-H"){
  cout << "\n -help : command list\n\n -n : add new item to inventory\n";
  cout << " -d : delete item from inventory\n -l : list all current items\n -q : exit the program\n";
  cout << " -m : modify an item's quantity.\n\n ";
}if(input=="-n"||input=="-N"){
  obj.newItem();
}if(input=="-d"||input=="-D"){
  obj.deleteItem();
}if(input=="-l"||input=="-L"){
  cout << "\n"; obj.getItemList(1); cout << "\n ";
}if(input=="-m"||input=="-M"){
  cout << "Please type your change, Ex.\n\tIncrease by 4 : Banana 4 or Banana +4\n\tDecrease by 7 : Apple -7\n\n ";
  cin >> item >> change;
  obj.chQuantity(item,change);
}if(input=="-q"||input=="-Q"){
  q++;
}

}}
