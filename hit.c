#include "structures.h"
#include "utils.h"
#include "trace.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec) //구가 카메라를 둘러쌈을 고려.
{
	rec->front_face = vdot(ray->direction, rec->normal); //백터 내적
	if (rec->front_face < 0) //벡터 내적이 0보다 작다면 법선벡터의 반대로 설정해준다.
		rec->normal = vmult(rec->normal, -1);
}

double	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec3 oc;

	double a;
	double half_b;
	double c;
	double result;
	double	sqrt_result;
	double	root;

	oc.x = ray->origin.x - sp->center.x;
	oc.y = ray->origin.y - sp->center.y;
	oc.z = ray->origin.z - sp->center.z;
	a = vlength2(ray->direction);
	half_b = vdot(oc, ray->direction);
	c = vlength2(oc) - sp->radius2;
	result = half_b * half_b - a * c; //짝수 근의공식
	if (result < 0 )
		return (0);
	sqrt_result = sqrt(result); //루트 씌우기
	root = (-half_b - sqrt_result) / a; //두 근 중 작은 근
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrt_result) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (0);
	}
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->normal.x = (rec->point.x - sp->center.x) / sp->radius1;
	rec->normal.y = (rec->point.y - sp->center.y) / sp->radius1;
	rec->normal.z = (rec->point.z - sp->center.z) / sp->radius1;
	set_face_normal(ray, rec);
	return (1);
}
