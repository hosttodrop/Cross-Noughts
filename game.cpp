#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>

using namespace std;

//������� ����� ����
int VictoryMove (char fld[9], char player, char bot); //����������� ����������� ���� (��� ������ 2 �� 3, ����� �� �������)
int CriticMove (char fld[9], char player, char bot); //����������� ������������ ����, ����� �� ��������� (����� ������ 2 �� 3)
int ClearAttack (char fld[9], char player, char bot); //�����, ����������� ������ ���������� ��� �������� �����, ����������� ��� ���� (��� ��������� ���� ������ ������� ����������� ����� ����)
int BotFork (char fld[9], char player, char bot); //����������� ���� ������� �����
int SafetyAttack (char fld[9], char player, char bot); //����������� ������ ������� ����� (������� ���� ��� ����� � "���������������" ������� �����)
int FreeMove (char fld[9], char player, char bot); //��� �� ��������� ���� (��� ������� ��� ��� ����� ����, �������� ���������)

//������� ������ � ��������
int CheckWin (char fld[9]); //��������, ���� �� ����������
void Hello (); //������� �� ����� ���������� � ������� ����
void Display (char fld[9], char player, char bot); //������� �� ����� ���� ����� ����� ���� ������/���� � ��������� ���� ��������� 

int main(int argc, char** argv) {
	//�������_����(���. ����-�� 1-3); ����� �� ����; �������� �����: ������ ����, ����� O ��� X ��� ����, ���� ��� ����; ����� ���� ��� ���� ������ � ����; ������ �����. ����. ������� ����, ��� ����������� ������������� ����;
	int lvl_bot=0, exit=0, accept_bot=0, accept_player=0, accept_turn=0, turn=0, b_turn=0, check=10; 
	char player='p', bot='b', fld[9]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'k'}; //��� ������ ����� � ���; ���� ��� ����
	
	srand(time(NULL));
	system("mode con cols=170 lines=85"); //������ ����������� ���� ������: 170 ����.; ������: 55 ����.

	//������������ ����, �.�. �������, ���� ����� �� ������� �����
	while (!exit) {
		system("cls"); //������� ���� � ���������� ����
		
		Hello();
		
		//�������� ������������ ������ ������ ���� (1, 2 ��� 3)
		while (!accept_bot) {
			if ((lvl_bot>3) || (lvl_bot<1)) {
				cout<<"Select bot level: enter <1>, <2> or <3> --> ";
				cin>>lvl_bot;	
			}
			else {
				cout<<"Bot level - <"<<lvl_bot<<">"<<endl;
				accept_bot=1;
			}
		}
	
		//�������� ������������ ������ �� ���� ������ (X-�������� ��� O-������)
		while (!accept_player) {
			if ((player!='O') && (player!='X')) {
				cout<<"Choose who to play: enter <X> - play for Cross or <O> - play for Noughts --> "<<endl;
				cin>>player;
			}
			else {
				cout<<"You play for <"<<player<<">"<<endl;
				accept_player=1;
			}
		}
		
		//������ ����::
		cout<<"The game has begun!!! Good luck have fun!)"<<endl<<endl;
		
		//������ ��� �� �������
		if (player=='X') {
			bot='O';
			switch (lvl_bot) {
				case 1: {
					for (int i=0; i<5; i++) {
						//��� ������::
						cout<<"Your turn. Choose a free field ";
						cin>>turn;
						
						//�������� ������������ ������ ���� ��� ����
						while (!accept_turn) {
							if ((fld[turn-1]==player) || (fld[turn-1]==bot) || (turn<1) || (turn>9)) {
								cout<<"This field is not free. Choose a free field ";
								cin>>turn;
							}
							else {
								fld[turn-1]=player;
								accept_turn=1;
							}
						}
						accept_turn=0;
						
						//�������� �������� ������
						if (CheckWin(fld)) {
							cout<<"You win!"<<endl;
							break;
						}
						
						//��� ����::
						switch (i) {
							case 0: {
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 1: {
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 2: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 3: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
						}
						
						Display(fld, player, bot);
						
						if (CheckWin(fld)) {
							cout<<"Bot win!"<<endl;
							break;
						}
					}
					break;
				}
				case 2: {
					for (int i=0; i<5; i++) {
						//��� ������::
						cout<<"Your turn. Choose a free field ";
						cin>>turn;
						
						//�������� ������������ ������ ���� ��� ����
						while (!accept_turn) {
							if ((fld[turn-1]==player) || (fld[turn-1]==bot) || (turn<1) || (turn>9)) {
								cout<<"This field is not free. Choose a free field ";
								cin>>turn;
							}
							else {
								fld[turn-1]=player;
								accept_turn=1;
							}
						}
						accept_turn=0;
						
						//�������� �������� ������
						if (CheckWin(fld)) {
							cout<<"You win!"<<endl;
							break;
						}
						
						//��� ����::
						switch (i) {
							case 0: {
								if (turn%2==0) { //���� ����� ����� ������ ����
									b_turn=rand()%4; //3 �������� ����: 50% �� ����� � �� 25% �� ������� ���� - ��� ����� ��������, �� ����������
									
									switch (b_turn) {
										case 0: { //������� ���� 1 - ����� ��� 2/8 ������� ������, ������� ��� 4/6 ������� ������
											if ((turn-1)/3==1) { //�������� ��� ���������� ������������ ������� ����� ��� ������ �����: ������(2/8 ���.) - [turn-2], [turn]; �������(4/6 ���.) - [turn-4], [turn+2]
												fld[turn-4]=bot;
												cout<<"The bot went to the "<<(turn-4)+1<<"`s field"<<endl;
											}	
											else {
												fld[turn-2]=bot;
												cout<<"The bot went to the "<<(turn-2)+1<<"`s field"<<endl;
											}
											break;
										}
										case 1: { //������� ���� 2 - ������ ��� 2/8 ������� ������, ������ ��� 4/6 ������� ������
											if ((turn-1)/3==1) { //�������� ��� ���������� ������������ ������� ����� ��� ������ �����: ������(2/8 ���.) - [turn]; �������(4/6 ���.) - [turn+2]
												cout<<"The bot went to the "<<(turn+2)+1<<"`s field"<<endl;
												fld[turn+2]=bot;
											}
												
											else {
												cout<<"The bot went to the "<<turn+1<<"`s field"<<endl;
												fld[turn]=bot;
											}
											break;
										}
										default: { //����������� ���� ��� ����� ������� ������
											cout<<"The bot went to the 5`s field"<<endl;
											fld[4]=bot;
										}
									}
								}
								else {
									if (fld[4]!=player) { //������ ����� ���� ������ ����� ������� ����
										cout<<"The bot went to the 5`s field"<<endl;
										fld[4]=bot;
									}
									else {
										b_turn=rand()%4; //���� ����� ����� �����, ������ ���� �� ������� ������� �����

										switch (b_turn) {
											case 0: {
												cout<<"The bot went to the 1`s field"<<endl;
												fld[0]=bot;
												break;
											}
											case 1: {
												cout<<"The bot went to the 3`s field"<<endl;
												fld[2]=bot;
												break;
											}
											case 2: {
												cout<<"The bot went to the 7`s field"<<endl;
												fld[6]=bot;
												break;
											}
											case 3: {
												cout<<"The bot went to the 9`s field"<<endl;
												fld[8]=bot;
												break;
											}
										}
									}
								}
								break;
							}
							case 1: {
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}	
							}
							case 2: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}		
							}
							case 3: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
						}
						Display(fld, player, bot);
						
						if (CheckWin(fld)) {
							cout<<"Bot win!"<<endl;
							break;
						}
					}
					break;
				}
				case 3: {
					for (int i=0; i<5; i++) {
						//��� ������::
						cout<<"Your turn. Choose a free field ";
						cin>>turn;
						
						//�������� ������������ ������ ���� ��� ����
						while (!accept_turn) {
							if ((fld[turn-1]==player) || (fld[turn-1]==bot) || (turn<1) || (turn>9)) {
								cout<<"This field is not free. Choose a free field ";
								cin>>turn;
							}
							else {
								fld[turn-1]=player;
								accept_turn=1;
							}
						}
						accept_turn=0;
						
						//�������� �������� ������
						if (CheckWin(fld)) {
							cout<<"You win!"<<endl;
							break;
						}
						
						//��� ����::
						switch (i) {
							case 0: {
								if (turn%2==0) { //���� ����� ����� ������ ����
									b_turn=rand()%4; //3 �������� ����: 50% �� ����� � �� 25% �� ������� ���� - ��� ����� ��������, �� ����������
									
									switch (b_turn) {
										case 0: { //������� ���� 1 - ����� ��� 2/8 ������� ������, ������� ��� 4/6 ������� ������
											if ((turn-1)/3==1) { //�������� ��� ���������� ������������ ������� ����� ��� ������ �����: ������(2/8 ���.) - [turn-2], [turn]; �������(4/6 ���.) - [turn-4], [turn+2]
												fld[turn-4]=bot;
												cout<<"The bot went to the "<<(turn-4)+1<<"`s field"<<endl;
											}	
											else {
												fld[turn-2]=bot;
												cout<<"The bot went to the "<<(turn-2)+1<<"`s field"<<endl;
											}
											break;
										}
										case 1: { //������� ���� 2 - ������ ��� 2/8 ������� ������, ������ ��� 4/6 ������� ������
											if ((turn-1)/3==1) { //�������� ��� ���������� ������������ ������� ����� ��� ������ �����: ������(2/8 ���.) - [turn]; �������(4/6 ���.) - [turn+2]
												cout<<"The bot went to the "<<(turn+2)+1<<"`s field"<<endl;
												fld[turn+2]=bot;
											}
												
											else {
												cout<<"The bot went to the "<<turn+1<<"`s field"<<endl;
												fld[turn]=bot;
											}
											break;
										}
										default: { //����������� ���� ��� ����� ������� ������
											cout<<"The bot went to the 5`s field"<<endl;
											fld[4]=bot;
										}
									}
								}
								else {
									if (fld[4]!=player) { //������ ����� ���� ������ ����� ������� ����
										cout<<"The bot went to the 5`s field"<<endl;
										fld[4]=bot;
									}
									else {
										b_turn=rand()%4; //���� ����� ����� �����, ������ ���� �� ������� ������� �����

										switch (b_turn) {
											case 0: {
												cout<<"The bot went to the 1`s field"<<endl;
												fld[0]=bot;
												break;
											}
											case 1: {
												cout<<"The bot went to the 3`s field"<<endl;
												fld[2]=bot;
												break;
											}
											case 2: {
												cout<<"The bot went to the 7`s field"<<endl;
												fld[6]=bot;
												break;
											}
											case 3: {
												cout<<"The bot went to the 9`s field"<<endl;
												fld[8]=bot;
												break;
											}
										}
									}
								}
								break;
							}
							case 1: {
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=ClearAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 2: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
																
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=BotFork(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field";
									fld[check]=bot;
									break;
								}
								
								check=ClearAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field";
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}		
							}
							case 3: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
													
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}	
							}
						}
						
						Display(fld, player, bot);
						
						if (CheckWin(fld)) {
							cout<<"Bot win!"<<endl;
							break;
						}
					
					}
					break;
				}
			}
		}
		if (player=='O') {
			bot='X';
			switch (lvl_bot) {
				case 1: {
					//������ ��� ����::
					check=FreeMove(fld, player, bot);
					cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
					fld[check]=bot;
					
					Display(fld, player, bot);
					
					for (int i=1; i<5; i++) {
						//��� ������::
						cout<<"Your turn. Choose a free field ";
						cin>>turn;
						
						//�������� ������������ ������ ���� ��� ����
						while (!accept_turn) {
							if ((fld[turn-1]==player) || (fld[turn-1]==bot) || (turn<1) || (turn>9)) {
								cout<<"This field is not free. Choose a free field ";
								cin>>turn;
							}
							else {
								fld[turn-1]=player;
								accept_turn=1;
							}
						}
						accept_turn=0;
						
						Display(fld, player, bot);
						
						//�������� �������� ������
						if (CheckWin(fld)) {
							cout<<"You win!"<<endl;
							break;
						}
						
						switch (i) {
							case 1: {
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 2: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
																
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 3: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
																
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 4: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
													
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
						}
						
						Display(fld, player, bot);
						
						if (CheckWin(fld)) {
							cout<<"Bot win!"<<endl;
							break;
						}	
					}
					break;
				}
				case 2: {
					//������ ��� ����::
					check=FreeMove(fld, player, bot);
					cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
					fld[check]=bot;
					
					Display(fld, player, bot);
					
					for (int i=1; i<5; i++) {
						//��� ������::
						cout<<"Your turn. Choose a free field ";
						cin>>turn;
						
						//�������� ������������ ������ ���� ��� ����
						while (!accept_turn) {
							if ((fld[turn-1]==player) || (fld[turn-1]==bot) || (turn<1) || (turn>9)) {
								cout<<"This field is not free. Choose a free field ";
								cin>>turn;
							}
							else {
								fld[turn-1]=player;
								accept_turn=1;
							}
						}
						accept_turn=0;
						
						Display(fld, player, bot);
						
						//�������� �������� ������
						if (CheckWin(fld)) {
							cout<<"You win!"<<endl;
							break;
						}
						
						switch (i) {
							case 1: {						
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 2: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
																
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 3: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
																
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 4: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
													
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
						}
						
						Display(fld, player, bot);
						
						if (CheckWin(fld)) {
							cout<<"Bot win!"<<endl;
							break;
						}
					}		
					break;
				}
				case 3: {
					//������ ��� ����::
					check=FreeMove(fld, player, bot);
					cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
					fld[check]=bot;
					
					Display(fld, player, bot);
					
					for (int i=1; i<5; i++) {
						//��� ������::
						cout<<"Your turn. Choose a free field ";
						cin>>turn;
						
						//�������� ������������ ������ ���� ��� ����
						while (!accept_turn) {
							if ((fld[turn-1]==player) || (fld[turn-1]==bot) || (turn<1) || (turn>9)) {
								cout<<"This field is not free. Choose a free field ";
								cin>>turn;
							}
							else {
								fld[turn-1]=player;
								accept_turn=1;
							}
						}
						accept_turn=0;
						
						Display(fld, player, bot);
						
						//�������� �������� ������
						if (CheckWin(fld)) {
							cout<<"You win!"<<endl;
							break;
						}
						
						switch (i) {
							case 1: {
								check=ClearAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 2: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
																
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=BotFork(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field";
									fld[check]=bot;
									break;
								}
								
								check=ClearAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field";
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 3: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
																
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=BotFork(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field";
									fld[check]=bot;
									break;
								}
								
								check=ClearAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field";
									fld[check]=bot;
									break;
								}
								
								check=SafetyAttack(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}													
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
							case 4: {
								check=VictoryMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
													
								check=CriticMove(fld, player, bot);
								if (check>-1) {
									fld[check]=bot;
									break;
								}
								
								check=FreeMove(fld, player, bot);
								if (check>-1) {
									cout<<"The bot went to the "<<check+1<<"`s field"<<endl;
									fld[check]=bot;
									break;
								}
							}
						}
						
						Display(fld, player, bot);
						
						if (CheckWin(fld)) {
							cout<<"Bot win!"<<endl;
							break;
						}
					}
					break;
				}
			}
		}
		
		if (!CheckWin(fld)) {
			cout<<"DRAW!"<<endl;
		}
	
		lvl_bot=0;
		accept_bot=0;
		accept_player=0;
		bot='b';
		player='p';
		check=-1;
		fld[0]='a';
		fld[1]='b';
		fld[2]='c';
		fld[3]='d';
		fld[4]='e';
		fld[5]='f';
		fld[6]='g';
		fld[7]='h';
		fld[8]='k';
		
		cout<<"Enter <1> - for exit or <0> - for restart game ";
		cin>>exit;
	}

	
	return 0;
}

