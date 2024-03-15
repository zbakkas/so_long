#include "libft/libft.h"
#include "mlx.h"
typedef struct Enemy {
    int x;
    int y;
    int m_x;
    int m_y;
} Enemy;
typedef struct Enemy2 {
    int x;
    int y;
    int m_x;
    int m_y;
} Enemy2;
#define INTERVAL_MS 10000
#define INTERVAL_ENEMY 1
int delay_counter =0; 
void tt(void *mlx, void *win, void *image,void *icon,void *door,char **maap)
{
    int x=0;
    int y=0;
    int m_x=0;
    int m_y=0;
    while (maap[m_y])
    {
        m_x=0;
        x=0;
        while (maap[m_y][m_x])
        {
            if(maap[m_y][m_x]=='1')
                mlx_put_image_to_window(mlx, win, image, x, y); 
            if(maap[m_y][m_x]=='C')
                mlx_put_image_to_window(mlx, win, icon, x, y); 
            if(maap[m_y][m_x]=='E')
                mlx_put_image_to_window(mlx, win, door, x, y); 
            x+=64;
            m_x++;
        }
        m_y++;
        y+=64;  
    }
}
void tt_palyer(void *mlx, void *win,int *playerPosition ,char **maap)
{
    int x=0;
    int y=0;
    int m_x=0;
    int m_y=0;
    while (maap[m_y])
    {
        m_x=0;
        x=0;
        while (maap[m_y][m_x])
        {
            if(maap[m_y][m_x]=='P')
            {
                playerPosition[0]=x;
                playerPosition[1]=y;
                playerPosition[2]=m_x;
                playerPosition[3]=m_y;

            }
            x+=64;
            m_x++;
        }
        m_y++;
        y+=64;  
    }
}
void tt_enemey(void *mlx, void *win,Enemy *enemy ,char **maap)
{
    int x=0;
    int y=0;
    int m_x=0;
    int m_y=0;
    int i=0;
    while (maap[m_y])
    {
        m_x=0;
        x=0;
        while (maap[m_y][m_x])
        {
            if(maap[m_y][m_x]=='M')
            {
                enemy->x=x;
                enemy->y=y;
                enemy->m_x=m_x;
                enemy->m_y=m_y;
                maap[m_y][m_x]='0';
                i=1;
                break;
            }
            x+=64;
            m_x++;
        }
        if(i==1)
            break;
        m_y++;
        y+=64;  
    }
}
void tt_enemey2(void *mlx, void *win,Enemy2 *enemy ,char **maap)
{
    int x=0;
    int y=0;
    int m_x=0;
    int m_y=0;
    int i=0;
    while (maap[m_y])
    {
        m_x=0;
        x=0;
        while (maap[m_y][m_x])
        {
            if(maap[m_y][m_x]=='M')
            {
                enemy->x=x;
                enemy->y=y;
                enemy->m_x=m_x;
                enemy->m_y=m_y;
                maap[m_y][m_x]='0';
                i=1;
                break;
            }
            x+=64;
            m_x++;
        }
        if(i==1)
            break;
        m_y++;
        y+=64;  
    }
}
void move_enemy(Enemy *enemy,int x,int y,char **map,int *l) {
    //enemy->x = enemy->x + (rand() % 3 - 1) * 64; // Move left, right, or stay in the same position
    int m_x=enemy->m_x;
    int m_y =enemy->m_y;
   // enemy->y = 64;
    if(map[m_y][m_x+1]=='1')
        *l=1;
    if(map[m_y][m_x-1]=='1')
        *l=0;        
    if(map[m_y][m_x+1]!='1'&&!*l)
    {
        map[m_y][m_x+1]='M';
        map[m_y][m_x]='0';
        enemy->m_x++;
        enemy->x+=64;
    }
    else if(map[m_y][m_x-1]!='1'&&*l)
    {
        map[m_y][m_x-1]='M';
        map[m_y][m_x]='0';
        enemy->m_x--;
        enemy->x-=64;
    }
}
// Function to draw the score
void move_enemy2(Enemy2 *enemy,int x,int y,char **map,int *l) {
    //enemy->x = enemy->x + (rand() % 3 - 1) * 64; // Move left, right, or stay in the same position
    int m_x=enemy->m_x;
    int m_y =enemy->m_y;
   // enemy->y = 64;
    if(map[m_y][m_x+1]=='1')
        *l=1;
    if(map[m_y][m_x-1]=='1')
        *l=0;        
    if(map[m_y][m_x+1]!='1'&&!*l)
    {
        map[m_y][m_x+1]='M';
        map[m_y][m_x]='0';
        enemy->m_x++;
        enemy->x+=64;
    }
    else if(map[m_y][m_x-1]!='1'&&*l)
    {
        map[m_y][m_x-1]='M';
        map[m_y][m_x]='0';
        enemy->m_x--;
        enemy->x-=64;
    }
}
void draw_score(void *mlx, void *win, int score)
{
    char score_str[50];
    sprintf(score_str, "Score: %d", score);
    mlx_string_put(mlx, win, 1, 1, 0x000000, score_str);
}
int deal_key(int key, void *param)
{
    // Unpack parameters
    void *mlx = ((void **)param)[0];
    void *win = ((void **)param)[1];
    void ***player_img = ((void **)param)[2];
    void *wall_img = ((void **)param)[3];
    void *coins = ((void **)param)[4];
    char **str = ((char ***)param)[5];
    int *playerPosition = ((int **)param)[6];
    int *score=((int **)param)[7];
    void *door = ((void **)param)[8];      
    void *door_open = ((void **)param)[9]; 
    int *direction = ((int **)param)[10];
    int *frame = ((int **)param)[11];  
    int *game_won = ((int **)param)[12]; 

    if(key ==53)
        exit(0);
    //printf("%c\n",str[playerPosition[3]-1][playerPosition[2]]);
    printf("xx==%d",playerPosition[2]);
    printf("yy==%d\n",playerPosition[3]);
    if(key ==126&& str[playerPosition[3]-1][playerPosition[2]]!='1')
    {
        *direction = 0;
        playerPosition[3]-=1;
        playerPosition[1] -= 64; // up   
    }
    if(key ==125&&str[playerPosition[3]+1][playerPosition[2]]!='1')
    {
        *direction = 1; // Down
        playerPosition[3]+=1;
        playerPosition[1] += 64; 

    }
    if(key ==123&&str[playerPosition[3]][playerPosition[2]-1]!='1')
    {
        *direction = 2; // Left
        playerPosition[2]-=1;
        playerPosition[0] -= 64; 
    }
    if(key ==124&&str[playerPosition[3]][playerPosition[2]+1]!='1')
    {
        *direction = 3; // Right
        playerPosition[2]+=1;
        playerPosition[0] += 64; 
    }

    // Check for collision with coin
    if (str[playerPosition[3]][playerPosition[2]]=='C')
    {
        str[playerPosition[3]][playerPosition[2]]='0';

        *score += 10; // Increase the score
        printf("Score: %d\n", *score);
        // Destroy the coin image
        //mlx_destroy_image(mlx, coins);
    }
   // Check for collision with exit gate
    if (str[playerPosition[3]][playerPosition[2]]=='E'&&*score==30)
    {
        *game_won = 1;
        //exit(0);
    }
    if (str[playerPosition[3]][playerPosition[2]]=='M')
    {
        
        exit(0);
    }
    // Redraw the player at the new position
    mlx_clear_window(mlx, win);
    if(*score==30)
        tt(mlx, win, wall_img,coins,door_open,str);
    else
        tt(mlx, win, wall_img,coins,door,str);
    draw_score(mlx, win, *score);
    // Animation: Cycle through player frames
    *frame = (*frame + 1) % 4;

        //mlx_put_image_to_window(mlx, win, player_img[*direction][*frame], playerPosition[0], playerPosition[1]);


    return 0;
}
int delayed_exit(void *param) {
    if (delay_counter < INTERVAL_MS) {
        delay_counter++;
        return 0; // Continue delaying
    } else {
        // Exit the program after one second
        exit(0);
    }
}
int main()
{
    int fd = open("map1.ber", O_RDONLY);
    char **str =ft_split(get_next_line(fd),'\n');
    
    void *mlx;
    void *win;

   void *wall_img;
   void *coins;
   void *door;
   void *door_open;
    int width, height;
    int playerPosition[4];
    void ***player_imgs;
    int score=0;
    void *enemy_img;
    void *enemy_img2;
    void *enemy_img3;
    // Initialize the enemy
    Enemy enemy;
    Enemy2 enemy2;
    Enemy enemy3;

    int direction = 0; // 0: up, 1: down, 2: left, 3: right
    int frame = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 832, 1088, "map1");


    wall_img = mlx_xpm_file_to_image(mlx, "walls.xpm", &width, &height);//
    door = mlx_xpm_file_to_image(mlx, "dooor.xpm", &width, &height);//
    door_open = mlx_xpm_file_to_image(mlx, "door_open.xpm", &width, &height);//
    coins = mlx_xpm_file_to_image(mlx, "coin.xpm", &width, &height);//
    enemy_img = mlx_xpm_file_to_image(mlx, "enemy.xpm", &width, &height);
    enemy_img2 = mlx_xpm_file_to_image(mlx, "enemy.xpm", &width, &height);
    enemy_img3 = mlx_xpm_file_to_image(mlx, "enemy.xpm", &width, &height);
    void *you_won_img = mlx_xpm_file_to_image(mlx, "you_won.xpm", &width, &height);
