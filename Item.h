#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

class Item{


public:

	void newItem(){
	x = 0;
	y = 0;
	t=0;
	typeExists=false;
	typeExists=false;
	cout << "Current item list as follows : " << "\n\n ";

	getItemList(1);

	cout << "\n Please enter an item name, must be unique.\n\n ";
	cin >> name;
	cout << "\n Enter the quantity, if none input '0' without the quotes.\n\n ";
	cin >> amt;

fstream Cats;
Cats.open("Categories.txt");
cout << '\n';
while(getline(Cats,line)){;
	cout << line << '\n';
}
Cats.close();

	cout << "\n Choose a category, or type a unique name to create a new category.\n\n ";
	cin >> cat;

	Cats.open("Categories.txt");

	while(getline(Cats,line)){;
		if(cat==line){
			catExists=true;
		}
	}
	Cats.close();

			for(int i=0;i<t;i++){
				if(name==item[i]){
					typeExists=true;
					cout << "\n" <<name<<" already exists! \n\n " ;
					}
				}
		if(typeExists==false){
				if(catExists==false){
					Cats.open("Categories.txt", ios_base::app);
					Cats << cat << '\n';
					Cats.close();
				}
			fstream Items;
			Items.open("Items.if", ios_base::app);
			Items << name << '\n';
			Items << amt << '\n';
			Items << cat << '\n';
			Items.close();
			cout << '\n' << name << " successfully added. \n\n ";
		}
	}



	 void deleteItem(){
		 string input;
		cout << "\nPlease type the name of the item you would like to delete. \n To return to the main menu, enter '-m'. \n For an item list enter '-l'\n\n ";
		cin >> input;
			if(input=="-l"){
				getItemList(1);
			}else if(input=="-m"){

			}else{
				getItemList(0);
				int ilnum;
				for(int m=0;m<=y;m++){
					if(input==item[m]){
						for(md=m;md<y;md++){
							item[md]=item[md+1];
							quan[md]=quan[md+1];
							category[md]=category[md+1];
						}
							m=y+1;
					}
				}
				fstream Items;
				remove("Items.if");
				Items.open("Items.if", ios_base::app);
				for(int m=0;m<y-1;m++){
					Items << item[m] << '\n';
					Items << quan[m] << '\n';
					Items << category[m] << '\n';
				}
				Items.close();
				cout << "Successfully deleted!\n\n ";
			}

	}

	int getItemList(int G){
		y=0;
		fstream Items;
		Items.open("Items.if");
		while(getline(Items,line)){;
			if(x==0){
				item[y]=line;
				x=1;
			}else if(x==1){
				quan[y]=atoi(line.c_str());
					if(G==1){
						cout << item[y] << ", " << quan[y] << "\n";
					}
				x=2;
			}else if(x==2){
				category[y]=line;
				y++;
				x=0;
			}
			t++;
		}
		Items.close();
	}

	void chQuantity(string it, int qu){
		getItemList(0);

		for(int p=0;p<=y;p++){
			if(item[p]==it){
				quan[p]+=qu;
				fstream Items;
				remove("Items.if");
				Items.open("Items.if", ios_base::app);
				for(int m=0;m<y;m++){
					Items << item[m] << '\n';
					Items << quan[m] << '\n';
					Items << category[m] << '\n';
				}
				Items.close();
				cout << " Change successful.\n\n ";
			}
		}

	}

private:
bool typeExists;
bool catExists;
int x;
int y;
int t;
int md;
int amt;
string cat;
string name;
string line;
string item[300];
int quan[300];
string category[300];

};