int VictoryMove (char fld[9], char player, char bot) {
	int bot_sum=0, bot_cnt=0, player_cnt=0; //����� �������� ������� ���� � ����; �������� ����� ���� � ������ � ����� ����;
	
	//�������� �� ������� �� ���������� ���
	for (int i=0; i<7; i+=3) {
		for (int j=i; j<i+3; j++) {
			if (fld[j]==player) {
				player_cnt++;
			}
			if (fld[j]==bot) {
				bot_cnt++;
				bot_sum+=j;
			}
		}
		if ((bot_cnt>1)&&(player_cnt<1)) {
			cout<<"The bot went to the "<<(i+1)*3-bot_sum+1<<"`s field"<<endl;
			return (i+1)*3-bot_sum;
		}
		bot_sum=0;
		bot_cnt=0;
		player_cnt=0;
	}
	
	//�������� �� �������� �� ���������� ���
	for (int i=0; i<3; i++) {
		for (int j=i; j<i+7; j+=3) {
			if (fld[j]==player) {
				player_cnt++;
			}
			if (fld[j]==bot) {
				bot_cnt++;
				bot_sum+=j;
			}
		}
		if ((bot_cnt>1)&&(player_cnt<1)) {
			cout<<"The bot went to the "<<(i+3)*3-bot_sum+1<<"`s field"<<endl;
			return (i+3)*3-bot_sum;
		}
		bot_sum=0;
		bot_cnt=0;
		player_cnt=0;
	}
	
	//�������� �� ���������� �� ���������� ���
	for (int i=0; i<9; i+=4) {
		if (fld[i]==player) {
			player_cnt++;
		}
		if (fld[i]==bot) {
			bot_cnt++;
			bot_sum+=i;
		}
	}
	if ((bot_cnt>1)&&(player_cnt<1)) {
		//12 - ����� �������� ����� �� ���������
		cout<<"The bot went to the "<<12-bot_sum+1<<"`s field"<<endl;
		return 12-bot_sum;
	}
	
	bot_sum=0;
	bot_cnt=0;
	player_cnt=0;
	
	for (int i=2; i<7; i+=2) {
		if (fld[i]==player) {
			player_cnt++;
		}
		if (fld[i]==bot) {
			bot_cnt++;
			bot_sum+=i;
		}
	}
	if ((bot_cnt>1)&&(player_cnt<1)) {
		//12 - ����� �������� ����� �� ���������
		cout<<"The bot went to the "<<12-bot_sum+1<<"`s field"<<endl;
		return 12-bot_sum;
	}
	
	return -1;
}

