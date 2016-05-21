#include "OwareGame.h"

bool fnGameWillStartPlayer1(){
	srand(time(NULL));
	int nLiczba = rand();
	if (nLiczba % 2 != 0) return true;
	else return false;
};

int fnTargetField(int nSelectedField, int nSeeds)
{
	if (nSeeds<14)
	{
		if (((nSelectedField + nSeeds % 12) % 12) != 0) return(nSelectedField + nSeeds % 12) % 12;
		else return 12;
	}
	if (nSeeds>11)
	{
		if (((nSelectedField + (nSeeds + 1) % 12) % 12) != 0) return(nSelectedField + (nSeeds + 1) % 12) % 12;
		else return 12;
	}
	if (nSeeds == 12)
	{
		if (nSelectedField == 12)
		{
			return 1;
		}
		else
		{
			return nSelectedField + 1;
		}
	}
}
int MinMax(C_Board StanGry, char Gracz, int nField, int nDepth, int MaxDepth){
	if (Gracz == 'B'){
		int X = fnTargetField(nField, StanGry.mGameBoarder[nField - 1]);
		fnMakeAMove(nField, &StanGry);
		fnArbiter(X, Gracz, &StanGry);
		if (fnIsItOver(&StanGry) && nDepth == 0){
			if (StanGry.mnBoxB>StanGry.mnBoxA) return numeric_limits<int>::max();
			else if (StanGry.mnBoxB<StanGry.mnBoxA) return numeric_limits<int>::min();
			else if (StanGry.mnBoxB == StanGry.mnBoxA) return 0;
		}
		else if (fnIsItOver(&StanGry) || nDepth == MaxDepth){
			if (StanGry.mnBoxB>StanGry.mnBoxA) return 1;
			else if (StanGry.mnBoxB<StanGry.mnBoxA) return -1;
			else if (StanGry.mnBoxB == StanGry.mnBoxA) return 0;
		}
		else{
			nDepth++;
			int Wynik = 0;
			int i = 1;
			while (i <= 6)
			{
				if (StanGry.mGameBoarder[i - 1] != 0)
					Wynik = Wynik + MinMax(StanGry, 'A', i, nDepth, MaxDepth);
				i++;
			}
			return Wynik;
		}
	}
	else{
		int X = fnTargetField(nField, StanGry.mGameBoarder[nField - 1]);
		fnMakeAMove(nField, &StanGry);
		fnArbiter(X, Gracz, &StanGry);
		if (fnIsItOver(&StanGry) && nDepth == 0){
			if (StanGry.mnBoxB>StanGry.mnBoxA) return numeric_limits<int>::max();
			else if (StanGry.mnBoxB<StanGry.mnBoxA) return numeric_limits<int>::min();
			else if (StanGry.mnBoxB == StanGry.mnBoxA) return 0;
		}
		else if (fnIsItOver(&StanGry) || nDepth == MaxDepth){
			if (StanGry.mnBoxB>StanGry.mnBoxA) return 1;
			else if (StanGry.mnBoxB<StanGry.mnBoxA) return -1;
			else if (StanGry.mnBoxB == StanGry.mnBoxA) return 0;
		}
		else{
			nDepth++;
			int Wynik = 0;
			int i = 7;
			while (i <= 12)
			{
				if (StanGry.mGameBoarder[i - 1] != 0)
					Wynik = Wynik + MinMax(StanGry, 'B', i, nDepth, MaxDepth);
				i++;
			}
			return Wynik;
		}
	}
}
C_Board::C_Board()
{
	for (int i = 0; i <= 12; i++)
	{
		mGameBoarder[i] = 4;
	}
	mnBoxA = 0;
	mnBoxB = 0;
}
C_Board::C_Board(const C_Board & org_plansza)
{
	for (int j = 0; j <= 12; j++)
	{
		mGameBoarder[j] = org_plansza.mGameBoarder[j];
	}
	mnBoxA = org_plansza.mnBoxA;
	mnBoxB = org_plansza.mnBoxB;
}
void C_Board::DrawPlayground(C_Player *Gracz1, C_Player *Gracz2)
{
	//fnClearScrean();
	cout << "|";
	for (int i = 11; i>5; i--)
	{
		cout << mGameBoarder[i] << "|";
	}
	cout << endl;
	cout << "-------------" << endl;
	cout << "|";
	for (int i = 0; i<6; i++)
	{
		cout << mGameBoarder[i] << "|";
	}
	cout << endl;
	cout << "Pkt. gracza " << Gracz1->msPlayerName << " : " <<
		Gracz1->mCollectedSeeds << ", Pkt. gracza " << Gracz2->msPlayerName <<
		" : " << Gracz2->mCollectedSeeds << endl;
	cout << endl;
	cout << "Numeracja planszy:" << endl;
	cout << "|12|11|10|9 |8 |7 |" << endl;
	cout << "-------------------" << endl;
	cout << "|1 |2 |3 |4 |5 |6 |" << endl;
}
C_Game::C_Game(int A = 1)
{
	if (A == 1){
		mPlayer_A.msPlayerName = "GraczAI";
		mPlayer_A.mCollectedSeeds = 0;
		mPlayer_A.mfIsHisTurn = false;
		cout << "Podaj nazwe gracza: ";
		string strNazwa;
		cin >> strNazwa;
		cout << endl;
		mPlayer_B.msPlayerName = strNazwa;
		mPlayer_B.mCollectedSeeds = 0;
		mPlayer_B.mfIsHisTurn = false;
		mfFirstTurn = true;
		mfItTakes = true;
	}
	else{
		cout << "Podaj nazwe pierwszego gracza: ";
		string strNazwa;
		cin >> strNazwa;
		mPlayer_A.msPlayerName = strNazwa;
		mPlayer_A.mCollectedSeeds = 0;
		mPlayer_A.mfIsHisTurn = false;
		strNazwa.clear();
		cout << "Podaj nazwe drugiego gracza: ";
		cin >> strNazwa;
		mPlayer_B.msPlayerName = strNazwa;
		mPlayer_B.mCollectedSeeds = 0;
		mPlayer_B.mfIsHisTurn = false;
		mfFirstTurn = true;
		mfItTakes = true;
	}
}
void C_Player::MakeAMove(int nField, C_Board *pPlayground)
{
	int nHand, iField;
	nHand = pPlayground->mGameBoarder[nField - 1];
	pPlayground->mGameBoarder[nField - 1] = 0;
	iField = nField - 1;
	while (true)
	{
		if (nHand == 0)break;
		if (iField == 11 && nHand >= 1){
			iField = 0;
			pPlayground->mGameBoarder[iField]++;
			nHand--;
		}
		else{
			iField++;
			if (iField == (nField - 1)) iField++;
			pPlayground->mGameBoarder[iField]++;
			nHand--;
		}
	}
}
void C_Game::Arbiter(int nCel, C_Board *pPlayground)
{
	if (mPlayer_A.mfIsHisTurn)
	{
		if (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
		{
			while (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
			{
				mPlayer_A.mCollectedSeeds = mPlayer_A.mCollectedSeeds + pPlayground->mGameBoarder[nCel - 1];
				pPlayground->mGameBoarder[nCel - 1] = 0;
				nCel--;
				if (nCel == 0) nCel = 12;
			}
			if (fnIsItOver(pPlayground)){
				mPlayer_A.mCollectedSeeds = mPlayer_A.mCollectedSeeds + pPlayground->mGameBoarder[0] + pPlayground->mGameBoarder[1] + pPlayground->mGameBoarder[2] + pPlayground->mGameBoarder[3] + pPlayground->mGameBoarder[4] + pPlayground->mGameBoarder[5];
				pPlayground->mGameBoarder[0] = 0;
				pPlayground->mGameBoarder[1] = 0;
				pPlayground->mGameBoarder[2] = 0;
				pPlayground->mGameBoarder[3] = 0;
				pPlayground->mGameBoarder[4] = 0;
				pPlayground->mGameBoarder[5] = 0;
				mPlayer_B.mCollectedSeeds = mPlayer_B.mCollectedSeeds + pPlayground->mGameBoarder[6] + pPlayground->mGameBoarder[7] + pPlayground->mGameBoarder[8] + pPlayground->mGameBoarder[9] + pPlayground->mGameBoarder[10] + pPlayground->mGameBoarder[11];
				pPlayground->mGameBoarder[6] = 0;
				pPlayground->mGameBoarder[7] = 0;
				pPlayground->mGameBoarder[8] = 0;
				pPlayground->mGameBoarder[9] = 0;
				pPlayground->mGameBoarder[10] = 0;
				pPlayground->mGameBoarder[11] = 0;
			}
			OwarePlayground.mnBoxA = mPlayer_A.mCollectedSeeds;
			OwarePlayground.mnBoxB = mPlayer_B.mCollectedSeeds;
		}
	}
	else
	{
		if (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
		{
			while (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
			{
				mPlayer_B.mCollectedSeeds = mPlayer_B.mCollectedSeeds + pPlayground->mGameBoarder[nCel - 1];
				pPlayground->mGameBoarder[nCel - 1] = 0;
				nCel--;
				if (nCel == 0) nCel = 12;
			}
			if (fnIsItOver(pPlayground)){
				mPlayer_A.mCollectedSeeds = mPlayer_A.mCollectedSeeds + pPlayground->mGameBoarder[0] + pPlayground->mGameBoarder[1] + pPlayground->mGameBoarder[2] + pPlayground->mGameBoarder[3] + pPlayground->mGameBoarder[4] + pPlayground->mGameBoarder[5];
				pPlayground->mGameBoarder[0] = 0;
				pPlayground->mGameBoarder[1] = 0;
				pPlayground->mGameBoarder[2] = 0;
				pPlayground->mGameBoarder[3] = 0;
				pPlayground->mGameBoarder[4] = 0;
				pPlayground->mGameBoarder[5] = 0;
				mPlayer_B.mCollectedSeeds = mPlayer_B.mCollectedSeeds + pPlayground->mGameBoarder[6] + pPlayground->mGameBoarder[7] + pPlayground->mGameBoarder[8] + pPlayground->mGameBoarder[9] + pPlayground->mGameBoarder[10] + pPlayground->mGameBoarder[11];
				pPlayground->mGameBoarder[6] = 0;
				pPlayground->mGameBoarder[7] = 0;
				pPlayground->mGameBoarder[8] = 0;
				pPlayground->mGameBoarder[9] = 0;
				pPlayground->mGameBoarder[10] = 0;
				pPlayground->mGameBoarder[11] = 0;
			}
			OwarePlayground.mnBoxA = mPlayer_A.mCollectedSeeds;
			OwarePlayground.mnBoxB = mPlayer_B.mCollectedSeeds;
		}
	}
}
void C_Game::Move()
{
	if (mPlayer_A.msPlayerName == "GraczAI")
	{
		if (this->mfFirstTurn)
		{
			int nLiczba = rand() % 100 + 1;
			cout << "Wylosowano:" << nLiczba << endl;
			if (nLiczba % 2 != 0)
			{
				cout << "Pierwszy ruch wykonyje gracz " << this->mPlayer_A.msPlayerName << endl;
				int Wybrane = mPlayer_A.AImove(this->OwarePlayground, this->AIlevel);
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_A.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_B.mfIsHisTurn = true;
				this->mPlayer_A.mfIsHisTurn = false;
				mfFirstTurn = false;
			}
			else
			{
				cout << "Pierwszy ruch wykonyje gracz " << this->mPlayer_B.msPlayerName << endl;
				int Wybrane;
				while (true)
				{
					cout << "Podaj pole(1-6): ";
					cin >> Wybrane;
					if (Wybrane<1 || Wybrane>6) cout << "Podales niepoprawny numer." << endl;
					else break;
				}
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_B.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_A.mfIsHisTurn = true;
				this->mPlayer_B.mfIsHisTurn = false;
				mfFirstTurn = false;
			}
		}
		else
		{
			if (this->mPlayer_A.mfIsHisTurn)
			{
				cout << "Ruch wykonyje gracz " << this->mPlayer_A.msPlayerName << endl;
				int Wybrane = mPlayer_A.AImove(this->OwarePlayground, this->AIlevel);
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_A.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_B.mfIsHisTurn = true;
				this->mPlayer_A.mfIsHisTurn = false;
			}
			else
			{
				cout << "Ruch wykonyje gracz " << this->mPlayer_B.msPlayerName << endl;
				int Wybrane;
				while (true)
				{
					cout << "Podaj pole(1-6): ";
					cin >> Wybrane;
					if (Wybrane<1 || Wybrane>6) cout << "Podales niepoprawny numer." << endl;
					else break;
				}
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_B.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_A.mfIsHisTurn = true;
				this->mPlayer_B.mfIsHisTurn = false;
			}
		}
	}
	else
	{
		if (this->mfFirstTurn)
		{
			int nLiczba = rand() % 100 + 1;
			cout << "Wylosowano:" << nLiczba << endl;
			if (nLiczba % 2 != 0)
			{
				cout << "Pierwszy ruch wykonyje gracz " << this->mPlayer_A.msPlayerName << endl;
				int Wybrane;
				while (true)
				{
					cout << "Podaj pole(7-12): ";
					cin >> Wybrane;
					if (Wybrane<7 || Wybrane>12) cout << "Podales niepoprawny numer." << endl;
					else break;
				}
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_A.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_B.mfIsHisTurn = true;
				this->mPlayer_A.mfIsHisTurn = false;
				mfFirstTurn = false;
			}
			else
			{
				cout << "Pierwszy ruch wykonyje gracz " << this->mPlayer_B.msPlayerName << endl;
				int Wybrane;
				while (true)
				{
					cout << "Podaj pole(1-6): ";
					cin >> Wybrane;
					if (Wybrane<1 || Wybrane>6) cout << "Podales niepoprawny numer." << endl;
					else break;
				}
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_B.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_A.mfIsHisTurn = true;
				this->mPlayer_B.mfIsHisTurn = false;
				mfFirstTurn = false;
			}
		}
		else
		{
			if (this->mPlayer_A.mfIsHisTurn)
			{
				cout << "Ruch wykonyje gracz " << this->mPlayer_A.msPlayerName << endl;
				int Wybrane;
				while (true)
				{
					cout << "Podaj pole(7-12): ";
					cin >> Wybrane;
					if (Wybrane<7 || Wybrane>12) cout << "Podales niepoprawny numer." << endl;
					else break;
				}
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_A.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_B.mfIsHisTurn = true;
				this->mPlayer_A.mfIsHisTurn = false;
			}
			else
			{
				cout << "Ruch wykonyje gracz " << this->mPlayer_B.msPlayerName << endl;
				int Wybrane;
				while (true)
				{
					cout << "Podaj pole(1-6): ";
					cin >> Wybrane;
					if (Wybrane<1 || Wybrane>6) cout << "Podales niepoprawny numer." << endl;
					else break;
				}
				int X = fnTargetField(Wybrane, this->OwarePlayground.mGameBoarder[Wybrane - 1]);
				this->mPlayer_B.MakeAMove(Wybrane, &this->OwarePlayground);
				this->Arbiter(X, &this->OwarePlayground);
				this->mPlayer_A.mfIsHisTurn = true;
				this->mPlayer_B.mfIsHisTurn = false;
			}
		}
	}
}
void C_Game::End()
{
	//fnClearScrean();
	cout << "Gra dobiegla konca!!!" << endl;
	if (mPlayer_A.mCollectedSeeds>mPlayer_B.mCollectedSeeds) cout << "Zwyciezyl gracz: " << mPlayer_A.msPlayerName << "." << endl;
	if (mPlayer_A.mCollectedSeeds<mPlayer_B.mCollectedSeeds) cout << "Zwyciezyl gracz: " << mPlayer_B.msPlayerName << "." << endl;
	if (mPlayer_A.mCollectedSeeds == mPlayer_B.mCollectedSeeds) cout << "Gra zakonczyla sie remisem." << endl;
}
bool C_Game::IsItOver()
{
	if ((this->OwarePlayground.mGameBoarder[0] + this->OwarePlayground.mGameBoarder[1] + this->OwarePlayground.mGameBoarder[2] +
		this->OwarePlayground.mGameBoarder[3] + this->OwarePlayground.mGameBoarder[4] + this->OwarePlayground.mGameBoarder[5]) == 0 || (this->OwarePlayground.mGameBoarder[6] + this->OwarePlayground.mGameBoarder[7] + this->OwarePlayground.mGameBoarder[8] +
		this->OwarePlayground.mGameBoarder[9] + this->OwarePlayground.mGameBoarder[10] + this->OwarePlayground.mGameBoarder[11]) == 0) return true;
	if (mPlayer_A.mCollectedSeeds >= 24 || mPlayer_B.mCollectedSeeds >= 24)
	{
		mPlayer_A.mCollectedSeeds = mPlayer_A.mCollectedSeeds + this->OwarePlayground.mGameBoarder[0] + this->OwarePlayground.mGameBoarder[1] + this->OwarePlayground.mGameBoarder[2] +
			this->OwarePlayground.mGameBoarder[3] + this->OwarePlayground.mGameBoarder[4] + this->OwarePlayground.mGameBoarder[5];
		mPlayer_B.mCollectedSeeds = mPlayer_B.mCollectedSeeds + this->OwarePlayground.mGameBoarder[6] + this->OwarePlayground.mGameBoarder[7] + this->OwarePlayground.mGameBoarder[8] +
			this->OwarePlayground.mGameBoarder[9] + this->OwarePlayground.mGameBoarder[10] + this->OwarePlayground.mGameBoarder[11];
		return true;
	}
	else return false;
}
void fnMakeAMove(int nField, C_Board *cPlansza)
{
	int nHand, iField;
	nHand = cPlansza->mGameBoarder[nField - 1];
	cPlansza->mGameBoarder[nField - 1] = 0;
	iField = nField - 1;
	while (true)
	{
		if (nHand == 0)break;
		if (iField == 11 && nHand >= 1){
			iField = 0;
			cPlansza->mGameBoarder[iField]++;
			nHand--;
		}
		else{
			iField++;
			if (iField == (nField - 1)) iField++;
			cPlansza->mGameBoarder[iField]++;
			nHand--;
		}
	}
}
void fnArbiter(int nCel, char Gracz, C_Board *pPlayground)
{
	if (Gracz == 'A')
	{
		if (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
		{
			while (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
			{
				pPlayground->mnBoxA = pPlayground->mnBoxA + pPlayground->mGameBoarder[nCel - 1];
				pPlayground->mGameBoarder[nCel - 1] = 0;
				nCel--;
				if (nCel == 0) nCel = 12;
			}
		}
		if (fnIsItOver(pPlayground)){
			pPlayground->mnBoxA = pPlayground->mnBoxA + pPlayground->mGameBoarder[0] + pPlayground->mGameBoarder[1] + pPlayground->mGameBoarder[2] + pPlayground->mGameBoarder[3] + pPlayground->mGameBoarder[4] + pPlayground->mGameBoarder[5];
			pPlayground->mGameBoarder[0] = 0;
			pPlayground->mGameBoarder[1] = 0;
			pPlayground->mGameBoarder[2] = 0;
			pPlayground->mGameBoarder[3] = 0;
			pPlayground->mGameBoarder[4] = 0;
			pPlayground->mGameBoarder[5] = 0;
			pPlayground->mnBoxB = pPlayground->mnBoxB + pPlayground->mGameBoarder[6] + pPlayground->mGameBoarder[7] + pPlayground->mGameBoarder[8] + pPlayground->mGameBoarder[9] + pPlayground->mGameBoarder[10] + pPlayground->mGameBoarder[11];
			pPlayground->mGameBoarder[6] = 0;
			pPlayground->mGameBoarder[7] = 0;
			pPlayground->mGameBoarder[8] = 0;
			pPlayground->mGameBoarder[9] = 0;
			pPlayground->mGameBoarder[10] = 0;
			pPlayground->mGameBoarder[11] = 0;
		}
	}
	else
	{
		if (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
		{
			while (pPlayground->mGameBoarder[nCel - 1] == 2 || pPlayground->mGameBoarder[nCel - 1] == 3)
			{
				pPlayground->mnBoxB = pPlayground->mnBoxB + pPlayground->mGameBoarder[nCel - 1];
				pPlayground->mGameBoarder[nCel - 1] = 0;
				nCel--;
				if (nCel == 0) nCel = 12;
			}
		}
		if (fnIsItOver(pPlayground)){
			pPlayground->mnBoxA = pPlayground->mnBoxA + pPlayground->mGameBoarder[0] + pPlayground->mGameBoarder[1] + pPlayground->mGameBoarder[2] + pPlayground->mGameBoarder[3] + pPlayground->mGameBoarder[4] + pPlayground->mGameBoarder[5];
			pPlayground->mGameBoarder[0] = 0;
			pPlayground->mGameBoarder[1] = 0;
			pPlayground->mGameBoarder[2] = 0;
			pPlayground->mGameBoarder[3] = 0;
			pPlayground->mGameBoarder[4] = 0;
			pPlayground->mGameBoarder[5] = 0;
			pPlayground->mnBoxB = pPlayground->mnBoxB + pPlayground->mGameBoarder[6] + pPlayground->mGameBoarder[7] + pPlayground->mGameBoarder[8] + pPlayground->mGameBoarder[9] + pPlayground->mGameBoarder[10] + pPlayground->mGameBoarder[11];
			pPlayground->mGameBoarder[6] = 0;
			pPlayground->mGameBoarder[7] = 0;
			pPlayground->mGameBoarder[8] = 0;
			pPlayground->mGameBoarder[9] = 0;
			pPlayground->mGameBoarder[10] = 0;
			pPlayground->mGameBoarder[11] = 0;
		}
	}
}

int C_Player::AImove(C_Board PlanszaGry, int MaxDepth)
{
	int pktPola[] = { 0, 0, 0, 0, 0, 0 };
	int tab[] = { 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i <= 5; i++){
		if (PlanszaGry.mGameBoarder[i + 6] != 0)
			pktPola[i] = MinMax(PlanszaGry, 'B', i + 7, 0, MaxDepth);
	}
	copy(pktPola, pktPola + 6, tab);
	sort(tab, tab + 6, greater < int >());
	for (int i = 0; i <= 5; i++){
		if (tab[i] != 0){
			for (int j = 0; j <= 5; j++){
				if (tab[i] == pktPola[j]) return j + 7;
			}
		}
	}
}
bool fnIsItOver(C_Board* OwarePlayground)
{
	if ((OwarePlayground->mGameBoarder[0] + OwarePlayground->mGameBoarder[1] + OwarePlayground->mGameBoarder[2] +
		OwarePlayground->mGameBoarder[3] + OwarePlayground->mGameBoarder[4] + OwarePlayground->mGameBoarder[5]) == 0 || (OwarePlayground->mGameBoarder[6] + OwarePlayground->mGameBoarder[7] + OwarePlayground->mGameBoarder[8] +
		OwarePlayground->mGameBoarder[9] + OwarePlayground->mGameBoarder[10] + OwarePlayground->mGameBoarder[11]) == 0) return true;
	if (OwarePlayground->mnBoxA >= 24 || OwarePlayground->mnBoxB >= 24) return true;
	else return false;
}