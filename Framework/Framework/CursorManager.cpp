#include "CursorManager.h"

CursorManager* CursorManager::Instance = nullptr;

CursorManager::CursorManager() : BufferIndex(0)
{

}

CursorManager::~CursorManager()
{
	DestroyBuffer();
}

void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	// ** Ŀ�� ����
	CONSOLE_CURSOR_INFO Cursor;

	Cursor.bVisible = FALSE;	// ** Ŀ�� �Ⱥ��̰� ��.
	Cursor.dwSize = 1;			// ** Ŀ���� ������ ����

	COORD Size = { (SHORT)_Width ,(SHORT)_Height };
	SMALL_RECT rect = { (SHORT)0, (SHORT)0, (SHORT)_Width, (SHORT)_Height };

	for (int i = 0; i < 2; ++i)
	{
		// ** ���� ����
		hBuffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

		// ** ���� ������ ����
		SetConsoleScreenBufferSize(hBuffer[i], Size);

		// ** ���۰� ���Ե� ������ ������ ����
		SetConsoleWindowInfo(hBuffer[i], TRUE, &rect);

		// ** Ŀ�� ����
		SetConsoleCursorInfo(hBuffer[i], &Cursor);
	}
}

void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	DWORD dw;

	COORD CurSorPosition = { (SHORT)_x ,(SHORT)_y };

	// ��ǥ �̵�
	SetConsoleCursorPosition(hBuffer[BufferIndex], CurSorPosition);

	// ** �ؽ�Ʈ �� ����
	SetColor(_Color);

	// ���ۿ� ����
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(float _x, float _y, int _Value, int _Color)
{
	DWORD dw;

	COORD CurSorPosition = { (SHORT)_x ,(SHORT)_y };

	// ��ǥ �̵�
	SetConsoleCursorPosition(hBuffer[BufferIndex], CurSorPosition);

	// ** �ؽ�Ʈ �� ����
	SetColor(_Color);

	char Buffer[4];
	_itoa(_Value, Buffer, 10);

	char* pBuffer = new char[strlen(Buffer)];
	strcpy(pBuffer, Buffer);

	// ���ۿ� ����
	WriteFile(hBuffer[BufferIndex], pBuffer, (DWORD)strlen(pBuffer), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	DWORD dw;

	COORD CurSorPosition = { (SHORT)_Position.x ,(SHORT)_Position.y };

	// ��ǥ �̵�
	SetConsoleCursorPosition(hBuffer[BufferIndex], CurSorPosition);

	// ** �ؽ�Ʈ �� ����
	SetColor(_Color);

	// ���ۿ� ����
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, int _Value, int _Color)
{
	DWORD dw;

	COORD CurSorPosition = { (SHORT)_Position.x ,(SHORT)_Position.y };

	// ��ǥ �̵�
	SetConsoleCursorPosition(hBuffer[BufferIndex], CurSorPosition);

	// ** �ؽ�Ʈ �� ����
	SetColor(_Color);


	char Buffer[4];
	_itoa(_Value, Buffer, 10);

	char* pBuffer = new char[strlen(Buffer)];
	strcpy(pBuffer, Buffer);

	// ���ۿ� ����
	WriteFile(hBuffer[BufferIndex], pBuffer, (DWORD)strlen(pBuffer), &dw, NULL);
}

void CursorManager::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[BufferIndex]);
	BufferIndex = !BufferIndex;

	ClearBuffer();
}

void CursorManager::ClearBuffer()
{
	DWORD dw;
	COORD Coord = { 0 ,0 };

	FillConsoleOutputCharacter(hBuffer[BufferIndex], ' ', ConsoleWidthSize * ConsoleHeightSize, Coord, &dw);
}

void CursorManager::DestroyBuffer()
{
	for (int i = 0; i < 2; ++i)
		CloseHandle(hBuffer[i]);
}

void CursorManager::SetColor(int _Color)
{
	SetConsoleTextAttribute(hBuffer[BufferIndex], _Color);
}
