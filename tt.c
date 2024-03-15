#include "libft/libft.h"
#include "mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
typedef struct Enemy {
    int x;
    int y;
} Enemy;
#define INTERVAL_MS 10000 // Interval in milliseconds (1 second)
int delay_counter = 0; // Counter to track the delay
void tt(void *mlx, void *win, void *image, void *icon, void *door, char **maap) {
    int x = 0;
    int y = 0;
    int m_x = 0;
    int m_y = 0;
    while (maap[m_y]) {
        m_x = 0;
        x = 0;
        while (maap[m_y][m_x]) {
            if (maap[m_y][m_x] == '1')
                mlx_put_image_to_window(mlx, win, image, x, y);
            if (maap[m_y][m_x] == 'C')
                mlx_put_image_to_window(mlx, win, icon, x, y);
            if (maap[m_y][m_x] == 'E')
                mlx_put_image_to_window(mlx, win, door, x, y);
            x += 64;
            m_x++;
        }
        m_y++;
        y += 64;
    }
}

void tt_palyer(void *mlx, void *win, int *playerPosition, char **maap) {
    int x = 0;
    int y = 0;
    int m_x = 0;
    int m_y = 0;
    while (maap[m_y]) {
        m_x = 0;
        x = 0;
        while (maap[m_y][m_x]) {
            if (maap[m_y][m_x] == 'P') {
                playerPosition[0] = x;
                playerPosition[1] = y;
                playerPosition[2] = m_x;
                playerPosition[3] = m_y;
            }
            x += 64;
            m_x++;
        }
        m_y++;
        y += 64;
    }
}

void draw_score(void *mlx, void *win, int score) {
    char score_str[50];
    sprintf(score_str, "Score: %d", score);
    mlx_string_put(mlx, win, 1, 1, 0x000000, score_str);
}

void draw_enemy(void *mlx, void *win, void *enemy_img, int enemy_x, int enemy_y) {
    mlx_put_image_to_window(mlx, win, enemy_img, enemy_x, enemy_y);
}

void move_enemy(Enemy *enemy) {
    //enemy->x = enemy->x + (rand() % 3 - 1) * 64; // Move left, right, or stay in the same position
    int i=1000;
    
    enemy->y = 64;
    if(enemy->x==64)
        enemy->x+=64;
    else if(enemy->x==128)
        enemy->x+=64;
    else if(enemy->x==192) 
        enemy->x+=64;  
    else
         enemy->x=64;
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
    int *game_won = ((int **)param)[11]; 
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
        *score += 10; // Increase the score
        printf("Score: %d\n", *score);
        // Destroy the coin image
       // mlx_destroy_image(mlx, coins);
        str[playerPosition[3]][playerPosition[2]]='0';
    }
   // Check for collision with exit gate
    if (str[playerPosition[3]][playerPosition[2]]=='E'&&*score==10)
    {
        game_won=1;
        //exit(0);
    }

    // Redraw the player at the new position
    mlx_clear_window(mlx, win);
    if(*score==10)
        tt(mlx, win, wall_img,coins,door_open,str);
    else
        tt(mlx, win, wall_img,coins,door,str);
    draw_score(mlx, win, *score);
    // Animation: Cycle through player frames
    *frame = (*frame + 1) % 4;

        mlx_put_image_to_window(mlx, win, player_img[*direction][*frame], playerPosition[0], playerPosition[1]);


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
int main() {
    // Open the map file
    int fd = open("map1.ber", O_RDONLY);
    char **str = ft_split(get_next_line(fd), '\n');

    // Initialize variables and resources
    void *mlx;
    void *win;
    int width, height;
    void *wall_img;
    void *coins;
    void *door;
    void *door_open;
    void *enemy_img;
    void ***player_imgs;
    int playerPosition[4];
    int score = 0;
    int direction = 0; // 0: up, 1: down, 2: left, 3: right
    int frame = 0;

    // Initialize the enemy
    Enemy enemy;
    enemy.x = 256; // Initial x position of the enemy
    enemy.y = 128; // Initial y position of the enemy

    // Initialize MiniLibX
    mlx = mlx_init();
    win = mlx_new_window(mlx, 832, 320, "map1");

    // Load images for game elements
    wall_img = mlx_xpm_file_to_image(mlx, "walls.xpm", &width, &height);
    door = mlx_xpm_file_to_image(mlx, "dooor.xpm", &width, &height);
    door_open = mlx_xpm_file_to_image(mlx, "door_open.xpm", &width, &height);
    coins = mlx_xpm_file_to_image(mlx, "coin.xpm", &width, &height);
    enemy_img = mlx_xpm_file_to_image(mlx, "enemy.xpm", &width, &height);
    void *you_won_img = mlx_xpm_file_to_image(mlx, "enemy.xpm", &width, &height);
    int game_won = 0;
    // Load player images for each direction and frame
    player_imgs = (void ***)malloc(4 * sizeof(void **));
    for (int i = 0; i < 4; i++) {
        player_imgs[i] = (void **)malloc(4 * sizeof(void *));
        for (int j = 0; j < 4; j++) {
            char filename[20];
            snprintf(filename, sizeof(filename), "player_%d_%d.xpm", i, j);
            player_imgs[i][j] = mlx_xpm_file_to_image(mlx, filename, &width, &height);
            if (!player_imgs[i][j]) {
                fprintf(stderr, "Failed to load player image\n");
                return 1;
            }
        }
    }

    // Find player's initial position
    tt_palyer(mlx, win, playerPosition, str);

    // Display player at initial position
    mlx_put_image_to_window(mlx, win, player_imgs[0][0], playerPosition[0], playerPosition[1]);

    // Display game elements (walls, coins, doors)
    tt(mlx, win, wall_img, coins, door, str);

    // Display initial score
    draw_score(mlx, win, score);

    // Set up parameters for event handling
    void *param[] = {mlx, win, player_imgs, wall_img, coins, str, playerPosition, &score, door, door_open, &direction, &frame};

    // Set up event handling for key presses
    mlx_hook(win, 2, 1L << 0, deal_key, param);

    // Main game loop
    // Main game loop
while (1) {
    // Clear the game window
    mlx_clear_window(mlx, win);

    // Update the player's position and handle collisions
    deal_key(0, param); // This is a placeholder. You need to replace it with your actual player movement logic.

    // Check if the game is won
    if (score == 10 && str[playerPosition[3]][playerPosition[2]] == 'E') {
        game_won = 1;
    }

  



    mlx_loop_hook(mlx, delayed_exit, NULL);

  
    // Move and render the enemy
    move_enemy(&enemy);
    draw_enemy(mlx, win, enemy_img, enemy.x, enemy.y);

    // Redraw other game elements
    if (score == 10)
        tt(mlx, win, wall_img, coins, door_open, str);
    else
        tt(mlx, win, wall_img, coins, door, str);
    draw_score(mlx, win, score);
    frame = (frame + 1) % 4;
    mlx_put_image_to_window(mlx, win, player_imgs[direction][frame], playerPosition[0], playerPosition[1]);

    mlx_do_sync(mlx); // Update the display
}



    return 0;
}
