#include "print.h"
#include "trace.h"
#include "scene.h"
#include "structures.h"
#include "utils.h"


void    write_color(t_color3 pixel_color)
{
    printf("%d %d %d\n", (int)(255.999 * pixel_color.x),
                        (int)(255.999 * pixel_color.y),
                        (int)(255.999 * pixel_color.z));
}

int	main(void)
{
    int     i;
    int     j;
	double	u;
	double	v;
	t_color3    pixel_color;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	t_object	*world;
	canv = canvas(400,300);
	cam = camera(&canv, point3(0,0,0));
	world = object(SP, sphere(point3(-2,0,-5),2));
	oadd(&world,object(SP,sphere(point3(2,0,-5),2)));
	oadd(&world,object(SP,sphere(point3(0,-1000,0),990)));
    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", canv.width, canv.height);
    j = canv.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			ray = ray_primary(&cam,u,v);
			pixel_color = ray_color(&ray, world);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
    return (0);
}
