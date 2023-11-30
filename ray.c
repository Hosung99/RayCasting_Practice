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

t_color3	ray_color(t_ray *r)
{
	double t;
	t = 0.5 * (r->direction.y + 1.0);
	// (1-t) * 흰색 + t * 하늘색
	return (plus_color(v_mult_color(color3(1,1,1), 1.0-t), v_mult_color(color3(0.5,0.7,1.0), t)));
}