int CriticMove (char fld[9], char player, char bot) {
	int player_cnt=0, bot_cnt=0, pl_sum=0; //�������� ����� ������ � ���� � ����� ����; ����� �������� ������� ������ � ����
	
	//�������� �� ������� �� ����������� ���
	for (int i=0; i<7; i+=3) {
		for (int j=i; j<i+3; j++) {
			if (fld[j]==player) {
				player_cnt++;
				pl_sum+=j;
			}
			if (fld[j]==bot) {
					bot_cnt++;
			}
		}
		if ((player_cnt>1)&&(bot_cnt<1)) {
			//(i+1)*3 - ����� �������� ����� � ������
			cout<<"The bot went to the "<<(i+1)*3-pl_sum+1<<"`s field"<<endl;
			return (i+1)*3-pl_sum;
		}
		bot_cnt=0;
		player_cnt=0;
		pl_sum=0;
	}
	
	//�������� �� �������� �� ����������� ���
	for (int i=0; i<3; i++) {
		for (int j=i; j<i+7; j+=3) {
			if (fld[j]==player) {
				player_cnt++;
				pl_sum+=j;
			}
			if (fld[j]==bot) {
				bot_cnt++;
			}
		}
		if ((player_cnt>1)&&(bot_cnt<1)) {
			//(i+1)*3 - ����� �������� ����� � �������
			cout<<"The bot went to the "<<(i+3)*3-pl_sum+1<<"`s field"<<endl;
			return (i+3)*3-pl_sum;
		}
		bot_cnt=0;
		player_cnt=0;
		pl_sum=0;
	}
	
	//�������� �� ���������� �� ����������� ���
	for (int i=0; i<9; i+=4) {
		if (fld[i]==player) {
			player_cnt++;
			pl_sum+=i;
		}
		if (fld[i]==bot) {
			bot_cnt++;
		}
	}
	if ((player_cnt>1)&&(bot_cnt<1)) {
		//12 - ����� �������� ����� �� ���������
		cout<<"The bot went to the "<<12-pl_sum+1<<"`s field"<<endl;
		return 12-pl_sum;
	}
	
	bot_cnt=0;
	player_cnt=0;
	pl_sum=0;
	
	for (int i=2; i<7; i+=2) {
		if (fld[i]==player) {
			player_cnt++;
			pl_sum+=i;
		}
		if (fld[i]==bot) {
			bot_cnt++;	
		}
	}
	if ((player_cnt>1)&&(bot_cnt<1)) {
		//12 - ����� �������� ����� �� ���������
		cout<<"The bot went to the "<<12-pl_sum+1<<"`s field"<<endl;
		return 12-pl_sum;
	}
	return -1;
}

