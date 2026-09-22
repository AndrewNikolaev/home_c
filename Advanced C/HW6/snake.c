#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
double DELAY = 0.1;
#define NUM_ITEMS 6
#define NUM_COLOR 4

int players = 2;
int color1 = 1;
int color2 = 2;
int deathEnabled = 1;

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=5,CONTROLS=2};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
                                                    {'s', 'w', 'a', 'd'}};
const char* menu_start[NUM_ITEMS] = {"Players:","Snake 1 color:","Snake 2 color:","Death:","Start game","Exit"};
const char* colorNamesMenu[NUM_COLOR] = {"Yellow", "Blue", "Green", "White"};
const short colorCodes[NUM_COLOR] = {COLOR_YELLOW, COLOR_BLUE, COLOR_GREEN, COLOR_WHITE};
const char* status[2] = {"OFF", "ON"};
/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

/*
 Еда — это массив точек, состоящий из координат x,y, времени,
 когда данная точка была установлена, и поля, сигнализирующего,
 была ли данная точка съедена.
 */
struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void setColor(int objectType)
{
	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(3)); 
	attroff(COLOR_PAIR(4)); 
	switch (objectType){
		case 1:{ // SNAKE1
			 attron(COLOR_PAIR(1)); 
			 break; 
		} 
		case 2:{ // SNAKE2  
			attron(COLOR_PAIR(2));
			break;
		} case 3:{ // FOOD
			attron(COLOR_PAIR(3));
			break;              
		} case 4:{ // DEAD
			attron(COLOR_PAIR(4));
			break;              
		} 
	} 
} 

void resetColor()
{
	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(3));
	attroff(COLOR_PAIR(4));  	
}

int startMenu(void)
{
	WINDOW *win;
    int selected = 0;
    border(0,0,0,0, 0,0,0,0);
    move(1,1);
    mvprintw(20,40,"Use arrow keys to navigate, Enter to select.");
    refresh();
    win = newwin(10,25,10,50);
    keypad(win, TRUE);
    while (1) {
    werase(win);
    box(win, 0, 0);
    mvwprintw(win,1,10, "Menu");    
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (i == selected) wattron(win, A_REVERSE);
        switch(i)
        {
			case 0:{
				mvwprintw(win, i+3, 2, "%s %d",menu_start[i], players);
				break;  
			}
			case 1:{
				mvwprintw(win, i+3, 2, "%s %s",menu_start[i], colorNamesMenu[color1-1]);
				break;  
			}
			case 2:{
				if(players==2)
				mvwprintw(win, i+3, 2, "%s %s",menu_start[i], colorNamesMenu[color2-1]);
				else
				mvwprintw(win, i+3, 2, "%s %s",menu_start[i], "------");
				break;  
			}
			case 3:{
				mvwprintw(win, i+3, 2, "%s %s",menu_start[i],  status[deathEnabled]);
				break;  
			}
			default:{
				mvwprintw(win, i + 3, 2, "%s", menu_start[i]);
				break;
			}			
		}
        
        if (i == selected) wattroff(win, A_REVERSE);
    }
    wrefresh(win);
    int ch = wgetch(win);
    if (ch == KEY_UP) selected = (selected - 1 + NUM_ITEMS) % NUM_ITEMS;
    else if (ch == KEY_DOWN) selected = (selected + 1) % NUM_ITEMS;
    else if (ch == '\n' || ch == '\r')
    {
		switch(selected)
		{
			case 0:{
				players = (players == 1) ? 2 : 1;
				break;  
			}
			case 1:{
				color1 = (color1 % 4) + 1;
				break;  
			}
			case 2:{
				color2 = (color2 % 4) + 1;
				break;  
			}
			case 3:{
				deathEnabled = !deathEnabled;
				break;  
			}
			case 4:{
				return 0;  
			}
			case 5:{
				return 1; 
			}
		}
	} 
}
delwin(win);
return selected;
}

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
/*
 Обновить/разместить текущее зерно на поле
 */
         
void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1) + 1;
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '*';
    fp->enable = 1;
    spoint[0] = fp->point;
    setColor(3);
    mvprintw(fp->y, fp->x, "%s", spoint);    
    resetColor();
}
/*
 Разместить еду на поле
 */
void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}
void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

//========================================================================
void initSnake(snake_t *head[], size_t size, int x, int y,int i)
{
    head[i]    = (snake_t*)malloc(sizeof(snake_t));
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->tail     = tail; // прикрепляем к голове хвост
    head[i]->tsize    = size+1;
    head[i]->controls = default_controls[i];
    //~ head[i]->controls = default_controls[0];
}
/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = 'O';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
        case LEFT:
            if(head->x <= 1) // Циклическое движение, чтобы не
// уходить за пределы экрана
                head->x = max_x-1;
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
			if(head->x >= max_x-2)
				head->x = 0;
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
			if(head->y <= 1)
				head->y = max_y-1;
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
			if(head->y >= max_y-2)
				head->y = 0;
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    refresh();
}

