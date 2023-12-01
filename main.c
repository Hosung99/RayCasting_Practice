#include "print.h"
#include "trace.h"
#include "scene.h"
#include "structures.h"
#include "utils.h"

t_scene	*scene_init(void)
{
	t_scene 	*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL); //exit하도록 수정
	scene->canvas = canvas(WIDTH,HEIGHT);
	scene->camera = camera(&scene->canvas, point3(0,0,0));
    world = object(SP, sphere(point3(-2, -5, 5), 2), color3(0.5, 0, 0)); // world 에 구1 추가
	oadd(&world, object(PL, plane(vec3(0.0,-1.0,0.0), point3(0.0,0.0,-100.0), color3(0,0,0.5)),color3(1,1,1)));
    scene->world = world;
    lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
	scene->light = lights;
	ka = 0.1;
	scene->ambient.r = ka;
	scene->ambient.g = ka;
	scene->ambient.b = ka;
	return (scene);
}


void    write_color(t_color3 pixel_color)
{
    printf("%d %d %d\n", (int)(255.999 * pixel_color.r),
                        (int)(255.999 * pixel_color.g),
                        (int)(255.999 * pixel_color.b));
}

int	main(void)
{
    int     i;
    int     j;
	double	u;
	double	v;
	t_color3    pixel_color;
	t_ray		ray;
	t_scene		*scene;

	scene = scene_init();
    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
    return (0);
}
