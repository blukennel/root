//==========================
// Adrian Romanowski
// Algorytm A* - rozwiazanie
// 30.10.2018
//==========================
//blabla gitfghfh
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct list
{
	int id;			// cyfra pobrana z grid.txt
	bool parent;	// czy byl wczesniej policzony koszt
	int parent_x;	// pozycja x rodzica
	int parent_y;	// pozycja y rodzica
	float cost;		// koszt ruchu
	int time;		// licznik kiedy listy/ kiedy dodany
};

bool read_file();
void save_file();
void print(string type);
void add(int x,int y,string list);
void remove(int x,int y,string list);
bool astar();
void set_grid();
float pitagoras(int x,int y);
bool check_open_list();
void make_route();

list grid[20][20];
bool open_list[20][20];
bool closed_list[20][20];
int start_x=0;		// pozycja startowa
int start_y=0;		// pozycja startowa
int goal_x=19;		// cel
int goal_y=19;		// cel
int pos_x=start_x;	// pole ostatnio dodane do listy zamknietej
int pos_y=start_y;	// pole ostatnio dodane do listy zamknietej
int index=0;			// licznik pol dodanych do listy otwartej

int main()
{
	if(!read_file())
		goto end;
	set_grid();
	add(start_x,start_y,"closed_list");
	astar();
	make_route();
	print("grid");
	end:
	return 0;
}

bool astar()
{	
	float low;	// najnizszy koszt ruchu
	int low_x;
	int low_y;
	low=50;

while(true)
{
	// dodaje pola jesli sa puste oraz nie wychodza poza grid 
	if(pos_y+1<20 && grid[pos_x][pos_y+1].id==0)
	{	// gora
		add(pos_x,pos_y+1,"open_list");
		grid[pos_x][pos_y+1].parent_x=pos_x;
		grid[pos_x][pos_y+1].parent_y=pos_y;
		grid[pos_x][pos_y+1].id=1;
		index++;
	}	// dol
	if(pos_y-1>=0 && grid[pos_x][pos_y-1].id==0)
	{
		add(pos_x,pos_y-1,"open_list");
		grid[pos_x][pos_y-1].parent_x=pos_x;
		grid[pos_x][pos_y-1].parent_y=pos_y;
		grid[pos_x][pos_y-1].id=1;
		index++;
	}	// lewa
	if(pos_x-1>=0 && grid[pos_x-1][pos_y].id==0)
	{
		add(pos_x-1,pos_y,"open_list");
		grid[pos_x-1][pos_y].parent_x=pos_x;
		grid[pos_x-1][pos_y].parent_y=pos_y;
		grid[pos_x-1][pos_y].id=1;
		index++;
	}	// prawa
	if(pos_x+1<20 && grid[pos_x+1][pos_y].id==0)
	{
		add(pos_x+1,pos_y,"open_list");
		grid[pos_x+1][pos_y].parent_x=pos_x;
		grid[pos_x+1][pos_y].parent_y=pos_y;
		grid[pos_x+1][pos_y].id=1;
		index++;
	}

	// oblicza koszt ruchu dla pol otwartych
	for(int i=0; i<20; i++)	
		for(int j=0; j<20; j++)
		{
			if(open_list[j][i]==true)
				if(grid[j][i].parent==false)
					grid[j][i].cost=pitagoras(j,i);
				else
					if(pitagoras(j,i)<grid[j][i].cost)
						grid[j][i].cost=pitagoras(j,i);
		}

	int lowi=0;
	for(int i=0; i<20; i++)	
		for(int j=0; j<20; j++)
		{
			if(open_list[j][i]==true)
				if(grid[j][i].time>lowi)
				{
					lowi=grid[j][i].time;
					low_x=j;
					low_y=i;
					low=pitagoras(j,i);
				}
		}

	for(int i=0; i<20; i++)	
		for(int j=0; j<20; j++)
			if(open_list[j][i]==true)
				if(grid[j][i].cost<low)
				{
					low=grid[j][i].cost;
					low_x=j;
					low_y=i;
				}
	
	pos_x=low_x;
	pos_y=low_y;
	add(low_x,low_y,"closed_list");
	remove(low_x,low_y,"open_list");

	if(check_open_list==false)
		return false;
	if(index==200)
		return true;
}	
}