int checkDirection(snake_t* snake,  int32_t key)
{
	if (key == snake->controls.down && snake->direction ==UP)
			return 0;
	else if (key == snake->controls.up && snake->direction ==DOWN)
			return 0;
	else if (key == snake->controls.right && snake->direction ==LEFT)
			return 0;
	else if (key == snake->controls.left && snake->direction ==RIGHT)
			return 0;
return 1;
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = 'o';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

//========================================================================
//Проверка того, является ли какое-то из зерен съеденным,
_Bool haveEat(struct snake_t *head, struct food f[], size_t size)
{
    for(size_t i=0; i<size; i++)
    {
		if( head->x ==  f[i].x && head->y == f[i].y && f[i].enable != 0)
		{
			f[i].enable = 0;
			return 1;
		}
	}
    return 0;
}

/*
 Увеличение хвоста на 1 элемент
 */

void addTail(struct snake_t *head)
{
    if (head->tsize != MAX_TAIL_SIZE)
		head->tsize +=1;
}

//Вынести тело цикла while из int main() в отдельную функцию update
//и посмотреть, как изменится профилирование
void update(struct snake_t *head, struct food f[], const int32_t key)
{
    clock_t begin = clock();
    go(head);
    goTail(head);
    if (checkDirection(head,key))
    {
        changeDirection(head, key);
    }
    refreshFood(food, SEED_NUMBER);// Обновляем еду
    if (haveEat(head,food,SEED_NUMBER))
    {
        addTail(head);
    }
    refresh();//Обновление экрана, вывели кадр анимации
    while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY)
    {}
}

_Bool isCrush(snake_t * snake)
{
	for(size_t i=1; i<snake->tsize; i++)
    {
		if( snake->x ==  snake->tail[i].x && snake->y == snake->tail[i].y)
		{
			return 1;
		}        
    }		
    return 0;
}

void deadSnake (snake_t * snake)
{
	for(size_t i=1; i<snake->tsize; i++)
    {
		mvprintw(snake->tail[i].y, snake->tail[i].x, " ");
    }
 }
 
 void drawSnake (snake_t * snake)
{
	char ch = 'o'; 
	for(size_t i=1; i<snake->tsize; i++)
    {
		mvprintw(snake->tail[i].y, snake->tail[i].x, "%c",ch);
    }
 }


void repairSeed(struct food f[], size_t nfood, struct snake_t *head)
{
    for( size_t i=0; i<head->tsize; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
			if( head->tail[i].x == f[j].x  && head->tail[i].y == f[j].y )
			{
				putFoodSeed(&f[j]);
			}   
        }
    for( size_t i=0; i<nfood; i++ )
        for( size_t j=i+1; j<nfood; j++ )
        {
			if( f[i].x == f[j].x  && f[i].y == f[j].y )
			{
				putFoodSeed(&f[i]);
			}    
        }
}


int main()
{
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    clear();
    start_color();
    use_default_colors();
    assume_default_colors(COLOR_WHITE, COLOR_BLACK);
    // Цвет пары:
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    int choice= startMenu();
    if(choice==1)
    {
		endwin(); // Завершаем режим curses mod
		return 0;
	}
	else
	{
		clear();
		refresh();
	}
	//========================================================================   
snake_t* snakes[players];
    for (int i = 0; i < players; i++)
        initSnake(snakes,START_TAIL_SIZE,10+i*10,10+i*10,i);
//========================================================================
    init_pair(1, colorCodes[color1-1],  COLOR_BLACK); // Желтый для 1 змейки
    init_pair(2, colorCodes[color2-1],    COLOR_BLACK); // Синий для 2 змейки
    init_pair(3, COLOR_GREEN, COLOR_BLACK); //Зеленый для еды
    init_pair(4, COLOR_RED,    COLOR_BLACK); // Красный для индикации смерти змейки
    border(0,0,0,0, 0,0,0,0);
    move(1,1);
    mvprintw(29,34,"|  Use arrows for control. Press 'F10' for EXIT  |");
    refresh();
    //~ getch();
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле 
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна   
    int key_pressed=0;
    while( key_pressed != STOP_GAME )
    {        
			key_pressed = getch(); // Считываем клавишу
			for (int i = 0; i < players; i++)
			{
				if(isCrush(snakes[i]) && deathEnabled==1)
				{
					setColor(4);
					for (int j=0; j<3; j++)
					{
						deadSnake(snakes[i]);
						refresh();
						napms(300);
						drawSnake(snakes[i]);
						refresh();
						napms(300);
						deadSnake(snakes[i]);
						refresh();						
					}
					resetColor();
					initSnake(snakes,START_TAIL_SIZE,10+i*10,10+i*10,i);					
				}
				setColor(i+1);
				update(snakes[i], food, key_pressed);
				resetColor();
				repairSeed(food, SEED_NUMBER, snakes[i]);
			}
	if(players==1)		          
	mvprintw(0, 0, "|Score: %d  |", snakes[0]->tsize-START_TAIL_SIZE-1);	
	else
	mvprintw(0, 0, "| Player 1: %d | Player 2: %d |", snakes[0]->tsize-START_TAIL_SIZE-1, snakes[1]->tsize-START_TAIL_SIZE-1);	          
    }
    for (int i = 0; i < players; i++)
    {
        free(snakes[i]->tail);
        free(snakes[i]);
    }
    endwin(); // Завершаем режим curses mod
    return 0;
}