int ClearAttack (char fld[9], char player, char bot) {
	int bot_moves=0, pl_moves=0, n=0; //������ ���-�� ������� ����� � ������� ����� (�����., ������. ���� � ���� ������); ��� ���������� � ������;
	
	for (int i=0; i<9; i++) {
		if (fld[i]==player) {
			pl_moves++;
		}
		if (fld[i]==bot) {
			bot_moves++;
		}
	}
	
	int bot_row[bot_moves], bot_col[bot_moves], bot_diag[bot_moves], bot_pos[bot_moves]; //����� ����� ������ ������ ����� �������� ���� (���� ����, ��� ������); ����� ������� ����� ���;
	int pl_row[pl_moves], pl_col[pl_moves], pl_diag[pl_moves], pl_pos[pl_moves]; //����� ����� ������ ������ ����� �������� ������ (���� ������, ��� ������); ����� ������� ����� �����;
	//������������� �������� ���� ��������, ���� <-1> - ����� �� �������� ��������� ������ ��� ���� ��� �� ������;
	for (int i=0; i<bot_moves; i++) {
		bot_row[i]=-1;
		bot_col[i]=-1;
		bot_diag[i]=-1;
	}
	for (int i=0; i<pl_moves; i++) {
		pl_row[i]=-1;
		pl_col[i]=-1;
		pl_diag[i]=-1;
	}
	
	int bot_clear_cnt[bot_moves*2], pl_clear_cnt[pl_moves*2]; //�������� ������ ����� � ��������/������� ��� ������ ������� ���� � ������; ���� �� ���������;
	for (int i=0; i<bot_moves*2; i++) {
		bot_clear_cnt[i]=0;
	}
	for (int i=0; i<pl_moves*2; i++) {
		pl_clear_cnt[i]=0;
	}
	
	//��������� ������� ����
	for (int i=0; i<9; i++) {
		if (fld[i]==bot) {
			bot_pos[n]=i;
			n++;
		}
		if (n==bot_moves) {
			break;
		}
	}
	n=0;
	
	//��������� ������� ������
	for (int i=0; i<9; i++) {
		if (fld[i]==player) {
			pl_pos[n]=i;
			n++;
		}
		if (n==pl_moves) {
			break;
		}
	}
	n=0;
	
	//�������� ����� � ������� �� ������� ������ ����� ������� ����; �������� bot_clear_cnt[]=2: ��� ������ �������, ���� ������� ����
	for (int j=0; j<bot_moves; j++) {
		for (int i=0; i<3; i++) {
			if ( (fld[bot_pos[j]/3*3+i]!=bot) && (fld[bot_pos[j]/3*3+i]!=player) ) {
				bot_clear_cnt[j]++;
			}
			
			if ( (fld[bot_pos[j]%3+3*i]!=bot) && (fld[bot_pos[j]%3+3*i]!=player) ) {
				bot_clear_cnt[bot_moves+j]++;
			}
		}
	}
	
	//�������� ����� � ������� �� ������� ������ ����� ������� ������; �������� pl_clear_cnt[]=2: ��� ������ �������, ���� ������� ������
	for (int j=0; j<pl_moves; j++) {
		for (int i=0; i<3; i++) {
			if ( (fld[pl_pos[j]/3*3+i]!=bot) && (fld[pl_pos[j]/3*3+i]!=player) ) {
				pl_clear_cnt[j]++;
			}
			
			if ( (fld[pl_pos[j]%3+3*i]!=bot) && (fld[pl_pos[j]%3+3*i]!=player) ) {
				pl_clear_cnt[pl_moves+j]++;
			}
		}
	}
	
	//���������� "���������" ����� � �������� ����
	for (int i=0; i<bot_moves; i++) {
		if (bot_clear_cnt[i]==2) {
			bot_row[i]=bot_pos[i]/3;
		}
		if (bot_clear_cnt[bot_moves+i]==2) {
			bot_col[i]=bot_pos[i]%3;
		}
	}
	
	//���������� "���������" ����� � �������� ������
	for (int i=0; i<pl_moves; i++) {
		if (pl_clear_cnt[i]==2) {
			pl_row[i]=pl_pos[i]/3;
		}
		if (pl_clear_cnt[pl_moves+i]==2) {
			pl_col[i]=pl_pos[i]%3;
		}
	}


	
	//�������� ���������� �� ������� ������ ����� ������� ���� ��� ������ � ���������� "���������" ����������; n - ������� ����/������, ��� ������� � �����. ������ �������;
	int clear_cnt=0; //������� clear_cnt=2: ��� ������ �������, ���� ������� ����/������;
	
	//������� ��������� <0>
	for (int i=0; i<9; i+=4) {
		if ((fld[i]!=bot) && (fld[i]!=player)) {
			clear_cnt++;
		}
		if (fld[i]==bot) {
			n=i;
		}
		if (fld[i]==player) {
			n=i;
		}
	}
	if (clear_cnt==2) {
		for (int i=0; i<5; i++) {
			if (n==bot_pos[i]) {
				bot_diag[i]=0;
				break;
			}
			if (n==pl_pos[i]) {
				pl_diag[i]=0;
				break;
			}	
		}
		
	}
	
	n=0;
	clear_cnt=0;
	
	//�������� ��������� <1>
	for (int i=2; i<7; i+=2) {
		if ((fld[i]!=bot) && (fld[i]!=player)) {
			clear_cnt++;
		}
		if (fld[i]==bot) {
			n=i;
		}
		if (fld[i]==player) {
			n=i;
		}
	}
	if (clear_cnt==2) {
		for (int i=0; i<5; i++) {
			if (bot_pos[i]==n) {
				bot_diag[i]=1;
				break;
			}
			if (pl_pos[i]==n) {
				pl_diag[i]=1;
				break;
			}	
		}
		
	}
	
	n=0;
	clear_cnt=0;
	
	//��� ��������� ��������� <2>
	for (int i=0; i<9; i+=2) {
		if ((fld[i]!=bot)&&(fld[i]!=player)&&(i!=4)) {
			clear_cnt++;
		}
	}
	if (clear_cnt==4) {
		for (int i=0; i<5; i++) {
			if (bot_pos[i]==4) {
				bot_diag[i]=2;
				break;
			}
			if (pl_pos[i]==4) {
				pl_diag[i]=2;
				break;
			}
		}
	}
	
	int temp[9]={-1, -1, -1, -1, -1, -1, -1, -1, -1,}, *bot_clearfld, *pl_clearfld; //��������� ������ ��� ������� ����� ������� � ���.������� "���������" ������� ���� � ������
	
	//���������� "���������" ����� ����
	for (int i=0; i<bot_moves; i++) {
		if (bot_row[i]>-1) {
			for (int j=0; j<3; j++) {
				if (fld[bot_row[i]*3+j]!=bot) {
					temp[n]=bot_row[i]*3+j;
					n++;
				}
			}
		}
		if (bot_col[i]>-1) {
			for (int j=0; j<3; j++) {
				if (fld[bot_col[i]+3*j]!=bot) {
					temp[n]=bot_col[i]+3*j;
					n++;
				}
			}	
		}
		if (bot_diag[i]>-1) {
			if (bot_diag[i]!=2) {
				for (int j=0; j<3; j++) {
					if (fld[2*(bot_diag[i]+j*(2-bot_diag[i]))]!=bot) {
						temp[n]=2*(bot_diag[i]+j*(2-bot_diag[i]));
						n++;
					}
				}
			}
			else {
				for (int j=0; j<5; j++) {
					if (j!=2) {
						temp[n]=2*j;
						n++;
					}
				}
			}
				
		}
	}
	
	//������ "���������" ����� ����
	bot_clearfld = new int[n];
	for (int i=0; i<n; i++) {
		bot_clearfld[i]=temp[i];
		temp[i]=-1;
	}
	size_t bot_size;
	bot_size=n;
	n=0;
	
	//���������� "���������" ����� ������
	for (int i=0; i<pl_moves; i++) {
		if (pl_row[i]>-1) {
			for (int j=0; j<3; j++) {
				if (fld[pl_row[i]*3+j]!=player) {
					temp[n]=pl_row[i]*3+j;
					n++;
				}
			}
		}
		if (pl_col[i]>-1) {
			for (int j=0; j<3; j++) {
				if (fld[pl_col[i]+3*j]!=player) {
					temp[n]=pl_col[i]+3*j;
					n++;
				}
			}	
		}
		if (pl_diag[i]>-1) {
			if (pl_diag[i]!=2) {
				for (int j=0; j<3; j++) {
					if (fld[2*(pl_diag[i]+j*(2-pl_diag[i]))]!=player) {
						temp[n]=2*(pl_diag[i]+j*(2-pl_diag[i]));
						n++;
					}
				}
			}
			else {
				for (int j=0; j<5; j++) {
					if (j!=2) {
						temp[n]=2*j;
						n++;
					}
				}
			}
				
		}
	}
	
	//������ "���������" ����� ������
	pl_clearfld = new int[n];
	for (int i=0; i<n; i++) {
		pl_clearfld[i]=temp[i];
		temp[i]=-1;
	}
	size_t pl_size;
	pl_size=n;
	n=0;
	
	//����������� ����� ������� ��������� ������ �� "���������" ������ ����, � �� ������ (�� ��� ����� ���������� ���� ������)
	clear_cnt=0;
	for (int i=0; i<bot_size; i++) {
		for (int j=0; j<pl_size; j++) {
			if (bot_clearfld[i]!=pl_clearfld[j]) {
				clear_cnt++;
			}
		}
		if (clear_cnt==pl_size) {
			temp[n]=bot_clearfld[i];
			n++;
		}
		clear_cnt=0;
	}
	
	delete[] bot_clearfld;
	delete[] pl_clearfld;
	
	//���� n==0, ������ ��� �����, ������� ����, ����� ���������� ��� ����
	if (n==0) {
		return -1;
	}
	else {
		int move; //��������� ����� ����, �� ������� ����� �������������� ������
		srand(time(NULL));
		move=temp[rand()%n];
	
		//����� ����� � ���� � ��� ���� ������ ���, ��� ���������� ���� ������
		for (int i=0; i<bot_moves; i++) {
			if (move/3==bot_row[i]) {
				return (bot_row[i]*3+1)*3-bot_pos[i]-move;
			}
		
			if (move%3==bot_col[i]) {
				return (bot_col[i]+3)*3-bot_pos[i]-move;
			}
			if ((move%4==0)&&((bot_diag[i]==0)||(bot_diag[i]==2))) {
				return 12-bot_pos[i]-move;
			}
			if ((move%2==0)&&((bot_diag[i]==0)||(bot_diag[i]==2))) {
				return 12-bot_pos[i]-move;
			}
		}
	}

}

