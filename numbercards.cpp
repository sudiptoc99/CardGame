#include<bits/stdc++.h>
using namespace std;
const int king = 11;
const int queen = 12;
const int jack = 13;
const int ace = 1;
class Card
{
	int number;
	string suit;

	public:

	void set(int number,string suit)
	{
		this->number = number;
		this->suit = suit;
	}

	int getNumber()
	{
		return number;
	}

	string getSuit()
	{
		return suit;
	}

	void displayCard()
	{
		if(number == ace)
			cout<<"Ace of "<<suit<<endl;
		else if(number == king)
			cout<<"King of "<<suit<<endl;
		else if(number == queen)
			cout<<"Queen of "<<suit<<endl;
		else if(number == jack)
			cout<<"Jack of "<<suit<<endl;
		else
			cout<<number<<" of "<<suit<<endl;
	}  

	friend void getCards(Card c[]);
	friend void shuffle(Card c[]);
	friend void swap(Card &c1,Card &c2);
};
void swap(Card &c1,Card &c2)
{
	Card temp;
	temp = c1;
	c1 = c2;
	c2 = temp;
}
void getCards(Card c[])
{
	int n;
	srand(time(0));
	bool alloted[13];
	memset(alloted,false,sizeof(alloted));
	for(int i=0;i<3;++i)
	{
		do
		{
			n = (rand()%13)+1;
		}
		while(alloted[n-1] != false);
		alloted[n-1] = true;

		int s = rand()%4;
		string su;
		switch(s)
		{
			case 0:
				su = "Hearts";
				break;
			case 1:
				su = "Diamonds";
				break;
			case 2:
				su = "Clubs";
				break;
			case 3:
				su = "Spades";
				break;
		}
		c[i].set(n,su);
	}
}
void shuffle(Card c[])
{
	srand(time(0));
	int count = (rand()%20) + 1;

	while(count--)
	{
		int i1,i2;
		i1 = rand()%3;
		do
		{
			i2 = rand()%3;
		}
		while(i1==i2);
		swap(c[i1],c[i2]);
		cout<<"Swapped cards "<<i1+1<<" and "<<i2+1<<endl;
	}
}

int msleep(unsigned long milisec) //This function has 
				  //taken from stackoverflow
{   
    struct timespec req={0};   
    time_t sec=(int)(milisec/1000);   
    milisec=milisec-(sec*1000);   
    req.tv_sec=sec;   
    req.tv_nsec=milisec*1000000L;   
    while(nanosleep(&req,&req)==-1)   
        continue;   
    return 1;   
}
int main()
{
	Card c[3];
	char choice;
	do
	{
		system("clear");
		getCards(c);
		cout<<"Your cards are:\n";
		for(int i=0;i<3;++i)
		{
			cout<<(i+1)<<". ";
			c[i].displayCard();
		}
		cout<<endl;
		msleep(2000);
		shuffle(c);
		msleep(5000);
		system("clear");
		int find = rand()%3;
		cout<<"Where is ";
		c[find].displayCard();
		cout<<". Choose position 1, 2 or 3. >>> ";

		int pos;
		cin>>pos;
		cout<<"Current positions are:\n";
		for(int i=0;i<3;++i)
		{
			cout<<(i+1)<<". ";
			c[i].displayCard();
		}
		cout<<endl<<endl;
		if(pos == find+1)
			cout<<"You win! Play another hand.\n";
		else
			cout<<"You loose! Try another hand.\n";
		cout<<"Continue?(y/n) >>> ";
		cin>>choice;
	}
	while(choice == 'y');
	cout<<"Its sad to let you go, come back soon!"<<endl;
	return 0;
}
