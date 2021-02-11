// #include "mlx.h"
// int main()
// {
//     void *mlx;//スクリーン接続識別子
//     void *mlx_win;//ウィンドウ識別子
//     int i;
//     int j;
//     int width = 1000; //ウィンドウのサイズ
//     int height = 1000;

//     //[# mlx_new_window - ウィンドウの作成]
//     //   mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title )
//     //   int       mlx_clear_window ( void *mlx_ptr, void *win_ptr )
//     //   int       mlx_destroy_window ( void *mlx_ptr, void *win_ptr )
//     mlx = mlx_init();//fileopenの時のfd的な？
//     mlx_win = mlx_new_window(mlx, width, height,"test");
//     // mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
//     //座標は左上が原点、矢印はx軸が右、y軸が下向きになる
//     //でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
//     i= 0;
//     while (i < width)
//     {
//             j = 0;
//             while (j < height)
//             {
//                     mlx_pixel_put(mlx, mlx_win, i, j, 127);
//                     j++;
//             }
//             i++;
//     }
//     mlx_loop(mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
//     //最初のうちはcntl+Cで強制終了すればおk
//     //クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
//     return (1);
// }

// #include "mlx.h"

// int		main(void)
// {
// 	void	*mlx;
// 	void	*win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "mlx_project");
// 	mlx_loop(mlx);
// }






#include <stdio.h>
#include <stdlib.h>
#include "./mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

//Since key_press() can recieve only one argument, all the argument shold be gathered in one structure
//x,y and str are meaningless variables.
typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;

//Only param->x will be used. 
void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_W)//Action when W key pressed
		param->x++;
	else if (keycode == KEY_S) //Action when S key pressed
		param->x--;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int			main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	printf("-------------------------------\n");
	printf("'W key': Add 1 to x.\n");
	printf("'S key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 3\n");
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx);
}