int SafetyAttack (char fld[9], char player, char bot) {
	int bot_moves=0, pl_moves=0, n=0; //������ ���-�� ������� ����� � ������� ����� (�����., ������. ���� � ���� ������); ��� ���������� � ������;
	
	for (int i=0; i<9; i++) {
		if (fld[i]==player) {
			pl_moves++;
		}
		if (fld[i]==bot) {
			bot_moves++;
		}
	}

	int bot_row[bot_moves], bot_col[bot_moves], bot_diag[bot_moves], bot_pos[bot_moves]; //����� ����� ������ ������ ����� �������� ���� (���� ����, ��� ������); ����� ������� ����� ���;
	int pl_row[pl_moves], pl_col[pl_moves], pl_diag[pl_moves], pl_pos[pl_moves]; //����� ����� ������ ������ ����� �������� ������ (���� ������, ��� ������); ����� ������� ����� �����;
	//������������� �������� ���� ��������, ���� <-1> - ����� �� �������� ��������� ������ ��� ���� ��� �� ������;
	for (int i=0; i<bot_moves; i++) {
		bot_row[i]=-1;
		bot_col[i]=-1;
		bot_diag[i]=-1;
	}
	for (int i=0; i<pl_moves; i++) {
		pl_row[i]=-1;
		pl_col[i]=-1;
		pl_diag[i]=-1;
	}
	
	int bot_clear_cnt[bot_moves*2], pl_clear_cnt[pl_moves*2]; //�������� ������ ����� � ��������/������� ��� ������ ������� ���� � ������; ���� �� ���������;
	for (int i=0; i<bot_moves*2; i++) {
		bot_clear_cnt[i]=0;
	}
	for (int i=0; i<pl_moves*2; i++) {
		pl_clear_cnt[i]=0;
	}
	
	//��������� ������� ����
	for (int i=0; i<9; i++) {
		if (fld[i]==bot) {
			bot_pos[n]=i;
			n++;
		}
		if (n==bot_moves) {
			break;
		}
	}
	n=0;
	
	//��������� ������� ������
	for (int i=0; i<9; i++) {
		if (fld[i]==player) {
			pl_pos[n]=i;
			n++;
		}
		if (n==pl_moves) {
			break;
		}
	}
	n=0;
	
	//�������� ����� � ������� �� ������� ������ ����� ������� ����; �������� bot_clear_cnt[]=2: ��� ������ �������, ���� ������� ����
	for (int j=0; j<bot_moves; j++) {
		for (int i=0; i<3; i++) {
			if ( (fld[bot_pos[j]/3*3+i]!=bot) && (fld[bot_pos[j]/3*3+i]!=player) ) {
				bot_clear_cnt[j]++;
			}
			
			if ( (fld[bot_pos[j]%3+3*i]!=bot) && (fld[bot_pos[j]%3+3*i]!=player) ) {
				bot_clear_cnt[bot_moves+j]++;
			}
		}
	}
	
	//�������� ����� � ������� �� ������� ������ ����� ������� ������; �������� pl_clear_cnt[]=2: ��� ������ �������, ���� ������� ������
	for (int j=0; j<pl_moves; j++) {
		for (int i=0; i<3; i++) {
			if ( (fld[pl_pos[j]/3*3+i]!=bot) && (fld[pl_pos[j]/3*3+i]!=player) ) {
				pl_clear_cnt[j]++;
			}
			
			if ( (fld[pl_pos[j]%3+3*i]!=bot) && (fld[pl_pos[j]%3+3*i]!=player) ) {
				pl_clear_cnt[pl_moves+j]++;
			}
		}
	}
	
	//���������� "���������" ����� � �������� ����
	for (int i=0; i<bot_moves; i++) {
		if (bot_clear_cnt[i]==2) {
			bot_row[i]=bot_pos[i]/3;
		}
		if (bot_clear_cnt[bot_moves+i]==2) {
			bot_col[i]=bot_pos[i]%3;
		}
	}
	
	//���������� "���������" ����� � �������� ������
	for (int i=0; i<pl_moves; i++) {
		if (pl_clear_cnt[i]==2) {
			pl_row[i]=pl_pos[i]/3;
		}
		if (pl_clear_cnt[pl_moves+i]==2) {
			pl_col[i]=pl_pos[i]%3;
		}
	}


	
	//�������� ���������� �� ������� ������ ����� ������� ���� ��� ������ � ���������� "���������" ����������; n - ������� ����/������, ��� ������� � �����. ������ �������;
	int clear_cnt=0; //������� clear_cnt=2: ��� ������ �������, ���� ������� ����/������;
	
	//������� ��������� <0>
	for (int i=0; i<9; i+=4) {
		if ((fld[i]!=bot) && (fld[i]!=player)) {
			clear_cnt++;
		}
		if (fld[i]==bot) {
			n=i;
		}
		if (fld[i]==player) {
			n=i;
		}
	}
	if (clear_cnt==2) {
		for (int i=0; i<5; i++) {
			if (n==bot_pos[i]) {
				bot_diag[i]=0;
				break;
			}
			if (n==pl_pos[i]) {
				pl_diag[i]=0;
				break;
			}	
		}
		
	}
	
	n=0;
	clear_cnt=0;
	
	//�������� ��������� <1>
	for (int i=2; i<7; i+=2) {
		if ((fld[i]!=bot) && (fld[i]!=player)) {
			clear_cnt++;
		}
		if (fld[i]==bot) {
			n=i;
		}
		if (fld[i]==player) {
			n=i;
		}
	}
	if (clear_cnt==2) {
		for (int i=0; i<5; i++) {
			if (bot_pos[i]==n) {
				bot_diag[i]=1;
				break;
			}
			if (pl_pos[i]==n) {
				pl_diag[i]=1;
				break;
			}	
		}
		
	}
	
	n=0;
	clear_cnt=0;
	
	//��� ��������� <2>
	for (int i=0; i<9; i+=2) {
		if ((fld[i]!=bot)&&(fld[i]!=player)&&(i!=4)) {
			clear_cnt++;
		}
	}
	if (clear_cnt==4) {
		for (int i=0; i<5; i++) {
			if (bot_pos[i]==4) {
				bot_diag[i]=2;
				break;
			}
			if (pl_pos[i]==4) {
				pl_diag[i]=2;
				break;
			}
		}
	}
	
	int temp[9]={-1, -1, -1, -1, -1, -1, -1, -1, -1,}, *pl_fork; //��������� ������ ������� ����� ������� � ���.������� "���������" ������� ���� � ������� ����� ������;
	
	//���������� ������� �������� ������
	//3*row+col: ���������� ����������� ������ �� ��������; (diag+row)*4, (diag+row)*2: ��������� ����., ���. �� �������; (diag-col)*2+4, (diag+col)*4: ��������� ����., ���. �� ��������;
	for (int i=0; i<pl_moves; i++) {
		for (int j=0; j<pl_moves; j++) {
			if ( (fld[(3*pl_row[i]+pl_col[j])]!=bot) && (fld[(3*pl_row[i]+pl_col[j])]!=player) && (pl_row[i]>-1) && (pl_col[j]>-1) ) {
				temp[n]=3*pl_row[i]+pl_col[j];
				n++;
			}
			
			switch (pl_diag[i]) {
				case 0: {
					if ( (fld[(pl_diag[i]+pl_row[j])*4]!=bot) && (fld[(pl_diag[i]+pl_row[j])*4]!=player) && (pl_row[i]>-1) ) {
						temp[n]=(pl_diag[i]+pl_row[j])*4;
						n++;	
					}
					
					if ( (fld[(pl_diag[i]+pl_col[j])*4]!=bot) && (fld[(pl_diag[i]+pl_col[j])*4]!=player) && (pl_col[i]>-1) ) {
						temp[n]=(pl_diag[i]+pl_col[j])*4;
						n++;	
					}
					break;
				}
				case 1: {
					if ( (fld[(pl_diag[i]+pl_row[j])*2]!=bot) && (fld[(pl_diag[i]+pl_row[j])*2]!=player) && (pl_row[i]>-1) ) {
						temp[n]=(pl_diag[i]+pl_row[j])*2;
						n++;	
					}
					
					if ( (fld[(pl_diag[i]-pl_col[j])*2+4]!=bot) && (fld[(pl_diag[i]-pl_col[j])*2+4]!=player) && (pl_col[i]>-1) ) {
						temp[n]=(pl_diag[i]-pl_col[j])*2+4;
						n++;	
					}
					break;
				}
				case 2: {
					if ( (fld[(pl_diag[i]+pl_row[j])*4]!=bot) && (fld[(pl_diag[i]+pl_row[j])*4]!=player) && (pl_row[i]>-1) ) {
						temp[n]=(pl_diag[i]+pl_row[j])*4;
						n++;	
					}
					
					if ( (fld[(pl_diag[i]+pl_col[j])*4]!=bot) && (fld[(pl_diag[i]+pl_col[j])*4]!=player) && (pl_col[i]>-1) ) {
						temp[n]=(pl_diag[i]+pl_col[j])*4;
						n++;	
					}
					
					if ( (fld[(pl_diag[i]+pl_row[j])*2]!=bot) && (fld[(pl_diag[i]+pl_row[j])*2]!=player) && (pl_row[i]>-1) ) {
						temp[n]=(pl_diag[i]+pl_row[j])*2;
						n++;	
					}
					
					if ( (fld[(pl_diag[i]-pl_col[j])*2+4]!=bot) && (fld[(pl_diag[i]-pl_col[j])*2+4]!=player) && (pl_col[i]>-1) ) {
						temp[n]=(pl_diag[i]-pl_col[j])*2+4;
						n++;	
					}
					break;
				}
			}
		}
	}
	
	//������ ����� ����� ������
	pl_fork = new int[n];
	for (int i=0; i<n; i++) {
		pl_fork[i]=temp[i];
		temp[i]=-1;
	}
	size_t pl_size; //���-�� ��-�� � ������� ����� ����� ������
	pl_size=n;
	n=0;
	
	
	clear_cnt=0;
	//���������� "���������" ����� ����, �� ���������� ������ ����� ������
	for (int i=0; i<bot_moves; i++) {
		if (bot_row[i]>-1) {
			for (int j=0; j<3; j++) {
				if (fld[bot_row[i]*3+j]!=bot) {
					for (int k=0; k<pl_size; k++) {
						if (((bot_row[i]*3+1)*3-bot_pos[i]-(bot_row[i]*3+j))!=pl_fork[k]) {
							clear_cnt++;
						}
					}
					if (clear_cnt==pl_size) {
						temp[n]=bot_row[i]*3+j;
						n++;
					}
				}
				clear_cnt=0;
			}
		}
		if (bot_col[i]>-1) {
			for (int j=0; j<3; j++) {
				if (fld[bot_col[i]+3*j]!=bot) {
					for (int k=0; k<pl_size; k++) {
						if (((bot_col[i]+3)*3-bot_pos[i]-(bot_col[i]+3*j))!=pl_fork[k]) {
							clear_cnt++;
						}
					}
					if (clear_cnt==pl_size) {
						temp[n]=bot_col[i]+3*j;
						n++;
					}
				}
				clear_cnt=0;
			}	
		}
		if (bot_diag[i]>-1) {
			if (bot_diag[i]!=2) {
				for (int j=0; j<3; j++) {
					if (fld[2*(bot_diag[i]+j*(2-bot_diag[i]))]!=bot) {
						for (int k=0; k<pl_size; k++) {
							if (12-bot_pos[i]-(2*(bot_diag[i]+j*(2-bot_diag[i])))!=pl_fork[k]) {
								clear_cnt++;	
							}
						}
						if (clear_cnt==pl_size) {
							temp[n]=2*(bot_diag[i]+j*(2-bot_diag[i]));
							n++;
						}	
					}
					clear_cnt=0;
				}
			}
			else {
				for (int j=0; j<5; j++) {
					if (j!=2) {
						for (int k=0; k<pl_size; k++) {
							if (8-2*j!=pl_fork[k]) {
								clear_cnt=0;	
							}
						}
						if (clear_cnt==pl_size) {
							temp[n]=2*j;
							n++;
						}
					}
					clear_cnt=0;
				}
			}		
		}
	}
	
	delete[] pl_fork;
	
	//����� ���������� ���� ��� "����������" ����� ����
	if (n==0) {
		return -1;
	}
	else {
		srand(time(NULL));
		return temp[rand()%n];
	}

}

