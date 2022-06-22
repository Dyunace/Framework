#define _CRT_SECURE_NO_WARNINGS
#include "Parent.h"
#include "Child.h"
#include "Bullet.h"

// ** 7. 생성자 & 소멸자 & 복사 생성자.
// ** 8. 깊은복사 얕은복사.
// ** (복사 생성자)
/*
struct tagInfo
{
	int Number;
};

class Object
{
protected:
	tagInfo m_Info;
public:
	int Number;
	char* Name;
public:
	virtual Object* Clone() = 0;




public:
	// ** 사용자가 호출하지 않아도 스스로 호출됨.
	// ** 클래스가 생성된 직후 호출.
	Object()
	{
		cout << "생성자" << endl;
	};

	// ** 사용자가 호출하는 시점에 호출 됨.
	// ** 전달값의 개수와 자료형에 따라서 선택적(자동)으로 호출 됨.
	Object(int _Number) : Number(_Number)
	{
		cout << "복사 생성자 : int" << endl;

		//Number = _Number;
	};

	Object(float _Number)
	{
		cout << "복사 생성자 : float" << endl;

		Number = (int)_Number;
	};

	Object(char* _Name)
	{
		Name = new char[strlen(_Name) + 1];
		strcpy(Name, _Name);
	};

	Object(Object* _Obj)
	{
		Name = new char[strlen(_Obj->Name) + 1];
		strcpy(Name, _Obj->Name);
	};

	Object(tagInfo _Info) : m_Info(_Info) { }



	// ** 클래스가 삭제되기 직전
	~Object()
	{
		cout << "소멸자" << endl;

		//delete[] Name;
		//Name = nullptr;
	};
};

class Player : public Object
{
public:
	virtual Object* Clone() override { return new Player(*this); }

	void Output() { cout << m_Info.Number << endl; }

public:
	Player() { };
	//Player(tagInfo _Info) : Object(_Info) { };
	Player(tagInfo _Info) : Object(_Info) { };
	~Player() { };
};
*/



// ** 9. 오버로딩 & 오버라이딩.
/*
class Object
{
public:
	virtual void Output()
	{
		cout << "Object : " << endl;
	}

	virtual void Output(string _str)
	{
		cout << "Object : " << _str << endl;
	}
};

class AAA : public Object
{
public:
	void Output() override
	{
		cout << "AAA : " << endl;
	}

	void Output(string _str) override
	{
		cout << "AAA : " << _str << endl;
	}
};
*/




// ** 10. 연산자 오버로딩.

struct tagInfo
{
	int Number;

	tagInfo() {};
	tagInfo(int _Number) : Number(_Number) {};
};

class Object
{
private:
	tagInfo Info;
public:
	Object& operator+=(const Object& _Obj)
	{
		Info.Number += _Obj.Info.Number;
		return *this;
	}

	Object& operator++()
	{
		Info.Number += 1;
		return *this;
	}

	void Output()
	{
		cout << Info.Number << endl;
	}
public:
	Object() { }
	Object(tagInfo _Info) : Info(_Info) { }
	~Object() { }
};






// ** 11. 포인터 (복습) & 캡슐화.











//map<string, Object*> PortotypeObject;

//Object* GetObject(string _Key);

int main(void)
{
	/*
	Object o = Object(3.141592f);
	cout << "Hello World!!" << endl;

	Object o1((char*)"홍길동");
	//Object o2 = o1;
	Object o2(o1);
	*/


	/*
	int i = 10;
	int n(10);
	*/



	/*
	tagInfo Info;
	AAA a[8];

	for (int i = 0; i < 8; ++i)
	{
		Info.Number = i + 1;
		a[i] = AAA(Info);
	}

	for (int i = 0; i < 8; ++i)
		a[i].Output();
	*/



	/*
	 * 예제
	tagInfo Info;

	Info.Number = 10;
	PortotypeObject["Player"] = new Player(Info);

	Object* pProtoObj = GetObject("Player");

	Object* pPlayer = nullptr;

	if (pProtoObj != nullptr)
		pPlayer = pProtoObj->Clone();
	*/





	/*
	Object o1(tagInfo(10));

	Object o2(o1);

	o2 += o1;

	++o2;

	o2.Output();
	*/

	return 0;
}




/*
Object* GetObject(string _Key)
{
	map<string, Object*>::iterator iter = PortotypeObject.find(_Key);

	if (iter == PortotypeObject.end())
		return nullptr;
	else
		return iter->second;
}
*/

