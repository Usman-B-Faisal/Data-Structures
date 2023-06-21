#include<iostream>
#include<sstream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

using namespace std;
using namespace sf;

class SFML
{
	VideoMode videomode;

	Texture texture;

	Font font;
	Text text;

	int pl;
	int exe;
public:
	Texture texture1;
	RenderWindow* window;
	Event event;
	Sprite* sprite;

	SFML()
	{
		pl = 0;
		videomode.height = 600;
		videomode.width = 720;
		window = new RenderWindow(videomode, "SFML");
		window->setFramerateLimit(60);
		exe = 0;
		texture.loadFromFile("image/luffy3.png");
		texture1.loadFromFile("image/luffy4.png");
		sprite = new Sprite[6];
		for (int i = 0; i < 6; i++)
		{
			sprite[i].setTexture(texture);
			sprite[i].setScale(0.4f, 0.4f);
		}

		font.loadFromFile("fonts/font.ttf");

		text.setFont(font);
		text.setCharacterSize(24);
		text.setFillColor(Color::Blue);
		text.setString("Who will survive?");
		text.setPosition(100, 500);
	}

	SFML(int ppl)
	{
		pl = ppl;
		videomode.height = 600;
		videomode.width = 720;
		window = new RenderWindow(videomode, "SFML");
		window->setFramerateLimit(60);
		exe = 0;
		texture.loadFromFile("image/luffy3.png");
		texture1.loadFromFile("image/luffy4.png");
		sprite = new Sprite[ppl];
		for (int i = 0; i < ppl; i++)
		{
			sprite[i].setTexture(texture);
			sprite[i].setScale(0.6f, 0.6f);
		}

		font.loadFromFile("fonts/font.ttf");

		text.setFont(font);
		text.setCharacterSize(24);
		text.setFillColor(Color::Blue);
		text.setString("Who will survive?");
		text.setPosition(100, 500);
	}

	void update()
	{
		int x = 0, y = 50;
		for (int i = 1; i < pl; i++)
		{
			sprite[i].setPosition(x, y);
			x = x + 150;
			if (x > 500)
			{
				y += y + 100;
				x = 0;
			}
		}
		sprite[0].setPosition(0, 50);
	}
	void render()
	{
		window->clear();
		//drawing
		for (int i = 0; i < pl; i++)
			window->draw(sprite[i]);
		stringstream ss;
		ss << "To see who survived look at console after closing this window";
		text.setString(ss.str());
		window->draw(text);
		window->display();
	}

	void render(int a)
	{
		window->clear();
		//drawing
		for (int i = 0; i < pl; i++)
			window->draw(sprite[i]);
		stringstream ss;
		ss << "Last Man Standing is Person no ";
		ss << a;
		text.setString(ss.str());
		window->draw(text);
		window->display();
	}
};

template<class t>
class node
{
public:
	t data;
	node<t>* next;
	node()//o(1)
	{
		data = NULL;
		next = NULL;
	}
	node(t d)//o(1)
	{
		data = d;
		next = NULL;
	}
};
template<class t>
class Queue
{
public:
	node<t>* head = NULL;
	node<t>* tail = NULL;
	Queue() {};//o(1)
	int size = 0;
	void enqueue(t Data)//o(1) inserts node at tail
	{
		node<t>* newN = new node<t>(Data);
		if (head == NULL)
		{
			head = newN;
			tail = newN;
			size++;
		}
		else
		{
			node<t>* curr = head;
			newN->next = tail->next;
			tail->next = newN;
			tail = newN;
			size++;
		}
	}
	void dequeue()//o(1) removes node from front
	{
		node<t>* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	int Size()//o(1) keeps track of size
	{
		return size;
	}
	t front()//o(1) returns data at head
	{
		return head->data;
	}
	void lastmanstanding(int k, SFML& s)//o(n) josephus algorithm
	{
		int temp = 0, i = 1;
		while (s.window->isOpen())
		{
			while (s.window->pollEvent(s.event))
			{
				if (s.event.type == Event::Closed)
					s.window->close();
			}

			if (size != 1)
			{
				if (i == k)
				{
					s.sprite[front() - 1].setTexture(s.texture1);
					dequeue();
					i = 0;
				}

				else
				{
					temp = front();
					dequeue();
					enqueue(temp);
				}

				i++;
			}

			s.update();
			if (size == 1)
				s.render(front());
			else
				s.render();
		}

	}
	~Queue()//o??
	{
		node<t>* temp1 = head;
		node<t>* temp2 = head;
		while (temp1 != NULL)
		{
			temp2 = temp1->next;
			delete temp1;
			temp1 = temp2;
		}
	}
	void print()//o(1)
	{
		if (head == NULL)
			cout << "Empty Queue\n";
		else
		{
			cout << "Last Man Standing is Person no " << head->data << "\n";
		}
	}
};

int main()
{
	Queue <int> q;
	int N = 0;
	cout << "Enter no of people to be executed(N). It must be greater than 1: ";
	cin >> N;
	if (N > 1)//o??
	{
		for (int i = 0; i < N; i++)
		{
			q.enqueue(i + 1);
		}
		int K = 0;
		cout << "Enter no of people to be skipped before execution(K): ";
		cin >> K;
		SFML s(N);
		q.lastmanstanding(K + 1, s);
		q.print();
	}
	else//o(1)
		cout << "N must be greater than 1\n";
	return 0;
}