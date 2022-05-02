#include<iostream>

using namespace std;

class TIME
{
	int hours;
	int min;
	int sec;
public:
	TIME() {						//Default Constructor
		hours = min = sec = 0;
	}
	void check() {					//conversion of time in the desired format
		while (sec >= 60) {
			min++;
			sec = sec - 60;
		}
		while (min >= 60) {
			hours++;
			min = min - 60;
		}
		while (hours > 12) {
			hours = hours - 12;
		}
		if(hours==0){
			hours=12;
		}
	}
	
	//these are parameterized constructor
	
	/*TIME(int h) {
		hours = h;
		while (hours > 12) {
			hours = hours - 12;
		}
	}
	TIME(int h, int m) {
		hours = h;
		min = m;
		check();
	}
	TIME(int h, int m, int s) {
		hours = h;
		min = m;
		sec = s;
		if (hours < 0) {
			hours = hours * -1;
		}
		if (min < 0) {
			min = min * -1;
		}
		if (sec < 0) {
			sec = sec * -1;
		}
		check();
	}*/
	
	void display() {			//Display funtion
		cout << "\n\n" << endl << endl << "\t\t" << hours << " : " << min << " : " << sec << " \n\n";
	}
	TIME& operator++() {		//Post Increment overload
		hours++;
		min++;
		sec++;
		check();
		return *this;
	}
	TIME& operator--() {		//Post Decrement Overload
		hours--;
		min--;
		sec--;
		if (sec < 0) {
			sec = sec + 60;
			min--;
		}
		if (min < 0) {
			min = min + 60;
			hours--;
		}
		if (hours < 0) {
			hours = hours + 12;
		}
		check();
		return *this;
	}
	TIME operator++(int) {		//Pre Increment Overload
		hours++;
		min++;
		sec++;
		check();
		return *this;
	}
	TIME& operator--(int) {		//Pre Decrement Overload
		hours--;
		min--;
		sec--;
		if (sec < 0) {
			sec = sec + 60;
			min--;
		}
		if (min < 0) {
			min = min + 60;
			hours--;
		}
		if (hours < 0) {
			hours = hours + 12;
		}
		check();
		return *this;
	}
	/*
	so in such overloads it is to make the return type same as for the class type i.e in this case the return type is TIME .
	*/
	
	//Below is the Subtraction overload
	TIME operator-(TIME& obj) {			
		TIME temp;
		temp.hours = hours - obj.hours;
		temp.min = min - obj.min;
		temp.sec = sec - obj.sec;
		if (temp.hours < 0) {
			temp.hours = temp.hours * -1;
		}
		if (temp.min < 0) {
			temp.min = temp.min * -1;
		}
		if (temp.sec < 0) {
			temp.sec = temp.sec * -1;
		}
		temp.check();
		return temp;
	}
	//Multiplication Overload
	TIME operator*(float num) {
		TIME temp;
		temp.hours = int(num * hours);
		temp.min = int(num * min);
		temp.sec = int(num * sec);
		temp.check();
		return temp;
	}
	//Assignment overload
	TIME& operator=(TIME obj) {
		hours = obj.hours;
		min = obj.min;
		sec = obj.sec;
		check();
		return *this;
	}
};
int main()
{
	int h, m, s;
	cout << "Enter Hours : ";
	cin >> h;
	cout << "\n\nEnter Minutes : ";
	cin >> m;
	cout << "\n\nEnter Seconds : ";
	cin >> s;
	TIME obj(h, m, s);
	obj.display();
	cout << "\n\n\tPOST INCREMENT|DECREMENT";
	obj++;
	obj.display();
	obj--;
	obj.display();
	cout << " \n\n\tPRE INCREMENT|DECREMENT";
	++obj;
	obj.display();
	--obj;
	obj.display();
	float vi = 0;
	cout << "\n\nEnter number by which you want to increase the time : ";
	cin >> vi;
	TIME obj1 = obj * vi;
	cout << "\n\nAFTER USING * OVERLOAD";
	obj1.display();
	TIME obj2 = obj1 - obj;
	cout << "\n\nAFTER USING - OVERLOAD";
	obj2.display();
	system("pause");
	return 0;
}



//feel free to play with the code <3. you can contact me if there is any problem

//     lame.hero.no.1@gmail.com