int game_won = 0;
    // Load player images for each direction and frame
    player_imgs = (void ***)malloc(4 * sizeof(void **));
    for (int i = 0; i < 4; i++)
    {
        player_imgs[i] = (void **)malloc(4 * sizeof(void *));
        for (int j = 0; j < 4; j++)
        {
            char filename[20];
            snprintf(filename, sizeof(filename), "player_%d_%d.xpm", i, j);
            player_imgs[i][j] = mlx_xpm_file_to_image(mlx, filename, &width, &height);
            if (!player_imgs[i][j])
            {
                fprintf(stderr, "Failed to load player image\n");
                return 1;
            }
        }
    }


    tt_palyer(mlx, win, playerPosition,str);
    tt(mlx, win, wall_img,coins,door,str);
  //  mlx_put_image_to_window(mlx, win, player_imgs[0][0], playerPosition[0], playerPosition[1]);

   // tt(mlx, win, wall_img,coins,door,str); 
   // draw_score(mlx, win, score);

    void *param[] = {mlx, win, player_imgs, wall_img,coins,str, playerPosition,&score,door,door_open, &direction, &frame,&game_won};
    mlx_hook(win, 2, 1L << 0, deal_key, param); // Key press event
; 
    tt_enemey(mlx, win,&enemy ,str);
    tt_enemey2(mlx, win,&enemy2 ,str);
    tt_enemey2(mlx, win,&enemy3 ,str);
    int enemy_x=enemy.x;
    int enemy_y=enemy.y;
    int enemy_x2=enemy2.x;
    int enemy_y2=enemy2.y;
    int enemy_x3=enemy3.x;
    int enemy_y3=enemy3.y;
    int l=1;
    int l2=1;
    int l3=1;
    int exit_countdown = 0;