int BotFork (char fld[9], char player, char bot) {
	int bot_moves=0, n=0, move=-1; //���-�� �����, ��������� �����; ������ ��� ������ � �����; �������� ����� ���� � ����� ����;  ������� �������� (����. ��� ����.); ��������� ������ ��� ���������� ������� ��������; ��������� ����;
	
	for (int i=0; i<9; i++) {
		if (fld[i]==bot) {
			bot_moves++;
		}
	}
	
	int row[bot_moves], col[bot_moves], diag[bot_moves], pos[bot_moves];  //����� ����� �������� ������� ���� - ��� �������� �����;
	//������������� �����: <-1> - ����. �� �������� ���������
	for (int i=0; i<bot_moves; i++) {
		row[i]=-1;
		col[i]=-1;
		diag[i]=-1;
	}
	
	int clear_cnt[bot_moves*2]; //�������� ������ �����;
	//��������� ���������;
	for (int i=0; i<bot_moves*2; i++) {
		clear_cnt[i]=0;
	}
	
	//��������� ������ ����
	for (int i=0; i<9; i++) {
		if (fld[i]==bot) {
			pos[n]=i;
			n++;
		}
		if (n==bot_moves) {
			break;
		}
	}
	n=0;
	
	//�������� ����� � ������� �� ������� ������ ����� ������� ����; �������� clear_cnt[]=2: ��� ������ �������, ���� ������� ����
	for (int j=0; j<bot_moves; j++) {
		for (int i=0; i<3; i++) {
			if ( (fld[pos[j]/3*3+i]!=bot) && (fld[pos[j]/3*3+i]!=player) ) {
				clear_cnt[j]++;
			}
			
			if ( (fld[pos[j]%3+3*i]!=bot) && (fld[pos[j]%3+3*i]!=player) ) {
				clear_cnt[bot_moves+j]++;
			}
		}
	}
	
	//���������� "���������" ����� � �������� ����
	for (int i=0; i<bot_moves; i++) {
		if (clear_cnt[i]==2) {
			row[i]=pos[i]/3;
		}
		if (clear_cnt[bot_moves+i]==2) {
			col[i]=pos[i]%3;
		}
	}
	
	
	//�������� ���������� �� ������� ������ ����� ������� ���� � ���������� "���������" ����������; n - ������� ���� ��� ������� � �����. ������ �������;
	clear_cnt[0]=0; //������� clear_cnt=2: ��� ������ �������, ���� ������� ����;
	
	//������� ��������� <0>
	for (int i=0; i<9; i+=4) {
		if ((fld[i]!=bot) && (fld[i]!=player)) {
			clear_cnt[0]++;
		}
		if (fld[i]==bot) {
			n=i;
		}
	}
	if (clear_cnt[0]==2) {
		for (int i=0; i<5; i++) {
			if (n==pos[i]) {
				diag[i]=0;
				break;
			}	
		}	
	}
	n=0;
	clear_cnt[0]=0;
	
	//�������� ��������� <1>
	for (int i=2; i<7; i+=2) {
		if ((fld[i]!=bot) && (fld[i]!=player)) {
			clear_cnt[0]++;
		}
		if (fld[i]==bot) {
			n=i;
		}
	}
	if (clear_cnt[0]==2) {
		for (int i=0; i<5; i++) {
			if (pos[i]==n) {
				diag[i]=1;
				break;
			}	
		}	
	}	
	n=0;
	clear_cnt[0]=0;
	
	//��� ��������� <2>
	for (int i=0; i<9; i+=2) {
		if ((fld[i]!=bot)&&(fld[i]!=player)&&(i!=4)) {
			clear_cnt[0]++;
		}
	}
	if (clear_cnt[0]==4) {
		for (int i=0; i<5; i++) {
			if (pos[i]==4) {
				diag[i]=2;
				break;
			}
		}
	}
	
	int temp[9]={-1, -1, -1, -1, -1, -1, -1, -1, -1,}, *fork; //��������� ������ ������� ����� ������� � ���.������ ������� ����� ����;
	
	//���������� ������� �������� ������
	//3*row+col: ���������� ����������� ������ �� ��������; (diag+row)*4, (diag+row)*2: ��������� ����., ���. �� �������; (diag-col)*2+4, (diag+col)*4: ��������� ����., ���. �� ��������;
	for (int i=0; i<bot_moves; i++) {
		for (int j=0; j<bot_moves; j++) {
			if ( (fld[(3*row[i]+col[j])]!=bot) && (fld[(3*row[i]+col[j])]!=player) && (row[i]>-1) && (col[j]>-1) ) {
				temp[n]=3*row[i]+col[j];
				n++;
			}
			
			switch (diag[i]) {
				case 0: {
					if ( (fld[(diag[i]+row[j])*4]!=bot) && (fld[(diag[i]+row[j])*4]!=player) && (row[i]>-1) ) {
						temp[n]=(diag[i]+row[j])*4;
						n++;	
					}
					
					if ( (fld[(diag[i]+col[j])*4]!=bot) && (fld[(diag[i]+col[j])*4]!=player) && (col[i]>-1) ) {
						temp[n]=(diag[i]+col[j])*4;
						n++;	
					}
					break;
				}
				case 1: {
					if ( (fld[(diag[i]+row[j])*2]!=bot) && (fld[(diag[i]+row[j])*2]!=player) && (row[i]>-1) ) {
						temp[n]=(diag[i]+row[j])*2;
						n++;	
					}
					
					if ( (fld[(diag[i]-col[j])*2+4]!=bot) && (fld[(diag[i]-col[j])*2+4]!=player) && (col[i]>-1) ) {
						temp[n]=(diag[i]-col[j])*2+4;
						n++;	
					}
					break;
				}
				case 2: {
					if ( (fld[(diag[i]+row[j])*4]!=bot) && (fld[(diag[i]+row[j])*4]!=player) && (row[i]>-1) ) {
						temp[n]=(diag[i]+row[j])*4;
						n++;	
					}
					
					if ( (fld[(diag[i]+col[j])*4]!=bot) && (fld[(diag[i]+col[j])*4]!=player) && (col[i]>-1) ) {
						temp[n]=(diag[i]+col[j])*4;
						n++;	
					}
					
					if ( (fld[(diag[i]+row[j])*2]!=bot) && (fld[(diag[i]+row[j])*2]!=player) && (row[i]>-1) ) {
						temp[n]=(diag[i]+row[j])*2;
						n++;	
					}
					
					if ( (fld[(diag[i]-col[j])*2+4]!=bot) && (fld[(diag[i]-col[j])*2+4]!=player) && (col[i]>-1) ) {
						temp[n]=(diag[i]-col[j])*2+4;
						n++;	
					}
					break;
				}
			}
		}
	}	
	
	if (n==0) {
		return -1;
	}
	else {
		srand(time(NULL));
		return temp[rand()%n];	
	}	
}