bool read_file()
{
	fstream file;
	file.open("grid.txt",ios::in);
	if(file.good()==true)
	{
		cout<<"File opened"<<endl;
		string data;
		int index=0;
		for(int j=19; j>=0; j--)
		{
			getline(file,data);
			for(int i=0; i<40; i+=2)
			{
				grid[index][j].id=data[i]-48;
				index++;
			}
			index=0;
		}
		cout<<"Grid loaded"<<endl;
		file.close();
		return true;
	}
	else
	{
		cout<<"File not opened"<<endl;
		return false;
	}
}

void print(string type)
{
	if(type=="grid")
	{
		for(int i=19; i>=0; i--)
		{
		for(int j=0; j<20; j++)
			cout<<grid[j][i].id<<" ";
		cout<<endl;
		}
	}

	if(type=="open_list")
	{
		cout<<"Open list:"<<endl;
		for(int i=19; i>=0; i--)
			for(int j=0; j<20; j++)
				if(open_list[j][i]==true)
				{
					cout<<"Node: ("<<j<<","<<i<<")";
					cout<<endl;
				}
	}

	if(type=="closed_list")
	{
		cout<<"Closed_list:"<<endl;
		for(int i=19; i>=0; i--)
			for(int j=0; j<20; j++)
				if(closed_list[j][i]==true)
				{
					cout<<"Node: ("<<j<<","<<i<<")";
					cout<<endl;
				}
	}

	if(type=="data")
	{
		int index=0;
		for(int j=0; j<20; j++)
		{
			for(int i=0; i<20; i++)
			{
				cout<<"["<<i<<","<<index<<"] ";
				if(grid[i][index].id==5)
					cout<<"Obstacle";
                if(grid[i][index].parent_x!=999)
					cout<<"  px = "<<grid[i][index].parent_x;
                if(grid[i][index].parent_y!=999)
					cout<<"  py = "<<grid[i][index].parent_y;
                if(grid[i][index].cost!=999)
					cout<<"  cost = "<<grid[i][index].cost;
            	cout<<endl;
			}
			index++;
		}
	}
}

void save_file()
{
	ofstream file("solution.txt");
  	for(int i=19; i>=0; i--)
  	{
  		for(int j=0; j<20; j++)
  		{
  			file<<grid[j][i].id;
  			file<<" ";
  		}
  		file<<endl;
  	}
  	file.close();
  	cout<<"Solution saved"<<endl;
}

void add(int x, int y, string list)
{
	if(list=="open_list")
	{
		open_list[x][y]=true;
		grid[x][y].time=index;
	}
	else if(list=="closed_list")
		closed_list[x][y]=true;
	else
		cout<<"Zla nazwa!"<<endl;
}

void remove(int x, int y, string list)
{
	if(list=="open_list")
		open_list[x][y]=false;
	else if(list=="closed_list")
		closed_list[x][y]=false;
	else
		cout<<"Zla nazwa!"<<endl;
}

void set_grid()
{
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)	
		{
			grid[i][j].parent_x=999;
			grid[i][j].parent_y=999;
			grid[i][j].cost=999;
			grid[i][j].parent=false;
		}
}

float pitagoras(int x,int y)
{
	float p;
	p=sqrt((goal_x-x)*(goal_x-x)+(goal_y-y)*(goal_y-y));
	p=p+(start_x-x)+(start_y-y);
	return p;
}

bool check_open_list()
{
	for(int i=0; i<20; i++)	
		for(int j=0; j<20; j++)
			if(open_list[j][i]==true)
				return true;
	return false;
}

void make_route()
{
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			if(closed_list[j][i]==true)
				grid[j][i].id=3;

	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			if(grid[j][i].id==2 || grid[j][i].id==3 || grid[j][i].id==1)
				grid[j][i].id=0;

	int rx,ry;
	rx=grid[goal_x][goal_y].parent_x;
	ry=grid[goal_x][goal_y].parent_y;
	grid[rx][ry].id=2;
	while(rx!=start_x && ry!=start_y)
	{
		rx=grid[rx][ry].parent_x;	// tu gdzies jest bug ze wraca na skos
		ry=grid[rx][ry].parent_y;
		grid[rx][ry].id=2;
	}
	

}

