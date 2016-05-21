#include <windows.h>
#include "config.h"
#include "OwareGame.h"
//do poprawy ID wywo�ywanego dialog boxa
static int xtab[] = { 0, 1, 8, 10, 0, -5, -5, 0, 32, 31, -24, -30, -25, 5, -15, -14, 25, 29, -3, 19, 0, 31, -9, 5, -15, -13, -11, -18, 17, -31, 16, 7, 20, -30, -15, 4, -9, -6, 30, -2, 38, -7, 5, 15, 12, 25, 36, 17 };
static int ytab[] = { -16, 11, 13, 0, -9, -5, 5, 32, 31, -1, 2, -2, 9, -5, 20, 30, 23, 8, 17, 20, 0, 15, -12, -12, -15, -7, 3, 40, -14, -9, 8, 30, 37, -17, 9, 20, 15, 27, -24, -46, -29, -19, 5, -5, 20, 30, 2, 1 };
C_Game Gra(2);
config*  cfg = NULL;
char* PKTinChar;
char* chAI = new char[4];
HWND NazwaGracza1, NazwaGracza2, Pkt1, Pkt2;
bool Player1Round;
void EndOfGame();
void GameRestart();

BOOL CALLBACK ConfigDialogProcedure(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK EndDlgProc(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch (Message) {
		/*case WM_CREATE:{
		HANDLE hIcon = LoadImage(NULL, "oware.ico",IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
		HANDLE hIconSm = LoadImage(NULL, "oware.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
		SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM) hIcon);
		SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM) hIconSm);
		}*/
	case WM_LBUTTONDOWN:{
		if ((LOWORD(lParam) - 60) *(LOWORD(lParam) - 60) + (HIWORD(lParam) - 75) *(HIWORD(lParam) - 75) < 50 * 50){
			//Pole 12"
			if (Player1Round == false && cfg->bAI == false && Gra.OwarePlayground.mGameBoarder[12 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[12 - 1];
				fnMakeAMove(12, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(12, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				else{
					MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
					Player1Round = true;
					Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				}
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 170) *(LOWORD(lParam) - 170) + (HIWORD(lParam) - 75) *(HIWORD(lParam) - 75) < 50 * 50){
			//Pole 11
			if (Player1Round == false && cfg->bAI == false && Gra.OwarePlayground.mGameBoarder[11 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[11 - 1];
				fnMakeAMove(11, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(11, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				else{
					MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
					Player1Round = true;
					Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				}
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 280) *(LOWORD(lParam) - 280) + (HIWORD(lParam) - 75) *(HIWORD(lParam) - 75) < 50 * 50){
			//Pole 10
			if (Player1Round == false && cfg->bAI == false && Gra.OwarePlayground.mGameBoarder[10 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[10 - 1];
				fnMakeAMove(10, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(10, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				else{
					MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
					Player1Round = true;
					Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				}
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 390) *(LOWORD(lParam) - 390) + (HIWORD(lParam) - 75) *(HIWORD(lParam) - 75) < 50 * 50){
			//Pole 9
			if (Player1Round == false && cfg->bAI == false && Gra.OwarePlayground.mGameBoarder[9 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[9 - 1];
				fnMakeAMove(9, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(9, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				else{
					MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
					Player1Round = true;
					Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				}
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 500) *(LOWORD(lParam) - 500) + (HIWORD(lParam) - 75) *(HIWORD(lParam) - 75) < 50 * 50){
			//Pole 8
			if (Player1Round == false && cfg->bAI == false && Gra.OwarePlayground.mGameBoarder[8 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[8 - 1];
				fnMakeAMove(8, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(8, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				else{
					MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
					Player1Round = true;
					Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				}
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 610) *(LOWORD(lParam) - 610) + (HIWORD(lParam) - 75) *(HIWORD(lParam) - 75) < 50 * 50){
			//Pole 7
			if (Player1Round == false && cfg->bAI == false && Gra.OwarePlayground.mGameBoarder[7 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[7 - 1];
				fnMakeAMove(7, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(7, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				else{
					MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
					Player1Round = true;
					Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				}
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 60) *(LOWORD(lParam) - 60) + (HIWORD(lParam) - 185) *(HIWORD(lParam) - 185) < 50 * 50){
			//Pole 1
			if (Player1Round&&Gra.OwarePlayground.mGameBoarder[1 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[1 - 1];
				fnMakeAMove(1, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(1, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				Player1Round = false;
				Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				if (cfg->bAI){
					InvalidateRect(hwnd, NULL, TRUE);
					MessageBox(hwnd, "Ruch AI!", "Info", MB_ICONINFORMATION);
					int Wybrane = Gra.mPlayer_B.AImove(Gra.OwarePlayground, Gra.AIlevel);
					itoa(Wybrane, chAI, 10);
					MessageBox(hwnd, chAI, "AI", MB_ICONINFORMATION);
					int Seeds = Gra.OwarePlayground.mGameBoarder[Wybrane - 1];
					fnMakeAMove(Wybrane, &Gra.OwarePlayground);
					int X = fnTargetField(Wybrane, Seeds);
					Gra.Arbiter(X, &Gra.OwarePlayground);
					if (Gra.IsItOver()){
						EndOfGame();
						int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
						if (ret == IDOK){
							ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
							if (ret == IDOK){
								GameRestart();
								if (Player1Round){
									MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
								}
								else{
									MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
								}
								if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
							}
							else if (ret == IDCANCEL)
								exit(-1);
						}
						else if (ret == IDCANCEL) exit(-1);
					}
					else{
						MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
						Player1Round = true;
						Gra.mPlayer_A.mfIsHisTurn = Player1Round;
					}
				}
				else MessageBox(hwnd, "Ruch gracza drugiego!", "Info", MB_ICONINFORMATION);
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 170) *(LOWORD(lParam) - 170) + (HIWORD(lParam) - 185) *(HIWORD(lParam) - 185) < 50 * 50){
			//Pole 2
			if (Player1Round&&Gra.OwarePlayground.mGameBoarder[2 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[2 - 1];
				fnMakeAMove(2, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(2, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				Player1Round = false;
				Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				if (cfg->bAI){
					InvalidateRect(hwnd, NULL, TRUE);
					MessageBox(hwnd, "Ruch AI!", "Info", MB_ICONINFORMATION);
					int Wybrane = Gra.mPlayer_B.AImove(Gra.OwarePlayground, Gra.AIlevel);
					itoa(Wybrane, chAI, 10);
					MessageBox(hwnd, chAI, "AI", MB_ICONINFORMATION);
					int Seeds = Gra.OwarePlayground.mGameBoarder[Wybrane - 1];
					fnMakeAMove(Wybrane, &Gra.OwarePlayground);
					int X = fnTargetField(Wybrane, Seeds);
					Gra.Arbiter(X, &Gra.OwarePlayground);
					if (Gra.IsItOver()){
						int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
						if (ret == IDOK){
							ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
							if (ret == IDOK){
								GameRestart();
								if (Player1Round){
									MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
								}
								else{
									MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
								}
								if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
							}
							else if (ret == IDCANCEL)
								exit(-1);
						}
						else if (ret == IDCANCEL) exit(-1);
					}
					else{
						MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
						Player1Round = true;
						Gra.mPlayer_A.mfIsHisTurn = Player1Round;
					}
				}
				else MessageBox(hwnd, "Ruch gracza drugiego!", "Info", MB_ICONINFORMATION);
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 280) *(LOWORD(lParam) - 280) + (HIWORD(lParam) - 185) *(HIWORD(lParam) - 185) < 50 * 50){
			//Pole 3
			if (Player1Round&&Gra.OwarePlayground.mGameBoarder[3 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[3 - 1];
				fnMakeAMove(3, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(3, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				Player1Round = false;
				Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				if (cfg->bAI){
					InvalidateRect(hwnd, NULL, TRUE);
					MessageBox(hwnd, "Ruch AI!", "Info", MB_ICONINFORMATION);
					int Wybrane = Gra.mPlayer_B.AImove(Gra.OwarePlayground, Gra.AIlevel);
					itoa(Wybrane, chAI, 10);
					MessageBox(hwnd, chAI, "AI", MB_ICONINFORMATION);
					int Seeds = Gra.OwarePlayground.mGameBoarder[Wybrane - 1];
					fnMakeAMove(Wybrane, &Gra.OwarePlayground);
					int X = fnTargetField(Wybrane, Seeds);
					Gra.Arbiter(X, &Gra.OwarePlayground);
					if (Gra.IsItOver()){
						int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
						if (ret == IDOK){
							ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
							if (ret == IDOK){
								GameRestart();
								if (Player1Round){
									MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
								}
								else{
									MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
								}
								if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
							}
							else if (ret == IDCANCEL)
								exit(-1);
						}
						else if (ret == IDCANCEL) exit(-1);
					}
					else{
						MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
						Player1Round = true;
						Gra.mPlayer_A.mfIsHisTurn = Player1Round;
					}
				}
				else MessageBox(hwnd, "Ruch gracza drugiego!", "Info", MB_ICONINFORMATION);
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 390) *(LOWORD(lParam) - 390) + (HIWORD(lParam) - 185) *(HIWORD(lParam) - 185) < 50 * 50){
			//Pole 4
			if (Player1Round&&Gra.OwarePlayground.mGameBoarder[4 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[4 - 1];
				fnMakeAMove(4, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(4, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				Player1Round = false;
				Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				if (cfg->bAI){
					InvalidateRect(hwnd, NULL, TRUE);
					MessageBox(hwnd, "Ruch AI!", "Info", MB_ICONINFORMATION);
					int Wybrane = Gra.mPlayer_B.AImove(Gra.OwarePlayground, Gra.AIlevel);
					itoa(Wybrane, chAI, 10);
					MessageBox(hwnd, chAI, "AI", MB_ICONINFORMATION);
					int Seeds = Gra.OwarePlayground.mGameBoarder[Wybrane - 1];
					fnMakeAMove(Wybrane, &Gra.OwarePlayground);
					int X = fnTargetField(Wybrane, Seeds);
					Gra.Arbiter(X, &Gra.OwarePlayground);
					if (Gra.IsItOver()){
						EndOfGame();
						int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
						if (ret == IDOK){
							ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
							if (ret == IDOK){
								GameRestart();
								if (Player1Round){
									MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
								}
								else{
									MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
								}
								if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
							}
							else if (ret == IDCANCEL)
								exit(-1);
						}
						else if (ret == IDCANCEL) exit(-1);
					}
					else{
						MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
						Player1Round = true;
						Gra.mPlayer_A.mfIsHisTurn = Player1Round;
					}
				}
				else MessageBox(hwnd, "Ruch gracza drugiego!", "Info", MB_ICONINFORMATION);
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 500) *(LOWORD(lParam) - 500) + (HIWORD(lParam) - 185) *(HIWORD(lParam) - 185) < 50 * 50){
			//Pole 5
			if (Player1Round&&Gra.OwarePlayground.mGameBoarder[5 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[5 - 1];
				fnMakeAMove(5, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(5, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				Player1Round = false;
				Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				if (cfg->bAI){
					InvalidateRect(hwnd, NULL, TRUE);
					MessageBox(hwnd, "Ruch AI!", "Info", MB_ICONINFORMATION);
					int Wybrane = Gra.mPlayer_B.AImove(Gra.OwarePlayground, Gra.AIlevel);
					itoa(Wybrane, chAI, 10);
					MessageBox(hwnd, chAI, "AI", MB_ICONINFORMATION);
					int Seeds = Gra.OwarePlayground.mGameBoarder[Wybrane - 1];
					fnMakeAMove(Wybrane, &Gra.OwarePlayground);
					int X = fnTargetField(Wybrane, Seeds);
					Gra.Arbiter(X, &Gra.OwarePlayground);
					if (Gra.IsItOver()){
						int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
						if (ret == IDOK){
							ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
							if (ret == IDOK){
								GameRestart();
								if (Player1Round){
									MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
								}
								else{
									MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
								}
								if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
							}
							else if (ret == IDCANCEL)
								exit(-1);
						}
						else if (ret == IDCANCEL) exit(-1);
					}
					else{
						MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
						Player1Round = true;
						Gra.mPlayer_A.mfIsHisTurn = Player1Round;
					}
				}
				else MessageBox(hwnd, "Ruch gracza drugiego!", "Info", MB_ICONINFORMATION);
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		else if ((LOWORD(lParam) - 610) *(LOWORD(lParam) - 610) + (HIWORD(lParam) - 185) *(HIWORD(lParam) - 185) < 50 * 50){
			//Pole 6
			if (Player1Round&&Gra.OwarePlayground.mGameBoarder[6 - 1] != 0){
				int Seeds = Gra.OwarePlayground.mGameBoarder[6 - 1];
				fnMakeAMove(6, &Gra.OwarePlayground);
				Gra.Arbiter(fnTargetField(6, Seeds), &Gra.OwarePlayground);
				if (Gra.IsItOver()){
					EndOfGame();
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
					if (ret == IDOK){
						ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
						if (ret == IDOK){
							GameRestart();
							if (Player1Round){
								MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
							}
							else{
								MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
							}
							if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
						}
						else if (ret == IDCANCEL)
							exit(-1);
					}
					else if (ret == IDCANCEL) exit(-1);
				}
				Player1Round = false;
				Gra.mPlayer_A.mfIsHisTurn = Player1Round;
				if (cfg->bAI){
					InvalidateRect(hwnd, NULL, TRUE);
					MessageBox(hwnd, "Ruch AI!", "Info", MB_ICONINFORMATION);
					int Wybrane = Gra.mPlayer_B.AImove(Gra.OwarePlayground, Gra.AIlevel);
					itoa(Wybrane, chAI, 10);
					MessageBox(hwnd, chAI, "AI", MB_ICONINFORMATION);
					int Seeds = Gra.OwarePlayground.mGameBoarder[Wybrane - 1];
					fnMakeAMove(Wybrane, &Gra.OwarePlayground);
					int X = fnTargetField(Wybrane, Seeds);
					Gra.Arbiter(X, &Gra.OwarePlayground);
					if (Gra.IsItOver()){
						int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(300), hwnd, EndDlgProc);
						if (ret == IDOK){
							ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
							if (ret == IDOK){
								GameRestart();
								if (Player1Round){
									MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
								}
								else{
									MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
								}
								if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
							}
							else if (ret == IDCANCEL)
								exit(-1);
						}
						else if (ret == IDCANCEL) exit(-1);
					}
					else{
						MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
						Player1Round = true;
						Gra.mPlayer_A.mfIsHisTurn = Player1Round;
					}
				}
				else MessageBox(hwnd, "Ruch gracza drugiego!", "Info", MB_ICONINFORMATION);
			}
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		break;
	}
	case WM_COMMAND:{
		if (LOWORD(wParam) == 100){
			//Nowa Gra
			int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
			if (ret == IDOK){
				//MessageBox( hwnd, "Wybra�e� \'OK\' w oknie dialogowym!", "Test", MB_ICONINFORMATION );
				if (Player1Round){
					MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
				}
				else{
					MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
				}
				if (cfg->bAI) SetWindowText(NazwaGracza2, "Komputer");
			}
			else if (ret == IDCANCEL)
				MessageBox(hwnd, "Wybra�e� \'Anuluj\' w oknie dialogowym!", "Test", MB_ICONINFORMATION);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		if (LOWORD(wParam) == 101){
			//Zako�czenie gry
			PostQuitMessage(0);
		}
		if (LOWORD(wParam) == 102){
			//Pomoc
			MessageBox(hwnd, "Brak Pomocy!", "Pomoc", MB_ICONINFORMATION);
			break;
		}
		else break;
	}
	case WM_PAINT:{
		PAINTSTRUCT ps;
		HDC hdcOkno;

		hdcOkno = BeginPaint(hwnd, &ps);
		HBRUSH PedzelZiel, Pudelko;
		HPEN OlowekCzerw, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B9B9);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0000);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, PedzelZiel);
		Piornik = (HPEN)SelectObject(hdcOkno, OlowekCzerw);

		Ellipse(hdcOkno, 10, 25, 110, 125);
		Ellipse(hdcOkno, 120, 25, 220, 125);
		Ellipse(hdcOkno, 230, 25, 330, 125);
		Ellipse(hdcOkno, 340, 25, 440, 125);
		Ellipse(hdcOkno, 450, 25, 550, 125);
		Ellipse(hdcOkno, 560, 25, 660, 125);

		Ellipse(hdcOkno, 10, 135, 110, 235);
		Ellipse(hdcOkno, 120, 135, 220, 235);
		Ellipse(hdcOkno, 230, 135, 330, 235);
		Ellipse(hdcOkno, 340, 135, 440, 235);
		Ellipse(hdcOkno, 450, 135, 550, 235);
		Ellipse(hdcOkno, 560, 135, 660, 235);

		SelectObject(hdcOkno, Pudelko);
		SelectObject(hdcOkno, Piornik);
		DeleteObject(OlowekCzerw);
		DeleteObject(PedzelZiel);
		if (Gra.OwarePlayground.mGameBoarder[0] != 0){ //60;170
			int x = 60, y = 185;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[0]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[1] != 0){ //170;170
			int x = 170, y = 185;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[1]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[2] != 0){ //280;170
			int x = 280, y = 185;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[2]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[3] != 0){
			int x = 390, y = 185;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[3]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[4] != 0){
			int x = 500, y = 185;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[4]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[5] != 0){
			int x = 610, y = 185;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[5]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[6] != 0){
			int x = 610, y = 75;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[6]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[7] != 0){
			int x = 500, y = 75;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[7]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[8] != 0){
			int x = 390, y = 75;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[8]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[9] != 0){
			int x = 280, y = 75;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[9]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[10] != 0){
			int x = 170, y = 75;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[10]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		if (Gra.OwarePlayground.mGameBoarder[11] != 0){
			int x = 60, y = 75;
			HBRUSH Pedzel, Pudelko;
			HPEN Olowek, Piornik;
			PedzelZiel = CreateSolidBrush(0xC5B900);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
			Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
			Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
			for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[11]; i++){
				Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
			}
		}
		SetWindowText(NazwaGracza1, (const char *)cfg->lpszGracz1);
		itoa(Gra.mPlayer_A.mCollectedSeeds, PKTinChar, 10);
		SetWindowText(Pkt1, PKTinChar);
		if (cfg->bAI != true)SetWindowText(NazwaGracza2, (const char *)cfg->lpszGracz2);
		itoa(Gra.mPlayer_B.mCollectedSeeds, PKTinChar, 10);
		SetWindowText(Pkt2, PKTinChar);
		ReleaseDC(hwnd, hdcOkno);
		EndPaint(hwnd, &ps);
		//ShowWindow(hwnd,SW_HIDE);
		return 0;
	}

	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}

	default:
		return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

//Funkcja MAIN
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	memset(&wc, 0, sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszClassName = "WindowClass";
	wc.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(1284));
	wc.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(1284));

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(200));

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "Oware", WS_VISIBLE | WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX | WS_SIZEBOX),
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		680, /* width */
		320, /* height */
		NULL, hMenu, hInstance, NULL);
	ShowWindow(hwnd, SW_HIDE);
	int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(666), hwnd, ConfigDialogProcedure);
	if (ret == IDOK)
		ShowWindow(hwnd, SW_SHOW);
	else if (ret == IDCANCEL)
		exit(-1);
	//PostMessage(hwnd, WM_CLOSE, 0, 0);
	//PostQuitMessage(0);

	HDC hdcOkno = GetDC(hwnd);
	HBRUSH PedzelZiel, Pudelko;
	HPEN OlowekCzerw, Piornik;
	PedzelZiel = CreateSolidBrush(0xC5B9B9);
	OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0000);
	Pudelko = (HBRUSH)SelectObject(hdcOkno, PedzelZiel);
	Piornik = (HPEN)SelectObject(hdcOkno, OlowekCzerw);

	Ellipse(hdcOkno, 10, 25, 110, 125);
	Ellipse(hdcOkno, 120, 25, 220, 125);
	Ellipse(hdcOkno, 230, 25, 330, 125);
	Ellipse(hdcOkno, 340, 25, 440, 125);
	Ellipse(hdcOkno, 450, 25, 550, 125);
	Ellipse(hdcOkno, 560, 25, 660, 125);

	Ellipse(hdcOkno, 10, 135, 110, 235);
	Ellipse(hdcOkno, 120, 135, 220, 235);
	Ellipse(hdcOkno, 230, 135, 330, 235);
	Ellipse(hdcOkno, 340, 135, 440, 235);
	Ellipse(hdcOkno, 450, 135, 550, 235);
	Ellipse(hdcOkno, 560, 135, 660, 235);

	SelectObject(hdcOkno, Pudelko);
	SelectObject(hdcOkno, Piornik);
	DeleteObject(OlowekCzerw);
	DeleteObject(PedzelZiel);
	if (Gra.OwarePlayground.mGameBoarder[0] != 0){ //60;170
		int x = 60, y = 185;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[0]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[1] != 0){ //170;170
		int x = 170, y = 185;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[1]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[2] != 0){ //280;170
		int x = 280, y = 185;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[2]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[3] != 0){
		int x = 390, y = 185;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[3]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[4] != 0){
		int x = 500, y = 185;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[4]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[5] != 0){
		int x = 610, y = 185;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[5]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[6] != 0){
		int x = 610, y = 75;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[6]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[7] != 0){
		int x = 500, y = 75;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[7]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[8] != 0){
		int x = 390, y = 75;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[8]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[9] != 0){
		int x = 280, y = 75;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[9]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[10] != 0){
		int x = 170, y = 75;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[10]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	if (Gra.OwarePlayground.mGameBoarder[11] != 0){
		int x = 60, y = 75;
		HBRUSH Pedzel, Pudelko;
		HPEN Olowek, Piornik;
		PedzelZiel = CreateSolidBrush(0xC5B900);
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xCC0111);
		Pudelko = (HBRUSH)SelectObject(hdcOkno, Pedzel);
		Piornik = (HPEN)SelectObject(hdcOkno, Olowek);
		for (int i = 0; i<Gra.OwarePlayground.mGameBoarder[11]; i++){
			Ellipse(hdcOkno, (xtab[i] + x) - 3, (ytab[i] + y) - 3, (xtab[i] + x) + 3, (ytab[i] + y) + 3);
		}
	}
	ReleaseDC(hwnd, hdcOkno);
	HWND hStaticA1 = CreateWindowEx(0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, 500, 250, 150, 200, hwnd, NULL, hInstance, NULL);

	HWND hStaticA2 = CreateWindowEx(0, "STATIC", "GRACZ_A", WS_CHILD | WS_VISIBLE |
		SS_LEFT, 545, 250, 150, 200, hwnd, NULL, hInstance, NULL);

	HWND hStaticA3 = CreateWindowEx(0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, 650, 250, 150, 200, hwnd, NULL, hInstance, NULL);

	PKTinChar = new char[4];
	itoa(0, PKTinChar, 10);

	SetWindowText(hStaticA1, "Gracz:");
	SetWindowText(hStaticA2, (const char *)cfg->lpszGracz1);
	SetWindowText(hStaticA3, PKTinChar);

	NazwaGracza1 = hStaticA2;
	Pkt1 = hStaticA3;

	HWND hStaticB1 = CreateWindowEx(0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, 10, 8, 150, 15, hwnd, NULL, hInstance, NULL);
	HWND hStaticB2 = CreateWindowEx(0, "STATIC", "GRACZ_B", WS_CHILD | WS_VISIBLE |
		SS_LEFT, 55, 8, 150, 15, hwnd, NULL, hInstance, NULL);
	HWND hStaticB3 = CreateWindowEx(0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, 160, 8, 150, 15, hwnd, NULL, hInstance, NULL);

	if (cfg->bAI){
		SetWindowText(hStaticB1, "Gracz:");
		SetWindowText(hStaticB2, "Komputer");
		SetWindowText(hStaticB3, PKTinChar);
	}
	else{
		SetWindowText(hStaticB1, "Gracz:");
		SetWindowText(hStaticB2, (const char *)cfg->lpszGracz2);
		SetWindowText(hStaticB3, PKTinChar);
	}
	NazwaGracza2 = hStaticB2;
	Pkt2 = hStaticB3;


	if (hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	if (Player1Round){
		MessageBox(NULL, "Gr� zaczyna Gracz pierwszy", "Start!", MB_ICONEXCLAMATION);
	}
	else{
		MessageBox(NULL, "Gr� zaczyna Gracz drugi", "Start!", MB_ICONEXCLAMATION);
		if (cfg->bAI){
			MessageBox(hwnd, "Ruch AI!", "Info", MB_ICONINFORMATION);
			int Wybrane = Gra.mPlayer_B.AImove(Gra.OwarePlayground, Gra.AIlevel);
			fnMakeAMove(Wybrane, &Gra.OwarePlayground);
			InvalidateRect(hwnd, NULL, TRUE);
			int X = fnTargetField(Wybrane, Gra.OwarePlayground.mGameBoarder[Wybrane - 1]);
			Gra.Arbiter(X, &Gra.OwarePlayground);
			if (Gra.IsItOver()) MessageBox(NULL, "Koniec", "Klik!", MB_ICONEXCLAMATION | MB_OK);
			else{
				MessageBox(hwnd, "Ruch gracza pierwszego!", "Info", MB_ICONINFORMATION);
				Player1Round = true;
			}
		}
	}

	while (GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

BOOL CALLBACK ConfigDialogProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg){
	case WM_COMMAND:{
		switch (LOWORD(wParam)) {
		case IDOK: {
			config *pCfg = new config;

			HWND hGracz1 = GetDlgItem(hwnd, IDC_GRACZ1);
			HWND hGracz2 = GetDlgItem(hwnd, IDC_GRACZ2);
			HWND hAI = GetDlgItem(hwnd, IDC_AI);
			HWND hPoziom = GetDlgItem(hwnd, IDC_COMBOBOX);

			DWORD dlugosc = GetWindowTextLength(hGracz1);
			pCfg->lpszGracz1 = new char[dlugosc + 1];
			GetWindowText(hGracz1, pCfg->lpszGracz1, dlugosc + 1);

			dlugosc = GetWindowTextLength(hGracz2);
			pCfg->lpszGracz2 = new char[dlugosc + 1];
			GetWindowText(hGracz2, pCfg->lpszGracz2, dlugosc + 1);
			pCfg->bAI = (IsDlgButtonChecked(hwnd, IDC_AI) == BST_CHECKED);
			pCfg->nPoziom = SendMessage(hPoziom, CB_GETCURSEL, 0, 0);
			if (pCfg->nPoziom == 0) Gra.AIlevel = 6;
			else if (pCfg->nPoziom == 1) Gra.AIlevel = 8;
			else if (pCfg->nPoziom == 2) Gra.AIlevel = 10;
			else if (pCfg->nPoziom == 3) Gra.AIlevel = 12;
			cfg = pCfg;
			Player1Round = fnGameWillStartPlayer1();

			EndDialog(hwnd, IDOK);
		}
				   break;
		case IDCANCEL:
			EndDialog(hwnd, IDCANCEL);
			break;
		}
	}
					break;
	case WM_INITDIALOG: {
		HWND hCombo = GetDlgItem(hwnd, IDC_COMBOBOX);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM) "1");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM) "2");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM) "3");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM) "4");
		//ComboBox_SetCurSel( hCombo, 1 );
		SetFocus(GetDlgItem(hwnd, IDC_GRACZ1));
	}
						break;
	case WM_PAINT:{
		PAINTSTRUCT ps;
		HDC hdcOkno;
		hdcOkno = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		return 0;
	}

				  return TRUE;
	}
}
BOOL CALLBACK EndDlgProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_COMMAND:
	{
		// reakcja na przyciski
		switch (LOWORD(wParam))
		{
		case IDOK: EndDialog(hwnd, IDOK); break;
		case IDCANCEL: EndDialog(hwnd, IDCANCEL); break;
		}
	}
	break;

	default: return FALSE;
	}

	return TRUE;
}

void EndOfGame(){
	if (Gra.mPlayer_A.mCollectedSeeds>Gra.mPlayer_B.mCollectedSeeds) MessageBox(NULL, "Zwyciezy� gracz pierwszy", "Koniec!", MB_ICONEXCLAMATION | MB_OK);
	if (Gra.mPlayer_A.mCollectedSeeds<Gra.mPlayer_B.mCollectedSeeds) MessageBox(NULL, "Zwyciezy� gracz drugi", "Koniec!", MB_ICONEXCLAMATION | MB_OK);
	if (Gra.mPlayer_A.mCollectedSeeds == Gra.mPlayer_B.mCollectedSeeds) MessageBox(NULL, "Remis!!!", "Koniec!", MB_ICONEXCLAMATION | MB_OK);
	GameRestart();
}
void GameRestart(){
	Gra.mPlayer_A.mCollectedSeeds = 0;
	Gra.mPlayer_B.mCollectedSeeds = 0;
	for (int i = 0; i <= 12; i++)
	{
		Gra.OwarePlayground.mGameBoarder[i] = 4;
	}
};