int FreeMove (char fld[9], char player, char bot) {
	int free[9], n=0;
	
	for (int i=0; i<9; i++) {
		if ((fld[i]!=player)&&(fld[i]!=bot)) {
			free[n]=i;
			n++;
		}
	}
	
	srand(time(NULL));
	return free[rand()%n];
}

int CheckWin (char fld[9]) {
	return ( ((fld[0]==fld[1])&&(fld[0]==fld[2])) || ((fld[3]==fld[4])&&(fld[3]==fld[5])) || ((fld[6]==fld[7])&&(fld[6]==fld[8])) || 
	((fld[0]==fld[3])&&(fld[0]==fld[6])) || ((fld[1]==fld[4])&&(fld[1]==fld[7])) || ((fld[2]==fld[5])&&(fld[2]==fld[8])) || 
	((fld[0]==fld[4])&&(fld[0]==fld[8])) || ((fld[2]==fld[4])&&(fld[2]==fld[6])) );
}

void Hello () {
		cout<<endl<<""
			  "-///`         ://:                                                            -///`                                                -/++/:.            \n"
			  "yMMMd.        NMMM                                                            hMMM/              .+++-                          `sNMMMMMMMm/          \n"
			  "yMMMMN:       NMMM                                                            hMMM/              +MMMs                          dMMMmsoyNMMM+         \n"
			  "yMMMMMMo      NMMM         `----`        `...      `...        .-:-` `...     hMMM/ `---`       .oMMMy.`        .----`         -MMMm    :MMMd         \n"
			  "yMMMmMMMh`    NMMM      .smMMMMMMms.     yMMM+     dMMM-    `omMMMMMddMMM+    hMMMhmMMMMMd+    .MMMMMMMM`    +dNMMMMMMNdo-     .MMMN`    ...`         \n"
			  "yMMM/+NMMm-   NMMM     :NMMMmhydMMMN/    yMMM+     dMMM-    dMMMNysymMMMM+    hMMMMmhydNMMMy   `ydMMMmhy`   yMMMmysshmMMm:      yMMMh`                \n"
			  "yMMM/ -mMMN+  NMMM     mMMM/    :MMMN`   yMMM+     dMMM-   :MMMm`    dMMM+    hMMMs    -NMMM.    +MMMs      NMMN.     ./      `omMMMMm/    sddd`      \n"
			  "yMMM/  `hMMMy`NMMM    `MMMN      mMMM-   yMMM+     dMMM-   /MMMy     yMMM+    hMMM/     dMMM-    +MMMs      sMMMMNNNmdho-    `dMMMdmMMMm/  mMMN       \n"
			  "yMMM/    oNMMdNMMM    .MMMN      mMMM-   yMMM+     dMMM-   /MMMy     yMMM+    hMMM/     dMMM-    +MMMs       :shdmmNNMMMMo   /MMMy  /mMMMdsMMMy       \n"
			  "yMMM/     :NMMMMMM     NMMM-    .NMMN`   sMMMs    `mMMM-   :MMMd     hMMM+    hMMM/     dMMM-    +MMMs      `/`      -NMMm   +MMMy    +mMMMMMm.       \n"
			  "yMMM/      .dMMMMM     +MMMNyooyNMMMo    -NMMMhoosmMMMM-   `mMMMdo++hMMMM+    hMMM/     dMMM-    /MMMmso   /mMNds+++odMMMy   `mMMMds+++yMMMMMd-       \n"
			  "yMMM/        sMMMM      :hNMMMMMMMd/      -dMMMMMMNNMMM-    .yNMMMMMNNMMM+    hMMM/     dMMM-    `yMMMMM`  -smMMMMMMMMMmo`    `smMMMMMMMMNyNMMMy.     \n"
			  ".:::`         -:::        `:/++/:`          .:/+/- -:::       `:+++:`hMMM/    .:::`     -:::`      .://:      `-/+++/:.          .:/++/:.  `::::.     \n"
			  "                                                            -yNh/--/yMMMd                                                                             \n"
			  "   `/shdddyo-            -oyddddyo-                         +mMMMMMMMMNs`                                                                             \n"
			  "  :mMMMMMMMMMh`        /mMMMMMMMMMMd:                         -+ssso+-                                                                                \n"
			  "`NMMMo-.:hMMMy       oMMMNo:..:sNMMMo                                                                                                                 \n"
			  "-MMMm    .hhhs      .NMMN-      .mNNm.   -ooo:.+sss+-     ./ossso/.         -+ossss+:.       `/osssso/-                                               \n"
			  "`NMMN-              /MMMd                +MMMNMMMMMMm-  -hMMMMMMMMMd-     /mMMMMMMMMMMm-   `yNMMMMMMMMMNy                                             \n"
			  "sMMMN/     `--.     /MMMd                +MMMNs/:/ys`  .NMMNy/:/yNMMN-   .NMMm+--:/sdm/    sMMMy:--:+yNy.                                             \n"
			  ":mMMMMMMh-   dMMM`  /MMMd                +MMMy         sMMMs     oMMMs   .MMMm+//:-.`      yMMMy+/::-.                                                \n"
			  "NMMN+oNMMMh-`NMMm   /MMMd                +MMMy         yMMM+     /MMMy    +NMMMMMMMMMm+    .hMMMMMMMMMNh-                                             \n"
			  "MMMo  `oNMMMmMMM+   -MMMN`       yhhh.   +MMMy         yMMM+     +MMMy      -/+oosymMMMo     .:++osshNMMN`                                            \n"
			  "MMMm-   `sMMMMMh     yMMMm/`  `:dMMMh    +MMMy         /MMMm-   -mMMM+    oh/.     +MMMy   .hs:`    `dMMM.                                            \n"
			  "sMMMMNdddNMMMMMNs`    sNMMMMNNMMMMNo     +MMMy          sMMMMNmNMMMMs   `hMMMMNdddNMMMN-  :NMMMNmddmNMMMy                                             \n"
			  " -sdNMMMNmhs:sNNNm/    .+hNMMMNmy+`      /NNNo           -sdNMMMNds-      :shmNMMMNmh+`    .+ydNMMMMNds:                                              \n"
			  "      ``                    ```                                `                ``               ```                                                  \n"
			  "===========================================================================================================\n"
			  "===========================================================================================================\n"<<endl;
		cout<<"		RULES:\nYou are playing against a bot. Before the game, you select the bot level and who to play.\n"
			"During the game, you choose the number of the field where you want to make a move (Cross make the first move).\n"
			"The task: Collect 3 your signs in a line faster than a bot.\n"<<endl;
		cout<<"===========================================================================================================\n"<<endl;
		cout<<"		INFO:\nBot level: 1 - easy, 2 - normal, 3 - hard;\n\nField:		How to collect signs for victory: columns, rows, diagonals;\n"
			"1|2|3		X| | 		X|X|X		X| | \n"
			"-+-+-		-+-+-		-+-+-		-+-+-\n"
			"4|5|6		X| | 		 | | 		 |X| \n"
			"-+-+-		-+-+-		-+-+-		-+-+-\n"
			"7|8|9		X| | 		 | | 		 | |X\n"<<endl;
		cout<<"===========================================================================================================\n"<<endl;	
}

void Display(char fld[9], char player, char bot) {
	cout<<endl<<"==================================="<<endl;
	for (int i=0; i<9; i++) {
		if ((fld[i]==bot) || (fld[i]==player)) {
			cout<<fld[i];	
		}
		else {
			cout<<" ";
		}
		
		if (i%3!=2) {
			cout<<"|";
		}
		else {
			if (i!=8)
				cout<<endl<<"-+-+-";
			cout<<endl;
		}		
	}			
	cout<<"==================================="<<endl<<endl;
}
