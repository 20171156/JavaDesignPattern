#include <iostream>
using namespace std;

class DiscountedMode
{
public:

	virtual double getDiscountRate() = 0;
};

class NonDiscounted : public DiscountedMode
{
public:
	double getDiscountRate()
	{
		// TODO Auto-generated method stub
		return 0.0;
	}

};

class OnSale : public DiscountedMode 
{
public :
	double getDiscountRate() 
	{
		// TODO Auto-generated method stub
		return 0.1;
	}

};

class TodayEvent : public DiscountedMode
{
public:
	double getDiscountRate()
	{
		// TODO Auto-generated method stub
		return 0.3;
	}

};

class Song {
private :
	DiscountedMode *mode;
public :
	void setMode(DiscountedMode *mode2) 
	{
		mode = mode2;
	}
public :
	double getPrice() 
	{
		return 10.0 - (10.0*mode->getDiscountRate());
	}
};

typedef struct ListNode
{
	Song * song;
	struct ListNode* link;
}listNode;

class CartForSongs
{
	//ArrayList<Song> cart = new ArrayList<Song>();
private:
	static listNode *head;

public :
	double calculateTotalPrice()
	{

		double total = 0.0;
		listNode *p = head;
		//Iterator<Song> itr = cart.iterator();
		//while (itr.hasNext()) {
		//	Song s = itr.next();
		//	total = total + s.getPrice();

		//}
		while (p != NULL)
		{
			total += (p ->song)->getPrice();
			p = p->link;
		}
		return total;
	}

	void add(Song *s)
	{
		listNode * L = new listNode;//(listNode *)malloc(sizeof(listNode));
		L->song = s;
		L->link = head;
		head = L;
	}

};

listNode * CartForSongs::head = NULL; //static °ª ÁöÁ¤

int main()
{
	Song s1, s2, s3, s4, s5;
	NonDiscounted nd;
	OnSale os;
	TodayEvent te;
	
	s1.setMode(&nd);
	s2.setMode(&os);
	s3.setMode(&os);
	s4.setMode(&te);
	s5.setMode(&nd);

	CartForSongs c;
	c.add(&s1);
	c.add(&s2);
	c.add(&s3);
	c.add(&s4);
	c.add(&s5);

	cout << c.calculateTotalPrice() << endl;

	return 0;
}
