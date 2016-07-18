#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[])
{

	    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        return -1;
    }

    //绘制窗口
    SDL_Window *win = NULL;
    win = SDL_CreateWindow("Helloworld",0,0,800,800,SDL_WINDOW_SHOWN);
    if(win)
    {
        printf("create window success\n");
		pause();
        return -1;
    }
	else
	{
		printf("create window failed\n");
	}


    // SDL_Renderer *render = NULL;
    // render = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // if(render == NULL)
    // {
    //     return -1;
    // }
	//
    // SDL_Surface *bmp = NULL;
    // bmp = SDL_LoadBMP("/Users/duanzw/stu/sdl2/dragon.jpg");
    // if(bmp == NULL)
    // {
	// 	printf("-----------\n");
    //     return -1;
    // }
	//
    // SDL_Texture *tex = NULL;
    // tex = SDL_CreateTextureFromSurface(render,bmp);
    // SDL_FreeSurface(bmp);
    // SDL_RenderClear(render);
    // SDL_RenderCopy(render,tex,NULL,NULL);
    // SDL_RenderPresent(render);
	//
    // SDL_Delay(2000);
    // SDL_DestroyTexture(tex);
    // SDL_DestroyRenderer(render);
    // SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