int delay_counter2 =0;
    while (1)
    {
        mlx_clear_window(mlx, win);
        deal_key(0, param); // This is a placeholder. You need to replace it with your actual player movement logic.


        if (score == 10 && str[playerPosition[3]][playerPosition[2]] == 'E') 
            game_won = 1;
        if (game_won==1) 
        {
            mlx_put_image_to_window(mlx, win, you_won_img, 300, 1088/2); // Display "You Won" image
            //delayed_exit(param);
            mlx_loop_hook(mlx, delayed_exit, NULL);
        } 
        else
        {
        draw_score(mlx, win, score);

            if(delay_counter2 < INTERVAL_ENEMY)
            {
                delay_counter2++;
            }
            else
            {
            delay_counter2=0;
            move_enemy(&enemy,enemy_x,enemy_y,str,&l);
            move_enemy2(&enemy2,enemy_x2,enemy_y2,str,&l2);
            move_enemy(&enemy3,enemy_x3,enemy_y3,str,&l3);

            mlx_put_image_to_window(mlx, win, enemy_img,enemy.x, enemy.y);
            mlx_put_image_to_window(mlx, win, enemy_img2,enemy2.x, enemy2.y);
            mlx_put_image_to_window(mlx, win, enemy_img3,enemy3.x, enemy3.y);
            }

        mlx_put_image_to_window(mlx, win, enemy_img,enemy.x, enemy.y);
        mlx_put_image_to_window(mlx, win, enemy_img2,enemy2.x, enemy2.y);
        mlx_put_image_to_window(mlx, win, enemy_img3,enemy3.x, enemy3.y);
        mlx_put_image_to_window(mlx, win, player_imgs[direction][frame], playerPosition[0], playerPosition[1]);

        }
        mlx_do_sync(mlx);
    }
    //mlx_loop(mlx);
}