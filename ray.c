#include "trace.h"


//ray 생성자(정규화 된 ray)
t_ray ray(t_point3 origin, t_vec3 dir)
{
	t_ray ray;

	ray.origin = origin;
	//vunit 함수에서 방향벡터의 크기를 1로 정규화해준다.
	ray.direction = vunit(dir);
	return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3 ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at.x = ray->origin.x + t * ray->direction.x;
	at.y = ray->origin.y + t * ray->direction.y;
	at.z = ray->origin.z + t * ray->direction.z;
	return (at);
}

t_ray	ray_primary(t_camera *camera, double u, double v)
{
	t_ray ray;
	t_vec3 vec;
	t_vec3 temp;

	ray.origin = camera->origin;
	temp = vplus(vmult(camera->horizontal, u), vmult(camera->vertical, v));
	vec.x = camera->left_top.x + temp.x - camera->origin.x;
	vec.y = camera->left_top.y + temp.y - camera->origin.y;
	vec.z = camera->left_top.z + temp.z - camera->origin.z;
	ray.direction = vec;
	return (ray);
}

int	in_shadow(t_object *obj, t_ray light_ray, double light_ren)
{
	t_hit_record rec;

	rec.tmin = 0;
	rec.tmax = light_ren;
	if (hit(obj, &light_ray, &rec))
		return (1);
	else
		return (0);
}

t_hit_record		record_init(void)
{
	t_hit_record record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3 diffuse;
	t_color3 color_temp;
	t_vec3 light_dir;
	t_vec3 temp;
	t_point3 point_temp;
	double	kd; //diffuse 강도
	double	brightness;
	double	light_len;
	t_ray	light_ray;

	temp.x = light->origin.x - scene->rec.point.x; //원점에서 광원까지의 벡터
	temp.y = light->origin.y - scene->rec.point.y;
	temp.z = light->origin.z - scene->rec.point.z;
	light_len = vlength(temp);
	point_temp.x = scene->rec.point.x + EPSILON * scene->rec.normal.x;
	point_temp.y = scene->rec.point.y + EPSILON * scene->rec.normal.y;
	point_temp.z = scene->rec.point.z + EPSILON * scene->rec.normal.z;
	light_ray = ray(point_temp, temp);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color3(0,0,0));
	light_dir = vunit(temp); //교점에서 출발하여 광원을 향하는 벡터 (정규화한)
	//cos세타가 90도일때 , 0이고 세타가 둔각일 시 음수가 되므로 0.0으로 초기화해준다.
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0); //두 벡터의 내적
	diffuse.r = light->light_color.r * kd;
	diffuse.g = light->light_color.g * kd;
	diffuse.b = light->light_color.b * kd;
	brightness = light->bright_ratio * LUMEN;
	color_temp = plus_color(scene->ambient, diffuse);
	color_temp.r = color_temp.r * brightness;
	color_temp.g = color_temp.g * brightness;
	color_temp.b = color_temp.b * brightness;
	return (color_temp);
}

t_color3	phong_lightning(t_scene *scene)
{
	t_color3 	light_color;
	t_object	*lights;
	t_color3	light_temp;

	light_color = color3(0,0,0); //광원 초기화
	lights = scene->light;
	while(lights)
	{
		if (lights->object_type == LIGHT_POINT)
			light_color = plus_color(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = plus_color(light_color, scene->ambient); //모든 광원에 의한 빛의 양을 구한 후
	light_color.r = light_color.r * scene->rec.albedo.r; //object의 반사율과 곱한다.
	light_color.g = light_color.g * scene->rec.albedo.g;
	light_color.b = light_color.b * scene->rec.albedo.b;
	return (color_min(light_color, color3(1,1,1))); //만약 광원의 합이 1보다 크면 color(1,1,1)을 반환
}

t_color3	ray_color(t_scene *scene)
{
	double t;
	t_vec3 n;

	scene->rec = record_init();
	//ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lightning(scene));
	else
	{
		// (1-t) * 흰색 + t * 하늘색
		t = 0.5 * (scene->ray.direction.y + 1.0);
		return (plus_color(v_mult_color(color3(1,1,1), 1.0-t), v_mult_color(color3(0.5,0.7,1.0), t)));
	}
}
